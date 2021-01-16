  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency.h"

typedef enum {FALSE=0, TRUE=1} boolean;


//TODO check if maloc and realoc need size+1 for /0


node* newNode (char Letter){
    node* new_node = (node*) calloc(1,sizeof(node));
    if (!new_node){
       //TODO check if need to send root, error num 1
      return new_node;
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        new_node->children[i]= NULL; 
    }
    new_node->count = 0;
    new_node->letter = Letter;
    new_node->word = NULL;
    return new_node;
}

char* toLower(char *c, int size){
for (int i = 0; i < size; i++)
{
   if(*(c+i)>='A' && *(c+i)<='Z')
        *(c+i) = *(c+i)-(int)('A'+'a');
}
return c;    
}
  

char* garbageRemover(char* c,int size){
    char *string = (char*)calloc(1,sizeof(char));
    if(string == NULL){
       exit(2);//no tree to delete, error num 2
    }  
    int i,j=0;
    for (i = 0; i < size; i++)
    {
        if ((*(c+i)>='a' && *(c+i)<='z') || *(c+i)==' ' || *(c+i)=='\n' || *(c+i)=='\t' || *(c+i)=='\r' ||*(c+i)=='\0')
        {
            string = (char*) realloc(string, sizeof(char)*(j+2));
            if(string == NULL){
                exit(2);//no tree to delete, error num 2
            }
            *(string+j)=*(c+i);
            j++;
        }
    }
    *(string+j) = '\0';
    return string;
}



int charTOindex(char c){
    return c-'a';
}
   

char* recivData (){
    char insert_char;
    char *arrData = (char*) calloc(1,sizeof(char)*2);
    if (arrData == NULL){
        exit(3);//no tree to delete, error num 3
    }
    int index = 0;
    while ((insert_char = fgetc(stdin))!= EOF){
        arrData = (char*) realloc(arrData, sizeof(char)*(index+2));
         if (arrData == NULL){
            exit(4);//no tree to delete, error num 4
        }
        arrData[index] = insert_char;
        index++;
    }
    int sArrData = strlen(arrData);
    arrData = toLower(arrData, sArrData);
    char *returnData = garbageRemover(arrData, sArrData);
    free(arrData);
    return returnData;
}


node* splitWordes(char *data){
    node *root = (node*) calloc(1,sizeof(node));
    if (root == NULL){
        exit(5);//no tree to delete, error num 5
    }
    
    char *word = (char*) calloc(1,sizeof(char));
    if(word == NULL){
        free(data);
        freeTree(root); //error num 6 
        exit(6);
    } 
    int index = 0;
    int dataLen = strlen(data);
    for (int i=0; i < dataLen; i++){
         if (*(data+i)!=' ' && *(data+i)!='\n' && *(data+i)!='\t' && *(data+i)!='\r' && *(data+i)!='\0')
        {
            word = (char*) realloc(word, sizeof(char)*(index+2));
             if(word == NULL){
                free(data);
                freeTree(root); //error num 7 
                exit(7);
             } 
            *(word+index) = *(data+i);
            index++;
        }
        else{
            word = (char*) realloc(word, sizeof(char)*(index+2));
            if(word == NULL){
                free(data);
                freeTree(root); //error num 10
                exit(10);
                } 
            word[index] = '\0';
            insertWord(root, word, index);
            //free(word);
            index = 0;
      }
    }

   return root;         

}


void insertWord (node *root ,char *wordf, int wordLenght){
    int c;
    for (c = 0; c < wordLenght-1; c++)
    {
        char letter = *(wordf+c);
        int index = charTOindex(letter);
        if(root->children[index]==NULL){
            root->children[index] = newNode(letter);
        }
        root = root->children[index];
        if(c==wordLenght-2){
            char* temp = calloc(1,strlen(wordf));
            if(temp == NULL){
                freeTree(root); //error num 11
                exit(11);
                } 
            strcpy(temp,wordf);
            root->word = temp;
            root->count++;
        }
    }
    
}

void freeTree(node *r){
    if (r==NULL)
        return;
    for (int i =NUM_LETTERS ; i > 0; i--) {
        if (r->children[i] != NULL) {
            freeTree(r->children[i]);
        }
    }
    free(r); //frees the root

}


void lexicographical_order(node* root){

    for(int i = 0; i <NUM_LETTERS ; i++)
    {
        if(root->count != 0 ){
            printf("%s %ld\n" ,root->word,root->count);
            root->count=0;
        }
        if(root->children[i]!=NULL){
            lexicographical_order(root->children[i]);
        }
    }
    
}



int main(int argc, char const *argv[])
{
    char *data = recivData();

    node *root = splitWordes(data);

    lexicographical_order(root);
    // if(argc==1) 
    //  ;   
    // //TODO print exicograph a-z
	// else if(argc==2 && *argcv[1]=='r') 
    // //TODO print exicograph z-a

    //freeTree(root);
   
return 0;
}

