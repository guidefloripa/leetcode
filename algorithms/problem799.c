/*

Author: Guilherme Steinmann
Date: 2018-03-13

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row. 
Each glass holds one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.
When the top most glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.
When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.
(A glass at the bottom row has it's excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.
After two cups of champagne are poured, the two glasses on the second row are half full.
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.
After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)

Example 1:
Input: poured = 1, query_glass = 1, query_row = 1
Output: 0.0
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)).
There will be no excess liquid so all the glasses under the top glass will remain empty.

Example 2:
Input: poured = 2, query_glass = 1, query_row = 1
Output: 0.5
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)).
There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.

Note:

    poured will be in the range of [0, 10 ^ 9].
    query_glass and query_row will be in the range of [0, 99].
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Using complete matrix in stack */
double champagneTower(int poured, int query_row, int query_glass)
{
	double glasses[102][102];
	double extra;
	int i,j;
	
	memset(glasses, 0, sizeof(glasses));
	
	glasses[0][0] = poured;
	for (i=0; i<102; i++) {
		for (j=0; j<=i; j++) {
			if (glasses[i][j] > 1) {
				extra = glasses[i][j] - 1.0;
				glasses[i][j] = 1.0;
				glasses[i+1][j] += extra/2.0;
				glasses[i+1][j+1] += extra/2.0;
			}
		}
	}
	
	// print tower of glasses
#if 0
	for (i=0; i<102; i++) {
		for (j=0; j<=i; j++) {
			if (glasses[i][j] > 0.0)
				printf("%.2f ", glasses[i][j]);
			else
				printf("  -  ");
		}
		printf("\n");
	}
#endif
	
	return glasses[query_row][query_glass];
}

/* ------------------------------------------- */

// (i*(i+1))/2 + j 
#define IDX(i,j) (((i)*((i)+1))/2+(j))

/* optimazation using less space (triangular matrix as vector) */
double champagneTowerSpaceOptimized(int poured, int query_row, int query_glass)
{
	int len = 102;
	int size = (len*(len+1))/2;
	double *glasses = (double*)calloc(size, sizeof(double));
	double extra;
	int i,j;
	
	glasses[IDX(0,0)] = poured;
	for (i=0; i<(len-1); i++) {
		for (j=0; j<=i; j++) {
			if (glasses[IDX(i,j)] > 1.0) {
				extra = glasses[IDX(i,j)] - 1.0;
				glasses[IDX(i,j)] = 1.0;
				glasses[IDX(i+1,j)] += extra/2.0;
				glasses[IDX(i+1,j+1)] += extra/2.0;
			}
		}
	}
	
	// print tower of glasses
#if 0
	for (int i=0; i<len; i++) {
		for (int j=0; j<=i; j++) {
			if (glasses[IDX(i,j)] > 0.0)
				printf("%.2f ", glasses[IDX(i,j)]);
			else
				printf("  -  ");
		}
		printf("\n");
	}
	printf("\n");
#endif
	
	return glasses[IDX(query_row,query_glass)];
}

/* ------------------------------------------- */

int main(int argc, char** argv)
{
	double res = champagneTowerSpaceOptimized(200, 7, 0);
	printf("%f\n", res);
	return 0;
}
