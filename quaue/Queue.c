#include <stdio.h>
#include <ctype.h>
#define MAX 10
int quaue[MAX];
int front = -1;
int rear = -1;

void addq(int val) {

    if (rear == MAX-1)
    {  
        printf("Quaue overflow:\n");
        return;
    }
    rear++;
    quaue[rear] = val;
    if (front==-1) {
        front++;
    }
}

int delq() {
    int tmp;
    if (front == -1)
    {
        printf("Quaue underflow:\n");
        return 0;
    }
    tmp = quaue[front];
    if (front == rear)
        rear=front= -1;
    else {
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
            printf("\nEnter value:");
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
}