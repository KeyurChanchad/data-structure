#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
int top = -1;
int stack[MAX];

void push(char val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow:\n");
        return;
    }
    top++;
    stack[top] = val;
}
char pop()
{
    int tmp;
    if (top == -1)
    {
        printf("Stack underflow:\n");
        return '\0';
    }
    tmp = stack[top];
    top--;
    return tmp;
}
int getpriority(char op)
{
    if (op == '$' || op == '^')
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
void infixtopostfix(char *s, char *d)
{
    int i = 0, j = 0;
    char tmp;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while ((stack[top] != '(') && (top != -1))
            {
                d[j] = pop();
                j++;
            }
            if (top == -1)
            {
                printf("Invalid infix expression:\n");
                break;  
            }
            tmp = pop();
            i++;
        }
        else if (isdigit(s[i]) || isalpha(s[i]))
        {
            d[j] = s[i];
            i++;
            j++;
        }
        else if (s[i] == '$' || s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '%')
        {
            while ( (top!=-1) && (stack[top]!='(') && (getpriority(stack[top]) >= getpriority(s[i])))
            {
               d[j] = pop();
               j++;
            }
            push(s[i]);
            i++;
        }
        else
        {
            printf("Not valid infix expression:\n");
            return;
        }
    }
    while ( (top != -1) && stack[top]!= '(')
    {
       d[j] = pop();
       j++;
    }
    d[j]='\0';
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter any infix expression:\n");
    gets(infix);
    strcpy(postfix, " ");
    infixtopostfix(infix, postfix);
    printf("The postfix expression:\n");
    puts(postfix);
    return 0;
}