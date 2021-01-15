  
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


//TODO check if maloc and realoc need size+1 for /0


node* newNode (char Letter){

    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL){
     //TODO free program 
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        new_node->children[i]= NULL; 
    }
    new_node->count = 0;
    new_node->letter = Letter;

    return new_node;
}


char* toLower(char *c, int size){
for (int i = 0; i < size; i++)
{
   if(c[i]>='A' && c[i]<='Z')
        c[i]=c[i]-'A'+'a';
}
return c;    
}
  

char* garbageRemover(char* c,int size){
    char *string = (char*)malloc(sizeof(char));
    if(string == NULL)
        ;//TODO free tree
    int i,j=0;
    for (i = 0; i < size; i++)
    {
        if ((c[i]>='a' && c[i]<='z') || c[i]==' ' || c[i]=='\n' || c[i]=='\t' || c[i]=='\r' ||c[i]=='\0')
        {//*word = (char*) realloc(word, sizeof(char)*(index+1));
            *string = (char*) realloc(string, sizeof(char)*(j+2));
            string[j]=c[i];
            j++;
        }
    }
    string[j+1] = '\0';
    return string;
}



int charTOindex(char c){
    return c-'a';
}


char* recivData (){
    char insert_char;
    char *arrData = (char*) malloc(sizeof(char));
    if (arrData == NULL){
        //TODO free program 
    }
    int index = 0;
    while (insert_char = fgetc(stdin) != EOF){
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

    node *root = (node*) malloc(sizeof(node));
    if (root == NULL){
     //TODO free program 
    }
    char *data = recivData();
    int length = strlen(data);
    char *word = (char*) malloc(sizeof(char));
    if(word == NULL){
     //TODO free program 
    } 
    int index = 0;
    for (int i=0; i<length; i++){
         if (data[i]!=' ' && data[i]!='\n' && data[i]!='\t' && data[i]!='\r' && data[i]!='\0')
        {
            *word = (char*) realloc(word, sizeof(char)*(index+1));
             if(word == NULL){
            //TODO free program 
             } 
            word[index] = data[i];
            index++;
        }
        else{
            word[index] = '\0';
            insertWordToTree(root, word);
            free(word);
            index = 0;
        }
    }

    free(root);           

}


void insertWord (node *root ,char *word){
    int c;
    node *insert = NULL;
    for (c = 0; c < strlen(word)-1; c++)
    {
        if (root->children[charTOindex(c)] == NULL){
            insert = newNode(c);
             if(insert == NULL){
            //TODO free program 
             } 
        }
        root = insert;
    }

    //end of word- counter++
    c = strlen(word)-1;
    if (root->children[charTOindex(c)] == NULL){
            insert = newNode(c);
            insert->count++;
             if(insert == NULL){
            //TODO free program 
             } 
        }

}



int main(int argc, char *argcv[])
{
 
    if(argc==1) 
     ;   
    //TODO print exicograph a-z
	else if(argc==2 && *argcv[1]=='r') 
    //TODO print exicograph z-a

    //TODO free program 


return 0;
}

