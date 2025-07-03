# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 16:00:20 by vblanc            #+#    #+#              #
#    Updated: 2025/04/29 18:16:58 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME := BraiiiiiiinnnzzzZ
RM := rm -rf

INCDIR := include
SRCDIR := srcs
OBJDIR := objs

FILES := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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