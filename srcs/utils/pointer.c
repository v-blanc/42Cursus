/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:43:42 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/16 22:11:02 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*secret(void *ptr, bool mode)
{
	static void	*_ptr = NULL;

	if (mode)
		_ptr = ptr;
	return (_ptr);
}

void	set_ptr(void *ptr)
{
	secret(ptr, true);
}

void	*get_ptr(void)
{
	return (secret(NULL, false));
}
