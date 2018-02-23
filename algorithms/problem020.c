/*

Author: Guilherme Steinmann
Date: 2018-02-23

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdbool.h>

bool isValid(char* s) {
	bool valid = true;
	
	int stack_limit = strlen(s)/2;
	char *stack = (char*)calloc(stack_limit, sizeof(char));
	int top = 0;
	
	const char *c = s;
	while (c != NULL) {
		if (*c=='(' || *c== '[' || *c== '{') {
			if (top == stack_limit) {
				valid = false;
				break;
			}
			stack[top++] = *c;
		}
		else if (*c==')') {
			if (top==0 || stack[top-1] != '(') {
				valid = false;
				break;
			}
			top--;
		}
		else if (*c==']') {
			if (top==0 || stack[top-1] != '[') {
				valid = false;
				break;
			}
			top--;
		}
		else if (*c=='}') {
			if (top==0 || stack[top-1] != '{') {
				valid = false;
				break;
			}
			top--;
		}
		else if (*c=='\0') {
			break;
		}
		else {
			valid = false;
			break;
		}
		c++;
	}
	
	free(stack);
	
	return valid && (top == 0);
}


int main(int argc, char** argv)
{
	char *s;
	if (argc == 2) {
		s = argv[1];
	}
	else {
		s = "()[]{}";
	}
	
	printf("%s\n", isValid(s) ? "true" : "false");
	
	return 0;
}
