CC := cc
CFLAGS := -Wall -Werror -Wextra -g

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := main.c\
		gc_functions/garbage_collector.c gc_functions/gc_setenv.c gc_functions/gc_strjoin.c\
		gc_functions/gc_strdup.c gc_functions/gc_substr.c gc_functions/gc_split.c\
		gc_functions/gc_itoa.c\
		parsing/tokenizer/tokenizer.c parsing/tokenizer/tokenizer_utils.c\
		parsing/expander/expander.c parsing/expander/expand_one_token.c parsing/expander/merge_tokens.c\
		parsing/parser/parser.c parsing/parser/parse_command.c parsing/parser/print_ast.c\
		parsing/parsing.c parsing/parse_quotes.c\
		stack/stack.c\
		sig/sig.c\
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