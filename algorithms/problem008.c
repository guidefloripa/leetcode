/*

Author: Guilherme Steinmann
Date: 2018-03-30

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace
character is found. Then, starting from this character, takes an optional initial plus or minus sign
followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored
and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such
sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the
range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str) {
    
    int len = strlen(str);
    int i = 0;
    int sign = 1;
    long long result = 0;
    
    if (!str)
        return 0;
    
    while (str[i] == ' ')
        i++;
    
    if (str[i] == '+') {
        i++;
    }
    else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    
    for (; i<len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result*10 + str[i]-'0';
            if (result*sign >= INT_MAX)
                return INT_MAX;
            if (result*sign <= INT_MIN)
                return INT_MIN;
        }
        else
            break;
    }
    
    return result * sign;
}

int main(int argc, char** argv)
{
    int i = myAtoi(" 2147483649");
    printf("Result = %d\n", i);
    return 0;
}
