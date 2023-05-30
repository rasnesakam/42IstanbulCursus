NAME = ex00
CXX = c++
CXXARGS = -Wall -Wextra -Werror --std=c++98
SRC = Fixed.cpp main.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXARGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re