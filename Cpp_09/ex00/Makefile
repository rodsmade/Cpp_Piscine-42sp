CC = c++ -Wall -Wextra -Werror -std=c++98 -g
NAME = btc

all: $(NAME)

run: $(NAME)
	./$^ input_good.txt

vava: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) $(ARGS)

$(NAME): BitcoinExchange.o main.o
	$(CC) $^ -o $@

BitcoinExchange.o: BitcoinExchange.cpp
	$(CC) -c $< -o $@

main.o: main.cpp
	$(CC) -c $< -o $@

clean:
	rm -f BitcoinExchange.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run vava clean fclean re
