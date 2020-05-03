#include <iostream>
#include "cstring"

using namespace std;

#define N 8

bool isSafe(char mat[][N], int r, int c)
{
    // return false if two queens share the same column
    for (int i = 0; i < r; i++) if (mat[i][c] == 'Q')   return false;

    // return false if two queens share the same \ diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)  if (mat[i][j] == 'Q')   return false;

    // return false if two queens share the same / diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)   if (mat[i][j] == 'Q')   return false;

    return true;
}
void nQueen(char mat[N][N],int row_No){
    if(row_No == N){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) cout <<mat[i][j] <<" ";
            cout<<endl;
        }
        cout <<endl;
        return;
    }
    for (int column = 0; column < N; ++column) {
        if(isSafe(mat, row_No, column)){
            mat[row_No][column] = 'Q';
            nQueen(mat,row_No + 1);
            mat[row_No][column] = '-';
        }
    }
}

int main(){
    char mat[N][N];
    memset(mat,'-',sizeof mat);

    nQueen(mat,0);
    return 0;
}
