NAME = ex00
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean