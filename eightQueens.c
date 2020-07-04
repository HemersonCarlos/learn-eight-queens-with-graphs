#include <stdbool.h>
#include <stdio.h>
#define N 8

void printSolution(int board[N][N]) {
    for(int row = 0; row < N; row++) {
        for(int column = 0; column < N; column++) {
            printf(" %d ", board[row][column]);
        }
        printf("\n"); 
    }
}

bool isSafe(int board[N][N], int row, int column) {
    int counterOne, counterTwo;
  
    for(counterOne = 0; counterOne < column; counterOne++)
        if(board[row][counterOne]) {
            return false;
        }

    for(counterOne = row, counterTwo = column; counterOne >= 0 && counterTwo >= 0; counterOne--, counterTwo--) 
        if(board[counterOne][counterTwo]) {
            return false;
        }

    for(counterOne = row, counterTwo = column; counterTwo >= 0 && counterOne < N; counterOne++, counterTwo--) 
        if(board[counterOne][counterTwo]) {
            return false;
        }
    return true;
}

bool solveProblemEightQueens(int board[N][N], int column) {
    if(column >= N) {
        return true;
    }

    for(int counter = 0; counter < N; counter++) {
        if(isSafe(board, counter, column)) {
            board[counter][column] = 1;
            if(solveProblemEightQueens(board, column + 1)) {
                return true;
            }
            board[counter][column] = 0;
        }
    }
    return false;
}

bool solveEightQueens() {
    int board[N][N] = { 
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }	  
    };
  
    if(solveProblemEightQueens(board, 0) == false) {
        printf("Solution does not exist!");
        return false; 
    }
    printSolution(board); 
    return true; 
} 

int main() {
    solveEightQueens();
    return 0;
}
