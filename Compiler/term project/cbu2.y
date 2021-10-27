%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG	0

#define	 MAXSYM	100
#define	 MAXSYMLEN	20
#define	 MAXTSYMLEN	15
#define	 MAXTSYMBOL	MAXSYM/2

#define STMTLIST 500

typedef struct nodeType {
	int token;
	int tokenval;
	struct nodeType *son;
	struct nodeType *brother;
	} Node;

#define YYSTYPE Node*
	
int tsymbolcnt=0;
int errorcnt=0;

FILE *yyin;
FILE *fp;

extern char symtbl[MAXSYM][MAXSYMLEN];
extern int maxsym;
extern int lineno;

void DFSTree(Node*);
Node * MakeOPTree(int, Node*, Node*);
Node * MakeNode(int, int);
Node * MakeListTree(Node*, Node*);
void codegen(Node* );
void prtcode(int, int);
Node * label(Node*);

void	dwgen();
int	gentemp();
void	assgnstmt(int, int);
void	numassgn(int, int);
void	addstmt(int, int, int);
void	substmt(int, int, int);
int		insertsym(char *);
%}

%token	ADD SUB MUL DIV ASSGN ID NUM STMTEND START END ID2 OPEN CLOSE IF GT GE LT LE EQ NQ HERE OPEN2 CLOSE2

%right ASSGN
%left ADD SUB
%left MUL DIV


%%
program	: START stmt_list END	{ if (errorcnt==0) {codegen($2); dwgen();} }
		;

stmt_list:	stmt_list stmt  {$$=MakeListTree($1, $2);}
		|   stmt         	{$$=MakeListTree(NULL, $1);}
		|   error STMTEND   { errorcnt++; yyerrok;}
		;

stmt 	:   ID ASSGN expr STMTEND   { $1->token = ID2; $$=MakeOPTree(ASSGN, $1, $3);}
		|	IF OPEN s_expr CLOSE OPEN2 stmt_list CLOSE2		{ $$=MakeOPTree(IF, $3, label($6)); }
		;
		
s_expr	:	expr GT expr	{ $$=MakeOPTree(GT, $1, $3); }
		|	expr GE expr	{ $$=MakeOPTree(GE, $1, $3); }
		|	expr LT expr	{ $$=MakeOPTree(LT, $1, $3); }
		|	expr LE expr	{ $$=MakeOPTree(LE, $1, $3); }
		|	expr EQ expr	{ $$=MakeOPTree(EQ, $1, $3); }
		|	expr NQ expr	{ $$=MakeOPTree(NQ, $1, $3); }
		;

expr   	:  	 expr ADD term    { $$=MakeOPTree(ADD, $1, $3); }
		|  	 expr SUB term    { $$=MakeOPTree(SUB, $1, $3); }
		|    term
		;

term   	:   term MUL factor   { $$=MakeOPTree(MUL, $1, $3); }
		|   term DIV factor   { $$=MakeOPTree(DIV, $1, $3); }
		|   factor;

factor  :  	OPEN expr CLOSE	{$$=$2;}
		|	ID      { /* ID node is created in lex */ }
		|   NUM      { /* NUM node is created in lex */ }
		;

%%
int main(int argc, char *argv[]) 
{
	printf("\nlovely JY compiler v1.1\n");
	printf("(C) Copyright by JU YEONG SHIN (shinoung2360@cbnu.ac.kr), 2021.\n");
	
	if (argc == 2)
		yyin = fopen(argv[1], "r");
	else {
		printf("Usage: cbu inputfile\noutput file is 'a.asm'\n");
		return(0);
		}
		
	fp=fopen("a.asm", "w");
	
	yyparse();
	
	fclose(yyin);
	fclose(fp);

	if (errorcnt==0) 
		{ printf("Successfully compiled. Assembly code is in 'a.asm'.\n");}
}

yyerror(s)
char *s;
{
	printf("%s (line %d)\n", s, lineno);
}


