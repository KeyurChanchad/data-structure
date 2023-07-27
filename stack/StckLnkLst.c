#include<stdio.h>
#include<stdlib.h>
/*********** Defining Structure Node ***********/
struct node
{
    int data;
    struct node *next;
} *top=NULL;
/*********** Push Function ********************/
void push(int val)
{
    struct node *new1;
    new1 = (struct node *) malloc (sizeof(struct node));
    if(new1==NULL)
    {
        printf("\nStack Overflow:");
        return;
    }
    new1->data=val;
    new1->next=NULL;
    top=new1;
}
/************* Pop Function *****************/
int pop()
{
    int tmp;
    struct node *curr;
    if(top==NULL)
    {
        printf("Stack Underflow:");
        return 0;
    }
    curr=top;
    tmp=curr->data;
    top=top->next;
    free(curr);
    return tmp;
}
/************* PEEP Function *****************/
int peep()
{
    int tmp;
    if(top==NULL)
    {
        printf("\nStack UnderFlow:");
        return 0;
    }
    tmp=top->data;
    return tmp;
}
/***************** Change Function ************/
void change(int key, int val)
{
    struct node *curr;
    if(top==NULL)
    {
        printf("Stack is Empty:");
        return;
    }
    curr=top;
    while(curr->data!=key && curr!=NULL)
        curr=curr->next;
    if(curr==NULL)
    {
        printf("Key Does Not Exists:");
        return;
    }
    curr->data=val;
}
/***************** Main Function **************/
void main()
{
    int ch, val, key;
    do
    {
        printf("\n|--------- MENU -----------|");
        printf("\n 1. Push:");
        printf("\n 2. Pop:");
        printf("\n 3. Peep:");
        printf("\n 4. Change:");
        printf("\n 5. Exit");
        printf("\n|--------------------------|");
        printf("\n Enter Your Choice:");
        scanf("%d", &ch);
        if(ch==1)
        {
            printf("Enter Value:");
            scanf("%d", &val);
            push(val);
        }
        else if(ch==2)
        {
            val=pop();
            printf("Value popped is: %d",val);
        }
        else if(ch==3)
        {
            val=peep();
            printf("Value Peeped is: %d",val);
        }
        else if(ch==4)
        {
            printf("Enter Key:");
            scanf("%d", &key);
            printf("Enter Value:");
            scanf("%d", &val);
            change(key,val);
        }
        else if(ch==5)
        {
            printf("\n Good Bye:");
            break;
        }
        else
        {
            printf("\nInvalid Choice:");
        }
    }while(ch!=5);

}
