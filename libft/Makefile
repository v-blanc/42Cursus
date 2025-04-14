# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 00:52:17 by vblanc            #+#    #+#              #
#    Updated: 2025/04/14 20:47:44 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

OBJDIR := ./objs

SRCS := ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_intlen.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c\
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strtrim.c\
	ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c ft_strlen_array.c
OBJS := $(patsubst %.c,$(OBJDIR)/%.o, $(SRCS))

BONUS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJSB := $(patsubst %.c,$(OBJDIR)/%.o,$(BONUS))


NAME := libft.a
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)

bonus: $(OBJSB)
	ar -rsc $(NAME) $(OBJSB)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus