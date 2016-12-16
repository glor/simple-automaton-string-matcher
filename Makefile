CC=clang
all:
	$(CC) -c matcher.c
test:
	$(CC) testMatcher.c matcher.o -o testMatcher
clean:
	rm -f matcher.o testMatcher
