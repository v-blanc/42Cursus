CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME := Polymorphisme
RM := rm -rf

INCDIR := include
SRCDIR := srcs
OBJDIR := objs

FILES := main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
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
