//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//DLL Headers
#include "dll.h"
#include "node.h"
//BST Headers
#include "tnode.h"
#include "bst.h"

//Macros
#define CLEAR_INPUT_BUFFER() do {int c; while ((c = getchar()) != '\n' && c != EOF);}while(0);
//Add chars one by one to int c from buffer to consume them

int main(){

    //Variables
    char input[100];
    char data[100];
    char f_char;
    int choice;
    bool start=true;

    //Create empty DDL & BST
    DLL * dll = createList();
    BST* bst=createTree();

    //Main loop
    while(1){
        //Main printing (I use multiple print statements for more readable code)
        if(start==false) printf("\n");
        start=false;
        printf("--- DLL operations ---\n");
        printf("11. Insert a string into the list\n");
        printf("12. Filter by initial letter in the list\n");
        printf("13. Search for a word in the list\n");
        printf("14. Delete a word from the list\n");
        printf("15. Load a file into the list\n");
        printf("16. Store the list to a file\n");
        printf("\n--- BST operations ---\n");
        printf("21. Insert a string into the tree\n");
        printf("22. Filter by initial letter in the tree\n");
        printf("23. Search for a word in the tree\n");
        printf("24. Delete a word from the tree\n");
        printf("25. Load a file into the tree\n");
        printf("26. Store the tree to a file\n");
        printf("\n0. Free memory and exit\n");
        printf("Enter your choice: ");

        //Safely read & Clear buffer
        if (!fgets(input, sizeof(input), stdin)) break; 
        if(!strchr(input, '\n')){CLEAR_INPUT_BUFFER();}
        //Remove \n
        input[strcspn(input, "\n")] = '\0'; 
        //Check if input contains chars & is not empty
        if(strlen(input)!=strspn(input, "0123456789")||input[0]=='\0'){
            printf("Invalid input!\n"); 
            continue;
        }
        //Get choice
        choice=atoi(input);

        //Different operations
        switch(choice){
            //Insert a string into the list
            case 11:
                printf("Input a string: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){
                    CLEAR_INPUT_BUFFER();
                    continue;
                } 
                //Remove \n
                data[strcspn(data, "\n")] = '\0'; 
                
                Node* newDLLNode=createNode(data);
                //Safety check
                if(newDLLNode!=NULL){
                    insert(dll, newDLLNode);
                    printf("Inserted!\n");
                }
                else{
                    printf("Failed to insert!\n");
                }
                continue;
            
            //Filter by initial letter in the list
            case 12:
                printf("Filter/Print list by char: ");
                //Safely read & Clear buffer
                if(!scanf(" %c",&f_char))break; 
                CLEAR_INPUT_BUFFER()

                displayList(dll, f_char);
                continue;

            //Search for a word in the list
            case 13:
                if(listEmpty(dll)){ 
                    printf("List is empty.\n");
                    break;
                }
                printf("Input a string: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();} 
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                Node* f_dll_node=search(dll,data);
                if(f_dll_node!=NULL){
                    printf("The address is: %p\n",f_dll_node);
                }
                else{
                    printf("Word not found\n");
                }
                continue;

            //Delete a word from the list
            case 14:
                if(listEmpty(dll)){ 
                    printf("List is empty.\n");
                    break;
                }
                printf("Input a string: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();}
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                Node* r_dll_node=search(dll, data);
                if(r_dll_node!=NULL) {
                    Remove(dll, r_dll_node);
                    printf("Removed!\n");
                } else {
                    printf("Word not found\n");
                }
                continue;

            //Load a file into the list
            case 15:
                printf("Enter file to import: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();} 
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                loadTextFile(dll, data);
                continue;

            //Store the list to a file
            case 16:
                printf("Enter file to store: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();} 
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                storeTextFile(dll, data);
                continue;

            //Insert a string into the tree
            case 21:
                printf("Input a string: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){
                    CLEAR_INPUT_BUFFER();
                    continue;
                } 
                //Remove \n
                data[strcspn(data, "\n")] = '\0';
                
                TNode* newBSTNode=createTNode(data);
                //Safety check
                if(newBSTNode!=NULL){
                    bstInsert(bst, newBSTNode);
                    printf("Inserted!\n");
                }
                else{
                    printf("Failed to insert!\n");
                }
                continue;

            //Filter by initial letter in the tree
            case 22:
                printf("Filter/Print tree by char: ");
                //Safely read & Clear buffer
                if(!scanf(" %c",&f_char))break;
                CLEAR_INPUT_BUFFER();

                printAlphabetical(bst,f_char);
                continue;

            //Search for a word in the tree
            case 23:
                printf("Input string to find in Tree: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER(); }
                //Remove \n
                data[strcspn(data, "\n")] = '\0'; 

                TNode* find_node=Tsearch(bst,data);
                if(find_node!=NULL){
                    printf("The address is: %p\n",find_node);
                }
                else{
                    printf("Value not found\n");
                }
                continue;

            //Delete a word from the tree
            case 24:
                printf("Input string to delete: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();}
                //Remove \n
                data[strcspn(data, "\n")] = '\0'; 

                TRemove(bst,data);
                continue;

            //Load a file into the tree
            case 25:
                printf("Input file to load in Tree: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break; 
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();}
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                TloadTextFile(bst,data);
                continue;

            //Store the tree to a file
            case 26:
                printf("Input file to store in Tree: ");
                //Safely read & Clear buffer
                if (!fgets(data, sizeof(data), stdin)) break;
                if(!strchr(data, '\n')){CLEAR_INPUT_BUFFER();}
                //Remove \n
                data[strcspn(data, "\n")] = '\0';

                TstoreTextFile(bst,data);
                continue;

            //Free memory and exit 
            case 0:
                printf("Bye!\n");
                freeList(dll);
                freeTree(bst);
                return 0;
            
            //Handle wrong input number
            default:
                printf("Invalid input!\n"); 
                continue;
                
        }
    }
}

//Printing the menu text would be cleaner in it's own function
//Output reading with buffer clearance could be its own function
//I'm not sure if these functions would be counted as "deviating from definitions provided in Sprint PDFs"
//So I will not add them here