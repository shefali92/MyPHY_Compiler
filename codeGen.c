//Group No 12 Team No 1
//Rashi Khandelwal 2011B5A7635P
//Shefali Garg 2011B2A7810P



#include"codeGen.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int label =0;

void assembly_code(ast a , SPTR s, FILE * f)
{
	fprintf(f,".MODEL TINY\n.STACK\n.DATA\n");	
	printf(".MODEL TINY\n.STACK\n.DATA\n");
	declaration_var (s,f);
	fseek(f,0,SEEK_END);
	fprintf(f,".CODE\n.STARTUP\n");
	printf(".CODE\n.STARTUP\n");
	code_generation(a,f);
	fprintf(f,".EXIT\nEND\n");
	printf(".EXIT\nEND\n");
	fclose(f);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void declaration_var (SPTR s, FILE *f)
{
	FPTR fp ;
	fp = s->f;
	int i;
	int j ;
	int k;
	VPTR v;
	
	for (i=0;i<s->size;i++)
	{
		if(!strcmp((fp+i)->fname,"start"))
		{
			v=(fp+i)->v;
			for(j=0;j<(fp->size);j++)
			{
				if(!strcmp((v+j)->token,"INT"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"MASS"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"LEN"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"TIME"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"DISP"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"FORCE"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"WORK"))
				{
						printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if(!strcmp((v+j)->token,"POW"))
				{
					printf("%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
					fprintf(f,"%-10s%10s\n",(v+j)->info.lexeme_name,"DW OH");
				}
				else if((v+j)->s==1)
				{
					printf("%-10s%10s%10s\n",(v+j)->info.lexeme_name,(v+j)->token,"{}");
					fprintf(f,"%-10s%10s%10s\n",(v+j)->info.lexeme_name,(v+j)->token,"{}");
				}
				
			}			
		}
}
		fseek(f,0,SEEK_END);
		return;
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void code_generation(ast a, FILE *f)
{
	int condn =0;
	Node temp_node;
	if(a->temp->children[0]==NULL)
	{
		while(!condn)
		{
			if(!strcmp(a->temp->info.token_name,"TK_STOP") && !remaining(a))
			{
				return ;
			}
			if(a->temp->position_children+1<a->temp->parent->number_children)
			{
				a->temp=a->temp->parent->children[a->temp->position_children+1];
				condn =1;
			}
			else
			{
				a->temp= a->temp->parent;
			}
		}
		code_generation(a,f);
	}
	else
	{
		if(!strcmp(a->temp->info.node_symbol,"program"))
		{
		temp_node=a->temp;	
		statements(a,f);
		a->temp=temp_node;
		a->temp=a->temp->children[0];
		}
		else
		{
			a->temp=a->temp->children[0];
			
		}
		code_generation(a,f);
		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void statements(ast a, FILE * f)
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
				if(!strcmp(a->temp->info.token_name,"TK_ELSE"))
				{
					label=label+1;
					fprintf(f,"\tJMP Label %d\n",label);
					printf("\tJMP Label %d\n",label);
					fprintf(f,"\tLabel %d\n",label-1);
					printf("\t Label %d\n",label-1);
				}
				if(!strcmp(a->temp->info.token_name,"TK_ENDIF"))
				{
					
					fprintf(f,"\tLabel %d\n",label);
					printf("\tLabel %d\n",label);
				}
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
				statements(a,f);
		}
		else
		{
		if(!strcmp(a->temp->info.token_name,"inputst")||!strcmp(a->temp->info.token_name,"outputst"))
		{
			temp_node=a->temp;
			if(!strcmp(a->temp->children[0]->info.node_symbol,"TK_IP"))
			{
				if(f==NULL)
				{
					printf("ERROR FILE POINTER IS NULL\n");
					
				}
				read_generation(a,f);
			}
			if(!strcmp(a->temp->children[0]->info.node_symbol,"TK_OP"))
			{
				if(f==NULL)
				{
					printf("ERROR FILE POINTER IS NULL\n");
					
				}
				write_generation(a,f);
			}
			a->temp=temp_node;
			a->temp=a->temp->children[0];
		}
		else if(!strcmp(a->temp->info.token_name,"TK_ASSIGN"))
		{
				temp_node=a->temp;
				assign_generation(a,f);
				a->temp=temp_node;
				a->temp=a->temp->children[0];
		}
			else if(!strcmp(a->temp->info.token_name,"iteratst"))
		{
				temp_node=a->temp;
				iterat_generation(a,f);
				a->temp=temp_node;
				a->temp=a->temp->children[0];
		}
			else if(!strcmp(a->temp->info.token_name,"selst"))
		{
				temp_node=a->temp;
				sel_generation(a,f);
				a->temp=temp_node;
				a->temp=a->temp->children[0];
		}
		else
		{
			a->temp=a->temp->children[0];
		}
		statements(a,f);
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sel_generation(ast a , FILE *f)
{
	int condn = 0;
	Node temp_node;
		if(a->temp->children[0]==NULL)
		{
			while(!condn)
			{
				if(!strcmp(a->temp->info.token_name,"TK_ENDIF"))
				{
					return;
				}
			
				if(!strcmp(a->temp->info.token_name,"TK_ENDCASE"))
				{
					return;
				}
			
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
			sel_generation(a,f);
		}
		else
		{
		if(!strcmp((a->temp->info.node_symbol),"exp"))
		{	
			//printf("in main = %s\n",AST->temp->info.node_symbol);
			//your code goes here.....
			temp_node = a->temp;
			boolExprGen(a,f);
			//printf("hello\n");
			a->temp = temp_node;
			a->temp = a->temp->parent->children[(a->temp->position_children)+1];
			//printf("in main = %s\n",AST->temp->info.node_symbol);
		}
		else
		{
			a->temp = a->temp->children[0];
		}
		sel_generation(a,f);
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void iterat_generation(ast a , FILE *f)
{
	int condn = 0;
	Node temp_node;
		if(a->temp->children[0]==NULL)
		{
			while(!condn)
			{
				if(!strcmp(a->temp->info.token_name,"TK_ENDWHILE"))
				{
					return;
				}
			
				if(!strcmp(a->temp->info.token_name,"TK_WHILE"))
				{
					label=label+1;
					fprintf(f,"\t Label %d: ",label);
					printf("\t Label %d: ",label);
				}
			
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
			iterat_generation(a,f);
		}
		else
		{
		
		}
}

/////////////////////////////en///////////////////////////////////////////////////////////////////////////////////////////////////

void read_generation(ast a, FILE * f)
{
	
	int condn = 0;
	Node temp_node;
	
	char lexeme[100];
				if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_ID"))
				{
					if(f==NULL)
					printf("FILE IS NULL\n");
					strcpy(lexeme,a->temp->children[1]->info.lexeme_name );
					fprintf(f,"\tMOV AH,1\n\tINT 21H\n\tSUB AX, 48\n\tMOV %s,AX \n",lexeme);
					printf("\tMOV AH,1\n\tINT 21H\n\tSUB AX, 48\n\tMOV %s,AX \n",lexeme);
				}
			
				else
				{
					a->temp=a->temp->children[1];
					strcpy(lexeme,a->temp->children[0]->info.lexeme_name );
					//strcat(lexeme,".");
					//strcat(lexeme,a->temp->children[1]->info.lexeme_name);
					fprintf(f,"\tMOV AH,1\n\tINT 21H\n\tSUB AX, 48\n\tMOV %s,AX \n",lexeme);
					printf("\tMOV AH,1\n\tINT 21H\n\tSUB AX, 48\n\tMOV %s,AX \n",lexeme);
				}
			return;
}
/////////////////////////////en///////////////////////////////////////////////////////////////////////////////////////////////////

void write_generation(ast a, FILE * f)
{
	
	int condn = 0;
	Node temp_node;
	char lexeme[100];
				if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_ID"))
				{
					if(f==NULL)
					printf("FILE IS NULL\n");
					strcpy(lexeme,a->temp->children[1]->info.lexeme_name );
					fprintf(f,"\tMOV DX,%s\n\tADD DX,48\n\tMOV AH,2\n\tINT 21H \n\n",lexeme);
					printf("\tMOV DX,%s\n\tADD DX,48\n\tMOV AH,2\n\tINT 21H \n\n",lexeme);
				}
			
				else
				{
					a->temp=a->temp->children[1];
					strcpy(lexeme,a->temp->children[0]->info.lexeme_name );
					//strcat(lexeme,".");
					//strcat(lexeme,a->temp->children[1]->info.lexeme_name);
					fprintf(f,"\tMOV DX,%s\n\tADD DX,48\n\tMOV AH,2\n\tINT 21H \n\n",lexeme);
					printf("\tMOV DX,%s\n\tADD DX,48\n\tMOV AH,2\n\tINT 21H \n\n",lexeme);
				}
			return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arith_generation(ast a, FILE * f)
{
	int condn = 0;
	Node temp_node;
	char var[50],var2[50];
		if(a->temp->children[0]==NULL)
		{
			while(!condn)
			{
				if(!strcmp(a->temp->info.token_name,"TK_ID" )||!strcmp(a->temp->info.token_name,"TK_NUMBERS" ))
				{
					if(!strcmp(a->temp->info.token_name,"TK_ID" ))
					{
						strcpy(var,a->temp->info.lexeme_name);
					}
					else
					{
						strcpy(var,a->temp->info.lexeme_name);
					}
					
			
						if(!strcmp(a->temp->parent->parent->info.node_symbol,"TK_DIV" ) 
				|| !strcmp(a->temp->parent->children[0]->info.node_symbol,"TK_DIV" ))
					{
				//	printf("Here");
					fprintf(f,"\tDIV AX,%s\n",var);
					printf("\tDIV AX,%s\n",var);
					}
				else	if(!strcmp(a->temp->parent->parent->info.node_symbol,"TK_MINUS" ) 
				|| !strcmp(a->temp->parent->children[0]->info.node_symbol,"TK_MINUS" ))
					{
					//printf("Here");
					fprintf(f,"\tSUB AX,%s\n",var);
					printf("\tSUB AX,%s\n",var);
					}
					else	if(!strcmp(a->temp->parent->parent->info.node_symbol,"TK_PLUS" ) 
				|| !strcmp(a->temp->parent->children[0]->info.node_symbol,"TK_PLUS" ))
					{
					fprintf(f,"\tADD AX,%s\n",var);
					printf("\tADD AX,%s\n",var);
					}
					else	if(!strcmp(a->temp->parent->parent->info.node_symbol,"TK_MUL" ) 
				|| !strcmp(a->temp->parent->children[0]->info.node_symbol,"TK_MUL" ))
					{
					fprintf(f,"\tMUL AX,%s\n",var);
					printf("\tMUL AX,%s\n",var);
					}
					
					else{
					
				///	printf("in else %s",a->temp->parent->info.node_symbol);
					fprintf(f,"\tADD AX,%s\n",var);
					printf("\tADD AX,%s\n",var);
					}
					if(!a->temp->position_children+1<a->temp->parent->number_children)
					return;
					
				}
			if(!a->temp->position_children+1<a->temp->parent->number_children)
					return;
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
			arith_generation(a,f);
		}	
		else
		{
				if(!strcmp(a->temp->info.node_symbol,"" ))
				{
					//fprintf(f,"\tMOV AX,0H\n");
					//printf("\tMOV AX,0H\n");
					//fprintf(f,"\tMOV BX,0H\n");
					//printf("\tMOV BX,0H\n");
					temp_node=a->temp;
					if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_DIV" ))
					{
						if(!strcmp(a->temp->children[0]->info.token_name,"TK_ID" ))
						{
							strcpy(var,a->temp->children[0]->info.lexeme_name);
							strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						else if(!strcmp(a->temp->children[0]->info.token_name,"TK_NUMBERS" ))
						{
								strcpy(var,a->temp->children[0]->info.lexeme_name);
								strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						
						fprintf(f,"\tMOV AX,%s\n",var);
						printf("\tMOV AX,%s\n",var);
						
						fprintf(f,"\tMOV BX,%s\n",var2);
						printf("\tMOV BX,%s\n",var2);
						
						
						fprintf(f,"\tDIV AX,BX\n",var);
						printf("\tDIV AX,BX\n",var);
						a->temp=temp_node;
						a->temp=a->temp->children[1];
						return;
					}
					else if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_MINUS" ))
					{
						if(!strcmp(a->temp->children[0]->info.token_name,"TK_ID" ))
						{
							strcpy(var,a->temp->children[0]->info.lexeme_name);
							strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						else if(!strcmp(a->temp->children[0]->info.token_name,"TK_NUMBERS" ))
						{
								strcpy(var,a->temp->children[0]->info.lexeme_name);
								strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						
						fprintf(f,"\tMOV AX,%s\n",var);
						printf("\tMOV AX,%s\n",var);
						
						fprintf(f,"\tMOV BX,%s\n",var2);
						printf("\tMOV BX,%s\n",var2);
						
						
						fprintf(f,"\tSUB AX,BX\n",var);
						printf("\tSUB AX,BX\n",var);
						a->temp=temp_node;
						a->temp=a->temp->children[1];
						return;
					}
					else if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_MUL" ))
					{
						if(!strcmp(a->temp->children[0]->info.token_name,"TK_ID" ))
						{
							strcpy(var,a->temp->children[0]->info.lexeme_name);
							strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						else if(!strcmp(a->temp->children[0]->info.token_name,"TK_NUMBERS" ))
						{
								strcpy(var,a->temp->children[0]->info.lexeme_name);
								strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						
						fprintf(f,"\tMOV AX,%s\n",var);
						printf("\tMOV AX,%s\n",var);
						
						fprintf(f,"\tMOV BX,%s\n",var2);
						printf("\tMOV BX,%s\n",var2);
						
						
						fprintf(f,"\tMUL AX,BX\n",var);
						printf("\tMUL AX,BX\n",var);
						a->temp=temp_node;
						a->temp=a->temp->children[1];
						return;
					}
					else if(!strcmp(a->temp->children[1]->info.node_symbol,"TK_DOT" ))
					{
						if(!strcmp(a->temp->children[0]->info.token_name,"TK_ID" ))
						{
							strcpy(var,a->temp->children[0]->info.lexeme_name);
							strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						else if(!strcmp(a->temp->children[0]->info.token_name,"TK_NUMBERS" ))
						{
								strcpy(var,a->temp->children[0]->info.lexeme_name);
								strcpy(var2,a->temp->children[1]->children[0]->info.lexeme_name);
						}
						
						fprintf(f,"\tMOV AX,%s\n",var);
						printf("\tMOV AX,%s\n",var);
						
						fprintf(f,"\tMOV BX,%s\n",var2);
						printf("\tMOV BX,%s\n",var2);
						
						
						fprintf(f,"\tDOT AX,BX\n",var);
						printf("\tDOT AX,BX\n",var);
						a->temp=temp_node;
						a->temp=a->temp->children[1];
						return;
					}
					else
					{
						a->temp=temp_node;
						a->temp=a->temp->children[0];
					
					}
				}
				else
				{
						a->temp=a->temp->children[0];
				}
		arith_generation(a,f);
	}
}			
/////////////////////////////////////////////////////////////////////////

void assign_generation(ast a, FILE *f)
{
	fprintf(f,"\tMOV AX,0H\n");
	printf("\tMOV AX,0H\n");
	char result[100];
	
	Node temp_node;
	temp_node=a->temp;
	
		
		
		
		
				if(!strcmp(a->temp->children[0]->info.node_symbol,"TK_ID"))
				{
					if(f==NULL)
					printf("FILE IS NULL\n");
				strcpy(result,a->temp->children[0]->info.lexeme_name);
				}
				else
					{
						//a->temp=a->temp->children[0];
						strcpy(result,a->temp->parent->children[0]->info.lexeme_name);
					//	strcat(result,".");
				//	strcat(result,a->temp->children[1]->info.lexeme_name);
					}
					a->temp=temp_node;
					a->temp=a->temp->children[0];
					arith_generation(a,f);
					fprintf(f,"\tMOV %s, AX\n",result);
					printf("\tMOV %s, AX\n",result);
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void relop_generation(char op[],FILE *f)
{
	//label++;
	if(!strcmp(op,"TK_LT"))
	{
		fprintf(f,"\tJGE label %d\n",label);
		printf("\tJGE label %d\n",label);
	}
	else if(!strcmp(op,"TK_LE"))
	{
		fprintf(f,"\tJG label %d\n",label);
		printf("\tJG label %d\n",label);
	}
	
	else if(!strcmp(op,"TK_EQEQ"))
	{
		fprintf(f,"\tJNE label %d\n",label);
		printf("\tJNE label %d\n",label);
	}
	else if(!strcmp(op,"TK_NE"))
	{
		fprintf(f,"\tJE label %d\n",label);
		printf("\tJE label %d\n",label);
	}
	else if(!strcmp(op,"TK_GT"))
	{
		fprintf(f,"\tJLE label %d\n",label);
		printf("\tJLE label %d\n",label);
	}
	else if(!strcmp(op,"TK_GE"))
	{
		fprintf(f,"\tJL label %d\n",label);
		printf("\tJL label %d\n",label);
	}
}
		

void boolExprGen(ast AST,FILE *f)
{
	//fprintf(f,".CODE\n.STARTUP\n");
	int condition=0;
	Node temp;
	char LHS[50];
	char RHS[50];
	char OP[10];
	//printf("%s\n",AST->temp->info.node_symbol);
	if(AST->temp->children[0] == NULL)
	{
		//while(!condition)
		//{
			//printf("terminals = %s\n",AST->temp->info.token_name);
			
			if((AST->temp->position_children)+1 < AST->temp->parent->number_children)
			{
				AST->temp = AST->temp->parent->children[(AST->temp->position_children)+1];
				condition = 1;
				boolExprGen(AST,f);
			}
			else
				return;
		//}
		
	}
	else
	{	
		//printf("non terminals = %s\n",AST->temp->info.node_symbol);
		if((!strcmp((AST->temp->children[0]->info.node_symbol),"TK_ID")) || (!strcmp((AST->temp->children[0]->info.node_symbol),"TK_NUM")))
		{	
			//printf("in main = %s\n",AST->temp->info.node_symbol);
			//your code goes here.....
			temp = AST->temp;
			if(!strcmp(AST->temp->children[0]->info.token_name,"TK_ID"))
				{
					//strcpy(LHS,"[");
					strcpy(LHS,(AST->temp->children[0]->info.lexeme_name));
					//strcat(LHS,"]");

				}
				else if((!strcmp(AST->temp->children[0]->info.token_name,"TK_NUM")) )
					strcpy(LHS,(AST->temp->children[0]->info.lexeme_name));
				fprintf(f,"\tMOV AX,%s\n",LHS );
				if(!strcmp(AST->temp->children[1]->info.token_name,"TK_ID"))
				{
					//strcpy(RHS,"[");
					strcpy(RHS,(AST->temp->children[1]->info.lexeme_name));
					//strcat(RHS,"]");
				}
				else if((!strcmp(AST->temp->children[1]->info.token_name,"TK_NUM")) )
					strcpy(RHS,(AST->temp->children[1]->info.lexeme_name));
				fprintf(f,"\tMOV BX,%s\n",RHS );
				fprintf(f, "\tCMP AX,BX\n" );
				strcpy(OP,AST->temp->children[1]->info.token_name);
				//printf("%s\n",OP );
				relop_generation(OP,f);
				
			AST->temp = temp;
			AST->temp = AST->temp->children[0];
		}
		else
		{
			AST->temp = AST->temp->children[0];
		}
		boolExprGen(AST,f);
	}
}


