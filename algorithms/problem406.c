/*

Author: Guilherme Steinmann
Date: 2018-03-08

Suppose you have a random list of people standing in a queue.
Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int h;
	int k;
	struct node* next;
};

// sort 'h' desc, 'k' asc
int compare_func(const void* first, const void *second) {
	const int* a = *(const int**) first;
	const int* b = *(const int**) second;
	return (a[0]<b[0]) || (a[0]==b[0] && a[1]>b[1]);
}

// first order by descendent height, then insert the element in kth position
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize)
{	
	if (!people || peopleRowSize < 1 || peopleColSize != 2) return NULL;
	
	struct node* ptr;
	struct node* tmp;
	struct node* head = (struct node*)calloc(1, sizeof(struct node)); // dummy element for list head
	head->h = -1;
	head->k = -1;
	head->next = NULL;
	
	// sort queue by descending height
	qsort(people, peopleRowSize, sizeof(int*), compare_func);
	
	// enqueue the elements in a linked list
	for (int i=0; i<peopleRowSize; i++) {
		int pos = 0;
		ptr = head;

		// enqueue the element in the kth position
		while (ptr->next && pos < people[i][1]) {
			ptr = ptr->next;
			pos++;
		}
		tmp = (struct node*)calloc(1, sizeof(struct node));
		tmp->h = people[i][0];
		tmp->k = people[i][1];
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	
	// free dummy element
	ptr = head->next;
	free(head);
	
	// create array from linked list
	int** res = (int**)calloc(peopleRowSize, sizeof(int*));
	for (int i=0; i<peopleRowSize; i++) {
		res[i] = (int*)calloc(2, sizeof(int));
		res[i][0] = ptr->h;
		res[i][1] = ptr->k;
		
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	
	if (returnSize) *returnSize = peopleRowSize;
	return res;
}

void printPeople(int** p, int n)
{
	for (int i=0; i<n; i++) {
		fprintf(stderr, "p[%d] = (%d, %d)\n", i, p[i][0], p[i][1]);
	}
	fprintf(stderr, "\n");
}


int main(int argc,char *argv[])
{
	int people[][2] = { {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
	
	int n = sizeof(people)/sizeof(people[0]);
	int **p = (int**)calloc(n, sizeof(int*));
	for (int i=0; i<n; i++) {
		p[i] = (int*)calloc(2, sizeof(int));
		p[i][0] = people[i][0];
		p[i][1] = people[i][1];
	}
	
	printPeople(p, n);
	
	int ret = 0;
	int **res = reconstructQueue(p, n, 2, &ret);
	
	printPeople(res, ret);
	
	return 0;
}
