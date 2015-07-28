//Group 12 :  Team 1 
//Shefali Garg 2011B2A7810P
//Rashi Khandelwal 2011B5A7635P


#include <stdio.h>
#include"parser.h"
#include <stdlib.h>
#include<string.h>
#include<math.h>
//#include "lexer.h"

FILE *input_string(FILE *fp, buffer B, int k);
token_info find_next_token(FILE *fp, buffer input);


void create_parsing_table(int T[][51])
{
    int i,j,k;

    for(i=0;i<=50;i++)
    {
        for(j=0;j<=51;j++)
        T[i][j]=-1;
    }


    //for nonterminal program
       T[0][10]=0;



    //for nonterminal stmt


       T[51][0]=1;
       T[51][1]=2;
       T[51][2]=2;
       T[51][3]=2;
       T[51][4]=2;
       T[51][5]= 2;
       T[51][6]=2;
       T[51][47]=2;
       T[51][11]=10;
       T[51][15]=10;
       T[51][16]=3;
       T[51][17]=5;
       T[51][18]=4;
       T[51][33]=7;
       T[51][34]=6;
       T[51][50]=8;
       T[51][38]=5;
       T[51][42]=4;
       T[51][43]=9;
		
		
    //for nonterminal expst
       T[1][0]=11;
	   T[2][0]=12;

       //for nonterminal operator

      T[3][32]= 18;
      T[3][19]=19;
      T[3][20]=19;
      T[3][21]=19;
      T[3][22]=19;
      T[3][23]=19;
      T[3][24]=19;
      T[3][25]=19;
      T[3][26]=19;
      T[3][27]=19;
      T[3][28]=19;
      T[3][29]=19;
      T[3][30]=19;
       T[3][31]=19;
      

       // FOR NONTERMINAL vectorop
      T[4][32]=20;
       // FOR NON TERMINAL scalarop
      T[5][19]=23;
      T[5][20]=23;
      T[5][21]=21;
      T[5][22]=21;
      T[5][23]=21;
      T[5][24]=21;
      T[5][25]=21;
      T[5][26]=21;
      T[5][28]=22;
      T[5][28]=22;
      T[5][29]=22;
      T[5][30]=22;
      T[5][31]=22;


       // FOR NON TERMINAL assignop
      T[6][27]=24;


        // FOR NON TERMINAL relop
      T[7][21]=25;
      T[7][22]=26;
      T[7][23]=28;
      T[7][24]=27;
      T[7][25]=29;
      T[7][26]=30;

      // FOR NON TERMINAL arithoop
      T[8][28]=31;
      T[8][29]=32;
      T[8][30]=33;
      T[8][31]=34;


       // FOR logicasl
      
      T[9][19]=35;
      T[9][20]=36;

        // FOR NON TERMINAL vardec
      T[10][1]=37;
      T[10][2]=37;
      T[10][3]=37;
      T[10][4]=38;
       T[10][5]=38;
      T[10][47]=38;
      T[10][6]=38;
      T[10][7]=38;
       // FOR NON TERMINAL primdec


      T[11][1]=39;
      T[11][2]=39;
      T[11][3]=39;
       // FOR NON TERMINAL primtypoe

                         
      T[12][1] = 40;
      T[12][3] = 41;
      T[12][2] = 42;


       // FOR NON TERMINAL varinit
      T[13][0]=43;

     /////////////////////////////varinit2
                  T[14][27] = 44;
                  T[14][7]=45;


       //FOR NON TERMINAL deriuived_type2
     T[15][5]=46;
     T[15][47]=46;
	 T[15][4] =47;
     T[15][6] =47;



     //FOR NON TERMINAL derived dec

                  T[16][4] = 49;
                     T[16][6] =49;

     T[16][5]=48;

                  T[16][47] = 48;




     //FOR NON TERMINALscalar dec
     T[17][47]=50;
     T[17][5]=50;




     //FOR NON TERMINAL scalar type
     T[18][47]=52;
     T[18][5]=51;

     //FOR NON TERMINAL vector_type2

    T[19][4] = 54;
    T[19][6]=55;

       //FOR NON TERMINAL vectordec

                  T[20][4] =53;

      T[20][6]=53;


    //FOR NON TERMINAL varlist2
                  T[21][0] = 56;


     // FOR NONTERMINAL varlist22
      T[22][8]=57;
      T[22][7]=58;

       //FOR NON TERMINAL params

                  T[23][1] = 59;
                T[23][2] = 59;
                T[23][3] = 59;
                T[23][4] = 59;
                T[23][47] = 59;
                T[23][6] = 59;
                T[23][5] = 59;
      T[23][13]=60;


     //FOR NON TERMINAL paramlist


        T[24][1] = 61;
                T[24][2] = 61;
                T[24][3] = 61;
                T[24][4] = 61;
                T[24][47] = 61;
                T[24][6] = 61;
                T[24][5] = 61;



      //FOR NON TERMINAL paramlist2

      T[25][8]=62;
      T[25][13]=63;

     //FOR NON TERMINAL paramtypelist
       T[26][1] = 64;
                T[26][2] = 64;
                T[26][3] = 64;
                T[26][4] = 64;
                T[26][47] = 64;
                T[26][6] = 64;
                T[26][5] = 64;


      //FOR NON TERMINAL type

T[27][1]=65;
      T[27][2]=65;
      T[27][3]=65;
      T[27][4] = 66;
                T[27][47] = 66;
                T[27][6] = 66;
                T[27][5] = 66;



     //FOR NON TERMINAL funcstmt

      T[28][43]=67;
      //FOR NON TERMINAL selst

                  T[29][38] = 69;

      T[29][17]=70;

     //FOR NON TERMINAL casebody

                  T[30][41] = 71;

      T[30][36]=72;

     //FOR NON TERMINAL iterat stmt

                  T[31][18] =73 ;

      T[31][42]=74;
     // /FOR NON TERMINAL rangest

                  T[32][18] = 75;
     //FOR NON TERMINAL condnst

                  T[33][42] = 76;





     //FOR NON TERMINAL boolEx

                  T[34][34] = 77;



     //FOR NON TERMINAL logicOp_1

                  T[35][0] = 78;


     //FOR NON TERMINAL ipvar2

                  T[36][9] = 79;

      T[36][7]=80;

      //FOR NON TERMINAL opstmt

      T[37][33]=81;

      //FOR NON TERMINAL outputvar_

      T[38][0]=82;
      T[38][46]=82;

                  T[38][44] = 83;

      //FOR NON TERMINAL Opvar2

                  T[39][9] = 84;

      T[39][7]=85;



      //FOR NON TERMINAL call
      T[40][50]=86;

     //FOR NON TERMINAL args

       T[41][0] = 87;
        T[41][13]=88;




     //FOR NON TERMINAL arglist
           T[42][0]=89;
     //FOR NON TERMINAL arglist2
      T[43][8]=90;
      T[43][13]=91;

      //FOR NON TERMINAL retStmt

      T[44][16]=92;

      //FOR NON TERMINAL retstmt2
      T[45][7]=93;
      T[45][0]=94;


     //FOR NON TERMINAL rettype


                  T[46][43] = 68;


     //FOR NON TERMINAL exp2


                  T[47][27] = 13;

      T[47][19]=14;
      T[47][20]=14;

 T[47][21]=14;
      T[47][22]=14;

 T[47][23]=14;
      T[47][24]=14;

 T[47][25]=14;
      T[47][26]=14;
 T[47][28]=90;
      T[47][29]=14;
 T[47][30]=90;
      T[47][31]=14;
      T[47][32]=14;
    ////////////// for nonassign

    T[48][0]=15;
    T[48][46]=15;
    /////////////////////////non assign 2
T[49][19]=16;
T[49][20]=16;
T[49][21]=16;
T[49][22]=16;
T[49][23]=16;
T[49][24]=16;
T[49][25]=16;
T[49][26]=16;
T[49][28]=16;
T[49][29]=16;
T[49][30]=16;
T[49][31]=16;
T[49][32]=16;
T[49][7]=17;
T[49][13]=17;

T[49][0]=97;
T[49][46]=97;


////////////////////////////////////////////////////////////

//for id

T[50][0]=95;
T[50][46]=96;
}


