CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = PmergeMe
ARGS = 10467 22137 26863 17758 2227 15961 6880 7108 26266 10684 19169 

all: $(NAME)

run: $(NAME)
	@./$(NAME) $(ARGS)

vava: $(NAME) generate_random_numbers.rb
	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) $(ARGS)
	

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
