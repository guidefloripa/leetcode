/*

Author: Guilherme Steinmann
Date: 2018-03-30

On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves.
The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below.
Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random
(even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard.
Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Note:
- N will be between 1 and 25.
- K will be between 0 and 100.
- The knight always initially starts on the board.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double knightProbability(int N, int K, int r, int c) {
    
    double arr[N][N];
    double arr2[N][N];
    
    memset(arr, 0, sizeof(arr));
    arr[r][c] = 1.0;
    
    for (int k=0; k<K; k++) {
        memset(arr2, 0, sizeof(arr2));
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (arr[i][j] > 0.0) {
                    double prob = arr[i][j]/8.0;
                    
                    if (i-2 >= 0) {
                        if (j-1 >= 0)
                            arr2[i-2][j-1] += prob;
                        if (j+1 < N)
                            arr2[i-2][j+1] += prob;
                    }
                    if (i-1 >= 0) {
                        if (j-2 >= 0)
                            arr2[i-1][j-2] += prob;
                        if (j+2 < N)
                            arr2[i-1][j+2] += prob;
                    }
                    if (i+1 < N) {
                        if (j-2 >= 0)
                            arr2[i+1][j-2] += prob;
                        if (j+2 < N)
                            arr2[i+1][j+2] += prob;
                    }
                    if (i+2 < N) {
                        if (j-1 >= 0)
                            arr2[i+2][j-1] += prob;
                        if (j+1 < N)
                            arr2[i+2][j+1] += prob;
                    }
                }
            }
        }
        
        memcpy(arr, arr2, sizeof(arr));
    }
    
    double sum_prob = 0.0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sum_prob += arr[i][j];
        }
    }
    
    return sum_prob;
}

int main(int argc, char** argv)
{
    double res = knightProbability(3, 2, 0, 0);
    printf("Result = %f\n", res);
    
    return 0;
}