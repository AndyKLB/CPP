
#######################################################
## ARGUMENTS
NAME:= Iter
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++98 -g

#######################################################
## SOURCES
SRCS_DIR:= ./srcs
OBJS_DIR:= ./objs

FILES:= main.cpp

SRCS:= $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS:= $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

#######################################################
## RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $< -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re