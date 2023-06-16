NAME = scravtrap

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra --std=c++98

SRC = ClapTrap.cpp main.cpp ScavTrap.cpp

BIN = $(SRC:.cpp=.o)

$(NAME): $(BIN)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(BIN)


all: $(NAME)

clean:
	rm -rf $(BIN)

fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: clean fclean re all