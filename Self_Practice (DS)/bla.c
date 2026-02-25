#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
   int data;
   struct stack *next;
};
struct stack *Top = NULL;
void printList()
{
   struct stack *nn = Top;
   while (nn != NULL)
   {
      printf("%d ", nn->data);
      nn = nn->next;
   }
}

void Push(int data)
{
   struct stack *nn = malloc(sizeof(struct stack));
   nn->data = data;
   nn->next = Top;
   Top = nn;
}

void Pop()
{
   struct stack *k = Top;
   Top = Top->next;
   free(k);
}
int top()
{
   return Top->data;
}
int main()
{
   Push(7);
   Push(8);
   Push(9);
   Push(10);
   Push(11);
   Push(12);
   Push(13);
   Pop();
   printList();
   printf("\n%d", top());
}
