#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Sudoku.cpp"

using namespace std;

int main()
{
Sudoku sd;
// Input csv file containing sudoku
ifstream filen("sudoku.csv");
string s;
if(!filen.is_open()){
	cout << "Error opening file";
	} 
else{
	while(!filen.eof()){
		getline(filen,s);
		sd.MakeSudoku(s);
		} 
   	}
filen.close();
sd.PrintSudoku();
cout<<"Solving.....\n";
if(!sd.Solver()) {cout<<"This Sudoku does not have a solution\n"; }
else{ sd.PrintSudoku();}
return 0;
}
