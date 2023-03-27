CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
OBJ_DIR = obj

all: obj PmergeMe

PmergeMe: $(OBJ_DIR)/main.o $(OBJ_DIR)/PmergeMe.o
	mkdir -p obj
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/PmergeMe.o -o PmergeMe

$(OBJ_DIR)/main.o: main.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/PmergeMe.o: PmergeMe.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c PmergeMe.cpp -o $(OBJ_DIR)/PmergeMe.o

clean:
	rm -f PmergeMe $(OBJ_DIR)/*.o
	rm -rf obj

obj:
	mkdir obj

.PHONY: all clean