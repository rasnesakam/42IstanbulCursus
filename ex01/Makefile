NAME = ex01
SRCS = main.cpp Span.cpp
CXX	 = c++
CXXARGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRCS)
	$(CXX) $(CXXARGS) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	@echo "There is no object files!"
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re