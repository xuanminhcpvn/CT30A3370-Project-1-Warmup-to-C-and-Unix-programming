CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

reverse: src/main.c src/reverse.c src/reverse.h
	$(CC) $(CFLAGS) src/main.c src/reverse.c -o reverse

test_files: reverse
	./reverse tests/input.txt > actual.txt
	diff actual.txt tests/expected.txt

test_reverse: tests/test_reverse.c src/reverse.c src/reverse.h
	$(CC) $(CFLAGS) tests/test_reverse.c src/reverse.c -o test_reverse

valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.out.txt ./reverse

clean:
	rm -f reverse test_reverse actual.txt valgrind.out.txt *.txt

.PHONY: clean test_files test_reverse valgrind
