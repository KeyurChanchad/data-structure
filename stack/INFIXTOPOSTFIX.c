#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
char stack[MAX];
float st[MAX];
int top=-1;
void infixtopostfix(char *, char *);
void push(char);
char pop();
int getpriority(char);
float postfixtoans(char*);

void pushpost(float val){
    if (top==MAX-1)
    {
        printf("Stack overflow:\n");
        return;
    }
    top++;
    st[top] = val;
}
float poppost(){
    float tmp;
    if (top==-1)
    {
        printf("Stack underflow:\n");
        return 0.0;
    }
    tmp = st[top];
    top--;
    return tmp;
}

void main() {
    char infix[MAX], postfix[MAX];
    float val;
    printf("Enter any infix expression:\n");
    gets(infix);              //  A+B*C+D 
    strcpy(postfix, "");
    infixtopostfix(infix, postfix);
    printf("\npostfix expression is :\n");
    puts(postfix);
    val = postfixtoans(postfix);
    printf("Answer is : %.2f\n",val);
}

float postfixtoans(char *s){
    int i=0,j=0;
    float op1, op2, val;
    while (s[i]!='\0')
    {
        if (isdigit(s[i]))
        {
            pushpost( (float)(s[i]-'0') );
        }
        else {
            op2 = poppost();
            op1  =poppost();
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
            pushpost(val);
        }
        i++;
    }
    return poppost();   
}

void infixtopostfix(char *s, char *d) {
    int i=0, j=0;
    char tmp;
    while (s[i]!='\0')
    {
         if (s[i] == '(')
        {
            push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while ((top != -1) && (stack[top]!= '('))
            {
                d[j] = pop();
                j++;
            }
            if (top==-1)
            {
                printf("Incorrect Infix Expression:\n");
                return;
            }
            tmp = pop();
            j++;
        }
        else if (isdigit(s[i]) || isalpha(s[i]))
        {
            d[j] = s[i];
            i++;
            j++;
        }
        else if (s[i]=='$' || s[i]=='^' || s[i]=='%' 
        || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            while ((top != -1) && (stack[top]!='(') && (getpriority(stack[top]) >= getpriority(s[i])))
            {
                d[j] = pop(stack);
                j++;
            }
            push(s[i]);
            i++;
        }
        else
        {
            printf("your infix expression is not correct :\n");
            return;
        }
    }
    while ((top != -1) && (stack[top] !='('))
    {
        d[j] = pop();
        j++;
    }
    d[j]='\0';
}
void push(char val) {
    if (top==MAX-1)
    {
        printf("Stack overflow:\n");
        return;
    }
    top++;
    stack[top] = val;
}
char pop() {
    char tmp;
    if (top==-1)
    {
        printf("Stack underflow:\n");
        return ' ';
    }
    tmp = stack[top];
    top--;
    return tmp;
}
int getpriority(char op) {
    if (op=='$' || op=='^')
        return 3;
    else if (op=='*' || op=='/')
        return 2;
    else if (op=='%')
        return 1;
    else if (op=='+' || op=='-')
        return 0;
    else
        return -1;
}
