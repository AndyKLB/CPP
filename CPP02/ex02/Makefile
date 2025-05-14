#######################################################
## ARGUMENTS
NAME := nowWeCanTalk
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

#######################################################
## SOURCES
SRCS_DIR := ./srcs
OBJS_DIR := ./objs

FILES := main.cpp fixed.cpp

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

#######################################################
## RULES

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
		mkdir -p $(OBJS_DIR)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re