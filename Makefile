CC := cc
CFLAGS := -Wall -Werror -Wextra -g

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := main.c utils_env.c\
		gc_functions/garbage_collector.c gc_functions/gc_strjoin.c gc_functions/gc_strdup.c\
		gc_functions/gc_substr.c gc_functions/gc_split.c\
		stack/stack.c\
		sig/sig.c\
		parsing/get_env_value.c parsing/parse_quotes.c\
		builtins/cd.c builtins/echo.c builtins/env.c builtins/export.c builtins/pwd.c builtins/unset.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT := ./libft/libft.a

NAME := minishell
RM := rm -rf

all: $(NAME)

libft:
	@make -C libft

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJDIR)

fclean:
	@make -C libft fclean
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re