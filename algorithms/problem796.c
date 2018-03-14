/*

Author: Guilherme Steinmann
Date: 2018-03-14

We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position.
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A.
Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

Note:
    A and B will have length at most 100.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdbool.h>

bool rotateString(char* A, char* B) {
	if (!A || !B)
		return false;
	
	int alen = strlen(A);
	int blen = strlen(B);
	if (alen != blen)
		return false;
	
	char* AA = (char*)malloc(2*alen+1);
	memcpy(AA, A, alen);
	memcpy(&AA[alen], A, alen);
	AA[2*alen] = '\0';
	
	for (int i=0; i<alen; i++) {
		if (strncmp(&AA[i], B, alen) == 0) {
			free(AA);
			return true;
		}
	}
	
	free(AA);
	return false;
}

int main(int argc,char *argv[])
{
	bool b = rotateString("abcd", "bcda");

	printf("%s\n", b ? "TRUE" : "FALSE");
	return 0;
}
