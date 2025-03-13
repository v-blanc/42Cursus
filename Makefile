CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := main.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT := ./includes/libft/libft.a

NAME := minishell
RM := rm -rf

all: $(NAME)

libft:
	@make -C includes/libft

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C includes/libft clean
	$(RM) $(OBJDIR)

fclean:
	@make -C includes/libft fclean
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re