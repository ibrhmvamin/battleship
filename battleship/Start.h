#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
using namespace std;

int row = 10;
int col = 10;
int MaxShips = 20;

void PrintBoard(int** arr, int row, int col);
int** ReserveArray(int row, int col);
void InitArray(int** arr);

enum Boats { Submarine = 1, Destroyer = 2, Cruiser = 3, Battleship = 4, Carrier = 5 };

void SetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void ShowMenu() {
	cout << "               **********Welcome To Battle Ship*************\n\n\n";
	cout << "Please choose from the following\n\n\n";
	cout << "1) Play Battleship\n";
	cout << "2) Print Game Rule\n";
	cout << "3) Exit The Game\n";

}

int** ReserveArray(int row, int col) {
	auto arr = new int* [row] {};
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int [col] {};
	}
	return arr;
}

void InitArray(int**arr) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			arr[i][k] = 0;
			
		}
	}
}

void PrintBoard(int** arr, int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			if (i == 0) {
				cout << setw(3) << k << " ";
			}
			else if (k == 0) {
				cout << setw(3) << i << " ";
			}
			else if (arr[i][k] == 0) {
				SetColor(9, 0);
				cout << setw(3) << (char)254 << " ";

			}
			else if (arr[i][k] == 1) {
				SetColor(2, 0);
				cout << setw(3) << (char)254 << " ";

			}
			else if (arr[i][k] == 2) {
				SetColor(5, 0);
				cout << setw(3) << (char)254 << " ";
			}
			else if (arr[i][k] == 9) {
				SetColor(14, 0);
				cout << setw(3) << (char)254 << " ";
			}
			SetColor(7, 0);
		}cout << endl;
	}cout << endl << endl;
}

void PrintGameBoard(int** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			if (i == 0) {
				cout << setw(3) << k << " ";
			}
			else if (k == 0) {
				cout << setw(3) << i << " ";
			}
			else if (arr[i][k] == 0) {
				SetColor(9, 0);
				cout << setw(3) << (char)254 << " ";

			}
			else if (arr[i][k] == 1) {
				SetColor(2, 0);
				cout << setw(3) << (char)254 << " ";

			}
			else if (arr[i][k] == 2) {
				SetColor(4, 0);
				cout << setw(3) << (char)254 << " ";
			}
			else if (arr[i][k] == 9) {
				SetColor(14, 0);
				cout << setw(3) << (char)254 << " ";
			}
			SetColor(7, 0);
		}cout << endl;
	}cout << endl << endl;
}

bool CheckSpace(int** arr, int X, int Y,char d,int bs){
	int size = 0;
	if (d == 'u') {
		for (size_t i = 0; i < bs; i++)
		{
			if (arr[X - i][Y] == 0 && arr[X - i][Y - 1] == 0 && arr[X - i][Y + 1] == 0
				&& arr[X + 1][Y] == 0 && arr[X + 1][Y - 1] && arr[X + 1][Y + 1] == 0) {
				size++;
			}
		}
	}
	else if (d == 'd') {
		for (size_t i = 0; i < bs; i++)
		{
			if (arr[X + i][Y] == 0 && arr[X + i][Y - 1] == 0 && arr[X + i][Y + 1] == 0
				&& arr[X - 1][Y] == 0 && arr[X - 1][Y - 1] && arr[X - 1][Y + 1] == 0) {
				size++;
			}
		}
	}
	else if (d == 'l') {
		for (size_t i = 0; i < bs; i++)
		{
			if (arr[X][Y -i] == 0 && arr[X +1][Y - i] == 0 && arr[X -1][Y -i] == 0
				&& arr[X ][Y+1] == 0 && arr[X - 1][Y + 1] && arr[X + 1][Y + 1] == 0) {
				size++;
			}
		}
	}
	else if (d == 'r') {
		for (size_t i = 0; i < bs; i++)
		{
			if (arr[X][Y + i] == 0 && arr[X - 1][Y + i] == 0 && arr[X + 1][Y + i] == 0
				&& arr[X][Y -1] == 0 && arr[X - 1][Y - 1] && arr[X + 1][Y + 1] == 0) {
				size++;
			}
		}
	}
	if (size == bs) {
		return true;
	}
	else {
		return false;
	}
}

