#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef double element;

typedef struct stackNode 
{			
element data; 
struct stackNode *link; 
}stackNode; 

stackNode* top;
void push(element item) 
{	
stackNode* temp=(stackNode *)malloc(sizeof(stackNode));
temp->data = item; 
temp->link = top;	
top = temp; 
} 

element pop() 
{ 
element item;
stackNode* temp=top;

if(top == NULL)
{ 	 
printf("\n\n Stack is empty !\n");	 
return 0; 
} 
else 
{ 
item = temp->data;	
top = temp->link;	 
free(temp);				
return item; 
} 
} 

element peek() 
{	
if(top == NULL) 
{		 
printf("\n\n Stack is empty !\n");	 
return 0;	 
} 
else
{ 
return top->data; 
} 
} 

void del() 
{  
stackNode* temp; 

if(top == NULL) 
{		
printf("\n\n Stack is empty !\n");			
} 
else 
{ 
temp = top;	
top = top->link;	 
free(temp); 
} 
} 

void printStack()
{
stackNode* p=top;

printf("\n STACK [ ");

while(p)
{
printf("%f ",p->data);
p = p->link;
}
printf("] ");
}

// ���� ǥ�� ����
element evalPostfix(char *exp)
{
double opr1, opr2;
int value, i=0, count=0;
int length = strlen(exp);
char symbol;

for(i=0; i<length; i++)
{
symbol = exp[i];

if(symbol >= '0' && symbol <= '9')
{
while(exp[i + count] != ' ') // ���� ������ ���� �˻�
{
count++;
}
value = atoi(&exp[i]);
i+=count;
count=0;
push(value);
}
else
{
if(symbol != ' ') // ���� ������ ���� ' ' �� �ƴ� ���쿡�� 
{
opr2 = pop();
opr1 = pop();

switch(symbol)
{
case '+' : push(opr1 + opr2); break;
case '-' : push(opr1 - opr2); break;
case '*' : push(opr1 * opr2); break;
case '/' : push(opr1 / opr2); break;
}
}
}
}
return pop();
}

void postfix_case_bloack(char* postfix, int *p)
{
char temp;

while(1)
{
temp = (char)pop(); // ���ÿ��� �ϳ��� ����

if((temp != '(') && (temp != '{') && (temp != '[')) // ���� ��ȣ�� �ƴ϶���
{
postfix[(*p)++] = temp; // ���� �迭�� ����
postfix[(*p)++] = ' ';
}
else
{
break; 
}
}
}

void postfix_case_operator_1(char* postfix, char symbol, int *p)
{
char temp;

while(1)
{
if(top == NULL)
{
break;
}
temp = (char)pop(); // ���ÿ��� �ϳ��� ����

if(temp == '+' || temp == '-' || temp == '*' || temp == '/') // ���� ��ȣ����
{
postfix[(*p)++] = temp; // ���� �迭�� ����	
postfix[(*p)++] = ' ';
}
else
{
push(temp); // ���� ��ȣ�� �ƴϸ� �ٽ� ���ÿ� ����
break;
}
}
push(symbol); // ���� ���� ��ȣ ����
}

void postfix_case_operator_2(char* postfix, char symbol, int *p)
{
char temp;

while(1)
{
if(top == NULL)
{
break;
}
temp = (char)pop(); // ���ÿ��� �ϳ��� ����

if(temp == '*' || temp == '/') // �켱������ ���� ���� ��ȣ����
{
postfix[(*p)++] = temp; // ���� �迭�� ����		
postfix[(*p)++] = ' ';
}
else
{
push(temp); // ���� ��ȣ�� �ƴϸ� �ٽ� ���ÿ� ���� 
break;
}
}
push(symbol); // ���� ���� ��ȣ ����
}