//// for parsing 

parse_Tree parse_input(char *testcase, int T[][51])
{
	stack s=create_stack(s);
	//s.top=NULL;
	//s.size=0;

	char first[]="program TK_DOLLAR";
	char first2[100]="program";

 	s=string_push(s,first);
 	
 	//print_stack(s);
 	
 	int rule_number=0;
 	int token_numbers=0;
 	char rule[500];
 	char rule_array [100][100];
 	char nonterminal[50];
 	
 	
	parse_Tree ptree;
	

	ptree=(parse_Tree)initialize_ptree();	
//	ptree =(parse_Tree) malloc(sizeof (parse_tree));
//	node_info inf1;
	
	//	ptree->head=NULL;
//	ptree->temp=NULL;	
 //	ptree->head=createnode(inf1,NULL,0);
 	
// 	ptree->temp=createnode(inf1,NULL,0);
 //	ptree->size=0;
 	

//printf(" Shefali  line number =\n");
 	token_list tokens;
 	tokens.head=NULL;
 	tokens.table_size=0;
 	link header=tokens.head;
 	
 	FILE *fp;
 	fp=fopen(testcase, "r");
 	
 	node_info inf;
 	strcpy(inf.lexeme_name,first2); //check
 	inf.line_nu=0;
 	strcpy(inf.token_name,first2); //check
 	strcpy(inf.parent_node,"\0"); 
 	strcpy(inf.node_symbol,first2);
 	inf.is_leaf=FALSE;
 	
 	
 	Node root;
 	root=(Node)createnode(inf,NULL,0);
 	
 	ptree->head=root;
 	ptree->temp=root;
 	ptree->size++;
 	buffer B;
 	
 	token_info t;
 	//printf("hello111");
 //	printf(" shefali line number =\n");
 	t=find_next_token( fp, B); 
 //	printf(" Rashi line number =\n");
 //	 printf(" line number =%d\n",t.line);
 	//printf("token====%s   stack ==%s\n", t.token_name, top(s));	
 //	printf("hello\n");
 	while( strcmp(top(s),"TK_DOLLAR" ) && strcmp(t.token_name,"TK_DOLLAR"))
 	{
 	//print_stack(s);
 		
 //	printf("token====%s   stack ==%s\n", t.token_name, top(s));	
 	//printf("hello222\n");
 	
 		if(strcmp(t.token_name,top(s)))
 		{
 	//	printf("hello444444\n");
 		
 			if( get_Value_NonTerm(top(s))==-1)
 			{
 		//	printf("hel3333lo222\n");
 				printf("This is an Unknown Non Terminal\n");
 				break;
 			}
 			else
 			{
 				rule_number=T[get_Value_NonTerm(top(s))][get_Value_Term(t.token_name)];
 		//		printf("Rule Number=%d\n", rule_number);
 				if(rule_number==-1)
 				{
 					printf("Corresponding to %s and %s \n", top(s),t.token_name); 
 					printf("Error in line %d !! Entry in the parse table does not exist\n", t.line);
 					break;
 				} 
 				strcpy(rule,get_rule(rule_number));
 		//	printf("rule===%s\n",rule);
 				s=pop(s);
 			//	print_stack(s);
 		
 				if(!strcmp(rule,"TK_EMPTY "))
 				{
					
	//		printf("inside tk empty\n");
 					s=string_push(s,rule);
 					token_numbers = tokenizer(rule, rule_array);
 //					printf("token numbers %d\n",token_numbers);
 					node_insert(ptree,rule_array,token_numbers);
 					ptree->temp->info.is_leaf=TRUE;
 					s=pop(s);
 					//print_stack(s);
 					balance_pos(ptree);
 					
 					
 				}
 				else
 				{
 //					printf("here in else\n");
 					s=string_push(s,rule);
 					//printf("******************\n");
 				//	print_stack(s);
 	//				printf("here in else111\n");
 					token_numbers = tokenizer(rule, rule_array);
 		//			printf("token numbers %d",token_numbers);
 			//		printf("here in else222\n");
 					node_insert(ptree,rule_array,token_numbers);
 				//	printf("here in else333\n");
 				}	
 			}	
 		}
 		
 		else
 		{
 			
 		//printf("rashi : lexeme name %s\n",t.lexeme_name);
 		    strcpy(ptree->temp->info.lexeme_name, t.lexeme_name);
 			
 		    ptree->temp->info.line_nu=t.line;
 	//printf("  lexeme = %s line =%d\n",ptree->temp->info.lexeme_name, ptree->temp->info.line_number);
 			strcpy(ptree->temp->info.token_name,t.token_name);
 		
 		//	if(!strcmp(t.token_name,"TK_NUMBERS"))
 		//	{
 			//	ptree->temp->info.number_value=(int)t.lexeme_name;
 		//	}
 		
 		
 			//******************************************************************************//
 	//--------------------------------------------------------------//
 	// ******************************************************************************************************//
 			ptree->temp->info.is_leaf= TRUE;
 			 strcpy(ptree->temp->info.node_symbol,t.token_name);
 			 
 			 s=pop(s);
 			// printf("heheh\n");
 			// print_stack(s);
 			 if(strcmp(top(s),"TK_DOLLAR"))
 			  balance_pos(ptree);
 				else 
 				{
 		//	printf("Shefali\n");
 //			print_stack(s);
 			  	break;
 			 	 }
 			 // printf("hello\n");
 			 	 t=find_next_token(fp,B);
 			//  printf(" Token_line_number\n");
 			 // printf(" lexeme = %s line =%d\n",t.token_name,t.line);
 			
 		}			
 	}
 
 //printf("Krishu\n");
 	//print_stack(s);

 	 // t=find_next_token(fp,B);
 	 // printf("%s\n",t);
 	  if(!strcmp(top(s),"TK_DOLLAR")&& (!strcmp(t.token_name, "TK_STOP")))
 	  printf(" Parsing Successful\n");
 	  else 
 	  {	printf("Parsing Unsuccessful\n");
 	  exit(1);
 	  }
 	  return ptree;
}
 	  
 	
/// creating node
 	
