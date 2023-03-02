NAME = sad
CXX = c++
CXXFLAG += -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Weapon.cpp Human*.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXFLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean $(NAME)

.PHONY: clean re