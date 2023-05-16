NAME = hi
CXX = c++
CXXFLAG += -Wall -Wextra -Werror -std=c++98
SRC = main.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re