Node createnode(node_info ninfo, Node parent_add, int pos)
{	
	Node n;
	n=(Node)malloc(sizeof(pnode));
	n->info=ninfo;
	//n->parent=(Node)malloc(sizeof (pnode));
	n->parent =parent_add;
	int i;
	for(i=0;i<20;i++)
	{
	//n->children[i]=(Node)malloc(sizeof (pnode));
	n->children[i]=NULL;
	}
	n->number_children = 0;
	n->position_children =pos;
	return n;
}


//////////////// Stack Functions  /////////////////

char* top(stack s)
{
	if(s.top!=NULL)
	return (s.top->token);
	else
	return NULL;
}

//------------------------------------------------------------------------

stack push(stack s, char temptok[50])
{
	
	
	//slink check= (slink) malloc(sizeof(snode));
//	check=s.top;
  //  while(!strcmp(check->token," "))
   // {
   // s=pop(s);
   // }
   
  // printf("hello\n");
   if(top(s)!=NULL ){//printf("%s\n", top(s));
   while((top(s)!=NULL) &&!(strcmp(top(s),"\0")))
  {
	//  printf("hi\n");
   	s=pop(s);
   }
  }
   slink ptr= (slink) malloc(sizeof(snode));
	if(ptr==NULL)
	{
		printf("ERROR ALLOCATING MEMORY\n");
		return s;
	}
    
	else 
	{
		strcpy(ptr->token, temptok);
		ptr->next=s.top;
		s.top=ptr;
		s.size=s.size+1;
		return s;
	}
}
	
