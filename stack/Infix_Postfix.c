#include<stdio.h>
#include<ctype.h>   //isdigit(2)== true ,  isalpha(A,a)==true return;
#define MAX 20
char st[MAX];
int top=-1;
int getpriority(char);
char pop();
void push(char);

/************ Main Function ***********************************/
void main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter Any Infix Expression:\n");
    gets(infix);
    strcpy(postfix,"");
    infixtopostfix(infix, postfix);
    printf("\nPostfix Expression is:\n");
    puts(postfix);
}
void infixtopostfix(char *s, char *d)
{
    int i=0, j=0;
    char tmp;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            push(s[i]);
            i++;
        }
        else if(s[i]==')')
        {
            while((top != -1) && (st[top] != '('))
            {
                d[j]=pop();
                j++;
            }
            if(top==-1)
            {
                printf("\nIncorrect Infix Expression");
                return;
            }
            tmp=pop();
            i++;
        }
        else if(isdigit(s[i]) || isalpha(s[i]))
        {
            d[j]=s[i];
            i++;
            j++;
        }
        else if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ||
                s[i] == '%' ||s[i] == '^' ||s[i] == '$')
        {
            while( (top != -1) && (st[top] != '(') && (getpriority(st[top]) >= getpriority(s[i]) ))
            {
                d[j]=pop(st);
                j++;
            }
            push(s[i]);
            i++;
        }
        else
        {
            printf("\n Incorrect Element  In the Expression:");
            return;
        }

    }
    while( (top != -1) && (st[top] != '(') )
        {
            d[j]=pop();
            j++;
        }
        d[j]='\0';
}
/********************* get Priority Function **************************/
int getpriority(char op)
{
    if( op== '$' || op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    else
        return -1;
}
/*********************** Push Function ********************************/
void push(char val)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow:");
        return;
    }
    top++;
    st[top]=val;
}
/************************ POP Function *********************************/
char pop()
{
    char tmp;
    if(top==-1)
    {
        printf("\nStack Underflow:");
        return ' ';
    }
    tmp=st[top];
    top--;
    return tmp;
}

