
CC = g++
CFLAGS = -c -Wall
OBJS = sudoku.o solve_sudoku.o client_connection.o

util: sudoku.o solve_sudoku.o client_connection.o
	$(CC) $(OBJS) -o util

sudoku.o: sudoku.cpp sudoku_header.h
	$(CC) $(CFLAGS) sudoku.cpp sudoku_header.h

solve_sudoku.o: solve_sudoku.cpp
	$(CC) $(CFLAGS) solve_sudoku.cpp

client_connection.o: client_connection.cpp
	$(CC) $(CFLAGS) client_connection.cpp

clean:
	rm -rf *.o util

