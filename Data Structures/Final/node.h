#ifndef node_H
#define node_H

typedef struct node{
    char data[20];
    struct node *prev;
    struct node *next;
} Node;

Node* createNode(const char *key);
void printNode(Node *nodePtr);

#endif