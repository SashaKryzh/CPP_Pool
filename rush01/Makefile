NAME		:= ft_gkrellm

# directories
SRC_DIR		:= .
OBJ_DIR		:= ./obj
COBJ_DIR	:= ./cobj
# src / obj files
SRC			:=	main.cpp \
				helpers.cpp \
				HostnameModule.cpp \
				OSInfoModule.cpp \
				DateTimeModule.cpp \
				CPUModule.cpp \
				RAMModule.cpp \
				NetworkModule.cpp \
				AdditionalModule.cpp \
				NCursesDisplay.cpp \
				MLXDisplay.cpp

CSRC		:=	mlx_things.c

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
COBJ		:= $(addprefix $(COBJ_DIR)/,$(CSRC:.c=.o))
# compiler
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) -I. $(CXXFLAGS) -o $@ -c $<

$(COBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(COBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc -I. -Wall -Wextra -Werror -o $@ -c $<

$(NAME): $(OBJ) $(COBJ)
	$(CXX) -o $(NAME) -I. $(OBJ) $(COBJ) -lncurses -lmlx -framework OpenGl -framework AppKit

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory