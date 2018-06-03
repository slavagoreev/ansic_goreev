//
// Created by puzankova 30.05.18
//

#include "stack.h"

#define ALLOCATE(t, n) (t *) malloc((n) * sizeof(t))

struct Node {
    double value;
    struct Node *next;
    struct Node *prev;
};

int capacity = 0;
struct Node *top = NULL;

int push(double value)
{
  // return the exit code:
  //	0 - success
  //	1 - not enough free space in the stack
  //    2 - other

  // the stack size is 50 elements

  if (capacity < 50) {
    struct Node *temp = ALLOCATE(struct Node, 1);
    if (temp == NULL) {
      return 1;
    }
    temp->value = value;
    temp->prev = top;
    top = temp;
    capacity++;
    return 0;
  } else
    return 1;
}

double pop()
{
  // returns top value and delete it from stack
  // if stack is empty returns -infinity and print error message to the screen
  if (capacity > 0) {
    struct Node *prevTop = top;
    double val = top->value;
    top = top->prev;
    free(prevTop);
    capacity--;
    return val;
  } else {
    printf("What the hack are you doing with my stack???");
    return INT64_MIN;
  }
}

double pick()
{
  // just returns the top value
  // if stack is empty returns -infinity and print error message to the screen
  return top->value;
}
