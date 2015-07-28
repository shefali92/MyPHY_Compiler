//Group No 12 Team No 1
//Rashi Khandelwal 2011B5A7635P
//Shefali Garg 2011B2A7810P




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "semantic_analyzer.h"

int icnt=0,ocnt=0;
Node temp3;
void check_semantic(ast a, FPTR f, SPTR s)
{
	int condn = 0;
	char f_name[20];
	char id[20];
	Node temp_node;
	if(a->temp->children[0]==NULL)
	{	
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP") && !remaining(a))
			{
				return;
			}
			if((a->temp->position_children)+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[(a->temp->position_children)+1];
				condn=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		check_semantic(a,f,s);
	}
	else
	{
	
			if(!strcmp("funcst", a->temp->info.node_symbol) || ! strcmp("program", a->temp->info.node_symbol)) 
			{
			//	printf("%s\n",a->temp->info.node_symbol);
			
				strcpy(f_name, a->temp->children[0]->info.lexeme_name);
				temp_node=a->temp;
				if(!strcmp("funcst", a->temp->info.node_symbol))
				
				{temp3=a->temp;
//printf("temp3 lallla ===   %s\n",temp3);				
				params_compare(a,f,s,f_name);
				}
				a->temp=temp_node;
				
				check_rules(a,f,s,f_name);
				a->temp=temp_node;
				
				if(!strcmp("funcst", a->temp->info.node_symbol))
				
				{temp3=a->temp;
			//	printf("temp3 lallla ===   %s\n",temp3);
				return_value(a,f_name,id,s);
					}
				a->temp=temp_node;
			//	printf("temp3 mamamam ===   %s\n",temp3);
			   check_return(a,f_name,s,f,temp3);
				a->temp=temp_node;
				a->temp=a->temp->children[0];				
			}
			else
			{
				a->temp=a->temp->children[0];
			}
			check_semantic(a, f, s);
			
	}
}


/////////////////// comparing parameters /////////////////////////
 
void params_compare(ast a, FPTR f, SPTR s, char f_name[])
{
//printf("Inside params compare\n");
	int condn= 0 ;
	FPTR fp =s->f;
	VPTR vp ;
	int i=0;
	int j=0;
	int t=0;
	
	char type_id[20];
	char id[20];
	Node temp_node;
	
	if(a->temp->children[0]==NULL)
	{	
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
				return;
			}
			if((a->temp->position_children)+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[(a->temp->position_children)+1];
				condn=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		params_compare(a,f,s,f_name);
	}
	else
	{
			if(! strcmp("paramtypelist", a->temp->info.node_symbol) ) 
			//&& ! strcmp("params", a->temp->parent->info.node_symbol
			{
			
		//	printf("Inside paramtypelist\n");
			temp_node=a->temp;
				do
				{
					strcpy(id, a->temp->children[1]->info.lexeme_name);
					for( i = 0 ; i < s->size ; i++)
					{
						if(!strcmp((fp+i)->fname, f_name)&& (fp+i)->s==1)
						{
				//			printf("Mil gya function\n");
							vp=(fp+i)->v;
							t=i;
							for(j=0;j<fp->size;j++)
							{
								if(!strcmp((vp+j)->info.lexeme_name,id)&& (vp+j)->s==1)
								{
							//		printf("%s\n..",id);
							//		printf("Shefali");
									(vp+j)->inparams=1;
								}
							}
						}
					}
					
					icnt++;
		//			printf("icnt %d\n",icnt);
					/// check for 2
					
					if(a->temp->number_children>2)
					a->temp=a->temp->children[2];
					//
					else break;								
				}while(a->temp!=NULL);
				
				(fp+t)->ip_params = icnt;
		//		printf(" jere chekc this\n");
				(fp+t)->op_params = 1;
		//		printf("temp node %s\n",temp_node);
				a->temp=temp_node;
				a->temp= a->temp->children[0];
				params_compare(a,f,s,f_name);
		}
		else
		{
			//		printf("Inside Else\n");
					a->temp= a->temp->children[0];
					params_compare(a,f,s,f_name);
					
					// check output params
		}	
}
}

//////////////////////////////////////////////check_other aspects



void check_rules(ast a, FPTR f, SPTR s, char f_name[])
{
	//printf("Inside check rules\n");
	int condn =0;
	int value =0;
	int condn2 =0;
	int search =0;
	char  func_name[20];
	char id[20];
	char type[20];
	char types[20];
	Node temp_node;
	Node temp_node1;
	int l_number;
//	printf("child here %s\n",a->temp->children[0]);
	if(a->temp->children[0]==NULL)
	{	
//	printf("NULL\n");
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
		//	printf("STOP\n");
				return ;
			}
			if((a->temp->position_children)+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[(a->temp->position_children)+1];
				condn=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		check_rules(a,f,s,f_name);
	}
	else
	{
		if(! strcmp("funcst", a->temp->info.node_symbol) )
		{
		
				temp3 = a->temp;
				icnt =0 ; ocnt = 0;
				strcpy(f_name, a->temp->children[1]->info.lexeme_name);
				temp_node=a->temp;
				params_compare(a,f,s,f_name);
				
				
		
		
	//	printf("func\n"); 
			a->temp=temp_node;
			a->temp=a->temp->children[0];
			check_rules(a, f, s, f_name);
			}
			else if(! strcmp("TK_CALL", a->temp->children[0]->info.token_name))
			{
	//			printf("inside tk call\n");
				strcpy(id,a->temp->children[1]->info.lexeme_name );
				char tempst[10];
				strcpy(tempst,find_type(id,f,s,f_name));
				if(!strcmp(tempst,"MASS")) strcpy(tempst,"mass");
				if(strcmp(temp3->children[0]->children[1]->info.lexeme_name,tempst))
				printf("Mismatch in the return type of call statement and declared funtion in line number %d\n", a->temp->children[0]->info.line_nu );
				
				temp_node= a->temp;
				strcpy(func_name,a->temp->children[2]->info.lexeme_name );
				
				
				
				input_param_check(a,f,s,"start",func_name);
				a->temp=temp_node;
				a->temp=a->temp->children[0];
				check_rules(a, f, s, f_name);
			}
			
			
			// chekc for 2
			
	//		l_number =a->temp->children[1]->info.line_nu;
	//		if(!strcmp(f_name, func_name))
	//		{
	//			printf("Recurrsion at %d for %s\n",a->temp->children[2]->info.line_nu,f_name);
	//		}
			//if(declaration_check(a,f,s,func_name,l_number))
		//	{	
			//	input_param_count(f,s,f_name,func_name);
//input_param_check(a,f,s,f_name,func_name);
				
			//	a->temp=temp_node;
				// output parameters count;
		//		output_param_check(a,f,s,f_name,func_name);
				
		//		a->temp=temp_node;
				
		//	}
		//	a->temp=a->temp->children[0];
	//		check_rules(a, f, s, f_name);
			
	//	}
		else if(! strcmp("iteratst", a->temp->info.node_symbol) )
		{
	//	printf("ute\n");
			search =0;
			temp_node= a->temp;
			// chekc for 2
			//check for while and for
			l_number =a->temp->children[0]->info.line_nu;
			a->temp=a->temp->children[1];
			
			while( strcmp("iteratst", a->temp->info.node_symbol) &&  strcmp("inputst", a->temp->info.node_symbol) &&strcmp("selstmt", a->temp->info.node_symbol) && strcmp("TK_ASSIGN", a->temp->info.node_symbol )&& strcmp("funcst", a->temp->info.node_symbol ) 
			&& strcmp("stmt", a->temp->info.node_symbol ) && strcmp("outputst", a->temp->info.node_symbol))
			{
				condn2=0;
				if(a->temp->children[0]==NULL)
				{
				while(!condn2)
				{
					if(!strcmp("TK_ID",a->temp->info.token_name))
					{
						temp_node1=a->temp;
						strcpy(id,a->temp->info.lexeme_name);
						a->temp= temp_node;
						if(find_while(temp_node,id))
						{
						search=1;
						}
						a->temp=temp_node1;
					}
					if((a->temp->position_children)+1<a->temp->parent->number_children)
					{
							a->temp= a->temp->parent->children[a->temp->position_children+1];
							condn2=1;
					}
					else
					{
						a->temp=a->temp->parent;
					}
					
				}
				}
				else
				{
						a->temp=a->temp->children[0];	
				}
			}
			
			
			if(!search)
			{
				printf("NO VAriable in iterate statement getting updated at %d \n",l_number);
			}
			
			a->temp=temp_node;
			a->temp=a->temp->children[0];
			check_rules(a, f, s, f_name);
			
		}
		
		else if(!strcmp("TK_ASSIGN", a->temp->info.node_symbol))
		{
	//	printf("level %s\n",a->temp->parent->children[0]->info.lexeme_name);
	//	printf("assign\n");
			temp_node=a->temp;
			if(strcmp("funcst", a->temp->parent->info.node_symbol))
			{
							if(!strcmp("TK_ID", a->temp->parent->children[0]->info.token_name))
							{
								
								strcpy(id, a->temp->parent->children[0]->info.lexeme_name);
							//	printf("id==%s\n",id);
						//		printf("%s\n",id);
						//		printf("%\n",f);
						//		printf("%s\n",s);
						//		printf("%s\n",f_name);
								strcpy(type,find_type(id,f,s,f_name));
						//		printf("papa  %s \n",a->temp);
						//		printf(" beta %s \n",a->temp->children[0]);
						//		printf("papa beta %s %s\n",a->temp,a->temp->children[0]);
								a->temp= a->temp->children[0];
						//		printf("papa beta %s %s\n",a->temp,a->temp->children[1]);
						//		printf("%s\n",type);
								if(strcmp(type, "UNKNOWN"))
								{
									assign_compare(a,type,f,s,f_name);
								}
							}
							
			}
			
			
			a->temp=temp_node;
			a->temp=a->temp->children[0];
			check_rules(a, f, s, f_name);
			
		}
		else if(!strcmp("selst", a->temp->info.node_symbol))
			{
			//printf("sel\n");
								temp_node=a->temp;
			
								a->temp= a->temp->children[1];
			
								
								condition_compare(a,f,s,f_name);
												
								a->temp=temp_node;
			a->temp=a->temp->children[0];
			check_rules(a, f, s, f_name);
			
			}
			
			else
			{
			
			//printf("else\n");
			
			a->temp=a->temp->children[0];
			check_rules(a, f, s, f_name);
			}
			
			
			
			
			
		}
	}
	
	/////////////// Matching input parameters ////////////////


int input_param_count(char f_name[], char type[],  char id[], SPTR s)
{
	//printf("Type = %s\n",type);
	//printf("id = %s\n",id);
		FPTR fp = s->f;
		VPTR vp ;
		 int i=0;
		 int j=0;
		 for(i=0;i<s->size;i++)
		 {
		 	if(!strcmp((fp+i)->fname, f_name)&& (fp+i)->s==1)
		 	{
			 	vp=(fp+i)->v;
				for(j=0;j<fp->size;j++)
				{
					//if(!strcmp(type,(vp+j)->token)&&(vp+j)->s==1&& (vp+j)->inparams==1)
					if(!strcmp(type,(vp+j)->token)&&(vp+j)->s==1)
					{
	//					printf("here");
						return 1;
					}
				}
	//			printf("there");
						return 0;		
			}
		}
		
}


//////// Matching Output Parameters ////////////////////////////

int output_param_count(char f_name[], char type[],  char id[], SPTR s)
{
		FPTR fp = s->f;
		VPTR vp ;
		 int i=0;
		 int j=0;
		 for(i=0;i<s->size;i++)
		 {
		 	if(!strcmp((fp+i)->fname, f_name)&& (fp+i)->s==1)
		 	{
			 	vp=(fp+i)->v;
				for(j=0;j<fp->size;j++)
				{
					if(!strcmp(type,(vp+j)->token)&&(vp+j)->s==1&& (vp+j)->outparams==1)
					{
						return 1;
					}
				}
						return 0;		
			}
		}

}
///////////////////////////////////////////////////////////


char* find_type(char id[], FPTR f, SPTR s, char f_name[])
{
	
	//pr//intf("inside find type id==%s\n",id);
								//printf("%s\n",id);
								//printf("%s\n",f);
							//	printf("%s\n",s);
	//			printf("inside find type %s\n",f_name);
//	printf("%s\n",s->f);
	
	//printf("Shefali11111111111");		
	
	FPTR fptr= s->f;
	VPTR vptr ;
	vptr= f->v;
	int i=0,j=0;
	char type[10];
	strcpy(type, "UNKNOWN");
//	printf("func ka size %d\n",f->size);
	
	
	
	for(i=0;i<f->size;i++)
{	

		
//		printf("Shefali\n");		
//		printf(" hello in find type %s\n",(vptr+i)->info.lexeme_name);
		if(!strcmp((vptr+i)->info.lexeme_name,id)&& (vptr+i)->s==1)
		
		{
			return (vptr+i)->token;	//token == type
		}
}
		for( i=0;i< s->size;i++)
		{
			if(!strcmp((fptr+i)->fname,f_name)&&((fptr+i)->s==1))
			{
				vptr=(fptr+i)->v;
				for(j=0;j<fptr->size;j++)
				{
//					printf("Hello in variables\n ");
//					printf(" hello in find type %s %s\n",(vptr+j)->info.lexeme_name, id);
					if(!strcmp(id,(vptr+j)->info.lexeme_name)&&(vptr+j)->s==1)
					{
					
						return (vptr+j)->token;
					}
				}
						return type;		
			}
		}
		//return type;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void assign_compare(ast a, char type[], FPTR f, SPTR s, char f_name[])
{

//	printf("Inside assign compare\n");
	int condn= 0;
	char types[20];
	char id[20];
//	printf("%s\n",a->temp);
	if( a->temp->children[0]==NULL)
	{
		while(! condn)
		{
			if(!strcmp("stmt", a->temp->info.node_symbol)|| !strcmp("TK_ASSIGN",a->temp->info.node_symbol))
			{
				return;
			}
			if(!strcmp("TK_ID", a->temp->info.token_name))
			{
//							printf("Inside TK ID\n");		
							strcpy(id, a->temp->info.lexeme_name);
								strcpy(types, find_type(id,f,s,f_name));
//								printf("%s %s\n",type, types);
								if(strcmp(types,type))
								{
									printf("Mismatch assignment in type of left hand side %s and right hand side %s in line number %d\n",type, types, a->temp->info.line_nu);
								}
								
							
			}
			// number check //
			if((a->temp->position_children)+1<(a->temp->parent->number_children))
			{
				a->temp= a->temp->parent ->children[a->temp->position_children+1];
				condn=1;
				
			}
			else
			{
				a->temp=a->temp->parent;
				
			}
		}
		assign_compare(a, type, f, s,  f_name);
	}
	else
	{
		a->temp=a->temp->children[0];
		assign_compare(a, type, f, s,  f_name);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
//////


void condition_compare ( ast a , FPTR f , SPTR s , char f_name[])
{

//	printf("Inside condition cmapre\n");
	int condn = 0 ;  
	char id[20] ;
	char id1[20] ;
	char type[20] ;
	char type1[20] ;
	if(a->temp->children[0]==NULL)
	{
	
		while(! condn)
		{
			
//			printf("Inside cond\n");
			if(!strcmp("TK_ELSE",a->temp->info.token_name))
			{
				return ;
			}
			if(!strcmp("TK_AND", a->temp->info.token_name)|| !strcmp("TK_OR",a->temp->info.token_name))
			{
					if(strcmp( a->temp->parent->children[0]->info.node_symbol,"logicalop"))
					{
						printf("Expected boolean expression line number %d\n",a->temp->info.line_nu);
					}
					
					// check
					if(strcmp( a->temp->parent->children[2]->info.node_symbol,"logicalop"))
					{
						printf("Expected boolean expression line number %d\n",a->temp->info.line_nu);
					}
			}
			
			
			if(!strcmp("TK_ID", a->temp->info.token_name)||!strcmp("TK_NUMBERS", a->temp->info.token_name)&& a->temp->position_children!=2)
			{
//			printf("Inside id and num\n");
			
							strcpy(id, a->temp->info.lexeme_name);
//							printf("id==%s",id);
							strcpy(id1, a->temp->parent->children[1]->children[0]->info.lexeme_name);
//							printf("Inside cond");
						
								if(!strcmp(a->temp->info.token_name,"TK_ID"))
								{
								
								strcpy(type,find_type(id,f,s,f_name));
//								printf("TYPE OF %s is %s\n", id,type);
								
								}
							
								if(!strcmp(a->temp->info.token_name,"TK_NUMBERS"))
								{
//								printf("inside number");
								strcpy(type,"INT");
								}
								
								if(!strcmp(a->temp->parent->children[1]->children[0]->info.token_name,"TK_ID"))
								{
//									printf("inside other side exp");
								strcpy(type1,find_type(id1,f,s,f_name));
								
								
								}
							
								if(!strcmp(a->temp->parent->children[1]->children[0]->info.token_name,"TK_NUMBERS"))
								{
//									printf("in numbber wali chiz TYPE OF %s is %s\n", id,type);
								strcpy(type1,"INT");
								}
								
								if(strcmp(type,"UNKNOWN")&& strcmp(type1,"UNKNOWN"))
								{
									if(strcmp(type, type1) && strcmp(type,"INT") && strcmp(type1,"INT"))
									{
										printf("error type of variables have to be same %d line number\n",a->temp->info.line_nu); 
									}
									
								}
								
					if((strcmp(a->temp->parent->children[1]->info.token_name,"TK_LT")&&strcmp(a->temp->parent->children[1]->info.token_name,"TK_LE")&&strcmp(a->temp->parent->children[1]->info.token_name,"TK_EQEQ")&&strcmp(a->temp->parent->children[1]->info.token_name,"TK_GT")&&strcmp(a->temp->parent->children[1]->info.token_name,"TK_GE")&&strcmp(a->temp->parent->children[1]->info.token_name,"TK_NE")))
								{
								printf("INVALLID BOOLEAN EXPRESSION EXPECTED RELATIOAL OPERATOR  %d line number\n",a->temp->info.line_nu); 
								return;
								}
								if((!strcmp(a->temp->parent->children[1]->info.token_name,"TK_LT")||!strcmp(a->temp->parent->children[1]->info.token_name,"TK_LE")||!strcmp(a->temp->parent->children[1]->info.token_name,"TK_EQEQ")||!strcmp(a->temp->parent->children[1]->info.token_name,"TK_GT")||!strcmp(a->temp->parent->children[1]->info.token_name,"TK_GE")||!strcmp(a->temp->parent->children[1]->info.token_name,"TK_NE")))
								
								{
//								printf("valid relational\n");
								return;
								}
//								printf("outside relational\n");
	}
	
//	printf("position of children %d\n",a->temp->position_children+1);
//	printf("parent number of children %d\n",a->temp->parent->number_children);
	if((a->temp->position_children)+1<(a->temp->parent->number_children))
			{
//				printf("Hello\n");
				a->temp= a->temp->parent ->children[a->temp->position_children+1];
				condn=1;
				
			}
			else
			{
				a->temp=a->temp->parent;
				
			}
		}
//		printf("I am finally here\n");
		condition_compare ( a ,  f ,  s , f_name);
	}
	else
	{
	a->temp=a->temp->children[0];
	condition_compare ( a ,  f ,  s , f_name);
	}
	
	
}


/////////////////////////////////////////// ////////////////////////////////////////////////////////////

int declaration_check(ast a, FPTR f, SPTR s, char f_name[], int line)
{
	FPTR fp = s->f;
	VPTR vp ;
	int i=0;
	int j=0;
	for(i=0;i<s->size;i++)
	{
		if(!strcmp((fp+i)->fname,f_name)&& (fp+i)->s==1)
		{
			vp=(fp+i)->v;
			for(j=0;j<fp->size;j++)
			{
				if((vp+j)->inparams!=0 || (vp+j)->outparams!=0 ) // output params
				return 1;
			} 
			printf("Line number %d function %s is undefined \n",line,f_name);
			return 0;
			
		}
			printf("Line number %d function %s is undefined \n",line,f_name);
		return 0;
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void assignment_set(char f_name[], char id[], SPTR s)
{
	FPTR fp = s->f;
	VPTR vp ;
	int i=0 ;
	int j=0 ;
	for(i=0 ; i<s->size;i++)
	{
		if(!strcmp((fp+i)->fname,f_name)&& (fp+i)->s==1)
		{
			vp = (fp+i)->v;
			for(j=0;j<fp->size;j++)
			{
				if((vp+j)->s==1 && (vp+j)->outparams ==1 && !strcmp((vp+j)->info.lexeme_name,id) ) // output params
				(vp+j)->assigned=1;
			} 
			
	}
}
return ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void assignment_check(char f_name[], SPTR s)
{
	FPTR fp = s->f;
	VPTR vp ;
	int i=0 ;
	int j=0 ;
	for(i=0 ; i<s->size;i++)
	{
		if(!strcmp((fp+i)->fname,f_name)&& (fp+i)->s==1)
		{
			vp = (fp+i)->v;
			for(j=0;j<fp->size;j++)
			{
				if((vp+j)->s==1 && (vp+j)->assigned==0 && (vp+j)->outparams) // output params
				printf("Line number %d no value assigned to %s  in  function %s\n",(vp+j)->info.line_nu, (vp+j)->info.lexeme_name, f_name);

			} 
			
	}
}
return ;
} 
//////////////////////////////////////////////////////////////////////////////////////////

void return_value(ast a, char f_name[], char id[], SPTR s)
{
	int condn =0;
	Node temp_node;
	
	
	if(a->temp->children[0]==NULL)
	{	
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
				return;
			}
			if((a->temp->position_children)+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[(a->temp->position_children)+1];
				condn=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		return_value(a,f_name,id,s);
	}
	else
	{
		if(! strcmp("param-list", a->temp->info.node_symbol) && ! strcmp("params", a->temp->parent->info.node_symbol)) 
		{
			
			strcpy(id,a->temp->children[1]->info.lexeme_name );
			
		
			
		}
		else if(! strcmp("TK_ASSIGN", a->temp->info.node_symbol) )
		{
			if(! strcmp(id, a->temp->children[0]->info.lexeme_name) )
			{
				 assignment_set(f_name, id,s);
			}
		}
		
		else if(!strcmp("inputst", a->temp->info.node_symbol) )
		{
			// check grammar
			if(a->temp->children[1]->children[0]==NULL) 
			{
				if(!strcmp(id, a->temp->children[1]->info.lexeme_name) )
				 assignment_set(f_name, id,s);
			}
			else
			{
				if(!strcmp(id, a->temp->children[1]->children[0]->info.lexeme_name) )
				 assignment_set(f_name, id,s);
				
			}
			
		}

		else if(!strcmp("funcst", a->temp->info.node_symbol) )
		{
			// check grammar
			temp_node =a->temp;
			a->temp= a->temp->children[0]->children[0];
				do
				{
					if(a->temp->number_children < 2)
					{
						 strcpy(id,a->temp->info.lexeme_name );
						 assignment_set(f_name, id,s);
						 break;
					}
					else
					{
						strcpy(id,a->temp->children[0]->info.lexeme_name );
						 assignment_set(f_name, id,s);
						 a->temp= a->temp->children[1];
						
					}
				}while(a->temp!=NULL);
		
		a->temp=temp_node;
		}
		a->temp=a->temp->children[0];
		return_value( a, f_name, id,  s);
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void check_return (ast a, char f_name[], SPTR s, FPTR f, Node temp1 )
{
//printf("temp3  ===   %s\n",temp1);
	
	int condn =0;
	Node temp_node;
	int i=0;
	int j=0;	
	char type[20];
	char id[20];
	FPTR fp= s->f;
	int ln;  // line number
	
	
	if(a->temp->children[0]==NULL)
	{	
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP"))
			{
				return;
			}
			if((a->temp->position_children)+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[(a->temp->position_children)+1];
				condn=1;
			}
			else
			{
				a->temp=a->temp->parent;
			}
			
		}
		check_return(a,f_name,s,f,temp1);
	}
	else
	{
		if(! strcmp("returnst", a->temp->info.node_symbol) )
		{
			
			temp_node=a->temp;
			a->temp= a->temp->children[1];
				do
				{
					if(a->temp->number_children < 2)
					{
						 strcpy(id,a->temp->info.lexeme_name );
//						 printf("id~~~~~~~~~~~~%s\n",id);
						 strcpy(type,find_type(id,f,s,f_name));
						 if(!strcmp(type,"MASS"))
						 strcpy(type,"mass");
						 if(!strcmp(type,"TIME"))
						 strcpy(type,"time");
						 if(!strcmp(type,"DISP"))
						 strcpy(type,"disp");
						 if(!strcmp(type,"FORCE"))
						 strcpy(type,"force");
						 if(!strcmp(type,"LEN"))
						 strcpy(type,"len");
						  if(!strcmp(type,"POWER"))
						 strcpy(type,"power");
						 if(!strcmp(type,"WORK"))
						 strcpy(type,"work");
						 a->temp=temp_node;
						 a->temp= a->temp->children[1];
						 //printf("hahahahahahaah  %s %s \n",a->temp,temp1);
						 
					//	 printf("Type=== %s and child %s \n",type,temp1->children[0]->children[1]->info.lexeme_name);
						 if( strcmp(temp1->children[0]->children[1]->info.lexeme_name,type))
						 
						//if(! output_param_count(f_name, type, id, s))
						{
							
							printf("line number %d type %s of variable %s does not match \n",a->temp->info.line_nu,type, id);
						}
						ln=a->temp->info.line_nu;
						//count++;
						break;
					}
					else
					{
						strcpy(id,a->temp->children[0]->info.lexeme_name );
						strcpy(type,find_type(id,f,s,f_name));
						if(! output_param_count(f_name, type, id, s))
						{
							printf("line number %d type %s of variable %s does not match \n",a->temp->info.line_nu,type, id);
						}
						a->temp=a->temp->children[1];
						//count++;
					
						
					}
				}	
				while(a->temp!=NULL);

// output params
		
		a->temp=temp_node;
		
		}
		a->temp= a->temp->children[0];
			
		check_return(a,f_name,s,f,temp1);
		
		}
		
}

/////////////////////////////////////////////////////////////////////////////////////////

int find_while(ast a, char id[])
{
		int condn =0;
		if (a->temp->children[0]==NULL)
		{
			while(!condn)
			{
				// add end while here
				
				if(a->temp->position_children+1<a->temp->parent->number_children)
				{
					a->temp=a->temp->parent->children[a->temp->position_children+1];
					condn=1;
				}
				else
				{
					a->temp=a->temp->parent;
					
				}

			}
//			a->temp=a->temp->parent;
				find_while( a,  id);
		}
		else
		{
			if(! strcmp("TK_ASSIGN", a->temp->info.node_symbol) )
		{
				if(! strcmp(id, a->temp->children[0]->info.lexeme_name) )
				{
					return 1;
				}
		}
		a->temp=a->temp->children[0];
		find_while( a,  id);
		
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		
void input_param_check(ast a, FPTR f, SPTR s, char calling[], char called[])
{
	//printf("Inside param input check\n");
	int cnt =0;
	int ip =0;
	int i= 0;
	FPTR fp= s->f;
	char id[20];
	char type[20];
	int lin;
	int pos = 0;
	// check for this 2 or wahr
	//printf("in input params %s\n",a->temp);
	a->temp=a->temp->children[3];
	
	do{
	
	//	printf("pos %d num child %d\n",pos,a->temp->number_children);
		if(a->temp->children[0]!=NULL && pos<a->temp->number_children){
		if(a->temp->number_children<2)
		{
		
			strcpy(id,a->temp->children[0]->info.lexeme_name );
	//		printf("hello  id =%s\n",id);
			strcpy(type,find_type(id,f,s,called));
			
			if(! input_param_count(called, type, id, s))
						{
							
							printf("line number %d type mismatch \n Parameters given %s with type %s but should be something else \n",a->temp->info.line_nu,id,type);
						}
						lin=a->temp->info.line_nu;
		
					cnt++;
						break;
					}
					else
					{
						strcpy(id,a->temp->children[pos]->info.lexeme_name );
						strcpy(type,find_type(id,f,s,called));
						if(! input_param_count(called, type, id, s))
						{
							printf("line number %d type mismatch \n Parameters given %s with type %s but should be something else \n",a->temp->info.line_nu,id,type);
						}
						a->temp=a->temp->parent;
						pos++;
						cnt++;
					
						
					}
					}
else break;			
			
		}
		while(a->temp!=NULL);
		for(i=0;i<s->size;i++)
		{
			if(!strcmp((fp+i)->fname,called))
			{
				ip=(fp+i)->ip_params;
				break;
			}
		}
		if(cnt!=ip)
		{
			if(cnt==0)cnt++;
			printf("function %s called with  %d parameters but should be %d parameters \n",called,cnt,ip);
		}
		
		
}	
		
///////////////////////////////////////////////////////////////////////		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////
		
void output_param_check(ast a, FPTR f, SPTR s, char calling[], char called[])
{

//	printf("Inside output params");
	int cnt = 0;
	int op = 0;
	int i= 0;
	FPTR fp= s->f;
	char id[20];
	char type[20];
	int lin;
	// check for this 2 or wahr
	//
	a->temp=a->temp->children[0];
	do
	{
		if(a->temp->number_children<2)
		{
			strcpy(id,a->temp->children[1]->info.lexeme_name );
			strcpy(type,id);
			if(! output_param_count(called, type, id, s))
						{
							
							printf("line number %d type mismatch \n Parameters given %s with type %s but should be something else \n",a->temp->info.line_nu,id,type);
						}
						lin=a->temp->info.line_nu;
					cnt++;
						break;
					}
					else
					{
						strcpy(id,a->temp->children[1]->info.lexeme_name );
						strcpy(type,id);
						if(! output_param_count(called, type, id, s))
						{
							printf("line number %d type mismatch \n Parameters given %s with type %s but should be something else \n",a->temp->info.line_nu,id,type);
						}
						a->temp=a->temp->children[1];
						cnt++;
					
						
					}
			
			
		}
		while(a->temp!=NULL);
		
		for(i=0;i<s->size;i++)
		{
			if(!strcmp((fp+i)->fname,called))
			{
				op=(fp+i)->op_params;
				break;
			}
		}
// output params
				
		
}

