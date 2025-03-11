#include <iostream>
#include <string>
#include <vector>
using namespace std;

// N Queen 2 nd variation of questions --- > //* count of all solution exist.   

void printBoard(vector<vector<char>> board)
{
     int n = board.size();
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << board[i][j] << " ";
          }
          cout << endl;
     }

     cout << "------------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col)

{
     int n = board.size();

     // horizontal
     for (int j = 0; j < n; j++)
     {
          if (board[row][j] == 'Q')
          {
               return false;
          }
     }

     // vertical

     for (int i = 0; i < row; i++)
     {
          if (board[i][col] == 'Q')
          {
               return false;
          }
     }

     // diagonal left

     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
     {
          if (board[i][j] == 'Q')
          {
               return false;
          }
     }

     // diagonal right

     for (int i = row, j = col; i >= 0 && j < n; i--, j++)
     {
          if (board[i][j] == 'Q')
          {
               return false;
          }
     }

     return true;
}

int nQueens(vector<vector<char>> &board, int row)
{

     int n = board.size();

     if (row == n)
     {
          printBoard(board);
          return 1;
     }

     int count = 0;

     for (int j = 0; j < n; j++) // cols
     {
          if (isSafe(board, row, j))
          {
               board[row][j] = 'Q';
               count += nQueens(board, row + 1);
               board[row][j] = '.';
          }
     }
     return count; // no of possible solution in each level.
}

int main()
{

     vector<vector<char>> board;

     int n = 4;
     for (int i = 0; i < n; i++)
     {
          vector<char> newRow;
          for (int j = 0; j < n; j++)
          {
               newRow.push_back('.');
          }
          board.push_back(newRow);
     }

     int count = nQueens(board, 0);
     cout << "count :" << count << endl;

     return 0;
}

// time complexity --- O(n!)
// space complexity --- O(n*n)