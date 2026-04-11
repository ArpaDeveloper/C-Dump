//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node struct
typedef struct node{
    char data[20];
    struct node *prev;
    struct node *next;
} Node;

//Create new node
Node* createNode(const char *key){
    //Allocate mem for one node
    Node* newNode=(Node*)malloc(sizeof(Node)); 
    if(newNode==NULL) return NULL;
    if(key!=NULL&&key[0]!='\0'){ 
        //Copy the user inputted val to newNode data field
        strcpy(newNode->data, key); 
    }else{
        //Ask user for string if NULL
        printf("Input a string (NULL error): ");
        if(fgets(newNode->data,sizeof(newNode->data),stdin)==NULL){
            free(newNode);
            return NULL;
        };
    }
    //Remove newline
    newNode->data[strcspn(newNode->data,"\n")]='\0';
    //Reject empty input
    if(newNode->data[0]=='\0'){
        free(newNode);
        return NULL;
    }
    //Set ptrs to NULL and return created node
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

//Print node
void printNode(Node *nodePtr){
    if(strlen(nodePtr->data) == 0){ 
        printf("The node is NULL.");
    }
    else{
        printf("[%s]",nodePtr->data);
    }
}