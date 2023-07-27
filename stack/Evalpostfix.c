#include <stdio.h>
#include<ctype.h>
#define MAX 20
float stack[MAX];
int top=-1;

void push(float val){
    if (top==MAX-1)
    {
        printf("Stack overflow:\n");
        return;
    }
    top++;
    stack[top] = val;
}
float pop(){
    float tmp;
    if (top==-1)
    {
        printf("Stack underflow:\n");
        return 0.0;
    }
    tmp = stack[top];
    top--;
    return tmp;
}

float postfixtoans(char *s){
    int i=0,j=0;
    float op1, op2, val;
    while (s[i]!='\0')
    {
        if (isdigit(s[i]))
        {
            push( (float)(s[i]-'0') );
        }
        else {
            op2 = pop();
            op1  =pop();
            switch (s[i])
            {
            case '+':
                val = op1 + op2;
                break;

            case '-':
                val = op1 - op2;
                break;

            case '*':
                val = op1 * op2;
                break;

            case '/':
                val = op1 / op2;
                break;

            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(val);
        }
        i++;
    }
    return pop();
    
}

int main()
{
   char postfix[MAX];
   float val;
   printf("Enter postfix :\n"); 
   gets(postfix);
   val = postfixtoans(postfix);
   printf("Answer is : %.2f\n",val);
    return 0;
}