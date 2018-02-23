/*

Author: Guilherme Steinmann
Date: 2018-02-22

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int v1, v2, sum;
	int carry = 0;
	struct ListNode* rcurrent = NULL;
	struct ListNode* rhead = NULL;
	
	while (l1 || l2) {
		v1 = l1 ? l1->val : 0;
		v2 = l2 ? l2->val : 0;
		sum = v1 + v2 + carry;
		if (!rhead) {
			rhead = (struct ListNode*)calloc(1,sizeof(struct ListNode));
			rcurrent = rhead;
		}
		else  {
			rcurrent->next = (struct ListNode*)calloc(1,sizeof(struct ListNode));
			rcurrent = rcurrent->next;
		}
		rcurrent->val = sum % 10;
		rcurrent->next = NULL;
		carry = sum / 10;
		
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	while (carry > 0) {
		if (!rhead) {
			rhead = (struct ListNode*)calloc(1,sizeof(struct ListNode));
			rcurrent = rhead;
		}
		else  {
			rcurrent->next = (struct ListNode*)calloc(1,sizeof(struct ListNode));
			rcurrent = rcurrent->next;
		}
		rcurrent->val = carry % 10;
		carry /= 10;
	}
	
	return rhead;
}

struct ListNode* append(struct ListNode* l, int value) {
	if (l) {
		while (l->next) {
			l = l->next;
		}
		l->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		l = l->next;
		l->val = value;
		l->next = NULL;
		return l;
	}
	else {
		struct ListNode* list = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		list->val = value;
		list->next = NULL;
		return list;
	}
}

int main(int argc, char** argv)
{
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* result;
	
	l1 = append(l1, 2);
	append(l1, 4);
	append(l1, 3);
	
	l2 = append(l2, 5);
	append(l2, 6);
	append(l2, 4);
	
	result = addTwoNumbers(l1, l2);
	while (result) {
		printf("%d ", result->val);
		result = result->next;
	}
	printf("\n");
	
	return 0;
}
