/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:25:31 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 13:15:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool		g_sigint = false;
bool		g_was_in_heredoc = false;

static void	disable_ctrl_backslash_echo(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	sig_handler(int sig)
{
	(void)sig;
	g_sigint = true;
}

void	init_sig(void)
{
	struct sigaction	sa;

	if (!isatty(STDIN_FILENO))
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return ;
	}
	disable_ctrl_backslash_echo();
	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

static void	sig_handler_heredoc(int sig)
{
	(void)sig;
	g_sigint = true;
}

void	init_sig_heredoc(void)
{
	struct sigaction	sa;

	if (!isatty(STDIN_FILENO))
		return ;
	disable_ctrl_backslash_echo();
	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler_heredoc;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
