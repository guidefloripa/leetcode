/*

Author: Guilherme Steinmann
Date: 2018-02-22

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int index;
	int value;
};

int compare_func(const void *a, const void *b) {
	return ((struct node*)a)->value - ((struct node*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target) {
	
	int i, j, sum;
	struct node *nodes = (struct node*)calloc(numsSize, sizeof(struct node));
	
	int* result = (int*)calloc(2, sizeof(int));
	
	for (i=0; i<numsSize; i++) {
		nodes[i].index = i;
		nodes[i].value = nums[i];
	}
	
	qsort(nodes, numsSize, sizeof(struct node), compare_func);
	
	i = 0;
	j = numsSize-1;
	
	while (i < j) {
		sum = nodes[i].value + nodes[j].value;
		if (sum == target) {
			if (nodes[i].index > nodes[j].index) {
				result[0] = nodes[j].index;
				result[1] = nodes[i].index;
			}
			else {
				result[0] = nodes[i].index;
				result[1] = nodes[j].index;
			}
			break;
		}
		else if (sum > target) {
			j--;
		}
		else {
			i++;
		}
	}
	
	free(nodes);
	return result;
}


int main(int argc, char** argv)
{
	int nums[] = {3,2,4};
	int target = 6;
	
	int* result = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target);
	printf("%d %d\n", result[0], result[1]);
	free(result);
	
	return 0;
}
