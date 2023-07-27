#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *lptr;
    struct node *rptr;
} *root = NULL;

/********** INSERRT FUNCTION***********/
void insert(int val){
     struct node *new1, *par, *curr;
     int d;
     new1 = (struct node *) malloc (sizeof(struct node));
     new1->data = val; 
     new1->lptr = new1->rptr = NULL;
     if (root == NULL)
     {
            root = new1;
            return;
     }
     curr = root;
     while (curr!=NULL)
     {
         if (val < curr->data)
         {
             d =0;
             par = curr;
             curr = curr->lptr;
         }
         else if (val > curr->data)
         {
             d = 1;
             par = curr;
             curr = curr->rptr;
         }
         else
         {
             printf("Duplicate value not allowed: \n");
             return;
         }
     }

     if (d==0)
     {
         par->lptr = new1;
     }
     else
     {  
         par->rptr = new1;
     }
        
}
/************ Preorder Travarsal Method ************/
void preorder(struct node *r){          // Root-left-Right
    if (r==NULL)
    {
        return;
    }
    printf("%d-->",r->data);
    preorder(r->lptr);
    preorder(r->rptr);   
}
/************ Inorder Travarsal Method ************/
void inorder(struct node *r){               // Left-Root-Right
    if (r == NULL)
    {
        return;
    }
    inorder(r->lptr);
    printf("%d-->",r->data);
    inorder(r->rptr);   
}
/*************** Postorder Travarsal Method **********/
void postorder(struct node *r){             // Left-Right-Root
    if (r == NULL)
    {
        return;
    }
    postorder(r->lptr);
    postorder(r->rptr);   
    printf("%d-->",r->data);
}
void main()
{
    int ch ,val;
    do{
        printf("\n------------Manu----------\n");
        printf(" 1.Insert:\n");
        printf(" 2.Preorder:\n");
        printf(" 3.Inorder:\n");
        printf(" 4.Postorder:\n");
        printf(" 5.Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter any value:\n");
            scanf("%d", &val);
            insert(val);
        }
        else if (ch==2)
        {
            printf("\n");
            preorder(root);
        }
        else if (ch==3)
        {
            printf("\n");
            inorder(root);
        }
        else if (ch==4)
        {
            printf("\n");
            postorder(root);
        }
        else if (ch==5)
        {
            printf("\nGood Bye:");
        }
        else
        {
            printf("invalid choice:\n");
        }  
        
    }while (ch!=5);
}