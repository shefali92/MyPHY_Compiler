//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30
#define BUFFERSIZE 100000

// Global Variables
//int line_number = 1; // to keep track to line number in the source code
//int begin=0;
//int offset=0;
int buf;
int lexeme_start;
int ahead;
typedef char buffer[BUFFERSIZE];


// Structure of Token

typedef struct token{
int final;
char lexeme_name[50];
char token_name[50];
int line;
//int attribute_value;
}token_info;


// Node containing data

typedef struct node
{
	token_info t;
	struct node* next;
}token_node;

typedef token_node *link;
// list of token nodes

typedef struct token_table{
int table_size;
link head;
}token_list;


 
