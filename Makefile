# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 16:18:52 by yabokhar          #+#    #+#              #
#    Updated: 2025/05/19 19:44:01 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -g

NAME := minishell
NAME_BONUS := minishell_bonus
RM := rm -rf

INCDIR := includes
SRCDIR := srcs
OBJDIR := objs

FILES := main.c\
		\
		gc_functions/gc_alloc.c gc_functions/gc_free.c gc_functions/gc_setenv.c\
		gc_functions/gc_strjoin.c gc_functions/gc_strdup.c gc_functions/gc_substr.c\
		gc_functions/gc_split.c gc_functions/gc_itoa.c gc_functions/gc_strndup.c\
		\
		parsing/tokenizer/tokenizer.c\
		parsing/tokenizer/tokenizer_utils.c\
		parsing/tokenizer/heredoc_tokenizer.c\
		parsing/tokenizer/catch_syntax_error.c\
		\
		parsing/expander/expander.c\
		parsing/expander/expand_one_token.c\
		parsing/expander/merge_tokens.c\
		\
		parsing/parser/parser.c\
		parsing/parser/parse_command.c\
		parsing/parser/parse_pipeline.c\
		parsing/parser/counters.c\
		parsing/parser/parse_paren.c\
		\
		parsing/wildcard/wildcard.c\
		parsing/wildcard/get_wildcard.c\
		parsing/wildcard/is_file_needed.c\
		\
		parsing/parsing_utils.c\
		parsing/parsing.c\
		\
		exec/exec.c\
		exec/track_paths.c\
		exec/heredoc.c\
		exec/resolve_heredoc.c\
		exec/exec_manager.c\
		exec/pipes.c\
		exec/redirections.c\
		\
		builtins/cd.c\
		builtins/echo.c\
		builtins/env.c\
		builtins/exit.c\
		builtins/export.c\
		builtins/export_utils.c\
		builtins/pwd.c\
		builtins/unset.c\
		builtins/repeat.c\
		\
		set_input/set_input.c\
		set_input/set_input_utils.c\
		\
		utils/main_utils.c\
		utils/close_heredoc_fds.c\
		utils/print.c\
		utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c\
		utils/sig.c\
		utils/pointer.c\
		utils/exit_eof.c

SRCS := $(addprefix $(SRCDIR)/, $(FILES))
OBJS := $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS := $(addprefix $(OBJDIR)/, $(FILES:.c=.d))

LIBFT := libft/libft.a


all: libft $(NAME)

bonus: $(NAME_BONUS)

libft:
	@make -C libft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(NAME_BONUS): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME_BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJDIR)

fclean:
	@make -C libft fclean
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all libft clean fclean re
