  
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
    else{
        //TODO free program
    }
    return new_node;
}



char* recivData (){
    char insert_char;
    char *arrData = (char*) malloc(sizeof(char));
    if (arrData == NULL){
        //TODO free program 
    }
    int index = 0;
    while (insert_char = scanf("%c", stdin) != EOF){
        *arrData = (char*) realloc(arrData, sizeof(char)*(index+1));
         if (arrData == NULL){
        //TODO free program 
        }
        arrData[index] = insert_char;
        index++;
    }
    *arrData = toLower(*arrData, strlen(arrData));
    char *returnData = garbageRemover(*arrData, strlen(arrData));
    free(arrData);
    return returnData;
}


void splitWordes(){

    char *data = recivData();
    int length = strlen(data);
    char *word = (char*) malloc(sizeof(char));
    int index = 0;
    for (int i=0; i<length; i++){
         if (data[i]!=' ' && data[i]!='\n' && data[i]!='\t' && data[i]!='\r' && data[i]!='\0')
        {
            *word = (char*) realloc(word, sizeof(char)*(index+1));
            word[index] = data[i];
            index++;
        }
        else{
            word[index] = '\0';
            //TODO sent to insert tree
            free(word);
            index = 0;
        }
    }           

}




char* garbageRemover(char* c,int size){
    char* string = (char*)malloc(sizeof(char));
    if(string == NULL)
        ;//TODO free tree
    int i,j=0;
    for (i = 0; i < size; i++)
    {
        if ((c[i]>='a' && c[i]<='z') || c[i]==' ' || c[i]=='\n' || c[i]=='\t' || c[i]=='\r' ||c[i]=='\0')
        {
            *string = (char*) realloc(string, sizeof(char)*(j+2));
            string[j]=c[i];
            j++;
        }
    }
    string[j+1] = '\0';
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
 


return 0;
}

