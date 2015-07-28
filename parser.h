//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P


#include "parserDef.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//////////////// Stack Functions  /////////////////

extern stack create_stack();

//------------------------------------------------------------------------------

extern char* top(stack s);

//------------------------------------------------------------------------


extern stack push(stack s, char temptok[50]);
	
//--------------------------------------------------------------------------------


extern stack pop(stack s);

//-------------------------------------------------------------------------------


extern void print_stack(stack s);

//-------------------------------------------------------------------------------


extern stack string_push(stack s, char temptoken[500]);

 //-------------------------------------------------------------------------------
 
 
//----------------------- Rules for Grammar and Parsing Table

 
extern void create_parsing_table(int T[][51]);
 
//------------------------------------------------------------------------------- 
 
extern  int get_Value_NonTerm(char* c);
//----------------------------------------------------------------------------------------------------


extern int get_Value_Term(char *c) ;
//---------------------------------------------------------------------------------------------------


extern char *get_rule(int parseindex);

//--------------------------------------------------------------------------------------------------


extern int tokenizer ( char *rule, char rule_array[][100] );

//---------------------------------------------------------------------------------------------------


///------------- Functions for parse tree-------------------------------------////

extern Node createnode(node_info ninfo, Node parent_add, int pos);


extern parse_Tree initialize_ptree();

extern parse_Tree parse_input(char *testcase, int T[][51]);

extern void node_insert (parse_Tree p, char rule_array[][100], int token_numbers);

//---------------------------------------------------------------------------------------

extern void parse_tree_print (parse_Tree p,FILE *fp);

//----------------------------------------------------------------------------------------------------

extern int remaining(parse_Tree p);

void balance_pos(parse_Tree p)	;

//-------------------------------------------------------------------------------
