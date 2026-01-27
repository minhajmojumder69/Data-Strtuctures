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
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
int maximum_value(Node *head)
{
    int max = INT_MIN;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (max < i->val)
            {
                max = i->val;
            }
    }
    return max;
}
int minimum_value(Node *head)
{
    int min = INT_MAX;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (min > i->val)
            {
                min = i->val;
            }
    }
    return min;
}
void printing_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
    }
    int max = maximum_value(head);
    int min = minimum_value(head);
    int def = max - min;
    cout << def;
    
    return 0;
}