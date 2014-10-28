#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Sudoku.h"

using namespace std;

// Constructor
Sudoku::Sudoku():trying(81,vector<int>(10)){
solved=0;
row_ptr=0;
iter=0;
}

void Sudoku::Readline(string s,int i) {

int comma_pos,start=0;
string temp_x_str;
char temp,*temp_x;
	
for(int k=0;k<9;k++){
     comma_pos=s.find(',',start);
     if(comma_pos==start){
	temp=' ';		
	} 
     else {
	temp_x_str=s.substr(start,comma_pos);
	temp_x=const_cast<char*>(temp_x_str.c_str());
	temp=temp_x[0];
	}
     start=comma_pos+1;

     if ((temp!=' ')&&(temp!='\0')) {
	cells.push_back((temp-'0')); // To convert into integers otherwise ascii
     } else {
	cells.push_back(0);
     }
}

}

void Sudoku::MakeSudoku(string s){
	if(row_ptr<9){
		Readline(s,row_ptr++);
	} else {
		row_ptr=0;
	}
}

void Sudoku::PrivatePrintSudoku(vector<int>& x) {
for(int i= 0 ; i<81; i++){
        cout<<x[i];
	if(((i+1)%3==0)&&(i!=0)) cout<<"|";
	if(((i+1)%9==0)&&(i!=0)) cout<<"\n";
	if(((i+1)%27==0)&&(i!=0)) cout<<"---+---+----\n";
	}
}

void Sudoku::PrintSudoku(){
if(solved==0){
PrivatePrintSudoku(cells);}
else {PrivatePrintSudoku(sol);}
}

bool Sudoku::IsRight(int pos,int val){
int x,y;
// For checking in every row and column
x=pos/9;
y=pos%9;
for(int i=0;i<9;i++){
	if(val == sol[x*9+i] || val == sol[9*i+y]){
	return false;	
	}
}
// For checking in every 3x3 box
x=(pos/27)*3;
y=((pos%9)/3)*3;
for(int i=x;i<=x+2;i++){
	for(int j=y;j<=y+2;j++){
 		if(sol[9*i+j]==val){
 		return false;
 		}
	}
}
return true;
}

void Sudoku::Possibility(){
int count;
// Initializing the vector of vectors
	for(int i=0;i<81;i++)
		{
		for(int j=0;j<9;j++)
		{
			trying[i][j]=0;
		}	
	}
	// List of possibilities
	for(int i=0;i<81;i++){
	   if(cells[i]==0){
		count=0;
		for(int j=1;j<=9;j++){
		    if(IsRight(i,j)){
			trying[i][count]=j;
			count++;
		     }			
		}
		trying[i][9]=count;
            }
	}
}



bool Sudoku::Solver(){
	sol=cells;
	Possibility();
	solved=Solve(0,0); // To start with the first position in grid
 	return solved;
}

bool Sudoku::Solve(int x,int y){
int pos=9*x+y;
int max,val;
	if(cells[pos]==0)
	{
		max=trying[pos][9];
		for(int i=0;i<max;i++){
			val=trying[pos][i];
			if(IsRight(pos,val)){
				sol[pos]=val;	
				if(next(x,y)) 
				return true;		
			}		
		}
		iter++;
		sol[pos]=0; // Incase the sudoku is insolvable
		return false;
	}
	return next(x,y);
}

bool Sudoku::next(int x, int y) 
{
    if (x == 8 && y == 8) return true;
    else if (x == 8) return Solve(0, y + 1);
    else return Solve(x + 1, y);
}
