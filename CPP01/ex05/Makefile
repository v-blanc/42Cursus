# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 18:27:11 by vblanc            #+#    #+#              #
#    Updated: 2025/04/29 20:12:29 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME := Harl_2.0
RM := rm -rf

INCDIR := include
SRCDIR := srcs
OBJDIR := objs
FILES := main.cpp Harl.cpp

SRCS := $(addprefix $(SRCDIR)/, $(FILES))
OBJS := $(addprefix $(OBJDIR)/, $(FILES:.cpp=.o))
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean:
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all libft clean fclean re
