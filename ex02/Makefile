NAME	= PmergeMe

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp PmergeMe.cpp
OBJS	= $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re