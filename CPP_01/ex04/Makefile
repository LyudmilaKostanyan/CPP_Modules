NAME = replace
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = $(wildcard *.cpp)
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm *.replace

re: fclean all

.PHONY: all clean fclean re