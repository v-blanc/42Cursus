/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:25:31 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/17 13:44:45 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	disable_ctrl_backslash_echo(void)
{
	struct termios	term;

	if (!isatty(STDIN_FILENO))
		return ;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	sig_handler(int sig)
{
	t_context	*ctx;

	(void)sig;
	ctx = get_ptr();
	ctx->signal = 130;
}

void	init_sig(void)
{
	struct sigaction	sa;

	if (!isatty(STDIN_FILENO))
		return ;
	disable_ctrl_backslash_echo();
	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
