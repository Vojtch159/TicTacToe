#include <iostream>
#include <vector>

std::vector<std::vector<int>> field;
int size_of_field{};

void Clear()
{
    system("clear");
}
//done
void new_line() {
	std::cout << ' ';
	for (int i{}; i < (size_of_field*4)+1; i++)
		std::cout << '-';
	std::cout << '\n';
}
//done
void new_symbols() {
	static int i{};//collumn counter
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
	i++;
	if(i == size_of_field){
		i = 0;
	}
}
//in progress
void field_update() {
	Clear();
	for(int i = size_of_field; i == 1; i--){
		new_line();
		new_symbols();
	}
}
//in progress
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
//in progress
inline void change_player(bool &a){
	a = !a; 
}
//done
void declare_field(){
	std::cout << "How large playing field do you want ? : ";
	std::cin >> size_of_field;
	while(size_of_field < 3){
		std::cout << "too small field, please choose playing field bigger than 2: ";
		std::cin >> size_of_field;
	}
	field.resize(size_of_field, std::vector<int>(size_of_field));
	field_update();
}
//done

int main(){
	bool O_or_X {true}; //true is O's turn
	declare_field();

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
//done
