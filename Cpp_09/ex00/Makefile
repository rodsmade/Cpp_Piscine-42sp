CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = btc

all: $(NAME)
	./$^ $(ARGS)

vava: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) $(ARGS)

$(NAME): BitcoinExchange.o main.cpp
	$(CC) $? -o $@

BitcoinExchange.o: BitcoinExchange.cpp BitcoinExchange.hpp
	$(CC) -c $< -o $@

clean:
	rm -f BitcoinExchange.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all vava clean fclean re