void SetShipsRandomly(int** arr) {

}

void SetShips(int** arr, int row, int col, char d, int bs) {
	if (d == 'u') {
		for (size_t i = 0; i < bs; i++)
		{
			arr[row - i][col] = 1;
		}
	}
	else if (d == 'd') {
		for (size_t i = 0; i < bs; i++)
		{
			arr[row + i][col] = 1;
		}
	}
	else if (d == 'l') {
		for (size_t i = 0; i < bs; i++)
		{
			arr[row][col - i] = 1;
		}
	}
	else if (d == 'r') {
		for (size_t i = 0; i < bs; i++)
		{
			arr[row][col + i] = 1;
		}
	}
	else {
		cout << "OUPS.PLEASE ENTER CORRECT DIRECTION " << endl;
	}
}

void SetManually(int** arr) {
	int cX = 0;
	int cY = 0;
	while (true)
	{
        cout << "Place Submarine(5 placed ship) coordinates : " << endl;
        cin >> cX;
        cin >> cY;
        char d = ' ';
        cout << "Enter direction : " << endl;
        cin >> d;
		if (CheckSpace(arr, cX, cY, d, 5))
		{
			SetShips(arr, row, col, d, 5);
			PrintBoard(arr, row, col);
			cout << endl;
		}
		else {
			cout << "OVERLAP" << endl;
			}
		for (size_t i = 0; i < 2; i++)
		{
			cout << "Place Battleship(4 placed ship) coordinates : " << endl;
			cin >> cX;
			cin >> cY;
			char d = ' ';
			cout << "Enter direction : " << endl;
			cin >> d;
			if (CheckSpace(arr, cX, cY, d, 4))
			{
				SetShips(arr, row, col, d, 4);
			}
			else {
				cout << "OVERLAP" << endl;
			}
		}
		PrintBoard(arr, row, col);
		cout << endl;
		for (size_t i = 0; i < 3; i++)
		{
			cout << "Place Cruiser(3 placed ship) coordinates : " << endl;
			cin >> cX;
			cin >> cY;
			char d = ' ';
			cout << "Enter direction : " << endl;
			cin >> d;
			if (CheckSpace(arr, cX, cY, d, 3))
			{
				SetShips(arr, row, col, d, 3);
			}
			else {
				cout << "OVERLAP" << endl;
			}
		}
		PrintBoard(arr, row, col);
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			cout << "Place Destroyer(2 placed ship) coordinates : " << endl;
			cin >> cX;
			cin >> cY;
			char d = ' ';
			cout << "Enter direction : " << endl;
			cin >> d;
			if (CheckSpace(arr, cX, cY, d, 5))
			{
				SetShips(arr, row, col, d, 5);
			}
			else {
				cout << "OVERLAP" << endl;
			}

		}
		PrintBoard(arr, row, col);
		cout << endl;
		for (size_t i = 0; i < 5; i++)
		{
			cout << "Place Carrier(1 placed ship) coordinates : " << endl;
			cin >> cX;
			cin >> cY;
			char d = ' ';
			cout << "Enter direction : " << endl;
			cin >> d;
			if (CheckSpace(arr, cX, cY, d, 1))
			{
				SetShips(arr, row, col, d, 1);
			}
			else {
				cout << "OVERLAP" << endl;
			}
		}
	}
}



int NumberOfShips(int**arr)
{
	int c = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 1)
				c++;
		}
	}

	return c;
}

bool IsGameWon(int** arr)
{
	for (int row = 0; row < 10; row++)
		for (int col = 0; col < 10; col++)
			if (arr[row][col] = 1)
			{
				return true; 
			}


	return false;

}

void PlayerAttack(int**arr,int X,int Y) {
	if (arr[X][Y] == 1) {
		cout << "Ship fired" << endl;
		arr[X][Y] = 2;
	}
	else if (arr[X][Y] == 0) {
		cout << "Missed" << endl;
		arr[X][Y] = 9;
	}
	else {
		cout << "Wrong coordinates.You cannot fire missed or fired coordinates again" << endl;
	}
}

