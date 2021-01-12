  
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








int charTOindex(char c){
    return c-'a';
}


int main(int argc, char *argcv[])
{
 
char c = 'a';
printf("char is %d", charTOindex(c));

return 0;
}

