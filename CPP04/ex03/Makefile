#######################################################
## ARGUMENTS
NAME:= Materia
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++98 -g

#######################################################
## SOURCES
SRCS_DIR:= ./srcs
OBJS_DIR:= ./objs

FILES:= AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp Thunder.cpp

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