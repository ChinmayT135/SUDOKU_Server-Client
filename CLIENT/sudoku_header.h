#include<iostream>
#include<string>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<fstream>

#define N 9
#define num 3
#define KEY 'C'

bool send_buffer_to_server(char* sudoku_array);
void guide();
void enc_dec(char* sudoku_array,char key);


class SUDOKU{
	private:
		bool is_solved(char* sudoku_array);
		bool is_input_valid(char* sudoku_array);
		bool complete_sudoku(char* sudoku_array);
		void print_sudoku(char* sudoku_array);
		bool get_input(const std::string& file_path, char* sudoku_array);
		
	public:
		void solve_sudoku();
		void solve(int input);
};