//--------------------------------------------------------------------------------

stack pop(stack s)
{
	if(s.top==NULL)
	{
		printf("Stack is empty");
		return s;
	}
	else
	{
		slink ptr =s.top;
		s.top = s.top->next;
		free(ptr);
		s.size=s.size-1;
	//	printf("stack size ---- %d \n",s.size);
		return s;
	}
}


//-------------------------------------------------------------------------------


stack create_stack()
{
	stack s;
	s.top=NULL;
	s.size=0;
	return s;
}


//---------------------------------------------------------------------------
void print_stack(stack s)
{
	//printf("Shefali\n");
	slink current =s.top;
	int count=0;
	while(current !=NULL)
	{
		count++;
		printf("%d %s\n",count,current->token);
		current=current->next;
	}
	if(count==0)
	printf("Stack is Empty");
	else printf("Stack has reached to its End");
}

//-------------------------------------------------------------------------------

stack string_push(stack s, char temptoken[500])
{	
	char string[50];
	char pushs[20][30];
	int i,j=0,k=0;
	for(i=0;i<=strlen(temptoken);i++)
	{
	
		if( temptoken[i]!=' ' && i!= strlen(temptoken) )
		{
			string[k]=temptoken[i];
			k++;
		}
		else
		{
			string[k]='\0';
			strcpy(pushs[j],string);
			k=0;
			j++;
		}
	}
	
	//printf("%d %d %d %d\n",'a' ,'z', 'A','Z');
//char str[100];
	for(i=j;i>=0;i--)
	{s=push(s,pushs[i]);
	
	
//	if( (strcmp(top(s),"z")>0) || (strcmp(top(s),"A")<0)|| ((strcmp(top(s),"Z")>0) && strcmp(top(s),"a")<0) )
//	if(str[0]>'z' || str[0]<'A' || (str[0]>'Z'&& str[0]<'a'))
	//s=pop(s);
//	}
	
	if((get_Value_NonTerm(top(s))==-1) && (get_Value_Term(top(s))==-1) )
	{
	//printf("popping out %s\n",top(s));
	s=pop(s);
	}
	}
	return s;
}
 //-------------------------------------------------------------------------------


