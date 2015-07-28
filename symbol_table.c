//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P


#include"symbol_table.h"
#include<string.h>
#include<stdlib.h>
#include<string.h>

int begin =0;
int offset= 0;

//Symbol Table funcntions implementation
//-----------------------------------------------------------------------------------------------------
SPTR symbol_table_create( int fsize,int vsize)
{
//printf("Creating.....\n");



	SPTR sptr=(SPTR)malloc(sizeof(s_table));
	FPTR fptr=(FPTR)malloc(fsize*sizeof(functions));
	VPTR vptr;

	int i,j=0,k=0;
	sptr->f=fptr;
	sptr->size=fsize;
		// printf("Going inside the for loop");	
	for(i=0;i<=fsize;i++)
	{
		vptr=(VPTR)malloc(vsize*sizeof(variable_fields));
	
	
	(fptr+i)->v=vptr;
	(fptr+i)->size=vsize;
	(fptr+i)->s=0;
	(fptr+i)->ip_params =0;
	(fptr+i) ->op_params = 0;
	// s =0 implies empty
	
	for(j=0;j<vsize;j++)
	{
	
	(vptr+j)->s=0;
	(vptr+j)->oft=0;
	(vptr+j)->inparams =0;
	(vptr+j)->outparams =0;
	(vptr+j) ->assigned =0;
	}
}

//printf("Created.....\n");
return sptr;
}
	
	
	
	
	
	
	
//-----------------------For main scope declare-------------------------------------------------------------//

FPTR global (SPTR s)
{

//printf("Global.....\n");
	FPTR f; 
	char global[]="MAIN";
	f= insert_functions(s,global,0);
	return f;
}

//----------------------------For other functions scope----------------------------------------------------//

FPTR insert_functions(SPTR s, char funcname[],int line )
{

//printf("Inside insert functions.....\n");
		int hash_key;
		int size= s->size;
		int j=0;
		int temp1=0;
		int temp2=0;
		int i=0;	
		FPTR f;
		f=s->f;
		for (i=0;i<size;i++)
		{
				
			if(!strcmp((f+i)->fname,funcname))
			{
				printf("\n--Function over loading here ! Not allowed ! --\n");
				printf("\n--Function name = %s Line Number %d --\n ",funcname,line); 
			}
		}
		//printf("I will not compute hash key\n");
		hash_key= hash(funcname,size);
		if((f+hash_key)->s==0)
		{
			//printf("hashkey= %d\n",hash_key);
			(f+hash_key)->s=1; // status =1
			strcpy((f+hash_key)->fname,funcname);
			
			//printf("Returning %d\n" , f+hash_key);
			
			return (f+hash_key);
		}
		
		
		// if filled space in table find new space 
		do{
		
		j++;
		temp2= hash_key+j*j;
		temp1= temp2 % size;
		
		}while((f+temp1)->s!=0&& j!=size);
		
		if((f+temp1)->s==0)
		{
			(f+temp1)->s=1;
			strcpy((f+temp1)->fname,funcname);
			//printf("Returning 2 %d\n" , f+hash_key);
			return (f+temp1);
		}
		else
		{
			printf("\n--YOU CANNOT INSERT THE FUNCTION %s IN THE TABLE--\n", funcname);
			return;
		}
}






//----------------------------------calculating hash index-----------------------------------------------------//

int hash(char string[],int size)
{
		int total_value=0;
		int i=0;
		for(i=0;string[i]!='\0';i++)
		{
			total_value= total_value+ toascii(string[i]);
		}
		total_value = total_value % size;
		
		return total_value ;	
		
}


//----------------------------------adding functions to table-----------------------------------------//

