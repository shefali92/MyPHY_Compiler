//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P

#include <stdio.h>
#include<stdlib.h>
#include"lexer.h"

int line_number =1;

FILE *input_string(FILE *fp, buffer input, int k)
{
	int i=buf;
	int j;
	char c;
	while(!feof(fp) && i<k)
	{
		c=getc(fp);
		input[i]=c;
		i++;
	}
	if(feof(fp))
	{
	//printf ("here\n");
		input[i-2]='$';
	}
	// printf(" here222");
	
	return fp;
}

token_info find_next_token(FILE *fp, buffer input)
{
	int k=BUFFERSIZE;
	token_info t;
	t.final=0;
	char lexeme[MAX]={NULL};
	//printf("heyy");
	int l=0;
	if(input[0]==NULL)
	{
		fp=input_string(fp,input,k);
	}
	
	//printf("%d",k);
	
	while(ahead!=k || t.final!=0)
	{
		if(input[buf]=='$')
		{
			exit(0);
		}
		
		while(input[buf]==' '|| input[buf]=='\n' || input[buf]=='#'|| input[buf]=='\t')
		{
			if(input[buf]==' ') // check spaces
			{
				buf++;
				
				ahead++;
				}
				
				
			if(input[buf]=='\t') // check spaces
			{
				buf++;
				
				ahead++;
				}
			if(input[buf]=='\n') //check newline
			{
				buf++;
				ahead++;
				line_number++;
			}
			
			
			if(input[buf]=='#') //check comments
			{
				while(input[buf]!='\n')
				{
					buf++;
				}
				//line_number++;
				ahead=buf+1;
			}
		}
		if(input[buf]=='(') // checking lpar
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_LPAR");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]==')') // checking rpar
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_RPAR");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]=='=') // checking equal equal
		{
			ahead=buf+1;
			lexeme[l]=input[buf];
			
			if(input[ahead]=='=')
			{
				lexeme[l+1]=input[ahead];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_EQEQ");
				t.line=line_number;
				t.final=1;
				buf=ahead+1;
				ahead=buf+1;
				return t;
				break;
			}
			else
			{
				//lex[l+1]=input[ahead];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_ASSIGN");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				//ahead=buf+1;
				return t;
				break;
			}
		}
		
		if(input[buf]=='{') // checking lbrace
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_LBRA");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}	
		if(input[buf]=='}') // checking rbra
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_RBRA");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		
		if(input[buf]==':') // checking colon
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_COLON");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]==';') // checking semicolon
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				t.final=1;buf=ahead;
				ahead++;
				t.line=line_number;
				strcpy(t.token_name,"TK_SEMI");
				return t;
				break;
		}	
		if(input[buf]==',') // checking comma
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_COMMA");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]=='&' && input[buf+1]=='&') // checking and
		{
			
				lexeme[l]=input[buf];
				lexeme[l+1]=input[buf+1];
				
				strcpy(t.lexeme_name,lexeme);
				t.final=1;
				ahead++;
				buf=ahead;
				t.line=line_number;
				strcpy(t.token_name,"TK_AND");
				return t;
				break;
		}
		if(input[buf]=='|' && input[buf+1]=='|') // checking or
		{
			
				lexeme[l]=input[buf];
				lexeme[l+1]=input[buf+1];
				strcpy(t.lexeme_name,lexeme);
				t.final=1;
				ahead++;
				buf=ahead;
				t.line=line_number;
				strcpy(t.token_name,"TK_OR");
				return t;
				break;
		}
		if(input[buf]=='!' && input[buf+1]=='=') // checking NE
		{
			
				lexeme[l]=input[buf];
				lexeme[l+1]=input[buf+1];
				strcpy(t.lexeme_name,lexeme);
				t.final=1;
				ahead++;
				buf=ahead;
				t.line=line_number;
				strcpy(t.token_name,"TK_NE");
				return t;
				break;
		}
		if(input[buf]=='+') // checking PLUS
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_PLUS");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]=='-') // checking MINUS
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_MINUS");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
		if(input[buf]=='*') // checking MUL
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_MUL");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}if(input[buf]=='/') // checking DIV
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_DIV");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}if(input[buf]=='@') // checking MINUS
		{
			
				lexeme[l]=input[buf];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_DOT");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				return t;
				break;
		}
	     if(input[buf]=='<') // checking equal equal
		{
			//ahead=buf+1;
			lexeme[l]=input[buf];
			
			if(input[ahead]=='=')
			{
				lexeme[l+1]=input[ahead];
				t.final=1;
				strcpy(t.token_name,"TK_LE");
				t.line=line_number;
				buf=ahead+1;
				strcpy(t.lexeme_name,lexeme);
				ahead=buf+1;
				return t;
				break;
			}
			else
			{
				//lex[l+1]=input[ahead];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_LT");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				//ahead=buf+1;
				return t;
				break;
			}
		}
		
		if(input[buf]=='>') // checking equal equal
		{
			//ahead=buf+1;
			lexeme[l]=input[buf];
			
			if(input[ahead]=='=')
			{
				lexeme[l+1]=input[ahead];
				t.final=1;
				strcpy(t.token_name,"TK_GE");
				t.line=line_number;
				buf=ahead+1;
				strcpy(t.lexeme_name,lexeme);
				ahead=buf+1;
				return t;
				break;
			}
			else
			{
				//lex[l+1]=input[ahead];
				strcpy(t.lexeme_name,lexeme);
				strcpy(t.token_name,"TK_GT");
				t.line=line_number;
				t.final=1;
				buf=ahead;
				ahead++;
				//ahead=buf+1;
				return t;
				break;
			}
		}
	ahead=buf;
	if(input[ahead]>='0' && input[ahead]<='9') //check numbers
	{
		lexeme[l]=input[ahead];
		l++;
		ahead++;
		while(input[ahead]>='0' && input[ahead]<='9')
		{
			lexeme[l]=input[ahead];
			ahead++;
			l++;
		}
		strcpy(t.token_name,"TK_NUMBERS");
		strcpy(t.lexeme_name,lexeme);
		//printf("rashi\n");
		t.line=line_number;
		buf=ahead;
		t.final=1;
		ahead=buf+1;
		return t;
		break;
	}
		
	////////////// check time ///////////////////////
	
	switch(input[buf])
	{
		case 't'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 'i':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'm':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'e':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_TIME");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
		default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			case 'o':
			
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_TO");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
					
			default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			default:
				break;
		}
		
		////////////////////////////////////////////////////////
		
		//////////////////// start stop step ///////////////////
		
		
		switch(input[buf])
	{
		case 's'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 't':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'a':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'r':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					
					switch(input[ahead]){
				case 't':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_START");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
		default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			case 'e':
			
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'p':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_STEP");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				
			default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			
				case 'o':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'p':
					
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_STOP");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				
			default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
			default:
				break;
				
		}

////////////////////// force ////////////////////

		switch(input[buf])
	{
		case 'f'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 'o':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'r':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'c':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					
					switch(input[ahead]){
				case 'e':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_FORCE");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
		default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					
					break;
				}
			
		
		////////////////////// pow ////////////////////
		
		switch(input[buf])
	{
		case 'p'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 'o':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'w':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_POW");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
		default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					
					break;
				}
				
				//////////////// mass match////////////////
				
				switch(input[buf])
	{
		case 'm'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 'a':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 's':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 's':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_MASS");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
		case 't'://printf("rashi lala");
			//ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				case 'c':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'h':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_MATCH");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
		default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
			
		
				default:
					
					break;
				}
				
				
				///////////////////////// if ip ///////////
				
		switch(input[buf])
	{
		case 'i'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
				
				case 'f':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_IF");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				case 'p':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_IP");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					
					break;
				}
				
				/////////////// range return ret ///////////////
					
		switch(input[buf])
	{
		case 'r'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'e':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 't':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'u':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
					case 'r':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'n':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_RETURN");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				case 't':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_RET");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				case 'a':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'n':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'g':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'e':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_RANGE");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				default:
					
					break;
				}
				
				///////////////////CASE condn //////////
				
			switch(input[buf])
	{
		case 'c'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'a':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 's':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
				
				
				
				
				
				
					switch(input[ahead]){
				
				case 'e':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_CASE");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				case 'l':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
				
				
				
				
				
				
					switch(input[ahead]){
				
				case 'l':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_CALL");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				case 'o':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
					case 'n':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
					case 'd':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'n':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_CONDN");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
					
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				
				default:
					
					break;
				}		
				
			
		/////////// work ////////////////////////
		switch(input[ahead]){
				
		
		case 'w'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'o':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'r':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'k':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_WORK");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
					
				
				
				default:
					
					break;
				}		
					
					
		/////////// quit ////////////////////////
		switch(input[ahead]){
				
		
		case 'q'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'u':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'i':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 't':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_QUIT");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
					
				
				
				default:
					
					break;
				}					
		
					///////////////////op ////////////
					
		switch(input[ahead]){
				
		
		case 'o'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'p':
					
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_OP");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			
				default:
					
					break;
				}	
				
				///////// disp def //////////
				
				switch(input[ahead]){
				
		
		case 'd'://printf("rashi lala");
			ahead=buf;
			lexeme[l]=input[ahead];
			l++;
			ahead++;
			switch(input[ahead]){
			case 'i':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 's':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'p':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_DISP");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
				
			case 'e':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'f':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_DEF");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
			
				default:
					
					break;
				}	
				
				///////// else endif ////////////
				
				switch(input[ahead]){
			case 'e':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'l':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 's':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'e':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ELSE");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				
			case 'n':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'd':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'i':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'f':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ENDIF");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					
					break;
				}
				/////////// len ////////////
				
				switch(input[ahead]){
			case 'l':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				case 'e':
					lexeme[l]=input[ahead];
					l++;
					ahead++;
					switch(input[ahead]){
				
				case 'n':
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_LEN");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					lexeme[l]=input[ahead];
					//l++;
					ahead++;
					strcpy(t.lexeme_name,lexeme);
					strcpy(t.token_name,"TK_ID");
					t.line=line_number;
					t.final=1;
					buf=ahead;
					ahead=buf+1;
					return t;
					break;
				}
				default:
					
					break;
				}
				////////////// id ///////////
				
				
				
				if(input[ahead]>='a' && input[ahead]<='z' ||  input[ahead]>='A' && input[ahead]<='Z')
				{
				lexeme[l]=input[ahead];
				l++;
				ahead++;
				if(input[ahead]>='a' && input[ahead]<='z' || input[ahead]>='A' && input[ahead]<='Z'|| input[ahead]>='0' && input[ahead]<='9')
				{
				while(input[ahead]>='a' && input[ahead]<='z' || input[ahead]>='A' && input[ahead]<='Z'|| input[ahead]>='0' && input[ahead]<='9')
				{				
				lexeme[l]=input[ahead];
			     ahead++;
			     l++;
			     }
			     strcpy(t.token_name,"TK_ID");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead;
			     ahead=buf+1;
			     return t;
			     break;
			     }
			     
				
				else
				{
		          strcpy(t.token_name,"TK_ID");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead;
			     ahead=buf+1;
			     return t;
			     break;
				}}
				
				
				
				/////////////////////////// id2 //////////////////////////
				if(input[buf]=='_')
				{
				lexeme[l]=input[ahead];
			     ahead++;
			     l++;
			     
				if(input[ahead]>='a' && input[ahead]<='z' ||  input[ahead]>='A' && input[ahead]<='Z')
				{
				lexeme[l]=input[ahead];
				l++;
				ahead++;
				if(input[ahead]>='a' && input[ahead]<='z' || input[ahead]>='A' && input[ahead]<='Z'|| input[ahead]>='0' && input[ahead]<='9')
				{
				while(input[ahead]>='a' && input[ahead]<='z' || input[ahead]>='A' && input[ahead]<='Z'|| input[ahead]>='0' && input[ahead]<='9')
				{				
				lexeme[l]=input[ahead];
			     ahead++;
			     l++;
			     }
			     strcpy(t.token_name,"TK_ID2");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead;
			     ahead=buf+1;
			     return t;
			     break;
			     }
			     
				
				else
				{
		          strcpy(t.token_name,"TK_ID2");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead;
			     ahead=buf+1;
			     return t;
			     break;
				}}
				else
				{
				lexeme[l]=input[ahead];
			     ahead++;
			     l++;
			     printf("ERROR : Lexeme %s found in line %d is UNKNOWN !! \n",lexeme,line_number);
			     strcpy(t.token_name,"ERROR");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead+2;
			     ahead=buf+1;
			     return t;
			     break;
				}}
				
				else
				
				{
				
				if(ahead !=k && !(feof(fp)))
				{
				lexeme[l]=input[ahead];
			     ahead++;
			     l++;
			     printf("ERROR : Lexeme %s found in line %d is UNKNOWN !! \n",lexeme,line_number);
			     strcpy(t.token_name,"ERROR");
			     strcpy(t.lexeme_name,lexeme);
			     t.line=line_number;
			     t.final=1;
			     buf=ahead+2;
			     ahead=buf+1;
			     return t;
			     break;
			     
			     }}
				} }	
					