//  enumerating non terminals

 
 int get_Value_NonTerm(char* c){
	if(strcmp(c,"program")==0) {return 0;}
 	if(strcmp(c,"expst")==0) {return 1;}
	if(strcmp(c,"exp")==0) {return 2;}
	if(strcmp(c,"operator")==0) {return 3;}
	if(strcmp(c,"vectorop")==0) {return 4;}
	if(strcmp(c,"scalarop")==0) {return 5;}
	if(strcmp(c,"assignop")==0) {return 6;}
	if(strcmp(c,"relop")==0) {return 7;}
	if(strcmp(c,"arithop")==0) {return 8;}
	if(strcmp(c,"logicalop")==0) {return 9;}
	if(strcmp(c,"vardec")==0) {return 10;}
	if(strcmp(c,"primdec")==0) {return 11;}
	if(strcmp(c,"primtype")==0) {return 12;}
	if(strcmp(c,"varinit")==0) {return 13;}
	if(strcmp(c,"varinit2")==0) {return 14;}
	if(strcmp(c,"derivedtype")==0) {return 15;}
	if(strcmp(c,"deriveddec")==0) {return 16;}
	if(strcmp(c,"scalardec")==0) {return 17;}
	if(strcmp(c,"scalartype")==0) {return 18;}
	if(strcmp(c,"vectortype")==0) {return 19;}
	if(strcmp(c,"vectordec")==0) {return 20;}
	if(strcmp(c,"varlist2")==0) {return 21;}
	if(strcmp(c,"varlist22")==0) {return 22;}
	if(strcmp(c,"params")==0) {return 23;}
	if(strcmp(c,"paramlist")==0) {return 24;}
	if(strcmp(c,"paramlist2")==0) {return 25;}
	if(strcmp(c,"paramtypelist")==0) {return 26;}
	if(strcmp(c,"type")==0) {return 27;}
	if(strcmp(c,"funcst")==0) {return 28;}
	if(strcmp(c,"selst")==0) {return 29;}
	if(strcmp(c,"casebody")==0) {return 30;}
	if(strcmp(c,"iteratst")==0) {return 31;}
	if(strcmp(c,"rangest")==0) {return 32;}
	if(strcmp(c,"condnst")==0) {return 33;}
	if(strcmp(c,"inputst")==0) {return 34;}
	if(strcmp(c,"inputvar")==0) {return 35;}
	if(strcmp(c,"inputvar2")==0) {return 36;}
	if(strcmp(c,"outputst")==0) {return 37;}
	if(strcmp(c,"outputvar")==0) {return 38;}
	if(strcmp(c,"outputvar2")==0) {return 39;}
	if(strcmp(c,"call")==0) {return 40;}
	if(strcmp(c,"args")==0) {return 41;}
	if(strcmp(c,"arglist")==0) {return 42;}
	if(strcmp(c,"arglist2")==0) {return 43;}
	if(strcmp(c,"returnst")==0) {return 44;}
	if(strcmp(c,"returnst2")==0) {return 45;}
	if(strcmp(c,"rettype")==0) {return 46;}
	if(strcmp(c,"exp2")==0) {return 47;}	
	if(strcmp(c,"nonassign")==0) {return 48;}
	if(strcmp(c,"nonassign2")==0) {return 49;}
	if(strcmp(c,"id")==0) {return 50;}
	if(strcmp(c,"stmt")==0) {return 51;}
//	printf("sending -1\n");
	return -1;
}

//----------------------------------------------------------------------------------------------------
// enumerating terminals


