#include <iostream>
#include <fstream>
#include"Header.h"
#include<time.h>    //rand seed
#include<Windows.h>
#include<conio.h> // getch use nai kerna werna time ni chalna :(
#include<cstdlib> //for rand :3


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
void menu(int option)
{
	cout << "***********WELCOME***********";
	cout << "\n Instruction:" << endl;
	cout << "A game by GROUP 20 \n";
	cout << " \n1. PLAY\n2. HOW TO PLAY \n\n";
	cin >> option;
	if (option == 1)
		system("cls");
	else if (option == 2)
	{
		cout << "move the white rectangle on the desired gem...& to swap press spacebar....Happy GEM CRUSHING :)";
		_getch();
		system("cls");
	}
}
void PrintBoard()
{
	for (int i = 0, s = 0; i < 8; i++, s = s + 50) //outer loop runs 8 times and adds news boxes row by row to the 1x8 column in inner loop
		for (int ele = 50; ele < 401; ele = ele + 50)//inner loop runs eight times till 400 to print a column of 8 boxes
			myRect(50 + s, ele, 100 + s, 50 + ele, 255, 0, 0, 0, 0, 0);
}

void addRandomElementsToArray(int arr[8][8])   //assinging random nums in a 2d array "arr"
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = (rand() % 5) + 1;  //1 2 3 4 5
		}
	}
}
//the following function removes consecutive elements in rows

void removeconsecx(int arr[8][8]){
	for (int i = 0; i <= 7; i++) //rows main remove kerta
	{
		for (int j = 0; j <= 6; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2])
			{

				// arr[i][j + 2] = (rand() % 3) + 1;
				arr[i][j] = (rand() % 5) + 1; //0 1 2 3 4 ////arr[i][j + 2] = (rand() % 3)+1; //chances of phir say wohi anay k //1,2,3
				arr[i][j + 1] = (rand() % 5) + 1;
				arr[i][j + 2] = (rand() % 5) + 1;
			}
		}
	}
}

//the following function removes consecutive elements in columns
void removeconsecy(int arr[8][8])
{
	for (int j = 0; j <= 6; j++)
	{
		for (int i = 0; i <= 6; i++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j])
			{
				arr[i][j] = (rand() % 5) + 1; //0 1 2 3 4 ////arr[i][j + 2] = (rand() % 3)+1; //chances of phir say wohi anay k //1,2,3
				arr[i + 1][j] = (rand() % 5) + 1;
				arr[i + 2][j] = (rand() % 5) + 1;
			}
		}
	}
}

bool CheckConsec(int arr[][8], int &a, int &b) {
		for (int i = 0; i < 8; i++) //rows main remove kerta
		{
			for (int j = 0; j < 8; j++){
				if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2]){
					a = i;
					b = j;
					return true;
				}
				else if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j]) {
					a = i;
					b = j;
					return true;
				}
			}
		}
		return false;
	}
	bool RemoveConsecX(int arr[][8],int &i,int &j){
		//for (int i = 0; i < 8; i++) //rows main remove kerta
		//{
		//	for (int j = 0; j < 8; j++)
		//	{
		if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2])
		{
			arr[i][j] = (rand() % 5+1);
			arr[i][j + 1] = (rand() % 5+1);
			arr[i][j + 2] = (rand() % 5+1);
			return true;
		}
		return false;
	}
	bool RemoveConsecY(int arr[][8], int &i, int &j){
		//for (int j = 0; j < 8; j++)
		//	for (int i = 0; i < 8; i++)
		if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j])
		{
			arr[i][j] = (rand() % 5+1);
			arr[i + 1][j] = (rand() % 5+1);
			arr[i + 2][j] = (rand() % 5+1);
			return true;
		}
		return false;
	}

void checkboardforblank(int arr[][8], int R)			// slides any blank positions
{

	for (int i = R - 1; i >= 0; i--)
		for (int j = R - 1; j >= 0; j--)
		{
			if (arr[i][j] == 0)
			{
				int x = i - 1;
				while (x >= 0 && arr[x][j] == 0)
					x = x - 1;
				if (x >= 0)
					swap(arr[x][j], arr[i][j]);

			}
		}
}

//the following fuction assings gems to numbers from 0 to 4
void gems(int g, int x1, int y1, int x2, int y2)
{
	if (g == 1)
	{
		myEllipse(x1, y1, x2, y2 , 0, 0, 0, 255, 255, 255);// White Circle
	}
	if (g == 2)
	{
		myRect(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);//purple RECT
	}
	if (g == 3)
	{
		myRect(x1, y1, x2, y2, 0, 0, 255, 0, 0, 255); // rect
	}
	if (g == 4)
	{
		myEllipse(x1, y1, x2, y2, 0, 255, 0, 0, 255, 0); //PURPLE  triANGLE
	}
	if (g == 5)
	{
		triangle(x1, y1, x2, y2, 0, 255, 255, 0, 0, 0); //Light blue triANGLE
	}
	if (g == 6)
		;
	if (g == 7)
		;
}

void PrintGems(int arr[][8], int x, int y) //the following function  prints gems in boxes and by  calling the above the function "gems"
{
	for (int a = 0; a < 8; a++, y = y + 50)
	{
		x = 55;
		for (int b = 0; b < 8; b++, x = x + 50)
		{
			gems(arr[a][b], x, y, x + 40, y + 40);
		}
	}
}

