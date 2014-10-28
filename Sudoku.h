#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
class Sudoku{
vector<int> cells;
vector< vector<int> > trying;
vector<int> sol;
int solved;
int iter;
int row_ptr;
void PrivatePrintSudoku(vector<int>& x);
public:
Sudoku(); // Constructor
void MakeSudoku(string s); // Method which decides which row is being read
void Readline(string s,int i); // To read the sudoku
void PrintSudoku(); // General print function
bool Solver(); // The method for solving the sudoku
bool IsRight(int,int); // To check whether the sudoku is a valid one
void Possibility(); // To calculate the possibile values in each empty cell
bool Solve(int x,int y); // Solving the sudoku
bool next(int x, int y); // For checking in every grid position
};
