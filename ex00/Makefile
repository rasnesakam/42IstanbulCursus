NAME = animals

CXX = c++
CXXARGS = -Wall -Werror -Wextra --std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
BIN = $(SRC:.cpp=.o)

$(NAME): $(BIN)
	$(CXX) $(BIN) $(CXXARGS) -o $@

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean