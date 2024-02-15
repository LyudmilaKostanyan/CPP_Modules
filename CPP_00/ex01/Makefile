NAME = phonebook
CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = $(wildcard *.cpp)
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re