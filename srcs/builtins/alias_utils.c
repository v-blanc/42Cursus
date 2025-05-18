/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:37:48 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 16:32:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"

void		create_aliases(t_context *ctx);
static void	get_content(int st_size, int fd, t_context *ctx);
static void	process_content(char **lines, t_context *ctx);
static bool	invalid_alias(const char *line);

void	create_aliases(t_context *ctx)
{
	char		*home;
	char		*path;
	int			fd;
	struct stat	st;

	home = getenv("HOME");
	if (!home)
		return ;
	path = gc_strjoin(home, "/.minishellrc", ctx->head);
	if (!path)
		return ;
	fd = open(path, O_RDONLY);
	gc_free(path, ctx->head);
	if (fd < 0)
		return ;
	if (fstat(fd, &st) < 0 || st.st_size == 0)
	{
		close(fd);
		return ;
	}
	get_content(st.st_size, fd, ctx);
}

static void	get_content(int st_size, int fd, t_context *ctx)
{
	char	*content;
	char	**lines;
	ssize_t	bytes_read;

	content = gc_malloc(st_size + 1, ctx->head);
	if (!content)
	{
		close(fd);
		return ;
	}
	bytes_read = read(fd, content, st_size);
	close(fd);
	if (bytes_read <= 0)
	{
		gc_free(content, ctx->head);
		return ;
	}
	content[bytes_read] = '\0';
	lines = gc_split(content, '\n', ctx->head);
	gc_free(content, ctx->head);
	if (!lines)
		return ;
	process_content(lines, ctx);
	free(lines);
}

static void	process_content(char **lines, t_context *ctx)
{
	char	*line;
	char	*key;
	char	*value;
	size_t	i;

	i = 0;
	while (lines[i])
	{
		line = lines[i];
		if (invalid_alias(line))
		{
			i++;
			continue ;
		}
		key = ft_strchr(line, '=');
		if (!key || key == line)
		{
			i++;
			continue ;
		}
		*key = '\0';
		value = key + 1;
		add_alias(line, value, ctx);
		i++;
	}
}

static bool	invalid_alias(const char *line)
{
	const char	*temp = ft_strchr(line, '=');
	size_t		i;

	if (!temp || temp == line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

void	add_alias(const char *key, const char *value, t_context *ctx)
{
	t_alias	*alias;
	t_alias	*new_alias;

	alias = ctx->aliases;
	while (alias)
	{
		if (ft_strcmp(alias->key, key) == 0)
		{
			gc_free(alias->value, ctx->head);
			alias->value = gc_strdup(value, ctx->head);
			return ;
		}
		alias = alias->next;
	}
	new_alias = gc_malloc(sizeof(t_alias), ctx->head);
	new_alias->key = gc_strdup(key, ctx->head);
	new_alias->value = gc_strdup(value, ctx->head);
	new_alias->next = ctx->aliases;
	ctx->aliases = new_alias;
}
