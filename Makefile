CC=gcc
FLAGS=-Wall -Werror -Wextra
DIR=./23-12-01\ Fibonacci/
OUT=a.out

all: main

main:
	$(CC) $(FLAGS) $(DIR)/main.c

run:
	./$(OUT)

fclang:
	clang-format -i */*.c

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean:
	rm -rf *.out *.o

rebuild: clean all
	./$(OUT)