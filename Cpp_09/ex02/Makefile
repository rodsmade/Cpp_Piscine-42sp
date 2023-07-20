CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = PmergeMe

all: $(NAME)

run: $(NAME) generate_random_numbers.rb
	ruby generate_random_numbers.rb | xargs ./$<

vava: $(NAME) generate_random_numbers.rb
	ruby generate_random_numbers.rb | xargs valgrind --leak-check=full --show-leak-kinds=all --quiet ./$<

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
