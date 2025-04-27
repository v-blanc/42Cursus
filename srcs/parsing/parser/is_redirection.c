/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:25 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/27 19:35:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirection(t_token_type type)
{
	return (type == REDIR_IN || type == REDIR_OUT || type == REDIR_APPEND
		|| type == REDIR_HEREDOC);
}
