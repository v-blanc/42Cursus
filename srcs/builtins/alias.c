/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:06:28 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 17:36:02 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"

int			alias(int argc, char **argv, t_context *ctx);
static int	print_aliases_then_return_zero(t_context *ctx);
static int	update_aliases(int argc, char **argv, t_context *ctx);
static bool	process_alias(t_alias *a, char *query, char *temp, t_context *ctx);

int	alias(int argc, char **argv, t_context *ctx)

{
	if (argc == 1)
		return (print_aliases_then_return_zero(ctx));
	return (update_aliases(argc, argv, ctx));
}

static int	print_aliases_then_return_zero(t_context *ctx)

{
	t_alias	*current;

	current = ctx->aliases;
	while (current)
	{
		print(1, "%s='%s'\n", current->key, current->value);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

static int	update_aliases(int argc, char **argv, t_context *ctx)

{
	int		i;
	char	*temp;
	t_alias	*aliases;

	i = 0;
	while (++i < argc)
	{
		temp = ft_strchr(argv[i], '=');
		if (!temp)
		{
			aliases = ctx->aliases;
			while (aliases)
			{
				if (process_alias(aliases, argv[i], temp, ctx))
					break ;
				aliases = aliases->next;
			}
		}
	}
	return (EXIT_SUCCESS);
}

static bool	process_alias(t_alias *a, char *query, char *temp, t_context *ctx)
{
	if (ft_strcmp(a->key, query) == 0)
	{
		print(1, "%s='%s'\n", a->key, a->value);
		return (true);
	}
	else
	{
		*temp = '\0';
		add_alias(query, temp + 1, ctx);
		return (false);
	}
}
