CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME := Serena_my_love!
RM := rm -rf

INCDIR := include
SRCDIR := srcs
OBJDIR := objs

FILES :=main.cpp ScavTrap.cpp ClapTrap.cpp
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
