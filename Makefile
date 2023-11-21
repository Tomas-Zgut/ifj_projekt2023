#Makefile
EXECUTABLE = IFJcode23
CC = gcc
CFLAGS = -g -Wall --std=c11 -g --pedantic -Wextra
HEADERS = src/scanner.h src/utils.h src/symtable.h

all: $(EXECUTABLE)

scanner.o: src/scanner.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

utils.o: src/utils.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

symtable.o: src/symtable.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

$(EXECUTABLE): scanner.o utils.o symtable.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean, valgrind, test_table
clean:
	rm -f $(EXECUTABLE) *.o
valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(EXECUTABLE)