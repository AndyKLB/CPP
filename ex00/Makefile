#######################################################
## ARGUMENTS
NAME := megaphone
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

#######################################################
## SOURCES
SRCS_DIR := ./src
OBJS_DIR := ./objs

FILES := megaphone.cpp

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

#######################################################
## RULES
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re