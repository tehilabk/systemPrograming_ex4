#ifndef FREQUANCT_H
#define FREQUANCT_H
#define NUM_LETTERS ((int)26)


typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;

node* newNode (char Letter);
char* toLower(char *c, int size);
char* garbageRemover(char* c,int size);
int charTOindex(char c);
char* recivData ();
node* splitWordes();
void insertWord (node *root ,char *word);
void freeTree(node *r, int error);

#endif //FREQUANCT_H