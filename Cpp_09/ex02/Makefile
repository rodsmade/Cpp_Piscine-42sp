CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = PmergeMe
# ARGS = $(shell ruby generate_random_numbers.rb)

all: $(NAME)

run: $(NAME)
	./$(NAME) 150 24769 12457 13054 1708 3670 14599 1131 1686 23540 21198 10140 821 19793 20387 18524 11075 15373 894

vava: $(NAME) generate_random_numbers.rb
	 | xargs valgrind --leak-check=full --show-leak-kinds=all --quiet ./$<

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
