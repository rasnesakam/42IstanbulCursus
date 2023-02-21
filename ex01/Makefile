NAME = phonebook
CXX = c++
CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRC = contact.cpp phonebook.cpp main.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clear:
	rm $(NAME)

.PHONY: clear