void postfix_case_default(char* postfix, char symbol, char* exp, int *p, int i)
{
postfix[(*p)++] = symbol; // ���ڸ� ���� �迭�� ����

// ���� ������ ����
if(exp[i+1] == '+' || exp[i+1] == '-' || exp[i+1] == '*' || exp[i+1] == '/' ||
exp[i+1] == ')' || exp[i+1] == '}' || exp[i+1] == ']' || exp[i+1] == '\0')
{
postfix[(*p)++] = ' '; // ���� ����
}
}

// ���� ǥ�⸦ ���� ǥ���� ��ȯ
char* infix_to_postfix(char* exp)
{
int i=0, p=0;
int length = strlen(exp);
char symbol;
char* postfix = (char*)malloc(length * 2);

for(i=0; i<length; i++)
{
symbol = exp[i];

switch(symbol)
{		
case '(' :
case '{' :
case '[' :
push(symbol); // ���� ��ȣ�� ���ÿ� ����
break;

case ')':
case '}':
case ']':
postfix_case_bloack(postfix, &p);
break;

case '+' :			
case '-' :	
postfix_case_operator_1(postfix, symbol, &p);
break;

case '*' :			
case '/' :				
postfix_case_operator_2(postfix, symbol, &p);
break;

default:
postfix_case_default(postfix, symbol, exp, &p, i);
break;
}
}

while(top) // ���ÿ� ���� �ִ� ����
{
postfix[p++] = (char)pop(); // ���� �迭�� ����
postfix[p++] = ' ';
}
postfix[p] = '\0'; // ���� �迭 �������� �� �� ����
return postfix;
}

// ���� �˻�
int syntaxsearch(char *exp)
{
int length = strlen(exp);
int i=0;
int ncount=0;
char symbol, opr;

for(i=0; i<length; i++)
{
symbol = exp[i];

switch(symbol)
{
case '+' : 
case '-' : 
case '*' : 
case '/' : 			
opr = exp[i+1];
if(opr == '+' || opr == '-' || opr == '*' || opr == '/')
{
printf("Operator error");
return -1;
}
break;

case '(' :
case '{' :
case '[' :
push(symbol);
break;

case ')':
if(top == NULL)
{
printf("' ) ' Syntax error!!\n");
return -1;
}
else
{
if(pop() != '(')
{
printf("' ( ' Syntax error!!\n");
return -1;
}
}
break;

case '}':
if(top == NULL)
{
printf("' } ' Syntax error!!\n");
return -1;
}
else
{
if(pop() != '{')
{
printf("' { ' Syntax error!!\n");
return -1;
}
}
break;

case ']':
if(top == NULL)
{
printf("' ] ' Syntax error!!\n");
return -1;
}
else
{
if(pop() != '[')
{
printf("' [ ' Syntax error!!\n");
return -1;
}
}
break;

default:
if(symbol < '0' || symbol > '9')
{
printf("All not number!!\n");
return -1;
}
else
{
ncount++;
}
break;
}
}
if(!ncount || ncount == 1)
{
printf("Nmber is empty or unavailable!!");
return -1;
}
while(top)
{
opr = (char)pop();
if(opr == '(' || opr == '{' || opr == '[' ||
opr == '+' || opr == '-' || opr == '*' || opr == '/')
{
printf("` %c ' syntax error!!\n", opr);
return -1;
}		
}	
return 0;
}

void main(void) 
{ 		
char buf[100 + 1];
char *postfix;
element result;

while(1)
{
printf("�� ���� ǥ������ �Է��ϼ��� [ ����: exit ]\n");
printf("[�Է�]: ");
scanf("%s", buf);
fflush(stdin);

if(!strcmp(buf, "exit"))
{
break;
}

if(syntaxsearch(buf) != -1)
{
postfix = infix_to_postfix(buf);
result = evalPostfix(postfix);

printf("\n���� ǥ���� : %s", buf);
printf("\n���� ǥ���� : %s", postfix);
printf("\n���� �� : %.2lf", result);
}
printf("\nPress Any Key..");
getchar();
system("cls");
}
} 
