NAME	= PmergeMe

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SRCS	= main.cpp PmergeMe.cpp
OBJS	= $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
