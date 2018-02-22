/*

Author: Guilherme Steinmann
Date: 2018-02-21

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:
- The length of both num1 and num2 is < 110.
- Both num1 and num2 contains only digits 0-9.
- Both num1 and num2 does not contain any leading zero.
- You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) 
{
	int len1 = strlen(num1); // length of num1
	int len2 = strlen(num2); // length of num2
	
	char* result = (char*)calloc(len1+len2+1, sizeof(char));
	int r = 0; // position in return string

	int carry = 0;
	int i, j;
	
	for (j=(len2-1); j>=0; j--) {
		int offset = 0;
		for (i=(len1-1); i>=0; i--,offset++) {
			int n1 = (int)(num1[i] - '0');
			int n2 = (int)(num2[j] - '0');
			int m = n1 * n2 + carry;
			if (result[r+offset] != '\0')
				m += (int)((result[r+offset]) - '0');

			result[r+offset] = (char)((m%10) + '0');
			carry = m/10;
		}
		while (carry > 0) {
			result[r+offset] = (char)((carry%10) + '0');
			carry /= 10;
			offset++;
		}
		r++;
	}
	
	// trim leading zeros
	int resultlen = strlen(result);
	for (i=(resultlen-1); i>0; i--) { // skip result[0]
		if (result[i] == '0') {
			result[i] = '\0';
			resultlen--;
		}
		else
			break;
	}
	
	// reverse result string
	for (i=0,j=(resultlen-1); i<(resultlen/2); i++,j--) {
		char c = result[i];
		result[i] = result[j];
		result[j] = c;
	}
	
	return result;
}


int main(int argc, char** argv)
{
	char *n1, *n2, *result;

	if (argc == 3) {
		n1 = argv[1];
		n2 = argv[2];
	}
	else {
		n1 = "30";
		n2 = "33";
	}
	
	result = multiply(n1, n2);
	printf("%s * %s = %s\n", n1, n2, result);
	free(result);

	return 0;
}
