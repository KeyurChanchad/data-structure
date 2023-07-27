#include <stdio.h>
#define MAX 10
int quaue[MAX];
int rear = -1;
int front = -1;

void addq(int val){
    if ( (rear == MAX-1 && front == 0) || (rear+1 == front))
    {
        printf("Circular Quaue is overflow:\n");
        return; 
    }
    if (rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
   quaue[rear] = val;
   if (front == -1)
   {
       front++;
   }   
}
 
int delq(){
    int tmp;
    if (front == -1)
    {
        printf("Quaue is underflow:\n");
        return 0;
    }
    tmp = quaue[front];
    if (front == rear)
    {
        rear = front = -1;
    }
    else
        if (front == MAX-1)
        {
            front=0;
        }
        else
        {
            front++;
        }   
    return tmp;
}
int main()
{
    int ch, val;
    do
    {
        printf("\n----------MANU--------\n");
        printf("1.addq\n");
        printf("2.delq\n");
        printf("3.exit\n");
        printf("----------------------\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        if (ch==1)
        {
            printf("Enter value:");
            scanf("%d", &val);
            addq(val);
        }
        else if (ch==2)
        {
            val=delq();
            printf("\nYou have delete :%d", val);
        }
        else if (ch==3)
        {
            printf("Good Bye: Keyur!!!\n");
            break;
        }
        else
        {
            printf("Enter a valid number:\n");
        }

    } while (ch!=3);
    return 0;
}