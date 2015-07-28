//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P

#include <stdio.h>
#include"symbolDef.h"
#include <stdlib.h>
#include<string.h>
#include<math.h>


extern SPTR symbol_table_create( int fsize,int vsize);

//--------------------------------------------------------------------------------


extern VPTR insert_variables (FPTR fglobal, FPTR f, node_info n, char token[], int off,int sz);
	
//--------------------------------------------------------------------------------


extern void symbol_table_print(SPTR s,FILE *fp);

//------------------------------------------------------------------------------------//


extern FPTR global (SPTR s);

//--------------------------------------------------------------------------------//


extern FPTR insert_functions(SPTR s, char funcname[],int line );


//---------------------------------------------------------------------------------------//


extern int hash(char string[],int size);

////----------------------------------------------------------------------------------------//


extern void add_functions(SPTR sptr,FPTR fptr,ast a);

///---------------------------------------------------------------------------------------///


extern void fill_symbol_table(FPTR f, FPTR fglobal, ast a,SPTR sptr);

	
//----------------------------------------------------------------------------------------//





 












