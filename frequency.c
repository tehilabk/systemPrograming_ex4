  
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


char* garbageRemover(char* c,int size){
    char* string = (char*)malloc(sizeof(char)*(size+1));
    if(string == NULL)
        ;//TODO free tree
    int i,j=0;
    for (i = 0; i < size; i++)
    {
        if ((c[i]>='a' && c[i]<='z') || c[i]==' ' || c[i]=='\n' || c[i]=='\t' || c[i]=='\r' ||c[i]=='\0')
        {
            string[j]=c[i];
            j++;
        }
    }
    string=(char)realloc(string,sizeof(char)*(j+1));
    return string;
}

char* toLower(char* c, int size){
for (int i = 0; i < size; i++)
{
   if(c[i]>='A' && c[i]<='Z')
        c[i]=c[i]-'A'+'a';
}
return c;    
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