int get_Value_Term(char *c) {
if(strcmp(c,"TK_ID")==0) {return 0;}
if(strcmp(c,"TK_MASS")==0) {return 1;}
if(strcmp(c,"TK_LEN")==0) {return 2;}
if(strcmp(c,"TK_TIME")==0) {return 3;}
if(strcmp(c,"TK_FORCE")==0) {return 4;}
if(strcmp(c,"TK_POW")==0) {return 5;}
if(strcmp(c,"TK_DISP")==0) {return 6;}
if(strcmp(c,"TK_SEMI")==0) {return 7;}
if(strcmp(c,"TK_COMMA")==0) {return 8;}
if(strcmp(c,"TK_COLON")==0) {return 9;}
if(strcmp(c,"TK_START")==0) {return 10;}
if(strcmp(c,"TK_STOP")==0) {return 11;}
if(strcmp(c,"TK_LPAR")==0) {return 12;}
if(strcmp(c,"TK_RPAR")==0) {return 13;}
if(strcmp(c,"TK_LBRA")==0) {return 14;}
if(strcmp(c,"TK_RBRA")==0) {return 15;}
if(strcmp(c,"TK_RETURN")==0) {return 16;}
if(strcmp(c,"TK_CASE")==0) {return 17;}
if(strcmp(c,"TK_RANGE")==0) {return 18;}
if(strcmp(c,"TK_AND")==0) {return 19;}
if(strcmp(c,"TK_OR")==0) {return 20;}
if(strcmp(c,"TK_LT")==0) {return 21;}
if(strcmp(c,"TK_GT")==0) {return 22;}
if(strcmp(c,"TK_LE")==0) {return 23;}
if(strcmp(c,"TK_GE")==0) {return 24;}
if(strcmp(c,"TK_EQEQ")==0) {return 25;}
if(strcmp(c,"TK_NE")==0) {return 26;}
if(strcmp(c,"TK_ASSIGN")==0) {return 27;}
if(strcmp(c,"TK_PLUS")==0) {return 28;}
if(strcmp(c,"TK_MINUS")==0) {return 29;}
if(strcmp(c,"TK_MUL")==0) {return 30;}
if(strcmp(c,"TK_DIV")==0) {return 31;}
if(strcmp(c,"TK_DOT")==0) {return 32;}
if(strcmp(c,"TK_OP")==0) {return 33;}
if(strcmp(c,"TK_IP")==0) {return 34;}
if(strcmp(c,"TK_STEP")==0) {return 35;}
if(strcmp(c,"TK_DEF")==0) {return 36;}
if(strcmp(c,"TK_ID2")==0) {return 37;}
if(strcmp(c,"TK_IF")==0) {return 38;}
if(strcmp(c,"TK_ELSE")==0) {return 39;}
if(strcmp(c,"TK_ENDIF")==0) {return 40;}
if(strcmp(c,"TK_MATCH")==0) {return 41;}
if(strcmp(c,"TK_CONDN")==0) {return 42;}
if(strcmp(c,"TK_RET")==0) {return 43;}
if(strcmp(c,"TK_NL")==0) {return 44;}
if(strcmp(c,"TK_TO")==0) {return 45;}
if(strcmp(c,"TK_NUMBERS")==0) {return 46;}
if(strcmp(c,"TK_WORK")==0) {return 47;}
if(strcmp(c,"TK_DOLLAR")==0) {return 48;}
if(strcmp(c,"TK_QUIT")==0) {return 49;}
if(strcmp(c,"TK_CALL")==0) {return 50;}
if(strcmp(c,"TK_EMPTY")==0) {return 54;}
return -1;
}

//---------------------------------------------------------------------------------------------------
// enumerating rules


