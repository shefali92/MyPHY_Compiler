//Group12:  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P




#include"ast.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//---------------------------------------------------------------------------------------------------------
//******************** AST FUNCTIONS ***********************************************//
//----------------------------------------------------------------------------------------------------------------//


void create_ast(parse_Tree p, ast a)
{


	a= get_ast();
	//printf("MEMEORY ALLOCATED\n");
	a->head=p->head;
	a->temp=p->head;
	p->temp=p->head;
	
	shift_empty(p);
	p->temp=p->head;
	// checking for this
	shift_ast(p);
	 p->temp=p->head;
	  
	  shift_assign(p);
	  p->temp=p->head;
	 //printf("lallla\n");
	  
  shift_conditions(p);
	 p->temp=p->head;
	  
	  shift_operators(p);
 p->temp=p->head;
	
}

//--------------------------------------------------------------------------------------------------------------///


ast get_ast()

{
	ast a;
	//printf("lallla\n");
	a=(ast)malloc(sizeof (parse_tree));
	//printf("lallla\n");
	a->head=NULL;
	a->size=0;
	a->temp=NULL;
	return a;
}

//  Handlng the Tokens that are useless


void shift_empty(parse_Tree p)
{
	Node current;
	int curr_pos;
	int i=0;
	if(p->temp->children[0]==NULL)
	{
		if( ! strcmp(p->temp->info.token_name,"TK_EMPTY")||! strcmp(p->temp->info.token_name,"TK_SEMI")||
		! strcmp(p->temp->info.token_name,"TK_COMMA")|| ! strcmp(p->temp->info.token_name,"TK_COLON")||
		! strcmp(p->temp->info.token_name,"TK_LPAR")|| ! strcmp(p->temp->info.token_name,"TK_RPAR")||
		! strcmp(p->temp->info.token_name,"TK_LBRA")|| ! strcmp(p->temp->info.token_name,"TK_RBRA")||
		! strcmp(p->temp->info.token_name,"TK_NL"))
		{
				while(p->temp->parent->number_children<=1)
				{
			//	printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
					current = p->temp;
					p->temp = p->temp->parent;
					free(current);
				}
				curr_pos = p->temp->position_children;
				current=p->temp;
				p->temp=p->temp->parent;
				free(current);
				
				p->temp->number_children = p->temp->number_children -1;
				for( i= curr_pos; i<(p->temp->number_children) ; i++)
				{
					p->temp->children[i]=p->temp->children[i+1];
					//printf("lallla\n");
				}
				for( i= curr_pos; i<(p->temp->number_children) ; i++)
				{
					//printf("lallla\n");
					p->temp->children[i]->position_children=p->temp->children[i]->position_children-1;
				}
				shift_empty(p);
		}
		else
		{
			if(!strcmp(p->temp->info.token_name,"TK_STOP")&& !remaining(p))
			return ;
			
			balance_pos(p);
			shift_empty(p);
		}
	}
	else 
	{
		p->temp = p->temp->children[0];
		shift_empty(p);
	}
	return ;
}

//----------------------------------------------------------------------------------------------------//




void shift_ast(parse_Tree p)
{
	Node current;
	char parent[50];
	int i=0;
	if(p->temp->children[0]==NULL)
	{
		if( ! strcmp(p->temp->info.token_name,"TK_STOP") && !remaining(p))
		return;
		if(p->temp->parent->number_children>1)
		{
//		printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
			balance_pos(p);
			shift_ast(p);
		}
		else
		{
			while(p->temp->parent->number_children <=1)
			{
				strcpy(parent, p->temp->parent->info.parent_node);
				p->temp->parent->info=p->temp->info;
				strcpy(p->temp->parent->info.parent_node,parent);
				p->temp->parent->number_children = 0;
				p->temp->parent->children[0]=NULL;
				current=p->temp;
				p->temp=p->temp->parent;
				free(current);
			}
		}
		if(  strcmp(p->temp->info.token_name,"TK_STOP") || remaining(p))
		balance_pos(p);
		shift_ast(p);
	}
	else
	{
		if(strcmp(p->temp->info.token_name,"program"))
		{
			if((p->temp->parent->number_children ==1) && (p->temp->number_children >1))
			{
				while(p->temp->parent->number_children==1)
				{
						if(!strcmp(p->temp->parent->info.token_name,"program"))
						{
						strcpy(parent,p->temp->parent->info.parent_node);
						p->temp->parent->info= p->temp->info;
						strcpy(p->temp->parent->info.parent_node,parent);
						p->temp->parent->number_children =p->temp->number_children ;
						
					//	printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
						for(i=0;i<p->temp->number_children;i++)
						{
							p->temp->parent->children[i]=p->temp->children[i];
							p->temp->children[i]->parent=p->temp->parent;
						}
						current=p->temp;
						p->temp=p->temp->parent;
						free(current);
						break;
						}
						else
						{
						strcpy(parent,p->temp->parent->info.parent_node);
						p->temp->parent->info= p->temp->info;
						strcpy(p->temp->parent->info.parent_node,parent);
						p->temp->parent->number_children =p->temp->number_children ;
					
						
						for(i=0;i<p->temp->number_children;i++)
						{
							p->temp->parent->children[i]=p->temp->children[i];
							p->temp->children[i]->parent=p->temp->parent;
						}
						
						current=p->temp;
						p->temp=p->temp->parent;
						free(current);
						
						}
			}
			}
			
		}
		
		p->temp=p->temp->children[0];
		shift_ast(p);
	}
	return;
}


