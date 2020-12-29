#include <iostream>
#include <vector>

void Clear()
{
    system("clear");
}

std::vector<std::vector<int>> field
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}; // field [rows][collumns]

void new_line() {
	std::cout << ' ';
	for (int i{}; i < 13; i++)
		std::cout << '-';
	std::cout << '\n';
}

void new_symbols(int k) {
	int i{};
	std::cout << " | ";
	for (int j = i; j < i + 3; j++) {
		if (field[k][j] == 1)
			std::cout << 'O';
		if (field[k][j] == 2)
			std::cout << 'X';
		if (field[k][j] == 0)
			std::cout << ' ';
		std::cout << " | ";
	}
	std::cout << '\n';
}

void field_update() {
	Clear();
	new_line();
	new_symbols(0);
	new_line();
	new_symbols(1);
	new_line();
	new_symbols(2);
	new_line();
}

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


bool is_over(){
	if(check_lines_columns() || check_diagonals() == true){
		return true;
	}
	return false;
}


int main(){
	bool O_or_X {true}; //true is O's turn
	int a{};
	int b{};
	field_update();
	while(true){
		if (O_or_X == true) {
			std::cout << "It's O's player turn. What position do you want ? (row collumn)";
			std::cin >> a; 
			std::cin >> b;
			field[a][b] = 1; 
			field_update(); 
		}
		if(O_or_X != true){
			std::cout << "It's X's player turn. What position do you want ? (row collumn)";
			std::cin >> a; 
			std::cin >> b;
			field[a][b] = 2;
			field_update(); 
		}
		O_or_X = !O_or_X; 
		if(is_over() == true){
			break;
		}
	}
	std::cout << "Game over\n";	
	return 0;
}   