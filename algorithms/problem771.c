/*

Author: Guilherme Steinmann
Date: 2018-02-22

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note:
- S and J will consist of letters and have length at most 50.
- The characters in J are distinct.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numJewelsInStones(char* J, char* S) {
	if (J == NULL || S == NULL) return 0;
	
	int lenj = strlen(J);
	int lens = strlen(S);
	int count = 0;
	int s,j;
	
	for (s=0; s<lens; s++) {
		for (j=0; j<lenj; j++) {
			if (S[s] == J[j]) {
				count++;
				break;
			}
		}
	}
	
	return count;
}

int main(int argc, char** argv)
{
	char *J, *S;
	if (argc == 3) {
		J = argv[1];
		S = argv[2];
	}
	else {
		J = "aA";
		S = "aAAbbbb";
	}
	
	int c = numJewelsInStones(J, S);
	printf("%d\n", c);
	return 0;
}
