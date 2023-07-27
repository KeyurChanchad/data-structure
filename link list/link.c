#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL;

/* insert value of function*/
void insert(int val)
{
    struct node *new1, *curr;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=val;
    new1->next=NULL;
    if(first==NULL)
    {
        first=new1;
        return;
    }
    curr=first;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=new1;
}

/* display link list*/
void display()
{
    struct node*curr;
    if(first==NULL)
    {
        printf("\nlink list is empty:");
        return;
    }
    curr=first;
    while(curr->next != NULL)
    {
        printf("%d__>",curr->data);
        curr=curr->next;
    }
    printf("%d",curr->data);
}

/* delete a node in link list*/
void delnode(int val)
{
    struct node *curr,*prev;
    if(first==NULL)
    {
        printf("\nlink list is empty:");
        return;
    }
    curr=first;
    if (first->data==val)
    {
        first=first->next;
        free(curr);
        return;
    }

    while(curr->data!=val && curr!=NULL);
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("\n value does not exit:");
        return;
    }
    prev->next=curr->next;
    free(curr);
}

/* insert after function*/
void insaft(int val,int key)
{
    struct node *curr, *new1;
    if(first==NULL)
    {
        printf("\n Link list is empty:");
        return;
    }
    curr=first;
    while(curr->data!=key && curr!=NULL)
    {
        curr=curr->next;
    }
    if (curr==NULL)
    {
        printf("\n Key does not exit:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->next=curr->next;
    curr->next=new1;
}

/* insert before function */
void insbfr(int val, int key)
{
    struct node *new1,*curr,*prev;
    if(first==NULL)
    {
        printf("\nlinked list is empty:");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->next=NULL;
    curr=first;
    if(first->data==key)
    {
        new1->next=first;
        first=new1;
        return;
    }
    while(curr!=NULL && curr->data!=key)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("\nkey does not exist:");
        return;
    }
    prev->next=new1;
    new1->next=curr;
}

//sort linl list
void sort()
{
    struct node *i,*j;
    int tmp;
    if(first==NULL)
    {
        printf("\nlink list is Empty:");
        return;
    }
    if(first->next==NULL)
    {
        return;
    }
    i=first;
    while(i->next!=NULL)
    {
        j=i->next;
        while(j!=NULL)
        {
            if(j->data < i->data)
            {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

// reverse link list
struct node *reverse(struct node *t)
{
    struct node * tmp;
    if(t->next==NULL)
    {
        first=t;
        return t;
    }
    tmp = reverse(t->next);
    tmp->next = t;
    return t;
}

/* main part of function*/

void main ()
{
    int val,ch,prev,key;
    struct node *lst;
    do
    {
     printf("\n------Menu-----");
     printf("\n 1.Insert:\n 2.Display\n 3.Delete\n 4.Insert After\n 5.Insert Before\n 6.Sort\n 7.Reverse\n 8.Exit");
     printf("\n --------------");
     printf("\n Enter your choice:");
     scanf("%d",&ch);
     if (ch==1)
     {
        printf("\n Enter value:");
        scanf("%d",&val);
        insert(val);
     }
     else if(ch==2)
     {
        printf("\n");
        display();
     }
     else if(ch==3)
        {
            printf("which node you want delete:");
            scanf("%d",&val);
            delnode(val);
        }
        else if(ch==4)
        {
            printf("\nEnter value:");
            scanf("%d",&val);
            printf("\nEnter key:");
            scanf("%d",&key);
            insaft(val,key);
        }
        else if(ch==5)
        {
            printf("\nEnter value:");
            scanf("%d",&val);
            printf("\nEnter key:");
            scanf("%d",&key);
            insbfr(val,key);
        }
        else if(ch==6)
        {
            sort();
        }
        else if(ch==7)
        {
            lst=reverse(first);
            lst->next=NULL;
        }

     else if (ch==8)
     {
        printf("\n Good Bye:");
        break;
     }
     else
        printf("\n Invalid choice:");
    }
    while(ch!=8);
}
