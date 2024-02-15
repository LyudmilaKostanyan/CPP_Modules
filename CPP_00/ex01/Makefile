NAME = phonebook
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = ./src
OBJ_DIR = ./obj
INCL = $(wildcard includes/*.h*)
FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(FILES:.cpp=.o)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: mkdir $(NAME)

$(NAME): $(OBJ) $(INCL) Makefile
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re