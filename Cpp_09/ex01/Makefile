CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = RPN
EXPR = "8 9 * 9 - 9 - 9 - 4 - 1 +"

all: $(NAME)

run: $(NAME)
	./$< $(EXPR)

vava: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$< $(EXPR)

$(NAME): RPN.o main.o
	$(CC) $^ -o $@

RPN.o: RPN.cpp
	$(CC) -c $< -o $@

main.o: main.cpp
	$(CC) -c $< -o $@

clean:
	rm -f RPN.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rerun: re run

.PHONY: all run vava clean fclean re rerun
