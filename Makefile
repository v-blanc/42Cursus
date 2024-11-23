# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 23:54:55 by vblanc            #+#    #+#              #
#    Updated: 2024/11/22 00:10:14 by vblanc           ###   ########.fr        #
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

$(NAME): repository $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

repository:
	@mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re