void add_functions(SPTR sptr,FPTR fptr,ast a)
{

//printf("222222nodesymbol %s \n",a->temp->info.node_symbol);
	//	printf("222222222token  %s \n",a->temp->info.token_name);
//		printf("222222222lexeme  %s \n",a->temp->info.lexeme_name);
	int flag=0;
	FPTR f;
	if(!strcmp(a->temp->info.token_name,"TK_QUIT") && !remaining(a) )
			{
				return ;
			}
	if(a->temp->children[0]==NULL)
	{

	if(!strcmp(a->temp->info.token_name,"TK_QUIT") && !remaining(a) )
			{
				return ;
			}
	//	printf("11nodesymbol %s \n",a->temp->info.node_symbol);
	//	printf("11token  %s \n",a->temp->info.token_name);
	//	printf("11lexeme  %s \n",a->temp->info.lexeme_name);
	
		while(!flag)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP") && !remaining(a) )
			{
				return ;
			}
			if(!strcmp(a->temp->info.token_name,"TK_QUIT") && !remaining(a) )
			{
				return ;
			}
			else if((a->temp->position_children)+1< a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[a->temp->position_children+1];
				flag=1;	
			}
			else
			{
				a->temp = a->temp->parent;
				
			}
			
		}
		add_functions(sptr,fptr, a);
	}
	else
	{
	
		a->temp=a->temp->children[0];
	//	printf("nodesymbol %s \n",a->temp->info.node_symbol);
		//printf("token  %s \n",a->temp->info.token_name);
	//	printf("lexeme  %s \n",a->temp->info.lexeme_name);
	
		if(! strcmp("funcst", a->temp->info.node_symbol) || ! strcmp("program", a->temp->info.node_symbol)) 
		{
	//	printf("in program Shefali\n");
		begin=0;
		offset=0;
		f=insert_functions(sptr,a->temp->children[0]->info.lexeme_name,a->temp->children[0]->info.line_nu);
		fill_symbol_table(f,fptr,a,sptr);
		}
		
		else if (! strcmp("funcst", a->temp->parent->info.node_symbol) || ! strcmp("program", a->temp->parent->info.node_symbol)) 
		{
	//	printf("in program rashi\n");
		a->temp=a->temp->parent;
		begin=0;
		offset=0;
		f=insert_functions(sptr,a->temp->children[0]->info.lexeme_name,a->temp->children[0]->info.line_nu);
		fill_symbol_table(f,fptr,a,sptr);
		}
		add_functions(sptr, fptr, a);
	}
}

///-----------------------------populating the symbol table----------------------------------------------------------///

