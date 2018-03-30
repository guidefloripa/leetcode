/*

Author: Guilherme Steinmann
Date: 2018-03-30

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes,
as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
"...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-").
We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
 
Note:
- The length of words will be at most 100.
- Each words[i] will have length in range [1, 12].
- words[i] will only consist of lowercase letters.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniqueMorseRepresentations(char** words, int wordsSize) {
    const char* code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    char** morse_words = (char**)calloc(wordsSize, sizeof(char*));
    int wlen;
    int idx;
    int i,j,w;
    
    for (i=0; i<wordsSize; i++) {
        wlen = strlen(words[i]);
        morse_words[i] = (char*)calloc(wlen*4+1, sizeof(char));
        morse_words[i][0] = '\0';
        
        for (w=0; w<wlen; w++) {
            idx = words[i][w] - 'a';
            strcat(morse_words[i], code[idx]);
        }
    }
    
    wlen = 0;
    for (i=0; i<wordsSize; i++) {
        for (j=(i+1); j<wordsSize; j++) {
            if (strcmp(morse_words[i], morse_words[j]) == 0)
                break;
        }
        if (j == wordsSize)
            wlen++;
    }
    
    for (i=0; i<wordsSize; i++) {
        free(morse_words[i]);
    }
    free(morse_words);
    
    return wlen;
}

int main(int argc, char** argv)
{
    char* words[] = {"gin", "zen", "gig", "msg"};
    int n = uniqueMorseRepresentations(words, 4);
    printf("Result = %d\n", n);
    return 0;
}
