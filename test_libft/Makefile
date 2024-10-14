# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 16:48:57 by vblanc            #+#    #+#              #
#    Updated: 2024/10/14 05:00:29 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
INCL := ../libft.a

SRCSDIR := ./srcs
EXECDIR := ./bin

SRCS := $(wildcard $(SRCSDIR)/*.c)
EXECS := $(patsubst $(SRCSDIR)/%_test.c,$(EXECDIR)/%_exec,$(SRCS))

RM := rm -rf

all: repository $(EXECS)

$(EXECDIR)/%_exec: $(SRCSDIR)/%_test.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCL)

repository:
	@mkdir -p $(EXECDIR)
	@mkdir -p ./output_user
	@mkdir -p ./results

clean:
	$(RM) $(EXECDIR)

fclean: clean
	$(RM) ./output_user
	$(RM) ./results

re: fclean all

.PHONY: all clean fclean re bonus