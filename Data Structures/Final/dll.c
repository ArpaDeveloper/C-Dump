//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

//Doubly linked list struct
typedef struct{
    Node *head;
} DLL;

//Create list handler
DLL * createList(){
    //Allocate mem to list
    DLL *L =(DLL*)malloc(sizeof(DLL)); 
    L->head=NULL;
    return L;
}

//Check if list is empty
int listEmpty(DLL *list){
    if(list->head==NULL){
        return 1;
    }
    return 0;
}

//Insert node to list
void insert(DLL *list, Node *newNode){
    Node *current = list->head;
    //If list empty (No prev/next, because its the only node in the list)
    if(listEmpty(list)){ 
        //Put newNode as head
        list->head=newNode; 
        newNode->prev=NULL;
        newNode->next=NULL;
    }
    //If node should be the first in the list, put newNode as head
    else if(strcmp(newNode->data, current->data) < 0) {
        newNode->next=current;
        //newNode has no previous its first
        newNode->prev=NULL; 
        //Original Node prev is newNode
        current->prev=newNode; 
        //Put newNode as head
        list->head=newNode; 
    }
    else{
        //If node should be somewhere from second to last
        while(current->next!=NULL && strcmp(newNode->data, current->next->data) > 0) {
            current=current->next;
        }
        //Insert at right place
        newNode->next=current->next;
        newNode->prev=current;
        //If newNode is not last, set next node prev to newNode
        if(current->next!=NULL) { 
            current->next->prev=newNode;
        }
        current->next=newNode;
    }
}

//Print whole list
void displayList(DLL *list, char startChar){
    Node* current=list->head;
    if(listEmpty(list)==1){
        printf("List is empty");
    }
    else{
        int firstPrinted = 1; 
        //Print all the elements in the list
        while(current!=NULL){ 
            //Check if string starts with startChar
            if(current->data[0] == startChar){ 
                //If not first match, print <->
                if(!firstPrinted){
                    printf(" <-> ");
                }
                //If its first match
                else{  
                    printf("List: ");
                }
                printNode(current);    
                firstPrinted = 0;
            }
            current=current->next;
        }
    }
    printf("\n");
}

//Find a node in the list
Node *search(DLL *L, char * key){
    Node* current=L->head;
    //While not the end of list & key doesn't match data on the current node
    while (current!=NULL && strcmp(current->data, key)!=0){ 
        current=current->next; 
    }
    if(current==NULL){
        return NULL; 
    }
    return current;
}

//Remove node in the list
void Remove(DLL *L, Node *ptr){
    //Remove head
    if(ptr==L->head){ 
        //Set new head to be the next node
        L->head=ptr->next; 
        //If not only on the list
        if(ptr->next!=NULL){ 
            //Change prev of the new head to null
            L->head->prev=NULL; 
        }
    }
    //Remove tail
    else if(ptr->next==NULL){
        //Set second last node next to null
        ptr->prev->next=NULL; 
    }
    //Remove middle {a} <-> {b} <-> {c} LINK A TO C
    else{ 
        //Change R_node prev node next to R_node next
        ptr->prev->next=ptr->next;
        //Change R_node next node prev to R_node prev
        ptr->next->prev=ptr->prev;  
    }
    free(ptr);
}

//Load file into list
void loadTextFile(DLL *L, char * filename){
    //Var to store line from file
    char line[100];
    //Pointer to file
    FILE *fp; 
    fp=fopen(filename, "r"); 
    if(fp==NULL){
        printf("Failed to load!\n");
        return;
    }
    //Read line from file as long as there are lines
    while(fgets(line, sizeof(line), fp)!=NULL){
        //Remove \n
        line[strcspn(line, "\r\n")] = '\0';
        //Create new node with line
        Node * newNode=createNode(line); 
        //Insert it to right place (alphabetical)
        insert(L, newNode); 
    }
    fclose(fp);
    printf("File imported!\n");
}

//Store list into file
void storeTextFile(DLL *L, char * filename){ 
    Node *current=L->head; 
    //Pointer to file
    FILE *fp; 
    fp=fopen(filename, "w"); 
    if(fp==NULL){ 
        printf("Failed to store!\n");
        return;
    }
    //Go to the LAST node (not NULL)
    if(current != NULL){
        while(current->next != NULL){
            current = current->next;
        }
    }
    //Traverse backwards
    while(current != NULL){
        fprintf(fp,"%s\n",current->data);
        current = current->prev;
    }
    fclose(fp);
    printf("File exported!\n");
}

//Free mem used by list
void freeList(DLL *L){
    Node* current=L->head;
    Node* next;
    while (current!=NULL){ 
        next=current->next;
        //Free mem of node
        free(current); 
        current=next;
    }
    //Free mem of list (pointer to node)
    free(L);
}

