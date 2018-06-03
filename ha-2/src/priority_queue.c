//
// Created by puzankova 30.05.18
//

#include "priority_queue.h"
#define ALLOCATE(t, n) (t *) malloc((n) * sizeof(t))

struct Node 
{
	double value;
	int key;
	struct Node* next;
	struct Node* prev;

};

int capacity = 0;
struct Node *highest = NULL;

void restore_props()
{
    struct Node *cur = highest;
    while(cur->prev != NULL && cur->key > cur->prev->key) {
        struct Node *max = cur;
        struct Node *min = cur->prev;

        if (max->next != NULL)
            min->next = max->next;
        else min->next = NULL;
        max->prev = min->prev;
        max->next = min;
        min->prev = max;
        if (cur == highest)
            highest = min;
        else
            min->next->prev = min;
        cur = max;
    }
}

int insert(double value, int key)
{
	// return the exit code:
	//	0 - success
	//	1 - not enough free space in the queue
	//  2 - other
	
	// the queue size is 100 elements

    if (capacity < 100) {
        struct Node *temp = ALLOCATE(struct Node, 1);
        if (temp == NULL) {
            return 1;
        }
        temp->key = key;
        temp->value = value;
        temp->prev = highest;
        temp->next = NULL;
        if (highest != NULL)
            highest->next = temp;
        highest = temp;
        restore_props();
        capacity++;
        return 0;
    } else
        return 1;
}

double extract_min()
{
	// returns the min value and delete it from queue
	// if queue is empty returns -infinity and print error message to the screen
    struct Node *temp = highest;
    if (highest != NULL) {
        highest = highest->prev;
        if (highest != NULL) {
            highest->next = NULL;
        }
        restore_props();
        capacity--;
        return temp->value;
    } else {
        printf("What the hack are you doing with my queue???");
        return INT64_MIN;
    }
}