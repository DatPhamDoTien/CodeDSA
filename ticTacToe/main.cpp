#include <iostream>
#include <string>

using namespace std;
class Player {
private:
  char symbol;
  string name;

public:
  // Contructor
  Player(char sym = 'X', string n = "Player X") : symbol(sym), name(n) {}
  char getSymbol() const { return symbol; }
  string getName() const { return name; }
};

class Board {
private:
  char grid[3][3];
  int filledCell;

public:
  // Contructor
  Board() : filledCell(0) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
        grid[i][j] = ' ';
    }
  }
  // Method to display board.
  void drawBoard() const {
    cout << "--------------------" << endl;
    for (int i = 0; i < 3; i++) {
      cout << "| ";
      for (int j = 0; j < 3; j++)
        cout << grid[i][j] << " | ";
      cout << endl << "-------------------" << endl;
    }
  }

  // Method to check if a move is valid
  bool isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 &&
            grid[row][col] == ' ');
  }
  // Method to make a move

  void makeMove(int row, int col, char symbol) {
    if (grid[row][col] == ' ') {
      grid[row][col] = symbol;
      filledCell++;
    }
  }

  // Method to check for a win
  bool checkWin(char symbol) const {
    // check row
    for (int i = 0; i < 3; i++) {
      if (grid[i][0] == symbol && grid[i][1] == symbol &&
          grid[i][2] == symbol) {
        return true;
      }
    }
    // check col
    for (int i = 0; i < 3; i++) {
      if (grid[0][i] == symbol && grid[1][i] == symbol &&
          grid[2][i] == symbol) {
        return true;
      }
    }
    // check diagonals.
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
      return true;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
      return true;
    }
    return false;
  }
  
  
};

int main() { return 0; }
