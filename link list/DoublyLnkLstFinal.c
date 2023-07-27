#include<stdio.h>
#include<stdlib.h>
/*********************Defining Structure Node ***********/
struct node
{
    struct node *lptr;
    int data;
    struct node *rptr;
} *first =NULL;
/********************** Create Function ******************/
void create()
{
    struct node *tmp, *new1;
    int n, i;
    if(first!=NULL)
    {
        printf("\nLink List already Exists:");
        return;
    }
    printf("Enter Number of Nodes:");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        if(first==NULL)
        {
            new1=(struct node *)malloc(sizeof(struct node));
            new1->lptr=new1->rptr=NULL;
            first=new1;
            printf("Enter Value:");
            scanf("%d", &new1->data);
        }
        else
        {
            new1->rptr=(struct node *)malloc(sizeof(struct node));
            tmp=new1;
            new1=new1->rptr;
            new1->rptr=NULL;
            new1->lptr=tmp;
            printf("Enter Value:");
            scanf("%d", &new1->data);
        }
    }
}
/**************** Display Function *************************/
void display()
{
    struct node *curr;
    if (first==NULL)
    {
        printf("\nLink List is Empty:");
        return;
    }
    curr=first;
    while(curr!=NULL)
    {
        printf("%d-->",curr->data);
        curr=curr->rptr;
    }
}
/******************** Main Function ************************/
void main()
{
    int val, ch, key;
    do
    {
        printf("\n|----------MENU-------------|");
        printf("\n 1. Create:");
        printf("\n 2. Display:");
        printf("\n 3. Delete:");
        printf("\n 4. Insert At Beginning:");
        printf("\n 5. Insert At End:");
        printf("\n 6. Insert After:");
        printf("\n 7. Insert Before:");
        printf("\n 9. Exit:");
        printf("\n|---------------------------|");
        printf("\n Enter Your Choice:");
        scanf("%d", &ch);
        if(ch==1)
        {
            create();
        }
        else if(ch==2)
        {
            display();
        }
        else if(ch==3)
        {
            printf("Enter Value to Delete:");
            scanf("%d", &val);
            delnode(val);
        }
        else if(ch==4)
        {
            printf("Enter value:");
            scanf("%d",&val);
            insatbeg(val);
        }
        else if(ch==5)
        {
            printf("Enter value:");
            scanf("%d",&val);
            insatend(val);
        }
        else if(ch==6)
        {
            printf("Enter Key:");
            scanf("%d",&key);
            printf("Enter Value:");
            scanf("%d",&val);
            insaft(key,val);
        }
        else if(ch==7)
        {
            printf("Enter Key:");
            scanf("%d",&key);
            printf("Enter Value:");
            scanf("%d",&val);
            insbfr(key,val);
        }
        else if(ch==9)
        {
            printf("\nGood Bye:");
            break;
        }
        else
        {
            printf("Invalid Choice:");
        }
    }while(ch!=9);

}
/****************** Deleting a value from Doubly linked list ****/
void delnode(int val)
{
    struct node *curr;
    if(first ==NULL)
    {
        printf("\nDoubly Linked List is Empty:");
        return;
    }
    curr=first;
    if(first->data==val)
    {
        first=first->rptr;
        first->lptr=NULL;
        free(curr);
        return;
    }
    while(curr->data!=val && curr!=NULL)
        curr=curr->rptr;
    if(curr==NULL)
    {
        printf("\nValue does not Exists:");
        return;
    }
    if(curr->rptr==NULL)
    {
        curr->lptr->rptr=NULL;
        free(curr);
        return;
    }
    curr->lptr->rptr=curr->rptr;
    curr->rptr->lptr=curr->lptr;
    free(curr);
}
/************ Insert at beginning **************/
void insatbeg(int val)
{
    struct node *new1;
    if(first==NULL)
    {
        printf("\nDoubly Linked List is Empty:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=NULL;
    new1->rptr=first;
    first=new1;
}
/************* Insert At End ******************/
void insatend(int val)
{
    struct node *curr, *new1;
    if(first==NULL)
    {
        printf("\nDoubly Linked List is Empty:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    curr=first;
    while(curr->rptr!=NULL)
        curr=curr->rptr;
    curr->rptr=new1;
    new1->lptr=curr;
    new1->rptr=NULL;
}
/************** Insert After ********************/
void insaft(int key, int val)
{
    struct node *curr, *new1;
     if(first==NULL)
    {
        printf("\nDoubly Linked List is Empty:");
        return;
    }
    curr=first;
    while(curr->data!=key && curr!=NULL)
        curr=curr->rptr;
    if(curr==NULL)
    {
        printf("Key does not Exists:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    if(curr->rptr==NULL)
    {
        new1->rptr=NULL;
        new1->lptr=curr;
        curr->rptr=new1;
    }
    else
    {
        new1->rptr=curr->rptr;
        new1->rptr->lptr=new1;
        new1->lptr=curr;
        curr->rptr=new1;
    }
}
/**************** Insert Before ********************/
void insbfr(int key, int val)
{
    struct node *new1,*curr;
    if(first==NULL)
    {
        printf("\nDoubly Linked List is Empty:");
        return;
    }
    curr=first;
    if(first->data==key)
    {
        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=val;
        new1->rptr=first;
        first->lptr=new1;
        new1->lptr=NULL;
        first=new1;
        return;
    }
    while(curr->data!=key && curr!=NULL)
        curr=curr->rptr;
    if(curr==NULL)
    {
        printf("\nKey does not Exists:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=curr->lptr;
    new1->rptr=curr;
    curr->lptr->rptr=new1;
    curr->lptr=new1;
}