void fill_symbol_table(FPTR f, FPTR fglobal, ast a,SPTR sptr)
{
	int flag=0;
	int pos=0;
	node_info n;
	char type[30];
	Node t;
	VPTR v;
	
	int sz;
	
	
	
	if(!strcmp(a->temp->info.token_name,"TK_QUIT") && !remaining(a) )
			{
				return ;
			}
	
	
if(! strcmp("funcst", a->temp->info.node_symbol)) 
		{
		//printf("in FUNCST\n");
		begin=0;
		offset=0;
		f=insert_functions(sptr,a->temp->children[1]->info.lexeme_name,a->temp->children[1]->info.line_nu);
		a->temp=a->temp->children[2];
		fill_symbol_table(f,fglobal,a,sptr);
		}
		
/*	 if (! strcmp("funcst", a->temp->parent->info.node_symbol)) 
	{
		printf("in program rashi\n");
	a->temp=a->temp->parent;
		begin=0;
		offset=0;
		f=insert_functions(sptr,a->temp->children[0]->info.lexeme_name,a->temp->children[0]->info.line_nu);
		fill_symbol_table(f,fglobal,a,sptr);
		}
*/	
	
	else if(a->temp->children[0]==NULL && strcmp(a->temp->info.token_name,"TK_ID"))
	{	
	//printf("222222I am lexeme TK_ID %s\n",a->temp->info.token_name );
	if( !strcmp(a->temp->info.token_name,"TK_QUIT"))
			return;
	//	printf("I am not TK_ID %s\n",a->temp->info.lexeme_name );
		while(!flag)
		{
			if( !strcmp(a->temp->info.token_name,"TK_STOP"))
			return;
			if( !strcmp(a->temp->info.token_name,"TK_QUIT"))
			return;
			else if(a->temp->position_children+1< a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[a->temp->position_children+1];
				flag=1;
			}

			else
			{
				a->temp=a->temp->parent;
				
			}			
		}
		fill_symbol_table(f,fglobal,a,sptr);
	}
	
	
	else if(a->temp->children[0]==NULL && !strcmp(a->temp->info.token_name,"TK_ID"))
	{
	
//	printf("I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
	//printf("I am token  TK_ID %s\n",a->temp->info.token_name );
		pos=a->temp->position_children;
		n=a->temp->info;
	
	if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_MASS")){
	
//	printf("~~~I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
	//printf("~~~I am token  TK_ID %s\n",a->temp->info.token_name );
			if(pos+1< a->temp->parent->number_children)
			
			{
				sz=1;
				strcpy(type,"MASS");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"MASS");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
	else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_LEN"))
	{
//	printf("00000000I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
//	printf("00000000I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=1;
				strcpy(type,"LEN");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"LEN");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_TIME"))
	{
//	printf("1111111I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
	//printf("111111111I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=1;
				strcpy(type,"TIME");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"TIME");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
		
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_FORCE"))
	{

	//printf("222222I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=2;
				strcpy(type,"FORCE");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"FORCE");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_POW"))
	{
	//printf("33333333I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
//	printf("33333333I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=2;
				strcpy(type,"POW");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"POW");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if( !strcmp(a->temp->parent->parent->children[0]->info.token_name, "TK_DISP"))
	{
		
	//printf("heloooooooooooooooooooooooooI am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
	//printf("444444444I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
				sz=2;
				strcpy(type,"DISP");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"DISP");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_WORK"))
	{
	//printf("555555I am lexeme TK_ID %s\n",a->temp->info.lexeme_name );
//	printf("555555I am token  TK_ID %s\n",a->temp->info.token_name );
	if(pos+1< a->temp->parent->number_children)
			
			{
				sz=2;
				strcpy(type,"WORK");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"WORK");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else
		{
			sz=0;
			strcpy(type,"UNKNOWN");
			insert_variables(fglobal,f,n,type,offset,sz);
			
		}
		
		
		while( !flag)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
				return;
			}
			if(!strcmp(a->temp->info.token_name,"TK_QUIT"))
			{
				return;
			}
			else if(a->temp->position_children+1 < a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[a->temp->position_children+1];
				flag=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		
		fill_symbol_table(f, fglobal,  a,sptr)		;
	
	}
	
	else
	{
	
	//	printf("chidren= %s \n",a->temp->children[0]);
		//printf("parent= %s \n",a->temp);
		a->temp=a->temp->children[0];
		
	//	printf("sibling %s\n", a->temp->parent->children[pos-1]);
		if(!strcmp("TK_ID",a->temp->info.token_name))
		{
			pos=a->temp->position_children;
			n=a->temp->info;
			if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_MASS")){
	
			if(pos+1< a->temp->parent->number_children)
			
			{
			sz=1;
				strcpy(type,"MASS");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"MASS");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
	else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_LEN"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=1;
				strcpy(type,"LEN");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"LEN");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_TIME"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
				strcpy(type,"TIME");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=1;
				begin =1;
				strcpy(type,"TIME");
				sz=1;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		
		
		else if( !strcmp(a->temp->parent->parent->children[0]->info.token_name, "TK_FORCE"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=2;
				strcpy(type,"FORCE");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
			
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"FORCE");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if( pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_POW"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=2;
				strcpy(type,"POW");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"POW");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if( !strcmp(a->temp->parent->parent->children[0]->info.token_name, "TK_DISP"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
				sz=2;
				strcpy(type,"DISP");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"DISP");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else if(pos>0 && !strcmp(a->temp->parent->children[pos-1]->info.token_name, "TK_WORK"))
	{
	if(pos+1< a->temp->parent->number_children)
			
			{
			sz=2;
				strcpy(type,"WORK");
				insert_variables(fglobal,f,n,type,offset,sz);
			}
			else
			{
				if(begin)
				offset+=2;
				begin =1;
				strcpy(type,"WORK");
				sz=2;
				insert_variables(fglobal,f,n,type,offset,sz);
			}
		}
		else
		{
		sz=0;
			strcpy(type,"UNKNOWN");
			insert_variables(fglobal,f,n,type,offset,sz);
			
		}
		}
		if(!strcmp("TK_ID",a->temp->info.token_name))
		{
			
			
			while( !flag)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
				return;
			}
			if(!strcmp(a->temp->info.token_name,"TK_QUIT"))
			{
				return;
			}
			else if(a->temp->position_children+1 < a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[a->temp->position_children+1];
				flag=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		
		fill_symbol_table(f, fglobal,  a,sptr)		;
			
		}
			
			fill_symbol_table(f, fglobal,  a,sptr)	;
			
			
			
		}
		
	}
//-----------------------------inserting the variables in the sybol table------------------------------------------------//


VPTR insert_variables (FPTR fglobal, FPTR f, node_info n, char token[], int off,int sz)
{

int key,size,j,temp1,temp2,i;
size=f->size;
j=0;
temp1=0;
temp2=0;
i=0;
VPTR v;
VPTR vglobal;
vglobal = fglobal->v;
v=f->v;
char h_key[20];


for(i=0;i<size;i++)
{
	if(!strcmp((v+i)->info.lexeme_name,n.lexeme_name)&& !strcmp(token,"UNKNOWN") && v!=vglobal)
	{
		return (v+i);
	}
	else if(!strcmp((v+i)->info.lexeme_name,n.lexeme_name)&& strcmp(token,"UNKNOWN") && v!=vglobal)
	{
		printf("\n-- Declaration more than once --\n");
		printf("\n-- Line number %d Lexeme_name %s --\n", n.line_nu,n.lexeme_name);
		 
		 if(!strcmp(token,"MASS"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"FORCE"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"LEN"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"TIME"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"DISP"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"WORK"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"POW"))
		 {
		 offset =offset-2;
		 }
		 return;
		 
	}
}
		
		for(i=0;i<size;i++)
		{
		if(!strcmp((vglobal+i)->info.lexeme_name,n.lexeme_name)&& !strcmp(token,"UNKNOWN"))
		{
		
			//  already variable is present
			return (v+i);
		}
		else if (!strcmp((vglobal+i)->info.lexeme_name,n.lexeme_name)&& strcmp(token,"UNKNOWN") )
		{
		
			printf("\n-- Global Declaration more than once --\n");
		    printf("\n-- Line number %d Lexeme_name %s --\n", n.line_nu,n.lexeme_name);
		     if(!strcmp(token,"MASS"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"FORCE"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"LEN"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"TIME"))
		 {
		 offset =offset-1;
		 }
		  if(!strcmp(token,"DISP"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"WORK"))
		 {
		 offset =offset-2;
		 }
		  if(!strcmp(token,"POW"))
		 {
		 offset =offset-2;
		 }
		 return;
		    
		}
			
		
		
		}
		
		if( !strcmp(token,"UNKNOWN"))
		{
			printf("\n-- Variable not declared --\n");
			printf("\n-- Lexeme name = %s\n in line number %d --\n",n.lexeme_name,n.line_nu);
			return;
		}
		
		strcpy(h_key,n.lexeme_name);
		key=hash(h_key,size);
		if((v+key)->s==0)
		{
			(v+key)->s=1;
			(v+key)->info=n;
			strcpy((v+key)->token, token);
			(v+key)->oft=off;
			(v+key)->size=sz;
			return (v+key);
		}
		
		do{
		
		j++;
		temp2= key+j*j;
		temp1= temp2 % size;
		
		}while((v+temp1)->s!=0 && j!=size);
		
		if((v+temp1)->s==0)
		{
			(v+temp1)->s=1;
			(v+temp1)->info=n;
			strcpy((v+temp1)->token,token);
			(v+temp1)->oft==off;
			(v+temp1)->size=sz;
			return (v+temp1);
			
		}
		
		/// table full cannot insert now;
		
		else
		{
			printf("\n-- Cannot insert this Variable %s --\n",n.lexeme_name);
			return;
		}
		
}		


//-------------------------printing the symbol table---------------------------------------------------------------//
void symbol_table_print(SPTR sp, FILE *fp)
{
int i,j,k;
char scope[20];
FPTR f= sp->f;
VPTR v;
char field[20];
int l=0;
for(i=0;i<sp->size;i++)
{
	if((f+i)->s==1)
	{
		strcpy(scope,(f+i)->fname);
		for(j=0;j<(f+i)->size;j++)
		{
			v=(f+i)->v;
			if( (v+j)->s==1)
			{
				printf("%20s | %20s | %15s | %15s | %10d | %10d | %10d | \n",(v+j)->info.lexeme_name,(v+j)->info.token_name,scope,(v+j)->token,(v+j)->size,(v+j)->oft,(v+j)->info.line_nu);
				fprintf(fp,"%20s | %20s | %15s | %15s | %10d | %10d | %10d | \n",(v+j)->info.lexeme_name,(v+j)->info.token_name,scope,(v+j)->token,(v+j)->size,(v+j)->oft,(v+j)->info.line_nu);
			}
			
		}
	}
}
	
}



