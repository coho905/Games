// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
#include "windows.h"

using namespace std;
void NLevel();
void MoveH(int K, char playe);
void MoveV(int R, char playe);
void Life();
void CoinAdd();
void botVert(int x, int y);
char map[10][25] = {
	"ABCDEFGHIJKL",
	"M@    #  NOP",
	"Q         W",
	"X    *   Y",
	"Z        A",
	"PAT   #   TT",
	"ER  #     R",
	"IS       *   D",
	"ELOP      o",
	"AHAHAHAHAHdf"

};
char map2[10][25] = {
	"ABCDEFGHIJKL",
	"M@       NOP",
	"Q   #   W",
	"X  *    sfdgY",
	"Z    dg A",
	"PAT adf #TT",
	"ER   df  R",
	"IS   vf    D",
	"ELOP #f  #  o",
	"AHAHAHAHAHghjg"
};
char map3[10][25] = {
	"ABCDEFGHIJKLMN",
	"M@ *         P",
	"Q           W",
	"X  sfg      Y",
	"Z   #   adafa",
	"PAT        TT",
	"ER     ff   #R",
	"IS      #  asdD",
	"ELOP#  df  o",
	"AHAHAHAHAHsf"
};
bool GameOn = true;
int x = 1;
int Level = 1;
int y = 1;
int lives = 3;
int coins = 0;
int a = 3;
int main()
{

	cout << "Get to the exit quickly\n";
	while (GameOn) {
		system("cls");
		cout << "Coins: ";
		for (int f = 1; f <= coins; f++) {
			cout << '#';
		}
		cout << endl;
		for (int l = 0; l < 10; l++) {
			cout << map[l] << endl;
		}
		cout << "Lives: ";
		for (int k = 1; k <= lives; k++) {
			cout << char(3);
		}
		
		system("pause>nul");
		if (GetAsyncKeyState(VK_UP)) {
			MoveV(-1, char(2));
			
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			MoveV(1, char(2));
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			MoveH(1, char(2));
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			MoveH(-1, char(2));
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			cout << "You lose";
			GameOn = false;
		}
		if (Level == 1) {
			// Bot 1 Just Back & Forth
			if (map[7][9] == '*') {

				if (map[6][9] == char(2)) {
					Life();
					map[6][9] = '*';
				}
				map[6][9] = '*';
				map[7][9] = ' ';
			}
			else if (map[6][9] == '*') {

				if (map[7][9] == char(2)) {
					Life();
					map[7][9] = '*';
				}
				map[7][9] = '*';
				map[6][9] = ' ';
			}
			// Bot 1 (Continued) Just Back & Forth
			if (map[3][5] == '*') {

				if (map[3][4] == char(2)) {
					Life();
					map[3][4] = '*';
				}
				map[3][4] = '*';
				map[3][5] = ' ';
			}
			else if (map[3][4] == '*') {

				if (map[3][5] == char(2)) {
					Life();
					map[3][5] = '*';
				}
				map[3][5] = '*';
				map[3][4] = ' ';
			}

		}
		else if (Level == 2) {
			// Bot 2 Diagnol
			if (map[3][3] == '*') {
				if (map[4][4] == char(2)) {
					Life();
					map[4][4] = '*';
				}
				map[4][4] = '*';
				map[3][3] = ' ';
			}
			else if (map[4][4] == '*') {

				if (map[3][3] == char(2)) {
					Life();
					map[3][3] = '*';
				}
				map[3][3] = '*';
				map[4][4] = ' ';
			}
		}
			else if (Level == 3) {
				// Bot 3 Slide and Jump Back
				map[1][a] = ' ';
				a++;
				if (a == 7) {
					a = 3;
				}
				map[1][a] = '*';


		}

		
		
	}
	system("pause>nul");

}

void MoveV(int K, char playe){
	int newY = y + K;
	if (map[newY][x] == ' ') {
		map[y][x] = ' ';
		y += K;
		map[y][x] = playe;
	}
	else if (map[newY][x] == 'o') {
		system("cls");
		NLevel();
	}
	else if (map[newY][x] == '*' || map[y][x] == '*') {
		Life();
	}
	else if (map[newY][x] == '#') {
		CoinAdd();
		map[y][x] = ' ';
		y += K;
		map[y][x] = playe;
	}
	else {
		Life();
	}

}

void MoveH(int R, char playe) {
	int newX = x + R;
	if (map[y][newX] == ' ') {
		map[y][x] = ' ';
		x += R;
		map[y][x] = playe;
	}
	else if (map[y][newX] == 'o') {
		system("cls");
		NLevel();
	}
	else if (map[y][newX] == '*' || map[y][x] == '*') {
		Life();
	}
	else if (map[y][newX] == '#') {
		CoinAdd();
		map[y][x] = ' ';
		x += R;
		map[y][x] = playe;
	}
	else {
		Life();
	}

}
void NLevel() {
	x = 1;
	y = 1;
	Level++;
	if (Level == 2) {
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 25; b++) {
				map[a][b] = map2[a][b];
			}
		}
	}
	else if (Level == 3) {
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 25; b++) {
				map[a][b] = map3[a][b];
			}
		}
	}
	else {
		cout << "Mission Complete, You Win";
		GameOn = false;
	}
	map[1][1] = char(2);
}

void Life() {
	lives--;
	if (lives == 0) {
		system("cls");
		cout << "You Lose\n";
		GameOn = false;
	}
	else {
		map[y][x] = ' ';
		x = 1;
		y = 1;
		map[y][x] = char(2);
	}
}

void CoinAdd() {
	coins++;
	if (coins == 5) {
		lives++;
		coins = 0;
	}
}
