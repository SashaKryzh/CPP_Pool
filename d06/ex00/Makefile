NAME		:= convert

# directories
SRC_DIR		:= .
OBJ_DIR		:= ./obj

# src / obj files
SRC			:=	main.cpp \

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

# compiler
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory