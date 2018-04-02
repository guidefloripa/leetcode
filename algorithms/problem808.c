/*

Author: Guilherme Steinmann
Date: 2018-04-02

There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:
    1. Serve 100 ml of soup A and 0 ml of soup B
    2. Serve 75 ml of soup A and 25 ml of soup B
    3. Serve 50 ml of soup A and 50 ml of soup B
    4. Serve 25 ml of soup A and 75 ml of soup B

When we serve some soup, we give it to someone and we no longer have it.
Each turn, we will choose from the four operations with equal probability 0.25.
If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.
We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.

Example:
Input: N = 50
Output: 0.625
Explanation: 
If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty at the same time.
For the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B
become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Notes:
    0 <= N <= 10^9. 
    Answers within 10^-6 of the true value will be accepted as correct.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int A;
	int B;
	double prob;
	struct Node *Next;
};

static struct Node *first = NULL;

static double probCalc(int A, int B) {
	if (A <= 0 && B <= 0) // A and B are empty
		return 0.5;
	if (A <= 0) // A is empty
		return 1.0;
	if (B <= 0) // B is empty
		return 0.0;
	
	// check if probabilty of A,B is already calculated
	struct Node *cur = first;
	while (cur) {
		if (cur->A == A && cur->B == B)
			return cur->prob;
		cur = cur->Next;
	}
	
	double prob = 0.0;
	prob += 0.25 * probCalc(A-100, B);
	prob += 0.25 * probCalc(A-75, B-25);
	prob += 0.25 * probCalc(A-50, B-50);
	prob += 0.25 * probCalc(A-25, B-75);
	
	// store the probabilty A,B
	cur = first;
	if (cur) {
		while (cur->Next)
			cur = cur->Next;
		
		cur->Next = (struct Node*)calloc(1,sizeof(struct Node));
		cur = cur->Next;
	}
	else {
		first = (struct Node*)calloc(1,sizeof(struct Node));
		cur = first;
	}
	
	cur->A = A;
	cur->B = B;
	cur->prob = prob;
	cur->Next = NULL;
	
	return prob;
}

double soupServings(int N) {
	if (N >= 5000)
		return 1.0;
	else
		return probCalc(N, N);
}

int main(int argc, char** argv)
{
	double p = soupServings(2200);
	printf("%f\n", p);

	while (first) {
		struct Node *cur = first;
		first = first->Next;
		free(cur);
	}

	return 0;
}
