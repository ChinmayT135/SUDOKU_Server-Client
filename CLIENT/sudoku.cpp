#include"sudoku_header.h"

int main(){
	

	std::cout<<"WELCOME TO SOLVING SUDOKU !!\n";
	int input = 0;

	do{

		std::cout<<"\nPlease select from the given options \n";
		std::cout<<"1) Get solution for sudoku grid\n";
		std::cout<<"2) Get help regarding input for sudoku grid\n";
		std::cout<<"3) Exit\n";

		std::cin>>input;

		switch(input){
			case 1:
			case 2:
				SUDOKU sd;
				sd.solve(input);
				break;
			case 3:
				std::cout<<"Thankyou for playing and hope you enjoyed !!\nComeback soon!!\n";
				break;
			default:
				std::cout<<"Please enter a valid input\n";
				input = 0;
				break;
		}

	}while(input != 3);

	return 0;
}
