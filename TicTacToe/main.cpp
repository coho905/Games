#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct spot{
  bool taken;
  char marker;
  int location;
};

void PrintBoard(spot t[3][3]);

void NewGame(spot s[3][3]);

void computer(spot s[3][3]);

char CheckWinner(spot check[3][3]);

int generated(spot s[3][3]);

void computerplay(spot s[3][3]);


int main() {

  srand(time(0));
  int end = 9;
  spot thisboard[3][3];
  NewGame(thisboard);
  PrintBoard(thisboard);
  char check;
  char winner = 'k';
  for(int big = 0; big < 9; big++){

  if(big % 2 == 0){
    //system("pause");
    computerplay(thisboard);
    
  }
  else{
  cout << "\n\nComputer is X's, You are O's\nWhere would you like to go?\t";
  int play;
  cin >> play;  
  
  for(int x = 0; x <3; x++){
   for(int y = 0; y <3; y++){
      if(play == thisboard[x][y].location){
        if(thisboard[x][y].taken == false){
          
            thisboard[x][y].marker = 'O';
            thisboard[x][y].taken = true;
          
        }
        else{
          cout << "Go Again";
          big--;
          end++;
        }
      }
    }
  }
  }
  system("clear");
  PrintBoard(thisboard);
  check = CheckWinner(thisboard);
  if(check != '$'){
    cout << check << " Wins!\n";
    winner = check;
    break;
  }
  else{
    continue;
  }
  }
    if(winner == 'k'){
      cout << "It's a draw\n";
    }
  }

void PrintBoard(spot t[3][3]){
    
    cout << "\n\n  " << t[0][0].marker << "  |  " << t[0][1].marker << "  |  " << t[0][2].marker << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << t[1][0].marker << "  |  " << t[1][1].marker << "  |  " << t[1][2].marker << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << t[2][0].marker << "  |  " << t[2][1].marker << "  |  " << t[2][2].marker << endl;

}

void NewGame(spot s[3][3]){
  int loc = 1;
  for(int x = 0; x<3; x++){
      for(int h = 0; h<3; h++){
        s[x][h].taken = false;
        s[x][h].location = loc;
       s[x][h].marker = char(48+loc); //'0' + s[x][h].location; Also work as it converts an int to a char
       loc++;
    }
  }
}

char CheckWinner(spot check[3][3]){
  for(int x = 0; x < 3; x++){
    if(check[x][0].marker == check[x][1].marker && check[x][1].marker == check[x][2].marker){
      return check[x][0].marker;
    }
    if(check[0][x].marker == check[1][x].marker && check[1][x].marker == check[2][x].marker){
      return check[0][x].marker;
    }
  }
  if(check[0][0].marker == check[1][1].marker && check[1][1].marker == check[2][2].marker){
    return check[0][0].marker;
  }
  if(check[0][2].marker == check[1][1].marker && check[1][1].marker == check[2][0].marker){
    return check[0][2].marker;
  }
    
    return '$';
}

void computer(spot s[3][3]){
  bool foundaspot = false;
  while(foundaspot != true){
  int spot = (rand() % 9 + 1) ;
  for(int x = 0; x <3; x++){
   for(int y = 0; y <3; y++){
      if(spot == s[x][y].location){
         if(s[x][y].taken == false){
            s[x][y].marker = 'X';
            s[x][y].taken = true;
            foundaspot = true;
           }
        }
        }
      }
    }
}

int generated(spot s[3][3]){
    for(int x = 0; x <3; x++){
      if(s[x][0].marker == s[x][1].marker){
        if(s[x][2].taken == false){
          return s[x][2].location;
          }
          else{
            continue;
          }
      }
      else if(s[x][1].marker == s[x][2].marker){
        if(s[x][0].taken == false){
          return s[x][0].location;
          }
          else{
            continue;
          }
      }
      else if(s[x][0].marker == s[x][2].marker){
        if(s[x][1].taken == false){
          return s[x][1].location;
          }
          else{
            continue;
          }      }
      else if(s[0][x].marker == s[1][x].marker){
         if(s[2][x].taken == false){
           return s[2][x].location;
          }
          else{
            continue;
          }
      }
      else if(s[1][x].marker == s[2][x].marker){
       if(s[0][x].taken == false){
          return s[0][x].location;
          }
          else{
            continue;
          }
      }
      else if(s[0][x].marker == s[2][x].marker){
        if(s[1][x].taken == false){
          return s[1][x].location;
          }
          else{
            continue;
          }
      }
      }
      if(s[0][0].marker == s[1][1].marker){
        if(s[2][2].taken == false){
          return s[2][2].location;
          }
      }
      else if(s[1][1].marker == s[2][2].marker){
        if(s[0][0].taken == false){
            return s[0][0].location;          
            }
          }
      else if(s[0][0].marker == s[2][2].marker){       
         if(s[1][1].taken == false){
            return s[1][1].location;          
            }
      }
      else if(s[0][2].marker == s[1][1].marker){
       if(s[2][0].taken == false){
            return s[2][0].location;          
            }
      }
      else if(s[1][1].marker == s[2][0].marker){
        if(s[0][2].taken == false){
            return s[0][2].location;          
            }
      }
      else if(s[0][2].marker == s[2][0].marker){
            if(s[0][2].taken == false){
            return s[0][2].location;          
            }      
            }
    
    return 50;
}

void computerplay(spot s[3][3]){

  int whattodo = generated(s);
  bool found = false;
  int nine = 0;
    if(whattodo != 50){
      for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
          if(s[x][y].location == whattodo){
            if(s[x][y].taken == false){
              s[x][y].marker = 'X';
              s[x][y].taken = true;
              found = true;
            }
          }
        }
      }
    }
    
  if(found == false){
    computer(s);
  }

}