void printthetext(int arr[][8], int q, int d)
{
	for (int i = 0; i < 8; i++, d = d + 1)
	{
		int q = 35 + 35;
		for (int j = 0; j < 8; j++, q = q + 3)
		{
			gotoxy(q, d);
			cout << arr[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
void gamegraphics(int Xcoordinate, int Ycoordinate)
{
	SetConsoleTextAttribute(hConsole, 11);
	gotoxy(30, 1);
	//gotoxy(Xcoordinate, Ycoordinate);
	cout << "CANDY CRUSH SAGA";

}

void cursor(int x, int  y, int R, int G, int B) //this function is the cursour on screen
												//X=50,Y=50
{
	myLine(x, y, x + 50, y, R, G, B);//top
	myLine(x, y, x, y + 50, R, G, B); //left
	myLine(x, y + 50, x + 50, y + 50, R, G, B);//bottom
	myLine(x + 50, y, x + 50, y + 50, R, G, B);//right
}
int fillfivesix(int arr[][8], int &score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 0 || arr[i][j] == 0)
			{
				arr[i][j] = -1;    //rand() % 5;  //0 1 2 3 4
				score = score + 10;
			}

		}
	}
	return score;
}
void checkboardforMinusONE(int arr[][8], int R)			// slides any blank positions
{

	for (int i = R - 1; i >= 0; i--)
		for (int j = R - 1; j >= 0; j--)
		{
			if (arr[i][j] == -1)
			{
				int x = i - 1;
				while (x >= 0 && arr[x][j] == -1)
					x = x - 1;
				if (x >= 0)
					swap(arr[x][j], arr[i][j]);

			}
		}
}
int main(){
	int option = 0, runGame = 0, score = 0, q = 5, d = 5, x = 50, y = 50, i = 0, j = 0, flag = 0;

	menu(option);
	gotoxy(0, 0);
	
	int R = 8;
	int arr[8][8];
	//cout << "PRESS Q TO TERMINATE ";
	//cout << "Score";
	srand((int)time(0));
	PrintBoard();		//prints a  8x8 box board
	PrintGems(arr, 55, 55); //this function reads the 2d array and places gems on screen within each sub box
	addRandomElementsToArray(arr); //this function initializes the array arr[8][8] with random elements ranging from 0 to 4
	removeconsecx(arr);// this function removes row wise pairs
	removeconsecy(arr); //this function removes column wise pairs

	
	printthetext(arr, q, d); //for the ease of the programming team the 2d array is being printed
	gamegraphics(80, 20); //SHOWCASING """USER FRIENDLYNESS"""
	
	char c;
	cursor(x, y, 255, 255, 255); //white
	int a = 0, b = 0, T = 300;
	int f = 1, ScoreFlag = 0;
	while (T > 60)
	{
		myRect(60, 480, T, 460, 0, 0, 0, 0, 0, 0); //Time-Bar
		T = T - 2;
		if (f == 1) {
			SetConsoleTextAttribute(hConsole, 67);
			gotoxy(0, 29);
			cout << "TIME";
			gotoxy(0, 32);
			cout << "SCORE\t" << score;
		}
		myRect(60, 480, T, 460, 255, 0, 0, 255, 255,0); //Time-Bar
		while (CheckConsec(arr, a, b) == true) {
						RemoveConsecX(arr, a, b);
						RemoveConsecY(arr, a, b);
						PrintBoard();
						PrintGems(arr,55,55);
		}
		c = _getch();
		cursor(x, y, 255, 0, 0);
		if (c == -32)
		{
			c = _getch();
			if (c == 'H')//up
			{
				y = y - 50; i--;
			}
			if (c == 'K')//left
			{
				x = x - 50; j--;
			}
			if (c == 'M')//right`
			{
				x = x + 50; j++;
			}
			if (c == 'P')//down
			{
				y = y + 50; i++;
			}
		}
		cursor(x, y, 255, 255, 255);
		if (c == 32)
		{
			c = _getch();
			if (c == -32) //enter space to swap..... it is imporatant to note that swaping is not occuring outofbound :)
			{
				c = _getch();
				if (c == 'H')//up    //perfect
				{
					swap(arr[i][j], arr[i - 1][j]);
					ScoreFlag = 1;
				}
				if (c == 'K')        //left
				{
					swap(arr[i][j], arr[i][j - 1]);
					ScoreFlag = 1;
				}
				if (c == 'M')//right`
				{
					swap(arr[i][j], arr[i][j + 1]);
					ScoreFlag = 1;
				}
				if (c == 'P')//down   
				{
					swap(arr[i][j], arr[i + 1][j]);
					ScoreFlag = 1;
				}
				//myRect(60, 480, T, 460, 255, 0, 0, 0, 0, 0); //Time-Bar
				//T = T - 2;
				//myRect(60, 480, T, 460, 255, 0, 255, 255, 0, 255); //Time-Bar

				if (ScoreFlag == 1) {
					score += 3;
					
					ScoreFlag = 0;
				
					//system("cls");
				}
			}
		}
		fillfivesix(arr, score);
		checkboardforMinusONE(arr, R);
		PrintBoard();
		PrintGems(arr, 55, 55);
		cursor(x, y, 255, 255, 255);//white cursour
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) //horizontal &&i>=0 && i<=7
				{

					arr[i][j] = 5; arr[i][j + 1] = 5; arr[i][j + 2] = 5;
				}
				if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) //vertical 
				{
					arr[i][j] = 6; arr[i + 1][j] = 6; arr[i + 2][j] = 6;
				}
			}
			
		}
	}
	system("cls");
	cout << "TIME UP\n";
	_getch();
}