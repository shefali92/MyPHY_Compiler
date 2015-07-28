//Group 12:  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "symbol_table.h"
//#include "semantic_analyzer.h"
//#include "parser.h"
//#include "lexer.h"
//#include "ast.h"
#include"codeGen.h"


void main(int argc, char *argv[]){

			FILE *fp;
			FILE *fp2;
			buffer B;
			FILE *filename,*filename2;
			ast a;
			FPTR fptr;
			SPTR sptr;
		//	printf("Hello inside main\n");
			sptr=symbol_table_create(20,20);
			fptr=global(sptr);
	//		printf("DOne\n");
				char testcopy[]="testcopy.txt";
				parse_Tree PT;
				int T[52][49];
				
				filename=fopen(argv[2],"w");
			//	filename2=fopen(argv[3],"w");
				fp2=fopen("testcopy.txt","r");
				fp=fopen(argv[1],"r");			
			int num;
		printf("Enter the desired Option !!\n\n");
		do{
		
		printf("  1 : Select Option 1 for Lexical Analysis \n  2 : Select Option 2 for Parse Tree \n  3 : Select Option 3 for Abstract Syntax Tree \n  4 : Select Option 4 for Symbol Table \n  5 : Select Option 5 for Semantic Analysis \n  6 : Select Option 6 for Code Generation\n");
		scanf("%d",&num);
		switch(num){
			case 1:
		
				
				//line_number=1;
				//int k=BUFFERSIZE;
				buf=0;
				ahead=0;
				token_info TI;
				printf("***************************LEXICAL ANALYSIS***************************\n\n");
				printf("   LEXEME_NAME    |     TOKEN_NAME  |     LINE_NUMBER |\n\n");
				fprintf(filename,"***************************LEXICAL ANALYSIS***************************\n\n");
				fprintf(filename,"   LEXEME_NAME    |     TOKEN_NAME  |     LINE_NUMBER |\n\n");
				TI=find_next_token(fp,B);
				while(strcmp(TI.lexeme_name,"$")!=0){
		
				printf("| %15s | %15s |    %d\n",TI.lexeme_name,TI.token_name,TI.line);
				fprintf(filename,"| %15s | %15s |    %d\n",TI.lexeme_name,TI.token_name,TI.line);
				TI=find_next_token(fp,B);
				}
				TI=find_next_token(fp,B);
				printf("| %15s | %15s |    %d\n",TI.lexeme_name,TI.token_name,TI.line);
				fprintf(filename,"| %15s | %15s |    %d\n",TI.lexeme_name,TI.token_name,TI.line);
				printf("\n\n\n");
				
				
	
			break;
	
	
			case 2:
						
				create_parsing_table(T);
				PT=parse_input(argv[1],T);
			//	printf("end of parsing\n");
				PT->temp=PT->head;
			//	printf("end of parsing2222\n");
				
				printf("*************************************Printing the Parse Tree*************************************\n\n\n");
	            printf("|           LEXEME_NAME|         TOKEN_NAME   |         PARENT_NODE |       IS_LEAF_NODE |      LINE NUMBER  |\n\n\n");
	           fprintf(filename,"**********************************Printing the Parse Tree**********************************\n\n\n");
	           fprintf(filename,"|           LEXEME_NAME |         TOKEN_NAME |         PARENT_NODE |       IS_LEAF_NODE |      LINE NUMBER |\n\n\n");
				parse_tree_print(PT,filename);
			return;
			 case 3: 
			 
			    create_parsing_table(T);
				PT=parse_input(argv[1],T);
			//	printf("end of parsing\n");
				PT->temp=PT->head;
				create_ast(PT,a);
				printf("*************************************Printing the AST Tree *************************************\n\n\n");
	printf(" |LEXEME_NAME         |TOKEN_NAME          |PARENT_NODE         |IS_LEAF_NODE        |LINE NUMBER\n\n\n");
	fprintf(filename,"*************************************Printing the AST Tree*************************************\n\n\n");
	fprintf(filename," |LEXEME_NAME         |TOKEN_NAME          |PARENT_NODE         |IS_LEAF_NODE        |LINE NUMBER\n\n\n");
				
				ast_print(PT,filename);
				return;
			case 4:
			
			//printf("Hello inside case 4\n");
				create_parsing_table(T);
				PT=parse_input(argv[1],T);
			//	printf("end of parsing\n");
				PT->temp=PT->head;
				create_ast(PT,a);
				//ast_print(PT,filename2);
				PT->temp=PT->head;
				
				add_functions(sptr,fptr,PT);
				
				printf("\n\n***********************************************Printing the Symbol Table*************************************************\n\n\n");
	printf("     LEXEME_NAME     |         TOKEN_NAME   |        SCOPE    |     DATA_TYPE   |     SIZE   |    OFFSET  |   LINE NUMBER\n\n\n");
	fprintf(filename,"*************************************Printing the Symbol Table***************************************\n\n\n");
	fprintf(filename,"     LEXEME_NAME     |         TOKEN_NAME  |           SCOPE    |     DATA_TYPE   |     SIZE   |    OFFSET  |   LINE NUMBER\n\n\n");
				symbol_table_print(sptr,filename);
				
				printf("\n\n");
				fprintf(filename,"\n\n");
				return;
			
			case 5: 
			//printf("Hello inside case 4\n");
				create_parsing_table(T);
				PT=parse_input(argv[1],T);
			//	printf("end of parsing\n");
				PT->temp=PT->head;
				create_ast(PT,a);
				//ast_print(PT,filename2);
				PT->temp=PT->head;
				
				add_functions(sptr,fptr,PT);
				PT->temp=PT->head;
				check_semantic(PT,fptr,sptr);
				return;
				
			case 6 :
			
				create_parsing_table(T);
				PT=parse_input(argv[1],T);
			//	printf("end of parsing\n");
				PT->temp=PT->head;
				create_ast(PT,a);
				//ast_print(PT,filename2);
				PT->temp=PT->head;
				
				add_functions(sptr,fptr,PT);
				PT->temp=PT->head;
				assembly_code(PT,sptr,filename);
				return;
			
			
			
			
			
			default:
				printf("\nWrong choice!!!Enter Between 1 to 4");
		}
		
	} while(1);
	
	fclose(fp);
		
	fclose(filename);
//	fclose(filename2);
	fclose(fp2);
	
	
	return 0;
}


