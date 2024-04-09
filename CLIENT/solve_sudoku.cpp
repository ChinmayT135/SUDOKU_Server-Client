#include"sudoku_header.h"

void guide(){
    std::cout<<"\nSUDOKU HELP\n";
    std::cout<<"Sudoku is 9X9 grid with 9 3X3 sub-grid with each row, column, and 3X3 box having unique instance of any number from 1 to 9\n";
    std::cout<<"Here is an example input for you :\n0 0 1 0 0 0 0 0 2\n0 0 0 0 0 0 0 0 0\n0 0 3 0 6 0 0 0 0\n0 0 0 0 0 0 0 0 0\n0 9 0 0 0 0 0 0 0\n0 0 0 0 0 4 0 0 0\n0 0 0 0 0 0 0 0 7\n1 0 0 7 0 0 0 0 0\n0 0 0 0 5 0 0 0 0\n";
	std::cout<<"\nPlease fill in such a grid in any empty txt file and please provide the path for this file when prompted.\nHere is one example for you: /root/sample/file.txt\n";
}

bool SUDOKU::is_input_valid(char* sudoku_array){
    for(int i=0 ; i<N*N ; i++){
  	    if(sudoku_array[i] != '0'){
            if(sudoku_array[i]<'1' || sudoku_array[i]>'9'){
                return false;
			}

           	int x = i/N;
       	    int y = i%N;
   	        char val = sudoku_array[i];
            int count = 0;

   	        for(int k=0 ; k<N ; k++){
                if(sudoku_array[(N*x)+k] == val)
                    count++;
               	if(sudoku_array[(N*k)+y] == val)
                   	count++;
       		    if(sudoku_array[(N*(((x/num)*num)+(k/num)))+(((y/num)*num)+(k%num))] == val)
   	                count++;
            }
            if(count > 3)
           	    return false;
       	}
   	} 
    return true;
}

void SUDOKU::print_sudoku(char* sudoku_array){
	for(int i=0 ; i<N*N ; i++){
		if(i%9 == 0)
			std::cout<<std::endl;
		std::cout<<sudoku_array[i]<<" ";
	}
	std::cout<<std::endl;
}	

bool SUDOKU::get_input(const std::string& file_path, char* sudoku_array){
	std::ifstream file(file_path);
	std::string text;
	int count = 0;

	if(!file.good()){
		std::cerr<<"ERROR: failed to read the file\n";
		return false;
	}

	while(getline(file,text)){
		for(int i=0 ; i<text.length() ; i++){
			if(48<= text[i] && text[i] <=57){
				sudoku_array[count++] = text[i];
			}else if(text[i] != 32){
				std::cerr<<"ERROR: input is wrong, please make sure you input numbers separated by spaces\n";
				return false;
			}
		}
	}
	
	file.close();
	return true;;
}

bool SUDOKU::is_solved(char* sudoku_array){
	
	for(int i=0 ; i<N*N ; i++)
		if(sudoku_array[i] == '0')
			return false;

	return true;
}

bool SUDOKU::complete_sudoku(char* sudoku_array){
	return send_buffer_to_server(sudoku_array);
}

void SUDOKU::solve_sudoku(){
	char sudoku_array[N*N] = {0};
	std::string file_path;

	std::cout<<"\nPlease provide the file path : ";
	std::cin>>file_path;

	struct stat st;

	if(stat(file_path.c_str(),&st) != 0){
		std::cerr<<"The path you provided does not exist : terminating process \nPlease try again !"<<std::endl;
		return;
	}

	if(get_input(file_path,sudoku_array) == false)
		return;

	if(is_input_valid(sudoku_array)){
		enc_dec(sudoku_array,KEY);
		if(complete_sudoku(sudoku_array)){
			enc_dec(sudoku_array,KEY);
			if(is_solved(sudoku_array))
				std::cout<<"\nHere is the solution :\n";
			else
				std::cerr<<"APOLOGIES: the grid you provided in unsolvable\n";
			print_sudoku(sudoku_array);
		}else
			std::cerr<<"\nPlease try again in sometime\n";
	}else
		std::cerr<<"ERROR: The given sudoku is invalid\nPlease try again!\n"; 
}

void SUDOKU::solve(int input){
	if(input == 1)
		solve_sudoku();
	else if(input == 2)
		guide();
}
