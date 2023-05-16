NAME = zombie
CXX = c++
CXXFLAG += -Wall -Wextra -Werror -std=c++98
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re