NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra --std=c++98

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp
BIN = $(SRC:.cpp=.o)

$(NAME): $(BIN)
	$(CXX) $(SRC) $(CXXFLAGS) -o $@

all: $(NAME)

all_term:
	clang++ -W -Wall -Werror *.cpp


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean