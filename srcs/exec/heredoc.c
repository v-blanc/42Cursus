#include "minishell.h"

static void	print_warning_eof(int count, const char *delimiter)
{
	print(2, "minishell: warning: here-document at line %d ", count);
	print(2, "delimited by end-of-file (wanted `%s')\n", delimiter);
}

void	handle_heredoc(const char *delimiter, t_gc **head)
{
	int				pipe_fd[2];
	int				count;
	char			*line;
	const size_t	delimiter_length = ft_strlen(delimiter);

	(void)head;
	if (pipe(pipe_fd) < 0)
		exit(EXIT_FAILURE);
	count = 1;
	while (true)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strncmp(line, delimiter, delimiter_length - 1) == 0
				&& line[delimiter_length] == '\n'))
		{
			if (!line)
				print_warning_eof(count, delimiter);
			gc_free(line, head);
			break ;
		}
		count++;
	}
	close(pipe_fd[OUT_FD]);
	dup2(pipe_fd[IN_FD], STDIN_FILENO);
	close(pipe_fd[IN_FD]);
}
