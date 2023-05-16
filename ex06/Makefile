NAME = harlfilter

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Harl.cpp main.cpp


$(NAME): $(SRC)
	g++ $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re