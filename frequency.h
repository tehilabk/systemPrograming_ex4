#ifndef FREQUANCT_H
#define FREQUANCT_H
#define NUM_LETTERS ((int)26)


typedef struct node {
char letter;
int count;
struct node* children[NUM_LETTERS];
char* word;
} node;  
   
node* newNode (char Letter);
char* toLower(char *c, int size);
char* garbageRemover(char* c,int size);
int charTOindex(char c);
char* recivData ();
node* splitWordes(char *data);
void insertWord (node *root ,char *word, int wordLength);
void freeTree(node *r);
void lexicographical_order_reverse(node* root);
void lexicographical_order(node* root);

#endif //FREQUANCT_H