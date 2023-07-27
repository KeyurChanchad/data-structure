#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
} *first = NULL;

void create()
{
    struct node *new1, *tmp;
    int n, i;
    if (first != NULL)
    {
        printf("Link list already exitsts:");
        return;
    }
    printf("Enter number how many node which you want to crate:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (first == NULL)
        {
            new1 = (struct node *)malloc(sizeof(struct node));
            new1->lptr = new1->rptr = NULL;
            first=new1;
            printf("Enter %d value:", i);
            scanf("%d", &new1->data);
        }
        else
        {
            new1->rptr = (struct node *)malloc(sizeof(struct node));
            tmp = new1;
            new1 = new1->rptr;
            new1->rptr = NULL;
            new1->lptr = tmp;
            printf("Enter %d value:", i);
            scanf("%d", &new1->data);
        }
    }
    new1=NULL;
    tmp=NULL;
}
void display()
{
    struct node *curr;
    if (first == NULL)
    {
        printf("Link list is empty:");
        return;
    }
    curr=first;
    while (curr != NULL)
    {
        printf("--%d>", curr->data);
        curr = curr->rptr;
    }
    curr=NULL;
}

void delnode(int val)
{
    struct node *curr;
    if (first == NULL)
    {
        printf("Link list is empty:");
        return;
    }
    curr=first;
    while (curr->data != val && curr != NULL)
    {
        curr = curr->rptr;
    }
    if (first->data==val)
    {
        first=first->rptr;
        first->lptr=NULL;
        free(curr);
        return;
    }
    if (curr->data == val && curr->rptr==NULL)
    {
        curr->lptr->rptr=NULL;
        free(curr);
        return;
    }
    if (curr==NULL)
    {
        printf("Value does not found\n");
        return;
    }
    curr->lptr->rptr = curr->rptr;
    curr->rptr->lptr = curr->lptr;
    free(curr);
    curr=NULL;
}

void insbeg(int val)
{
    struct node *new1;
    if (first==NULL)
    {
        printf("Link list is empty:\n");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=NULL;
    new1->rptr=first;
    first->lptr=new1;
    first=new1;
    new1=NULL;

}
void insend(int val)
{
    struct node *new1, *curr;
    if (first==NULL)
    {
        printf("Link List Is Empty:");
        return;
    }
    curr=first;
    while (curr->rptr!=NULL)
    {
        curr=curr->rptr;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=curr;
    new1->rptr=NULL;
    curr->rptr=new1;
    new1=NULL;
    curr=NULL;
}

void insertafter(int key, int val)
{
    struct node *new1, *curr;
    if (first==NULL)
    {
        printf("Link List is Empty:\n");
        return;
    }
    curr=first;
    while (curr->data!=key && curr!=NULL)
    {
        curr=curr->rptr;
    }
    if (curr==NULL)
    {
        printf("Key does not found:\n");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=curr;
    new1->rptr=curr->rptr;
    curr->rptr=new1;
    new1->rptr->lptr=new1;
    new1=NULL;
    curr=NULL;
}

void insbfr(int key, int val)
{
    struct node *new1, *curr;
    if (first == NULL)
    {
        printf("Link List Is Empty:\n");
        return;
    }
    curr=first;
    if (first->data==key)
    {
        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=val;
        new1->rptr=first;
        first->lptr=new1;
        new1->lptr=NULL;
        first=new1;
        return;
    }
    while (curr->data!=key && curr!=NULL)
    {
        curr = curr->rptr;
    }
    if (curr==NULL)
    {
        printf("Key does not found:\n");
        return;
    }
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=val;
    new1->lptr=curr->lptr;
    new1->rptr=curr;
    curr->lptr->rptr=new1;
    curr->lptr=new1;
}
void main()
{
    int ch, val, key;
    do
    {
        printf("\n |----------Manu---------|");
        printf("\n 1.Create:");
        printf("\n 2.Display:");
        printf("\n 3.Delete:");
        printf("\n 4.Insert at Begging:");
        printf("\n 5.Insert at End:");
        printf("\n 6.Insert After:");
        printf("\n 7.Insert Before:");
        printf("\n 8.Exite:");
        printf("\n------------------------");

        printf("\nEnter your choich:");
        scanf("%d", &ch);

        if (ch == 1)
        {
            create();
        }
        else if (ch == 2)
        {
            display();
        }
        else if (ch == 3)
        {
            printf("Enter value which you want to delete:");
            scanf("%d", &val);
            delnode(val);
        }
        else if (ch == 4)
        {
            printf("Enter value:");
            scanf("%d", &val);
            insbeg(val);
        }
        else if (ch==5)
        {
            printf("Enter value:");
            scanf("%d", &val);
            insend(val);
        }
        else if (ch== 6)
        {
            printf("Enter value:\n");
            scanf("%d", &val);
            printf("Enter key:");
            scanf("%d", &key);
            insertafter(key, val);
        }
        else if (ch == 7)
        {
            printf("Enter value:");
            scanf("%d", &val);
            printf("Enter key:");
            scanf("%d", &key);
            insbfr(key, val);

        }
        else if (ch == 8)
        {
            printf("Good bye:");
            return;
        }
        else
        {
            printf("You have entered invalid choich:");
        }
    } while (ch != 8);
}
