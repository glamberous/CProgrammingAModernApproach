/* a) Add a peek function to stackADT.c This function will have a parameter of
type Stack. When called, it returns the top item on the stack but doesn't modify
the stack. */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define STACK_SIZE 100

struct stack_type
{
  int *contents;
  int top;
  int size;
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(int size)
{
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL)
  {
    free(s);
    terminate("Error in create: stack could not be created.");
  }
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack s)
{
  s->top = 0;
}

bool is_emtpy(Stack s)
{
  return s->top == 0;
}

bool is_full(Stack s)
{
  return s->top == s->size;
}

void push(Stack s, int i)
{
  if (is_full(s))
    terminate("Error in push: stack is full.");
  s->contents[s->top++] = i;
}

int pop(Stack s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

int peek(Stack s)
{
  return s->contents[s->top];
}
