#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure exactly as in your image
struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

// Functions using 'struct Node' explicitly
void insert_at_head(struct Node **head, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->prev = NULL;
    newnode->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = newnode;
    }
    *head = newnode;
}

void delete_head(struct Node **head, struct Node **tail) {
    if (*head == NULL) return; 

    struct Node *delete_node = *head;
    *head = (*head)->next;
    free(delete_node); 
    
    if (*head == NULL) {
        *tail = NULL;
        return;
    }
    (*head)->prev = NULL;
}

void insert_at_any_position(struct Node **head, int idx, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;

    struct Node* tmp = *head;
    for (int i = 0; i < idx - 1; i++) {
        tmp = tmp->next;
    }
    
    newnode->next = tmp->next;
    tmp->next = newnode;
    newnode->prev = tmp;
    
    if (newnode->next != NULL) {
        newnode->next->prev = newnode;
    }
}

void delete_at_any_position(struct Node **head, int idx) {
    struct Node *tmp = *head;
    for (int i = 1; i < idx; i++) {
        tmp = tmp->next;
    }
    struct Node *delete_node = tmp->next;
    tmp->next = tmp->next->next;
    
    if (tmp->next != NULL) {
        tmp->next->prev = tmp;
    }
    free(delete_node); 
}

void insert_at_tail(struct Node **tail, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->next = NULL;

    (*tail)->next = newnode;
    newnode->prev = *tail;
    *tail = newnode;
}

void delete_tail(struct Node **head, struct Node **tail) {
    if (*tail == NULL) return;

    struct Node *delete_node = *tail;
    *tail = (*tail)->prev;
    free(delete_node);
    
    if (*tail == NULL) {
        *head = NULL;
        return;
    }
    (*tail)->next = NULL;
}

void print_forward(struct Node *head) {
    struct Node* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void print_backward(struct Node *tail) {
    struct Node* tmp = tail;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->prev;
    }
    printf("\n");
}

int main() {
    // Creating initial nodes manually
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 10;
    head->next = NULL;
    head->prev = NULL;

    struct Node *a = (struct Node*)malloc(sizeof(struct Node));
    a->val = 20;
    a->next = NULL;
    a->prev = NULL;

    struct Node *tail = (struct Node*)malloc(sizeof(struct Node));
    tail->val = 30;
    tail->next = NULL;
    tail->prev = NULL;

    // Linking nodes
    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    // Call functions
    insert_at_head(&head, 5);
    print_forward(head);

    return 0;
}