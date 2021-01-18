#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency.h"

node* newNode (char Letter){
    node* new_node = (node*) calloc(2,sizeof(node));
    if (!new_node){
      return new_node; // error num 1
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        new_node->children[i]= NULL; 
    }  
    new_node->count = 0;
    new_node->letter = Letter;
    new_node->word = (char*) calloc(2,sizeof(char));
   
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
    arrData = toLower(arrData, index);
    char *returnData = garbageRemover(arrData, index);
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
            index = 0;
             
      }   
    }
    free(word);
    
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
            if(root->children[index] == NULL)
                freeTree(root);
        }
        root = root->children[index];
        if(c==wordLenght-2){
            root->word = (char*) realloc(root->word, wordLenght+3);
            if(root->word == NULL){
                freeTree(root); //error num 11
                exit(11);
                } 
            strcpy(root->word, wordf);
            root->count++;
        }
    }
}

void freeTree(node *r){

    for (int i =NUM_LETTERS-1 ; i >= 0; i--) {
        if (r->children[i] != NULL) {
            freeTree(r->children[i]);
        } 
    }
    
    //frees the root
    free(r->word);
     free(r); 

}


void lexicographical_order(node* root){

    for(int i = 0; i <NUM_LETTERS ; i++)
    {
        if(root->count != 0 ){
            printf("%s %d\n" ,root->word,root->count);
            root->count=0;            
        }
        if(root->children[i]!=NULL){
            lexicographical_order(root->children[i]);
        }
    }
}

void lexicographical_order_reverse(node* root){

    for(int i = NUM_LETTERS-1; i >= 0 ; i--)
    {
        if(root->children[i]!=NULL){
            lexicographical_order_reverse(root->children[i]);
        }
        if(root->count != 0 ){
            char* word = root->word;
            int count = root->count;
            printf("%s %d\n" , word , count);
            root->count=0;
        }
        
    }
}


int main(int argc, char const *argv[])
{
    char *data = recivData();
    node *root = splitWordes(data);
    free(data);
    
    if(argc==1){
    lexicographical_order(root);
    }

	else if(argc==2 && *argv[1]=='r'){ 
        lexicographical_order_reverse(root);
    }
     freeTree(root);
return 0;
}