char *get_rule(int parseindex)
{
	char *rule[100];
	int i;
	
	rule[0]="TK_START TK_LPAR params TK_RPAR stmt TK_STOP ";
	rule[1]="expst stmt ";
	rule[2]="vardec stmt ";
	rule[3]="returnst stmt ";
	rule[4]="iteratst stmt ";
	rule[5]="selst stmt ";
	rule[6]="inputst stmt ";
	rule[7]="outputst stmt ";
	rule[8]="call stmt ";
	rule[9]="funcst stmt ";
	rule[10]="TK_EMPTY ";
	rule[11]="exp TK_SEMI ";
	rule[12]="TK_ID exp2 ";
	rule[13]="assignop nonassign ";
	rule[14]="operator nonassign ";
	rule[15]="id nonassign2 ";
	rule[16]="operator nonassign2 ";
	rule[17]="TK_EMPTY ";
	rule[97]="id nonassign2 ";
	rule[18]="vectorop ";
	rule[19]="scalarop ";
	
	rule[20]="TK_DOT ";
	rule[21]="relop ";
	rule[22]="arithop ";
	rule[23]="logicalop ";
	rule[24]="TK_ASSIGN ";
	rule[25]="TK_LT ";
	rule[26]="TK_GT ";
	rule[27]="TK_GE ";
	rule[28]="TK_LE ";
	rule[29]="TK_EQEQ ";
	rule[30]="TK_NE ";
	rule[31]="TK_PLUS ";
	rule[32]="TK_MINUS ";
	rule[33]= "TK_MUL ";
	rule[34]= "TK_DIV ";
	rule[35]= "TK_AND ";
	rule[36]= "TK_OR ";
	rule[37]= "primdec ";
	rule[38]="deriveddec ";
	rule[39]="primtype varinit TK_SEMI ";
	rule[40]="TK_MASS ";
	rule[41]="TK_TIME ";
	rule[42]="TK_LEN ";
	rule[43]="TK_ID varinit2 ";
	rule[44]="TK_ASSIGN nonassign ";
	rule[45]="TK_EMPTY ";
	rule[46]="scalartype ";
	rule[47]="vectortype ";
	rule[48]="scalardec ";
	rule[49]="vectordec ";
	rule[50]="scalartype varinit TK_SEMI ";  
	rule[51]="TK_POW ";
	rule[52]="TK_WORK ";
	rule[53]="vectortype varlist2 TK_SEMI ";
	rule[54]="TK_FORCE ";
	rule[55]="TK_DISP ";
	rule[56]="TK_ID TK_LPAR id TK_COMMA id TK_COMMA id TK_RPAR varlist22 ";
	rule[57]="TK_COMMA TK_ID TK_LPAR id TK_COMMA id TK_COMMA id TK_RPAR varlist22 ";
	rule[58]="TK_EMPTY ";
	rule[59]="paramlist ";
	rule[60]="TK_EMPTY ";
	rule[61]="paramtypelist paramlist2 ";
	rule[62]="TK_COMMA paramtypelist paramlist2 ";
	rule[63]="TK_EMPTY ";
	rule[64]="type id ";
	rule[65]="primtype ";
	rule[66]="derivedtype ";
	rule[67]="rettype TK_ID2 TK_LPAR params TK_RPAR TK_LBRA stmt TK_RBRA TK_QUIT";
	rule[68]="TK_RET type ";
	rule[69]="TK_IF TK_LPAR exp TK_RPAR TK_LBRA stmt TK_RBRA TK_ELSE TK_LBRA stmt TK_RBRA TK_ENDIF ";
	rule[70]="TK_CASE TK_LBRA casebody TK_RBRA ";
	rule[71]="TK_MATCH TK_LPAR exp TK_RPAR TK_COLON TK_LBRA stmt TK_RBRA casebody ";
	rule[72]="TK_DEF TK_COLON TK_LBRA stmt TK_RBRA ";
	rule[73]="rangest ";
	rule[74]="condnst ";
	rule[75]="TK_RANGE TK_LPAR TK_ID TK_ASSIGN id TK_TO id TK_STEP arithop id TK_RPAR TK_LBRA stmt TK_RBRA ";
	rule[76]="TK_CONDN TK_LPAR exp TK_RPAR TK_LBRA stmt TK_RBRA ";
	rule[77]="TK_IP TK_COLON inputvar TK_SEMI ";
	rule[78]="TK_ID inputvar2 ";
	rule[79]="TK_COLON inputvar ";
	rule[80]="TK_EMPTY ";
	rule[81]="TK_OP TK_COLON outputvar TK_SEMI ";
	rule[82]="id outputvar2 ";
	rule[83]="TK_NL ";
	rule[84]="TK_COLON outputvar ";
	rule[85]="TK_EMPTY ";
	rule[86]="TK_CALL TK_ID TK_ASSIGN TK_ID2 TK_LPAR args TK_RPAR TK_SEMI ";
	rule[87]="arglist ";
	rule[88]="TK_EMPTY ";
	rule[89]="id arglist2 ";
	rule[90]="TK_COMMA id arglist2 ";
	rule[91]="TK_EMPTY ";
	rule[92]="TK_RETURN returnst2 ";
	rule[93]="TK_SEMI ";
	rule[94]="nonassign returnst2";
	rule[95]="TK_ID ";
	rule[96]="TK_NUMBERS ";
 return rule[parseindex];
	
}

//--------------------------------------------------------------------------------------------------
// string breaking

int tokenizer ( char *rule, char rule_array[][100] )
{
	//printf("rule== %s\n",rule);
	char string[50];
	int i,j=0,k=0;
	for(i=0;i<strlen(rule);i++)
	{
	
	
		if(rule[i]!=' ' && i!=strlen(rule))
		{
	//		printf("rule[i]=%c\n",rule[i]);
		//	printf("my name\n");
			string[k]=rule[i];
			k++;
	
		}
	
		else
		{
			//printf("rashi\n");
			string[k]='\0';
			strcpy(rule_array[j],string);
	//		printf("rulearray[]==%s\n",rule_array[j]);
			k=0;
			j++;
		//	printf("j==%d\n",j);
		}
		
				
	}
	string[k]='\0';
			strcpy(rule_array[j],string);
		//	printf("rulearray[]==%s\n",rule_array[j]);
			j++;
	return j;
}

