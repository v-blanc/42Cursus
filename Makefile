# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 23:54:55 by vblanc            #+#    #+#              #
#    Updated: 2025/01/27 13:03:02 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := main.c rules.c sort.c stack_utils.c stack.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT := ./libft/libft.a

NAME := push_swap
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd libft && make clean	&& cd ..
	$(RM) $(OBJDIR)

fclean:
	@cd libft && make fclean && cd ..
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re