//Group 12:  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P
#include"ast.h"

typedef struct variablefields
{
char token[50];  // token type
node_info info;
int s;
int size;
int oft;
int inparams;
int outparams;
int assigned;
} variable_fields;

typedef variable_fields * VPTR;

typedef struct functions
{
VPTR v;
int size;
char fname[30];
int s;
int ip_params;
int op_params;
} functions;

typedef functions * FPTR;

typedef struct symbol_table
{
	FPTR f;
	int size;
}s_table;

typedef s_table * SPTR;

