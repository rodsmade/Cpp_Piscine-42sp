CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = btc

all: $(NAME)
	./$^

vava: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

$(NAME): BitcoinExchange.o
	$(CC) $? main.cpp -o $@

BitcoinExchange.o: BitcoinExchange.cpp BitcoinExchange.hpp
	$(CC) -c $< -o $@

clean:
	rm -f BitcoinExchange.o

fclean: clean
	rm -f $(NAME)