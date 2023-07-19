CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = PmergeMe
EXPR = "8 9 * 9 - 9 - 9 - 4 - 1 +"

all: $(NAME)

run: $(NAME)
	./$< $(EXPR)

vava: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$< $(EXPR)

$(NAME): PmergeMe.o main.o
	$(CC) $^ -o $@

PmergeMe.o: PmergeMe.cpp
	$(CC) -c $< -o $@

main.o: main.cpp
	$(CC) -c $< -o $@

clean:
	rm -f PmergeMe.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rerun: re run

.PHONY: all run vava clean fclean re rerun
