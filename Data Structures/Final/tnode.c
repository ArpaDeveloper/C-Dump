//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tnode struct
typedef struct tnode{
    char data[20];
    struct tnode *left;
    struct tnode *right;
} TNode;

//Create new tnode
TNode* createTNode(const char *key){
    //Allocate mem block size of TNode to a pointer to TNode
    TNode* newNode=(TNode*)malloc(sizeof(TNode)); 
    if(key!=NULL&&key[0]!='\0'){
        strcpy(newNode->data, key);
    }
    else{
        printf("Enter string (Null error): ");
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
    //Set newNode subtree's to NULL
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//Print tnode
void printTNode(TNode *nodePtr){
    if(strlen(nodePtr->data)!=0){ 
        printf("(%s)",nodePtr->data);
    }
    else{
        printf("The node is NULL.");
    }
}

//Print tnodes filtered (INORDER left->root->right)
void inOrderFiltered(TNode *node, char startChar){
    //Base case
    if(node==NULL)return;
    //Traverse left subtree
    inOrderFiltered(node->left,startChar);
    //Print node if it matches
    if(node->data[0]==startChar){ 
        printTNode(node);
    }
    //Traverse right subtree
    inOrderFiltered(node->right,startChar);
}

//Write tnode to file (PREORDER root->left->right)
void writePreOrder(TNode *node, FILE *fp){
    //Base case
    if(node==NULL)return;
    //Write current
    fprintf(fp,"%s\n",node->data);
    //Traverse left subtree
    writePreOrder(node->left,fp);
    //Traverse right subtree
    writePreOrder(node->right,fp);
}

//Free mem used by tnodes (POSTORDER left->right->root)
void freeNodes(TNode *node){ 
    //Base case
    if(node==NULL)return;
    //Traverse left subtree
    freeNodes(node->left);
    //Traverse right subtree
    freeNodes(node->right);
    //Free node
    free(node);
}