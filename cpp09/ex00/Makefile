CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
OBJ_DIR = obj

all: obj btc

btc: $(OBJ_DIR)/main.o $(OBJ_DIR)/BitcoinExchange.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/BitcoinExchange.o -o btc

$(OBJ_DIR)/main.o: main.cpp BitcoinExchange.hpp | obj
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/BitcoinExchange.o: BitcoinExchange.cpp BitcoinExchange.hpp | obj
	$(CC) $(CFLAGS) -c BitcoinExchange.cpp -o $(OBJ_DIR)/BitcoinExchange.o

clean:
	rm -f btc $(OBJ_DIR)/*.o
	rm -rf obj

obj:
	mkdir -p obj

.PHONY: all clean
