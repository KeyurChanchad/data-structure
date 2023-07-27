#include<stdio.h>
#define MAX 10

char stack[MAX];
int top=-1;

void push(char val)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow:");
        return;
    }
    top++;
    stack[top]=val;
}

char pop()
{
   char tmp;
    if(top==-1)
    {
        printf("\nStack Underflow:");
        return '\0';
    }
    tmp=stack[top];
    top--;
    return tmp;
}

void main()
{
    char name[MAX];
    int i;
    printf("\nEnter Your Name:");
    scanf("%s", name);
    for(i=0; name[i]!='\0'; i++ )
        push(name[i]);

    printf("\nReverse String is:");

    while(top!=-1)
        printf("%c", pop());
}
