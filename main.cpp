#include <iostream>
#include <vector>

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
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
		if (field[k][j] == 0)
			std::cout << ' ';
		if (field[k][j] == 1)
			std::cout << 'O';
		if (field[k][j] == 2)
			std::cout << 'X';
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

int main()
{
    field_update();
	bool X_or_O{true}; //false means X
	int j{};
	int i{};

while(true){
		if(X_or_O == true){
			std::cout << "O player's turn. Choose position(row, collumn):\n";
			std::cin >> i;
			std::cin >> j;
			field[i][j] = 1;
			X_or_O = false; 
			field_update();
		}
		if(X_or_O != true){
			std::cout << "X player's turn. Choose position(row, collumn):\n";
			std::cin >> i;
			std::cin >> j;
			field[i][j] = 2;
			X_or_O = true;  
			field_update();
		}   
}

return 0;
}
