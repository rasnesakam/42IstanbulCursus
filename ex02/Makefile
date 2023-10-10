NAME = bin
CXX = g++
CXXARGS = -Wall -Wextra -Werror

SRCS = AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXARGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re