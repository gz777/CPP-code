//BCS120 Demo code
//10/21/19
//two-dimensional array
//this code is on Windows OS only (not cross-platform compatible)
//chessboard setup 8 by 8
//Pawn, Knight, Bishop, Rook, Queen, King
//Rows on the board are called ranks and are numbered 1 to 8, and columns are called files and denoted with letters, a through h
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std; 
  
 
  
int main() 
{ 
   string pieces[6] = {"pawn", "knight", "bishop", "rook", "queen", "king"}; 
   
   string checkboard[8][8] = {{pieces[3],pieces[1],pieces[2],pieces[4],pieces[5],pieces[2],pieces[1],pieces[3]},
                              {pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0]},
                              {" "," "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "," "},
                              {" "," "," "," "," "," "," "," "},
                              {pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0],pieces[0]},
                              {pieces[3],pieces[1],pieces[2],pieces[5],pieces[4],pieces[2],pieces[1],pieces[3]}
                            };
   
   for(int i=0;i<8;i++) {
       for(int j=0;j<8;j++){
           cout << "|" <<setw(7) <<right << checkboard[i][j];
       }
       cout  << "|\n";
   }
   
   
    return 0; 
} 

