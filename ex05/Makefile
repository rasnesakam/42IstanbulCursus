NAME = harl
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Harl.cpp main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

re: clean all

clean:
	rm -rf $(NAME)

.PHONY: all re clean