//-----------------------------------------------------------------------------------------------//

//Handling assign operator

void shift_assign(parse_Tree p)
{
	char parent[50];
	int i=0;
	int curr_pos =0;
	Node current;
	
	if(p->temp->children[0]==NULL)
	{
		if( !strcmp(p->temp->info.token_name,"TK_ASSIGN"))
		{
		
		//printf("shefali");
						strcpy(parent,p->temp->parent->info.parent_node);
						p->temp->parent->info= p->temp->info;
						strcpy(p->temp->parent->info.parent_node,parent);
						p->temp->parent->number_children =p->temp->parent->number_children-1 ;
						curr_pos= p->temp->position_children;
						current= p->temp;
						p->temp=p->temp->parent;
						free(current);
						
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]=p->temp->children[i+1];
							
						}
						
				//		printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]->position_children=p->temp->children[i]->position_children-1;
						
						}
						
						for(i=0;i<p->temp->number_children;i++)
						{
						strcpy(p->temp->children[i]->info.parent_node,p->temp->info.lexeme_name);
							
						}
						
		}
		
		if( ! strcmp(p->temp->info.token_name,"TK_STOP") && !remaining(p))
		return;
		balance_pos(p);
		shift_assign(p);
		
	}
	else
	{
			p->temp=p->temp->children[0];
			shift_assign(p);
	}
		return;
}


//----------------------------------------------------------------------------------------------------------//
//printing the ast

