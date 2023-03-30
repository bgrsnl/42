NAME = phonebook
SRCS = phonebook.cpp
HDRS=*.hpp
CMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME):$(SRCS) $(HDRS)
	$(CMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean : clean

re: fclean all