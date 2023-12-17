SRCS	= main.cpp RPN.cpp
OBJS	= $(SRCS:%.cpp=%.o)

NAME	= RPN
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re