#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_any_pos(Node *&head,int idx, int val)
{
    Node* newnode = new Node(val); // creating newnode;
    Node* tmp = head;
    for (int i = 0; i < idx-1 ; i++)
    {
        tmp = head->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;

}

void printing_liked_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_any_pos(head,2, 69);
    printing_liked_list(head);

    return 0;
} 