// parse tree functions
//---------------------------------------------------------------------------------------------------


parse_Tree initialize_ptree()
{
	parse_Tree ptree;
	ptree=(parse_Tree)malloc(sizeof(parse_tree));
	ptree->head=NULL;
	ptree->temp=NULL;
	ptree->size=0;
	return ptree;
}

//---------------------------------------------------------------------------------------------------

void node_insert (parse_Tree p, char rule_array[][100], int token_numbers)
{
//printf("inside 111\n");
	Node current, newnode;
	int i=0;
	current = p->temp;
	//printf("inside 222 \n");

	
	//printf("inside 33\n");
		node_info n ;
	//	current=(Node)malloc(sizeof (pnode));
	current->number_children = token_numbers;
	//printf("444\n");
	for(i=0;i<token_numbers;i++)
	{
		//printf("555\n");
	//	printf("rule array %s\n",rule_array[i]);
		int len=strlen(rule_array[i]);
//		printf("length %d\n", strlen(rule_array[i]));
		int j;
	 	//for(j=0;j<len;j++)
	 	//{
	 //	printf("hello\n");
	//	if(rule_array[i][j]==' ')
		//continue;
	//	else break;
		//}
		if(len==0 ) 
     	{
	//	printf("Rule is empty");
		current->number_children--;
		break;
		}
		
	
		
		strcpy(n.lexeme_name,rule_array[i]);
		n.line_nu= 0;
		strcpy(n.token_name,rule_array[i]);
	//	n.number_value=0;
		strcpy(n.parent_node,current->info.token_name);
		//n.line_number=current->info.line_number;
		n.is_leaf=FALSE;
	    strcpy(n.node_symbol,rule_array[i]);
		newnode=createnode(n,current,i);
		current->children[i]=newnode;
	}
	p->temp=p->temp->children[0];
	
}


//---------------------------------------------------------------------------------------

void parse_tree_print (parse_Tree p,FILE *fp)
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
		//printf("--------------------------------------------------------------------------------------------\n\n");
		printf("| %20s | %20s | %20s | %20s |  %d  \n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,leaf,p->temp->info.line_nu);
		//fprintf(fp,"--------------------------------------------------------------------------------------------\n\n");
	fprintf(fp,"| %20s | %20s | %20s | %20s |  %d  \n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,leaf,p->temp->info.line_nu);
	
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
	parse_tree_print (p,fp);
	}
	else
	{
		if(!strcmp("program",p->temp->info.token_name))
		{
			//fprintf(fp,"- %20s - %20s - %20s - %20s - %20s \n\n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,blank);
			printf("| %20s | %20s | %20s | %20s |  %d    \n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,p->temp->info.line_nu);
			fprintf(fp,"| %20s | %20s | %20s | %20s |  %d    \n",p->temp->info.lexeme_name,p->temp->info.token_name,blank,notleaf,p->temp->info.line_nu);
		}
		else
		{
	//	fprintf(fp," - %20s - %20s - %20s - %20s - %20s \n\n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,blank);
	printf("| %20s | %20s | %20s | %20s |  %d    \n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,p->temp->info.line_nu);	
	fprintf(fp,"| %20s | %20s | %20s | %20s |  %d    \n",p->temp->info.lexeme_name,p->temp->info.token_name,p->temp->info.parent_node,notleaf,p->temp->info.line_nu);	
		}
		p->temp = p->temp->children[0];
		parse_tree_print (p,fp);
	}
}

//----------------------------------------------------------------------------------------------------

int remaining(parse_Tree p)
{
	//printf("inside remaining\n");
	Node current;
	current= p->temp;
	while(current !=p->head)
	{
		if((current->position_children)+1 < (current->parent->number_children)-1)
		return 1;
		else

{		current  = current->parent;}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------


void balance_pos(parse_Tree p)
{
//printf("balance\n");
	//node_info n;
	//printf("if balance\n");
	Node current;
	//=(Node)createnode(n,NULL,0);
	//printf("if balance\n");
	current = p->temp;
//	printf("if balance\n");
	
	 //current->parent=(Node)malloc(sizeof (pnode));

	if(((current->position_children)+1) <= ((current->parent->number_children)-1))
	
	{
	p->temp=current->parent->children[(current->position_children)+1];
	
	}
	else
	{
	//printf("else balance\n");
		p->temp=p->temp->parent;
		balance_pos(p);
	}
	//printf("Out of balance\n");
}


