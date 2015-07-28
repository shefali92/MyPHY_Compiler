//Group 12:  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P



#include<stdlib.h>
#include<stdio.h>
#include<string.h>



typedef enum {TRUE, FALSE} boolean;


// Stack used for parsing 
typedef struct snode
{
	char token[50];
	struct snode* next;
} snode;

typedef snode * slink;

typedef struct stack
{
	int size;
	slink top;
} stack;

// parse tree node

typedef struct nodeinfo
{
	char lexeme_name[50];
	char token_name[50];
	int line_nu;   
	char parent_node[50];
	boolean is_leaf;       // set to 1 when node is leaf
	char node_symbol[30];
	//int number_value;
}node_info ;

typedef struct pnode
{
	node_info info;
	struct pnode* parent;
	struct pnode* children[20];
	int number_children;
	 int position_children;   // position in all children
}pnode;

typedef pnode * Node;

// Parse tree
typedef struct parsetree
{
	pnode * temp;
	pnode *head;
	int size;
	
}parse_tree;

typedef parse_tree * parse_Tree;

typedef int table;
//typedef FILE *grammar;

