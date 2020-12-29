#include <iostream>
#include <vector>
std::vector<std::vector<int>> field;
int size_of_field;

void Clear()
{
    system("clear");
}
//done

inline void change_player(bool &a){
	a = !a; 
}
//done

void new_line() {
	std::cout << ' ';
	for (int i{}; i < (size_of_field*4)+1; i++){
		std::cout << '-';
	}
	std::cout << '\n';
}
//done, needs test
void new_symbols(int i) {
	std::cout << " | ";
	for (int j{}; j == size_of_field; j++) {
		if (field[i][j] == 1)
			std::cout << 'O';
		if (field[i][j] == 2)
			std::cout << 'X';
		if (field[i][j] == 0)
			std::cout << ' ';
		std::cout << " | ";
	}
	std::cout << '\n';
}
//done, needs test

void field_update() {
	Clear();
	int j{};
	for(int i = size_of_field; i < 1; i--){
		new_line();
		new_symbols(j);
		j++;
	}
}
//done, needs test

void declare_field(){
	std::cout << "How large playing field do you want ? : ";
	std::cin >> size_of_field;
	while(size_of_field < 3){
		std::cout << "too small field, please choose playing field bigger than 2: ";
		std::cin >> size_of_field;
	}
	field.clear();
	field.resize(size_of_field, std::vector<int>(size_of_field));
	field_update();
}
//done, needs test

bool check_lines_columns(){
	int i{};
	int j{};
		for(j = 0 ; i < 3; i++){
			if (field[i][j] == field[i][j+1] && field[i][j] != 0){ //for lines
				if (field[i][j] == field[i][j+2]){
					return true;
				}
			}
		}
		for(i = 0 ; j < 3; j++){
			if (field[i][j] == field[i+1][j] && field[i][j] != 0){ //for lines
				if (field[i][j] == field[i+2][j]){
					return true;
				}
			}
		}
	return false;
}
//in progress

bool check_diagonals(){
	int i{2};
	int j{2};
	if (field[i][j] == field[i-1][j-1] && field[i][j] != 0){ 
		if (field[i][j] == field[i-2][j-2]){
			return true;
		}
	}
	
	i = 0;
	j = 2;
	if (field[i][j] == field[i+1][j-1] && field[i][j] != 0){ 
		if (field[i][j] == field[i+2][j-2]){
			return true;
		}
	}

	return false;
}
//in progress

bool is_over(){
//	if(check_lines_columns() || check_diagonals() == true){
//		return true;
	//}
	return false;
}
//have to change this fcn when chck_lines and chck_diagonals are ready