  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;


node* newNode (char Letter){

node* new_node = (node*) malloc(sizeof(node));

if (new_node != NULL){
    for (int i = 0; i < NUM_LETTERS; i++)
    {
       new_node->children[i]= NULL; 
    }
    new_node->count = 0;
    new_node->letter = Letter;
}
return new_node;
}





int charTOindex(char c){
    return c-'a';
}


int main(int argc, char *argcv[])
{
 
char c = 'a';
printf("char is %d", charTOindex(c));

return 0;
}

