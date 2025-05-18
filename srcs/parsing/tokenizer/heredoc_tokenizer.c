/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:47:14 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 17:28:34 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	heredoc_tokenizer(t_token **tks, const char *s, t_gc **gc)
{
	t_token	*tok;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace((unsigned char)s[i]))
			i++;
		if (!s[i])
			break ;
		if (is_operator_char(s[i]))
		{
			tok = new_token(get_op_type(&s[i], &len), 0, NULL, gc);
			if (handle_error(tok, NULL, &i, len))
				return (1);
		}
		else if (sub_tokenizer(s, &i, &tok, gc))
			return (1);
		if (!tok)
			return (1);
		token_add_back(tks, tok);
	}
	return (0);
}
