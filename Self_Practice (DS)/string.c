#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char data[1000];
    struct node *next;
    struct node *pre;
};
struct node *head = NULL; // Global variable call ;it can access from anywhere .

// joining new node in begin.
void insertatbegin(char data[1000])
{
    struct node *nn = malloc(sizeof(struct node));
    if (nn == NULL)
    {
        printf("Memory Allocate failed");
        return;
    }

    else if (head == NULL)
    {
        strcpy(nn->data, data);
        nn->pre = NULL;
        nn->next = head;
        head = nn;
    }
    else
    {
        strcpy(nn->data, data);
        nn->pre = NULL;
        nn->next = head;
        head->pre = nn;
        head = nn;
    }
}

// joining new node in middle
void insertatmiddle(char data[1000], char After_Node[1000])
{
    struct node *nn = malloc(sizeof(struct node));
    if (nn == NULL)
    {

        printf("Memory Allocate failed");
        return;
    }
    else
    {

        strcpy(nn->data, data); // string e data input dite hobe strcpy use korte hoi .likhar niom strcpy( jei khane rakhbo, jah rakhbo)
        struct node *temp = head;

        while (strcmp(temp->next->data, After_Node) != 0) // string use korle while loop e compare string use korte hobe .
        {
            temp = temp->next;
        }
        nn->pre = temp;
        nn->next = temp->next;
        temp->next = nn;
        temp->next->pre = nn;
    }
}
// Joining new node in the end
void insertatlast(char data[1000])
{
    struct node *nn = malloc(sizeof(struct node));
    if (nn == NULL)
    {

        printf("Memory Allocate failed");
        return;
    }

    else
    {
        strcpy(nn->data, data);
        nn->next = NULL;
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        nn->pre = temp;
        temp->next = nn;
    }
}
// Deleting new node in the begin
void deleteatbegin()
{
    struct node *k = head;
    head = head->next;
    head->next->pre = NULL;
    free(k);
}

// Deleting new node in the Middle
void deleteatmiddle(char value[1000])
{
    struct node *k;
    struct node *temp = head;
    while (strcmp(temp->next->data, value) != 0)

    {
        temp = temp->next;
    }
    k = temp->next;
    temp->next = k->next;

    temp->next->next->pre = temp;

    free(k);
}

// Deleting new node in the Last
void deleteatlast()
{
    struct node *k;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        k = temp;
        temp = temp->next;
    }
    temp->pre = NULL;
    temp->next = NULL;
    k->next = NULL;
    free(temp);
}

// display
void printList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insertatbegin("4"); // string use korle in [ " ___" ] use korte hoi. nahole kaj korbe nah
    insertatbegin("6");
    insertatbegin("8");
    insertatbegin("10");
    insertatbegin("11");
    insertatbegin("12");
    printf("\nAt the Beginning List: ");
    printList();
    printf("\n");

    // (Bangladesh is the Data & 8 is the After_Node)
    insertatmiddle("Bangladesh", "8");
    // insertatmiddle("14" , "Bangladesh");
    // insertatmiddle("15", "14");
    // insertatmiddle("India", "15");
    // insertatmiddle("17" , "India");
    // insertatmiddle("18" , "17");
    printf("\nAt the Middle List: ");
    printList();
    printf("\n");

    printf("\nThe List: ");
    printList();
    printf("\n");

    deleteatbegin();
    printf("\nThe deleted at Begin List: ");
    printList();
    printf("\n");

    deleteatmiddle("India");
    printf("\nThe deleted at Middle List: ");
    printList();
    printf("\n");

    deleteatlast();
    printf("\nThe deleted at Last List: ");
    printList();
    printf("\n");
}