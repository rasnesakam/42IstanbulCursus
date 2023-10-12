NAME = iter

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXARGS = -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $(CXXARGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re