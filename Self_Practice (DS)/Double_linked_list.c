#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
   int data;
   char name[1000];
   float cgpa;
   struct node *next;
   struct node *pre;
};
struct node *head = NULL;
void insertatbegin(int data,char name[1000])
{
   struct node *nn = malloc(sizeof(struct node));
   if (head == NULL)
   {
      nn->data = data;
      strcpy(nn->name,name);
      nn->pre = NULL;
      nn->next = NULL;
      head = nn;
   }
   else
   {
      nn->data = data;
      strcpy(nn->name,name);
      nn->pre = NULL;
      nn->next = head;
      head->pre = nn;
      head = nn;
   }
}

// joining new node in middle
void insertatmiddle(int data,char name, char After_Node)
{
   struct node *nn = malloc(sizeof(struct node));
   nn->data = data;
   strcpy(nn->name,name);
   struct node *temp = head;

   while (strcmp(nn->name,After_Node) != 0)
   {
      temp = temp->next;
   }
   nn->pre = temp;
   nn->next = temp->next;
   temp->next = nn;
   temp->next->pre = nn;
}

// Joining new node in the end
void insertatlast(int data)
{
   struct node *nn = malloc(sizeof(struct node));
   nn->data = data;
   nn->next = NULL;
   struct node *temp = head;
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   nn->pre = temp;
   temp->next = nn;
}

// Deleting new node in the begin
void deleteatbegin()
{
   struct node *tmp = head;
   head = head->next;
   head->next->pre = NULL;
   free(tmp);
}

//Deleting new node in the Middle
void deleteatmiddle(char Aftervalue[1000])
{
   struct node *k;
   struct node *temp = head;
   while (strcmp(temp->name,Aftervalue))
   {
      temp = temp->next;
   }
   k = temp->next;
   temp->next = k->next;

   temp->next->next->pre = temp;
   free(k);
}

void deleteatlast()
{
   //struct node *k;
   struct node *temp = head;
   while (temp->next != NULL)
   {
      //k = temp;
      temp = temp->next;
   }
   temp->pre->next = NULL;
   //temp->pre = NULL;
   //temp->next = NULL;
   //k->next = NULL;
   free(temp);
}

void printList()
{
   struct node *temp = head;
   while (temp != NULL)
   {
      printf("%d %s", temp->data, temp->name);
      temp = temp->next;
   }
}

void printulta()
{
   struct node *tmp = head;
   while (tmp->next != NULL)
   {
      tmp = tmp->next;
   }
   while (tmp != NULL)
   {
      printf("%d ", tmp->data);
      tmp = tmp->pre;
   }
}

int main()
{
   
   insertatbegin(8,"nmh");
   //insertatbegin(10);
   // insertatbegin(11);
   // insertatbegin(12);
   printf("\nAt the Beginning List: ");
   printList();
   printf("\n");

   // (13 is the Data & 8 is the After_Node)
   // insertatmiddle(13, 8);
   // insertatmiddle(14, 13);
   // insertatmiddle(15, 14);
   // insertatmiddle(16, 15);
   // insertatmiddle(17, 16);
   // insertatmiddle(18, 17);
   // printf("\nAt the MIddle List: ");
   // printList();
   // printf("\n");

   // insertatlast(20);
   // insertatlast(21);
   // insertatlast(22);
   // insertatlast(23);
   // insertatlast(24);
   // insertatlast(25);
   // printf("\nAt the Last List: ");
   // printList();
   // printf("\n");

   // printf("\nThe List: ");
   // printList();
   // printf("\n");

   // deleteatbegin();
   // printf("\nThe deleted at Begin List: ");
   // printList();
   // printf("\n");

   // deleteatmiddle(20);
   // printf("\nThe deleted at Middle List: ");
   // printList();
   // printf("\n");

   // deleteatlast();
   // printf("\nThe deleted at Last List: ");
   // printList();
   // printf("\n");
}
