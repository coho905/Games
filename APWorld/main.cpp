// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "iostream"
#include "unistd.h"
#include "termios.h"

using namespace std;
void NLevel();
void MoveH(int K, char playe);
void MoveV(int R, char playe);
void Life();
void CoinAdd();
void GlassAdd();
void PepperAdd();

void botVert(int x, int y);
char map[10][25] = {
	"__________________",
	"|@|        ^     |",
	"| |  #           |",
	"| |     ^        |", 
	"| |            # |",
	"|  !       ^     |",
	"|        *   #   |",
	"|  !    #        |",
	"|     !  #   #   |",
	"|_______________o  "

};
char map2[10][25] = {
	"________________",
	"|@|             |",
	"| | ##          |",
	"| | ##          |",
	"|   |   #       |",
	"|__|  | |---    |",
	"|          ^^   |",
	"| !!       ^^   |",
	"| !!   ^        |",
	"|______________o"
};
char map3[10][25] = {
	"________________",
	"|@|             |",
	"| |             |",
	"| |____________ |",
	"|              ||",
	"|------------  ||",
	"|       !!   | ||",
	"|  ^^           |",
	"|     ##        |",
	"|______________o"
};
char map4[10][25] = {
	"________________",
	"|@|      |      |",
	"| | ##   |      |",
	"| | ##   |      |",
	"| |   #  |      |",
	"|    |          |",
	"|____|    !  ^^ |",
	"| !!       ^^   |",
	"| !!   ^        |",
	"|______________o"
};
bool GameOn = true;
int x = 1;
int Level = 1;
int y = 1;
int lives = 3;
int coins = 0;
int glass = 0;
int pepper = 0;
int a = 9;//
#define key 1

int main()
{
  // Creating a termios term
  struct termios term;
  // Using tcgetattr
  tcgetattr(key, &term);
  term.c_lflag &= ~ICANON;
  // Setting key, TCSANOW, and term
  tcsetattr(key, TCSANOW, &term);
  // Asking For Character
	//
  char k;
  // Input
	while (GameOn) {
    system("clear");
    cout << "This simulates trade routes in the post-classical Venetian Republic.  Avoid walls and navigate the canals as you try to collect as much glass, salt, and pepper (the biggest commodities) along the way.  And avoid bandits that have the * icon.  As they will steal all of your supplies.  The level exit as at the o.  You have 3 lives, good luck!\n\n\n";
		cout << "Salt: ";
		for (int f = 1; f <= coins; f++) {
			cout << '#';
		}
		cout << " Glassware: ";
		for (int f = 1; f <= glass; f++) {
			cout << '^';
		}
		cout << " Pepper: ";
		for (int f = 1; f <= pepper; f++) {
			cout << '!';
		}
		cout << endl;
		for (int l = 0; l < 10; l++) {
			cout << map[l] << endl;
		}
		cout << "Lives: ";
		for (int k = 1; k <= lives; k++) {
			cout << 'L' << " ";
		}
    cout << endl;


		//system("pause");
    cin >> k;
		if (k == 65) 
    {
			MoveV(-1, 'P');

		}
		if (k == 66) 
    {
			MoveV(1, 'P');
		}
		if (k == 67) 
    {
			MoveH(1, 'P');
		}
		if (k == 68) 
    {
			MoveH(-1, 'P');
		}
		if (k == 69) {
			cout << "You lose";
			GameOn = false;
		}
		if (Level == 1) {
			// Bot 1 Just Back & Forth
			if (map[2][14] == '*') {

				if (map[2][14] == 'P') {
					Life();
					map[2][14] = '*';
				}
				map[2][14] = '*';
				map[3][14] = ' ';
			}
			else if (map[2][14] == '*') {

				if (map[3][14] == 'P') {
					Life();
					map[3][14] = '*';
				}
				map[3][14] = '*';
				map[2][14] = ' ';
			}
		}
		else if (Level == 2) {
			// Bot 2 Diagnol
			if (map[2][8] == '*') {
				if (map[3][7] == 'P') {
					Life();
					map[3][7] = '*';
				}
				map[3][7] = '*';
				map[2][8] = ' ';
			}
			else if (map[3][7] == '*') {
				//
				if (map[2][8] == 'P') {
					Life();
					map[2][8] = '*';
				}
				map[2][8] = '*';
				map[3][7] = ' ';
			}
		}
		else if (Level == 3) {
			// Bot 3 Slide and Jump Back
			map[8][a] = ' ';
			a++;
			if (a == 14) {
				a = 9;
			}
			map[8][a] = '*';


		}
		else if (Level == 4) {
			// Bot 1 Just Back & Forth
			if (map[5][14] == '*') {

				if (map[5][11] == 'P') {
					Life();
					map[5][11] = '*';
				}
				map[5][11] = '*';
				map[6][11] = ' ';
			}
			else if (map[5][11] == '*') {

				if (map[6][11] == 'P') {
					Life();
					map[6][11] = '*';
				}
				map[6][11] = '*';
				map[5][11] = ' ';
			}
		}

}
	
	//system("pause");

}

void MoveV(int K, char playe) {
	int newY = y + K;
	if (map[newY][x] == ' ') {
		map[y][x] = ' ';
		y += K;
		map[y][x] = playe;
	}
	else if (map[newY][x] == 'o') {
		system("clear");
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
	else if (map[newY][x] == '!') {
		PepperAdd();
		map[y][x] = ' ';
		y += K;
		map[y][x] = playe;
	}
	else if (map[newY][x] == '^') {
		GlassAdd();
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
		system("clear");
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
	else if (map[y][newX] == '!') {
		PepperAdd();
		map[y][x] = ' ';
		x += R;
		map[y][x] = playe;
	}
	else if (map[y][newX] == '^') {
		GlassAdd();
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
  else if (Level == 4) {
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 25; b++) {
				map[a][b] = map4[a][b];
			}
		}
	}
	else {
    cout << "Mission Complete, You Win";
		GameOn = false;
	}
	map[1][1] = '@';
}

void Life() {
	lives--;
	if (lives == 0) {
		system("clear");
		cout << "You Lose\n";
		GameOn = false;
	}
	else {
		map[y][x] = ' ';
		x = 1;
		y = 1;
		map[y][x] = 'P';
    pepper=0;
    glass=0;
    coins=0;
	}
}

void CoinAdd() {
	coins++;
}

void GlassAdd() {
	glass++;
}

void PepperAdd() {
	pepper++;
}
