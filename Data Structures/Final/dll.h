#ifndef DLL_H
#define DLL_H

#include "node.h"
typedef struct{
    Node *head;
} DLL;

DLL * createList();
int listEmpty(DLL *list);
void insert(DLL *list, Node *newNode);
void displayList(DLL *list, char startChar);
Node *search(DLL *L, char * key);
void Remove(DLL *L, Node *ptr);
void loadTextFile(DLL *L, char * filename);
void storeTextFile(DLL *L, char * filename);
void freeList(DLL *L);
#endif