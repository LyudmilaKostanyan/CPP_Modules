NAME = array
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
IFLAGS = -I.
OBJ_DIR = ./obj
INCL = $(wildcard .h*)
FILES = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(FILES))

$(OBJ_DIR)/%.o: %.cpp
	$(CPP) $(IFLAGS) -I. -c $< -o $@

all: mkdir $(NAME)

$(NAME): $(OBJ) $(INCL) Makefile
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re