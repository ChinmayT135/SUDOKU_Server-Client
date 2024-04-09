#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<syslog.h>
#include<signal.h>
#include<fstream>
#include<filesystem>

#define N 9
#define num 3
#define KEY 'C'

#define MAX_CLIENTS 400


void start_server();
void enc_dec(char* sudoku_array, int key);


class SUDOKU{
	private:
		bool check(int x, int y, char j, char* sudoku_array);
		bool complete_sudoku(char* sudoku_array);
	public:
		void sudoku_solver(char* sudoku_array);

};
