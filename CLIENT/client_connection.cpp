#include"sudoku_header.h"
bool send_buffer_to_server(char* sudoku_array){

    int client;
    int port_no = 1500;
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if(client < 0){
        std::cerr<<"ERROR: failed connecting to server...\n";
        return false;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_no);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if(connect(client,(struct sockaddr *)&server_addr,sizeof(server_addr)) == 0)
        std::cout<<"\nConnection established...\n";
    else{
        std::cerr<<"ERROR: Failed to establish connection !\n";
		return false;
    }

	send(client,sudoku_array,N*N,0);

	memset(sudoku_array,'\0',N*N);
	recv(client,sudoku_array,N*N,0);

    close(client);
    return true;
}


void enc_dec(char* sudoku_array,char key){
	for(int i=0 ; i<N*N ; i++)
		sudoku_array[i] = sudoku_array[i]^key; 
}

