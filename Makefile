CC=gcc
FLAGS=-Wall -Werror -Wextra
OUT=a.out

all: main

main: clean

all_devisors: clean
	$(CC) $(FLAGS) ./23-11-30\ All\ Devisors/main.c
	make run

factorize: clean
	$(CC) $(FLAGS) ./23-11-30\ Factorize/main.c
	make run

array_reverse: clean
	$(CC) $(FLAGS) ./23-12-01\ Array\ Reverse/main.c
	make run

fibonacci: clean
	$(CC) $(FLAGS) ./23-12-01\ Fibonacci/main.c
	make run

predicate: clean
	$(CC) $(FLAGS) ./23-12-04\ Predicate/main.c
	make run

str_ct_wc: clean
	$(CC) $(FLAGS) ./23-12-05\ String\ Length\ Words/main.c
	make run

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