#include<stdio.h>
#include <conio.h>

char expr[20];//array to store entered expression
char stack[20];//store the postfix expression
int precedence(char a,char b)
{//returns true if precedence of operator a is more or equal to than that of b
    if(((a=='+')||(a=='-'))&&((b=='*')||(b=='/')))
    return 0;
    else
    return 1;
}
int i;
int ctr;
int top=-1;//top of postfix stack
int topOper=-1;//top of operator stack
int operate(int a,int b,char oper)
{
    int res=0;
switch(oper)
{
    case '+':res=a+b;break;
    case '-':res=a-b;break;
    case '*':res=a*b;break;//return result of evaluation
    case '/':res=a/b;break;
}
return res;
}
void postfixConvert()
{
char topsymb,operatorStack[20];
ctr=0;
while(expr[ctr]!='\0')
{//read till the end of input
if(expr[ctr]>='0'&&expr[ctr]<='9')
stack[++top]=expr[ctr];//add numbers straightaway
else
{
while(topOper>=0&&precedence(operatorStack[topOper],expr[ctr]))
{//check for the operators of higher precedence and then add them to stack
topsymb=operatorStack[topOper--];
stack[++top]=topsymb;
}
operatorStack[++topOper]=expr[ctr];
}
ctr++;
}
while(topOper>=0)//add remaining operators to stack
stack[++top]=operatorStack[topOper--];
printf("The Resulting Postfix expression for the given infix expression\n%s\n",stack);
}
int main()
{
printf("\t\tExpression Evaluator\n");
printf("This Program Evaluates Basic Expressions(without brackets) with arithmetic operations(+,-,*,/) on single digit operand length below 20\n");
printf("Enter the Expression\n");
scanf("%s",expr);
postfixConvert();//function to convert in postfix form
char oper;
int operand1,operand2;
ctr=0;
int result[2];//stack to keep storing results
int rTop=-1;//top of result stack
while(stack[ctr]!='\0')
{
oper=stack[ctr];
if(oper>='0'&&oper<='9')
result[++rTop]=(int)(oper-'0');//add numbers
else
{//if an operator is encountered than pop twice and push the result of operation to the stack
    operand1=result[rTop--];
    operand2=result[rTop--];
    result[++rTop]=operate(operand2,operand1,oper);
}
ctr++;
}
printf("The result of the expression is\n%d\n",result[0]);
getch();
}


