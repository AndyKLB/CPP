#######################################################
## ARGUMENTS
NAME:= AbstractClass
CC:= c++
FLAGS:= -Wextra -Werror -Wall -std=c++98 -g3

#######################################################
## SOURCES
SRCS_DIR:= ./srcs
OBJS_DIR:= ./objs

FILES:= AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp main.cpp

SRCS:= $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS:= $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

#######################################################
## RULES

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
		mkdir -p $(OBJS_DIR)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re