CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
OBJ_DIR = obj

all: obj rpn

rpn: $(OBJ_DIR)/main.o $(OBJ_DIR)/RPN.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/RPN.o -o rpn

$(OBJ_DIR)/main.o: main.cpp RPN.hpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/RPN.o: RPN.cpp RPN.hpp
	$(CC) $(CFLAGS) -c RPN.cpp -o $(OBJ_DIR)/RPN.o

clean:
	rm -f rpn $(OBJ_DIR)/*.o
	rm -rf obj

obj:
	mkdir obj

.PHONY: all clean