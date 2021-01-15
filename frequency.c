  
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
      freeTree(new_node,1); //TODO check if need to send root, error num 1
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
       exit(2);//no tree to delete, error num 2
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



int charTOindex(char c){
    return c-'a';
}


char* recivData (){
    char insert_char;
    char *arrData = (char*) malloc(sizeof(char));
    if (arrData == NULL){
        exit(3);//no tree to delete, error num 3
    }
    int index = 0;
    while (insert_char = fgetc(stdin) != EOF){
        *arrData = (char*) realloc(arrData, sizeof(char)*(index+1));
         if (arrData == NULL){
        exit(4);//no tree to delete, error num 4
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
     exit(5);//no tree to delete, error num 5
    }
    char *data = recivData();
    int length = strlen(data);
    char *word = (char*) malloc(sizeof(char));
    if(word == NULL){
        freeTree(root, 6); //error num 6 
        exit(6);
    } 
    int index = 0;
    for (int i=0; i<length; i++){
         if (data[i]!=' ' && data[i]!='\n' && data[i]!='\t' && data[i]!='\r' && data[i]!='\0')
        {
            *word = (char*) realloc(word, sizeof(char)*(index+1));
             if(word == NULL){
                freeTree(root, 7); //error num 7 
                exit(7);
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
                freeTree(root, 8); //error num 8
                exit(8); 
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
                freeTree(root, 9); //error num 9
                exit(9); 
             } 
        }

}

void freeTree(node *r, int error){
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (r->children[i]) {
            freedom(r->children[i]);
        }
    }
    free(r); //frees the root
    if (error != 0){
        printf("error num %d",error);
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

