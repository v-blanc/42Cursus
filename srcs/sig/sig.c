#include "minishell.h"

void	sig_handler(int sig)
{
	(void)sig;
	// printf("\n");
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sig(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