Node * MakeOPTree(int op, Node* operand1, Node* operand2)
{
Node * newnode;

	newnode = (Node *)malloc(sizeof (Node));
	newnode->token = op;
	newnode->tokenval = op;
	newnode->son = operand1;
	newnode->brother = NULL;
	operand1->brother = operand2;
	return newnode;
}

Node * MakeNode(int token, int operand)
{
Node * newnode;

	newnode = (Node *) malloc(sizeof (Node));
	newnode->token = token;
	newnode->tokenval = operand; 
	newnode->son = newnode->brother = NULL;
	return newnode;
}

Node * MakeListTree(Node* operand1, Node* operand2)
{
Node * newnode;
Node * node;

	if (operand1 == NULL){
		newnode = (Node *)malloc(sizeof (Node));
		newnode->token = newnode-> tokenval = STMTLIST;
		newnode->son = operand2;
		newnode->brother = NULL;
		return newnode;
		}
	else {
		node = operand1->son;
		while (node->brother != NULL) node = node->brother;
		node->brother = operand2;
		return operand1;
		}
}

void codegen(Node * root)
{
	DFSTree(root);
}

void DFSTree(Node * n)
{
	if (n==NULL) return;
	DFSTree(n->son);
	prtcode(n->token, n->tokenval);
	DFSTree(n->brother);
	
}

Node* label(Node* operand1)
{
	Node * node;
	node = (Node *)malloc(sizeof (Node));
	node->token = node-> tokenval = HERE;
	node->son = operand1;
	node->brother = NULL;
	return node;
}

void prtcode(int token, int val)
{
	switch (token) {
	case ID:
		fprintf(fp,"RVALUE %s\n", symtbl[val]);
		break;
	case ID2:
		fprintf(fp, "LVALUE %s\n", symtbl[val]);
		break;
	case NUM:
		fprintf(fp, "PUSH %d\n", val);
		break;
	case ADD:
		fprintf(fp, "+\n");
		break;
	case SUB:
		fprintf(fp, "-\n");
		break;
	case MUL:
		fprintf(fp, "*\n");
		break;
	case DIV:
		fprintf(fp, "/\n");
		break;
	case OPEN:
		fprintf(fp, "\n");
		break;
	case CLOSE:
		fprintf(fp, "\n");
		break;
	case OPEN2:
		fprintf(fp, "\n");
		break;
	case CLOSE2:
		fprintf(fp, "\n");
		break;
	case IF:
		fprintf(fp, "\n");
		break;
	case GT:
		fprintf(fp, "-\nGOMINUS Here\n");
		break;
	case GE:
		fprintf(fp, "-\nGOFALSE There\nGOMINUS Here\nLABEL There\n");
		break;
	case LT:
		fprintf(fp, "-\nGOPLUS Here\n");
		break;
	case LE:
		fprintf(fp, "-\nGOFALSE There\nGOPLUS Here\nLABEL There\n");
		break;
	case EQ:
		fprintf(fp, "-\nGOTRUE Here\n");
		break;
	case NQ:
		fprintf(fp, "-\nGOFALSE Here\n");
		break;
	case HERE:
		fprintf(fp, "LABEL Here\n");
		break;
	case ASSGN:
		fprintf(fp, ":=\n");
		break;
	case STMTLIST:
	default:
		break;
	};
}


/*
int gentemp()
{
char buffer[MAXTSYMLEN];
char tempsym[MAXSYMLEN]="TTCBU";

	tsymbolcnt++;
	if (tsymbolcnt > MAXTSYMBOL) printf("temp symbol overflow\n");
	itoa(tsymbolcnt, buffer, 10);
	strcat(tempsym, buffer);
	return( insertsym(tempsym) ); // Warning: duplicated symbol is not checked for lazy implementation
}
*/
void dwgen()
{
int i;
	fprintf(fp, "HALT\n");
	fprintf(fp, "$ -- END OF EXECUTION CODE AND START OF VAR DEFINITIONS --\n");

// Warning: this code should be different if variable declaration is supported in the language 
	for(i=0; i<maxsym; i++) 
		fprintf(fp, "DW %s\n", symtbl[i]);
	fprintf(fp, "END\n");
}