void ast_print (ast p,FILE *fp)
{
//printf("INside");

	char blank[]= " #### ";
	char notleaf[]="notleaf";
	int flag=0;
	char leaf[]="leaf";
	//fprintf(fp,"*************************************Printing the Parse Tree ************************************/n/n/n");
	//fprintf(fp," - LEXEME_NAME    -   TOKEN_NAME   -   PARENT_NODE     -     IS_LEAF_NODE     -     LINE_NUMBER      -/n/n");
	
	
	
	if(p->temp->children[0]==NULL)
	{
//	printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
		
	
		//fprintf(fp," - %20s - %20s - %20s - %20s - %20s \n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,leaf,p->temp->info.line_number);
		printf("|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,leaf,p->temp->info.line_nu);
	fprintf(fp,"|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,leaf,p->temp->info.line_nu);
	
	while(!flag)
	{
		//printf("Value of remaining= %d\n",remaining(p));
		//printf("Vlue of token =%s\n",p->temp->info.token_name);
		if(!strcmp(p->temp->info.token_name , "TK_STOP") && (!remaining(p)))
		{
			//printf("shefali\n");
			return;	
		}
		if( (p->temp->position_children)+1 < p->temp->parent->number_children)
		{
			p->temp= p->temp->parent->children[(p->temp->position_children)+1];
			flag=1;
		}
		else
		{
			p->temp= p->temp->parent;
			
		}
		
	}
	ast_print (p,fp);
	}
	else
	{
		if(!strcmp("program",p->temp->info.token_name))
		{
			//fprintf(fp,"- %20s - %20s - %20s - %20s - %20s \n\n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,blank);
			printf("|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,p->temp->info.line_nu);
			fprintf(fp,"|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,p->temp->info.line_nu);
		}
		else
		{
	//	fprintf(fp," - %20s - %20s - %20s - %20s - %20s \n\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,blank);
	printf("|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,p->temp->info.line_nu);	
	fprintf(fp,"|%20s|%20s|%20s|%20s|  %d\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,p->temp->info.line_nu);	
		}
		p->temp = p->temp->children[0];
		ast_print (p,fp);
	}
}


//-------------------------------------------------------------------------------------------------//

// handling relational operators

void shift_conditions(parse_Tree p)
{
		
	char parent[50];
	Node current;
	int curr_pos;
	int i=0;
	
	if(p->temp->children[0]==NULL)
	{
		if( ! strcmp(p->temp->info.token_name,"TK_LT")||! strcmp(p->temp->info.token_name,"TK_LE")||
		! strcmp(p->temp->info.token_name,"TK_EQEQ")|| ! strcmp(p->temp->info.token_name,"TK_GE")||
		! strcmp(p->temp->info.token_name,"TK_NE")|| ! strcmp(p->temp->info.token_name,"TK_GT")||
		! strcmp(p->temp->info.token_name,"TK_AND")|| ! strcmp(p->temp->info.token_name,"TK_OR")
	)
		{
		
		
						strcpy(parent,p->temp->parent->info.parent_node);
						p->temp->parent->info= p->temp->info;
						strcpy(p->temp->parent->info.parent_node,parent);
						p->temp->parent->number_children =p->temp->parent->number_children-1 ;
						curr_pos= p->temp->position_children;
						current= p->temp;
						p->temp=p->temp->parent;
						free(current);
						
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]=p->temp->children[i+1];
							
						}
						
				//		printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]->position_children=p->temp->children[i]->position_children-1;
						
						}
						
						for(i=0;i<p->temp->number_children;i++)
						{
						strcpy(p->temp->children[i]->info.parent_node,p->temp->info.lexeme_name);
							
						}
						
		}
		
		if( ! strcmp(p->temp->info.token_name,"TK_STOP") && !remaining(p))
		return;
		balance_pos(p);
		shift_conditions(p);
		
	}
	else
	{
			p->temp=p->temp->children[0];
			shift_conditions(p);
	}
		return;
		
}

//-----------------------------------------------------------------------------------------------//
	//handling arithmetic operators
		
	void shift_operators(parse_Tree p)
{
		
	char parent[50];
	Node current;
	int curr_pos;
	int i=0;
	
	if(p->temp->children[0]==NULL)
	{
		if( ! strcmp(p->temp->info.token_name,"TK_PLUS")||! strcmp(p->temp->info.token_name,"TK_MINUS")||
		 ! strcmp(p->temp->info.token_name,"TK_MUL")||! strcmp(p->temp->info.token_name,"TK_DIV")
		 ||!strcmp(p->temp->info.token_name,"TK_DOT")
	)
		{
		
		
						strcpy(parent,p->temp->parent->info.parent_node);
						p->temp->parent->info= p->temp->info;
						strcpy(p->temp->parent->info.parent_node,parent);
						p->temp->parent->number_children =p->temp->parent->number_children-1 ;
						curr_pos= p->temp->position_children;
						current= p->temp;
						p->temp=p->temp->parent;
						free(current);
						
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]=p->temp->children[i+1];
							
						}
						
				//		printf("I am %s\n",p->temp->info.lexeme_name);
//	printf("I am %s\n",p->temp->info.token_name);
//	printf("I am %s\n",p->temp->info.parent_node);
//printf("I am %s\n",p->temp->info.line_number);
						for(i=curr_pos;i<p->temp->number_children;i++)
						{
							p->temp->children[i]->position_children=p->temp->children[i]->position_children-1;
						
						}
						
						for(i=0;i<p->temp->number_children;i++)
						{
						strcpy(p->temp->children[i]->info.parent_node,p->temp->info.lexeme_name);
							
						}
						
		}
		
		if( ! strcmp(p->temp->info.token_name,"TK_STOP") && !remaining(p))
		return;
		balance_pos(p);
		shift_operators(p);
		
	}
	else
	{
			p->temp=p->temp->children[0];
			shift_operators(p);
	}
		return;
		
}	
//----------------------------------------------------------------------------------------------------------//

