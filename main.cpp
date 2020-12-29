#include <iostream>
#include <vector>
#include "functions.h"

int main(){
	bool O_or_X {true}; //true is O's turn
	declare_field(); // asks user for field size and creates the field

	while(true){
		if (O_or_X == true) {
			std::cout << "It's O's player turn. What position do you want ? (row collumn)";
			int a{};
			int b{};
			std::cin >> a; 
			std::cin >> b;
			while(a > size_of_field || b > size_of_field || a < 0 || b < 0){
				std::cout << "invalid row or collumn, please enter again: ";
				std::cin >> a; 
				std::cin >> b;
			}
			field[a][b] = 1; 
			field_update();
		}
		if(O_or_X != true){
			std::cout << "It's X's player turn. What position do you want ? (row collumn)";
			int a{};
			int b{};
			std::cin >> a; 
			std::cin >> b;
			while(a > size_of_field || b > size_of_field || a < 0 || b < 0){
				std::cout << "invalid row or collumn, please enter again: ";
				std::cin >> a; 
				std::cin >> b;
			}
			field[a][b] = 2;
			field_update(); 
		}
		change_player(O_or_X);
		if(is_over() == true){
			break;
		}
	}
	std::cout << "Game over\n";	
	return 0;
}   