bool IsHit(int** arr,int X,int Y) {
	if (arr[X][Y] == 1) {
		return true;
	}
	return false;
}
	
void Start() {
	int** arr1 = ReserveArray(row, col);
	InitArray(arr1);
	int** arr2 = ReserveArray(row, col);
	InitArray(arr2);
	ShowMenu();
	while (true)
	{
	int select = 0;
	cout << "Select one of this selections : ";
	cin >> select;
		if (select == 1) {
			cout << "AUTO - 1" << endl;
			cout << "MANUAL - 2" << endl;
			int choice = 0;
			cout << "Enter choice : ";
			cin >> choice;
			system("cls");
			if (choice == 1) {
				/*SetShipsRandomly(arr1);
				cout << "**********YOU**********" << endl << endl;
				PrintBoard(arr1, row, col);
				cout << endl;
				cout << "SHIPS LEFT [" << NumberOfShips(arr1) << "]" << endl;
				SetShipsRandomly(arr2);
				cout << "*******COMPUTER*******" << endl << endl;
				PrintGameBoard(arr2, row, col);
				cout << endl;
				cout << "SHIPS LEFT [" << NumberOfShips(arr2) << "]" << endl;*/
			}
			else if (choice == 2) {
				PrintBoard(arr1, row, col);
				SetManually(arr1);
				PrintBoard(arr1, row, col);
				system("cls");
				cout << "**********YOU**********" << endl << endl;
				PrintBoard(arr1, row, col);
				cout << endl;
				cout << "SHIPS LEFT [" << NumberOfShips(arr1) << "]" << endl;
				SetShipsRandomly(arr2);
				cout << "*******COMPUTER*******" << endl << endl;
				PrintGameBoard(arr2, row, col);
				cout << endl;
				cout << "SHIPS LEFT [" << NumberOfShips(arr2) << "]" << endl;
				int X, Y = 0;
				while (IsGameWon)
				{
					cout << "Enter coordinates(X) : " << endl;
					cin >> X;
					cout << "Enter coordinates(Y) : " << endl;
					cin >> Y;
					PlayerAttack(arr2,X,Y);
					if (IsHit(arr1, X, Y)) {
						PlayerAttack(arr2, X, Y);
					}
					else {
						cout << "Now it is computer turn" << endl;
						int ranX = rand() % row;
						int ranY = rand() % col;
						PlayerAttack(arr1, ranX, ranY);
						if (IsHit(arr1, ranX, ranY)) {
							PlayerAttack(arr1, X, Y);
						}
						else {
							cout << "Now it is computer turn" << endl;

						}
						if (IsGameWon == 0) 
						{
							cout << "WE HAVE A WINNER";
						}
						}
				}
				
				}
			else {
				cout << "Wrong choice " << endl;

			}
			
		}
		else if (select == 2) {
			SetColor(9,0);
			cout << "Battleship is a war-themed board game for two players in which the opponents try to guess the location of their opponent's warships and sink them.";
			cout << "Each player receives a game board and five ships of varying lengths. Each ship has holes where the hit pegs are inserted and a supply of hit and miss markers.";
			cout << "The five ships are: " << endl;
			cout << "Carrier, which has five holes" << endl;
			cout << "Battleship, which has four holes" << endl;
			cout << "Cruiser, which has three holes" << endl;
			cout << "Submarine, which has two holes" << endl;
			cout << "Destroyer, which has one holes" << endl;
			cout << "The two players should be positioned so they face each other across a game table.";
			cout << "Their target grids back up to one another vertically so that neither player can see his opponent's ocean grid and ship locations.";
			cout << "Before the game starts, each opponent secretly places their own five ships on the ocean grid(lower part of the board) by laying out their shipsand anchoring them into the holes on the grid.";
			cout << "Each ship must be placed horizontally or vertically across grid spaces—not diagonally—and the ships can't hang off the grid. Ships can touch each other, but they can't occupy the same grid space.You cannot change the position of the ships after the game begins." << endl;
			SetColor(7, 0);
		}
		else if (select == 0) {
			cout << "SEE YOU LATER" << endl;
			break;
		}
		else {
			cout << "Wrong selection" << endl;
		}
	}
}

