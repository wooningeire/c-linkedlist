#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int length;
} linkedList;

node* push(linkedList* ls, int value) {
    node* n = malloc(sizeof(node));
    n->value = value;
    
    if (ls->head == NULL) {
        ls->head = n;
        ls->tail = n;
    } else {
        ls->tail->next = n;
        ls->tail = n;
    }
    
    ls->length++;
    
    return n;
}

int main() {
    linkedList* ls = malloc(sizeof(linkedList));
    
    push(ls, 0);
    push(ls, 1);
    push(ls, 2);
    
    printf("%d", ls->length);
    printf("\n");
    
    node* n = ls->head;
    while (n != NULL) {
        printf("%d", n->value);
        n = n->next;
    }
    
    return 0;
}