/*

Author: Guilherme Steinmann
Date: 2018-02-22

Given a string, find the length of the longest substring without repeating characters.

Examples:

- Given "abcabcbb", the answer is "abc", which the length is 3.

- Given "bbbbb", the answer is "b", with the length of 1.

- Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
	int pos[256];
	int max_len = 0;
	int last_pos = -1;
	int len = strlen(s);
	int i;
	unsigned char c;
	
	memset(pos, -1, sizeof(pos));
	
	for (i=0; i<len; i++) {
		c = s[i];
		if (pos[c] != -1 && last_pos < pos[c]) {
			last_pos = pos[c];
		}
		if (i-last_pos > max_len) {
			max_len = i-last_pos;
		}
		pos[c] = i;
	}
	
	return max_len;
}

int main(int argc, char** argv)
{
	char *s;
	if (argc == 2) {
		s = argv[1];
	}
	else {
		s = "pwwkew";
	}
	
	printf("%d\n", lengthOfLongestSubstring(s));
	
	return 0;
}
