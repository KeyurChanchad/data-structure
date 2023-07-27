#include <stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;

void push(int val)
{
    if (top==MAX-1)      
    {
        printf("Stack Overflow:\n");
        return;
    }
    top++;
    stack[top]=val;
    printf("The value %d is at position of %d\n",val,top);
}
 
 int pop()
 {
     int tmp;
     if (top==-1 )
     {
         printf("Stack Underflow:\n");
         return 0;
     }
        tmp=stack[top];
        top--;
        return tmp;
 }
 int peep()
 {
     int tmp;
     if (top==-1 )
     {
         printf("Stack Underflow:\n");
         return 0;
     }
        tmp=stack[top];
        return tmp;
     
 }
 void change(int index, int val)
 {
     if (index>=MAX)
     {
         printf("Stack Overflow:\n");
         return;
     }
     stack[index]=val;

    printf("The value %d at position %d:-\n",val,index);
     
 }
int main()
{
    int ch,val,index;
    do
    {
        printf("\n\n------Manu-----\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peep\n");
        printf("4.Replace\n");
        printf("5.Exite\n");
        printf("--------------\n");

        printf("Enter your choice:\n");
        scanf("%d",&ch);
          
          if (ch==1)
          {
              printf("Enter the value:\n");
              scanf("%d",&val);
              push(val);
          }
          if (ch==2)
          {
              val = pop();
              printf("The value you poped is %d :\n",val);
              remove(val);
          }
          else if (ch==3)
          {
              val=peep();
              printf("In stack the value %d at position %d\n",val,top);
          }
          else if (ch==4)
          {
                printf("Enter the index:\n");
                scanf("%d",&index);
                printf("Enter the value:\n");
                scanf("%d",&val);
                change(index,val);
          }   
          else if (ch==5)
          {
              printf("Good Bye:\n");
              break;
          }

    } while (ch!=5);

}