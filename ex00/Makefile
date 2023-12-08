NAME = easyfind
SRCS = main.cpp
CXX	 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	@echo "There is no object files!"
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
