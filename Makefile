# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:48:03 by vblanc            #+#    #+#              #
#    Updated: 2024/11/16 09:09:50 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := ft_printf.c ft_write_numbers.c ft_write_characters.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(SRCS))
# OBJS := $(patsubst %.c,%.o,$(SRCS))

NAME := libftprintf.a
RM := rm -rf

all: $(NAME)

$(NAME): repository $(OBJS)
	ar -rsc $(NAME) $(OBJS)

# bonus: repository $(OBJSB)
# 	ar -rsc $(NAME) $(OBJSB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

repository:
	@mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSB)	
#$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus