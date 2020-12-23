#include <iostream>
#include <vector>

void Clear()
{
	system("cls");
} 
// clears the terminal for windows

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
	while (true) {

		field_update();
	}
return 0;
}
