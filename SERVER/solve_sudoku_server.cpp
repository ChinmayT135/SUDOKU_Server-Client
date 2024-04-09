#include"server.h"


bool SUDOKU::check(int x, int y, char j, char* sudoku_array){
    for(int i=0 ; i<N ; i++){
        if(sudoku_array[(N*x)+i] == j)
            return false;
        if(sudoku_array[(N*i)+y] == j)
            return false;
        if(sudoku_array[(N*(((x/num)*num)+(i/num))) + (((y/num)*num)+(i%num))] == j)
            return false;
    }
    return true;
}

bool SUDOKU::complete_sudoku(char *sudoku_array){
    for(int i=0 ; i<N*N ; i++){
        if(sudoku_array[i] == '0'){
            int x = i/N;
            int y = i%N;
            for(char k=49 ; k<=57 ; k++){
                if(check(x,y,k,sudoku_array)){
                    sudoku_array[i] = k;
                    if(complete_sudoku(sudoku_array))
                        return true;
                    else
                        sudoku_array[i] = '0';
                }
            }
            return false;
        }
    }
    return true;
}


void SUDOKU::sudoku_solver(char* buffer){
	complete_sudoku(buffer);
}

void enc_dec(char* sudoku_array,int key){
    for(int i=0 ; i<N*N ; i++)
        sudoku_array[i] = sudoku_array[i]^key;
}

