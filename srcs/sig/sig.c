#include "../../include/minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	// else if (sig == SIGQUIT)
	// {
	// 	printf("^\\");
	// 	//TODO: cleanup everything
	// 	printf("temp: ctrl+\\ have been pressed\n");
	// }
}

void	init_sig(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
