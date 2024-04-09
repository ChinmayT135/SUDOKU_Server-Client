CC = g++
CFLAGS = -c -Wall -std=c++17
OBJS = server.o solve_sudoku_server.o

server_util : server.o solve_sudoku_server.o
	$(CC) $(OBJS) -o server_util

server.o : server.cpp server.h
	$(CC) $(CFLAGS) server.cpp server.h

solve_sudoku_server.o : solve_sudoku_server.cpp
	$(CC) $(CFLAGS) solve_sudoku_server.cpp


clean: 
	rm -rf *.o server_util
