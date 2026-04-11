//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tnode.h"

//Binary search tree struct
typedef struct{
    TNode *root;
} BST;

//Create BST handler
BST * createTree(){
    //Allocate mem block size of BST to a pointer to BST
    BST* newBST=(BST*)malloc(sizeof(BST)); 
    newBST->root=NULL; 
    return newBST;
}

//Check if tree is empty
int treeEmpty(BST *tree){
    if(tree->root==NULL){
        return 1;
    }
    return 0;
}

//Insert tnode to tree
void bstInsert(BST *tree, TNode *newNode){
    TNode* current=tree->root;
    TNode* prev=NULL;
    while(current!=NULL){
        //Save parent node
        prev=current; 
        if(strcmp(current->data, newNode->data)==0){ 
            free(newNode);
            return;
        }
        //If newNode is "smaller" go left subtree
        else if(strcmp(current->data, newNode->data)>0){
            current=current->left; 
        }
        //Otherwise go right subtree
        else{ 
            current=current->right;
        }
    }
    //Insertions
    //Tree empty
    if (prev==NULL){
        tree->root=newNode;
    }
    //newNode is smaller than parent insert left
    else if (strcmp(prev->data, newNode->data)>0){ 
        prev->left=newNode; 
    }
    //newNode is larger than parent insert right
    else{ 
        prev->right=newNode;
    }
}

//Print tree in alphabetical order
void printAlphabetical(BST *tree, char startChar){
    if(treeEmpty(tree)==1){
        printf("Tree is empty.\n");
    }
    else{
        printf("Tree: ");
        inOrderFiltered(tree->root,startChar);
    }
    printf("\n");
}

//Search for tnode in tree
TNode * Tsearch(BST *tree, char * key){
    TNode* current=tree->root;
    if(treeEmpty(tree)==1){
        return NULL;
    }
    while(current!=NULL){
        if(strcmp(current->data,key)==0){
            return current;
        }
        //If current is earlier in alphabets than key we try to find move to left
        //Because BST is always ordered
        if(strcmp(current->data,key)>0){ 
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    //If not found return NULL
    return NULL;
}

//Remove tnode from tree
void TRemove(BST *tree, char * key){
    //Nodes
    TNode* r_node=Tsearch(tree,key);
    TNode* parent=tree->root;
    TNode* child=NULL;

    //If r_node is not found
    if(r_node==NULL){
        printf("Value not found\n");
        return;
    }
    //Find parent
    if(r_node==tree->root){
        //If its root it will have no parent
        parent=NULL;
    }
    else{
        //Search for the parent
        while(parent!=NULL){
            //If parents child is the r_node we found parent
            if(parent->left==r_node || parent->right==r_node){ 
                break;
            }
            //If parent is earlier in alphabets than key we try to find move to left
            //Because BST is always ordered
            if(strcmp(parent->data,key)>0){ 
                parent=parent->left;
            }
            else{
                parent=parent->right;
            }
        }
    }
    //Leaf node (no children)
    if(r_node->left==NULL&&r_node->right==NULL){
        if(parent==NULL){
            //r_node is root
            tree->root=NULL; 
        }
        //r_node is parent's left child
        else if(parent->left==r_node){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
    }
    //Two children
    else if(r_node->left!=NULL&&r_node->right!=NULL){
        //Successor will be one right and max to left
        //Its leftmost node (1||0 children)
        TNode* successor=r_node;
        parent=r_node;
        successor=successor->right;
        while(successor->left!=NULL){
            //Keep track of successor parent
            parent=successor;
            successor=successor->left;
        }
        //Copy the data from successor to r_node
        strcpy(r_node->data,successor->data);
        //Successor might have right child or be NULL
        child=successor->right; 
        //successor is parent's left child
        if(parent->left==successor){
            parent->left=child;
        }
        else{
            parent->right=child;
        }    
        printf("The node at address %p is deleted\n",successor);
        free(successor);
        return;
    }
    //One child
    else{
        //Check which side r_node has it's child
        child=(r_node->left!=NULL) ? r_node->left:r_node->right;
        //r_node is root so the child will become root
        if(parent==NULL){
            tree->root=child;
        }
        //Left child
        else if(parent->left==r_node){
            parent->left=child;
        }
        //Right child
        else{
            parent->right=child;
        }
    }
    printf("The node at address %p is deleted\n",r_node);
    free(r_node);
    r_node=NULL;
}

//Load file into tree
void TloadTextFile(BST *tree, char * filename){
    char line[100];
    FILE* fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Failed to load!\n");
        return;
    }
    while(fgets(line,sizeof(line),fp)!=NULL){
        line[strcspn(line,"\r\n")]='\0'; 
        TNode* new_node = createTNode(line); 
        bstInsert(tree,new_node); 
    }
    fclose(fp);
    printf("Successfully loaded!\n");
}

//Store tree into file
void TstoreTextFile(BST *tree, char * filename){
    FILE* fp=fopen(filename,"w");
    if(fp==NULL){
        printf("Failed to store!\n");
        return;
    }
    writePreOrder(tree->root,fp);
    fclose(fp);
    printf("Successfully stored!\n");
}

//Free tree
void freeTree(BST *tree){
    //Free nodes
    freeNodes(tree->root);
    //Free the space taken by tree (bst struct)
    free(tree);
}