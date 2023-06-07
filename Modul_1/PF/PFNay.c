#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 100
long int stack[MAX]; int top=-1;
char postfix[MAX];

int isFull()
{return(top==MAX-1)?1:0;}

int isEmpty()
{return(top==-1)?1:0;}

int push(long int data)
{ if(isFull())
    {
        printf("Sorry, stack overflow\n");
        exit(1);
    }
    stack[++top] = (int)(postfix[data]-48);
    return 1;
}

void hitung(char input)
{
   long int a,b,j;
   a=stack[top];
   stack[top--]='\0';
   b=stack[top];
   stack[top--]='\0';
   switch(input)
   {
      case '+': j=b+a;
          break;
      case '-': j=b-a;
          break;
      case '*': j=b*a;
          break;
      case '/': j=b/a;
          break;
      case '^': j=b^a;
          break;
      default:
          j=0;
   }
   stack[++top]=j;
}

int main()
{
   printf("%c Postfix : ",16);
   scanf("%[^\n]*c", postfix);
   int i;
   for(i=0;i<strlen(postfix);i++)
   {
      if(postfix[i]>='0' && postfix[i]<='9')
      {
          push(i);
      }
      if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' ||
      postfix[i]=='/' || postfix[i]=='^')
      {
          hitung(postfix[i]);
      }
   }
   printf("\n%c Value  : %ld",16,stack[top]);
   return 0;
}