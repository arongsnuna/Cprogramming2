//binary tree
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
//description of a node
struct tnode {
	char *word;
	int count; //number of occurrences
	struct tnode *left; //left child
	struct tnode *right; //right child
};
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
//word frquency count
int main(void)
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
struct tnode *talloc(void);
char *mystrdup(char *);
//add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL){ //a new word has arrived
		p = talloc(); //make a new node
		p->word = mystrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0) //same word occur
		p->count++;
	else if (cond < 0) //less than into left subtree
		p->left = addtree(p->left, w);
	else //greater than into right subtree
		p->right = addtree(p->right, w); 
	return p;
}
//make a tnode
struct tnode *talloc(void)
{
	return (struct tnode*) malloc(sizeof(struct tnode));
}
//makde a duplicat of s
char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
//in-order print of tree p
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}	
//get next word of character from input
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if ( c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
