#######################################################
## ARGUMENTS
NAME		:=	dreamjob
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g3

#######################################################
## SOURCES
SRCS_DIR 	:=	./srcs
OBJS_DIR 	:=	./objs

FILES		:=	tests.cpp Account.cpp 

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))


#######################################################
## RULES
all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re