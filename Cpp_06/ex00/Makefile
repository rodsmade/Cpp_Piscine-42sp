NAME = convert.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

run: all
	./$(NAME) nan

fclean:
	rm -f $(NAME)
