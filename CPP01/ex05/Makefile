#######################################################
## ARGUMENTS
NAME:= harl
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++98 -g3

#######################################################
## SOURCES
OBJS_DIR:= ./objs
SRCS_DIR:= ./srcs

FILES:= main.cpp harl.cpp

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
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re