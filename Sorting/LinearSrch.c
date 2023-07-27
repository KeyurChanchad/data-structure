/* Program of Linear Search (Can be used on Any Array Sorted or Unsorted)*/
#include<stdio.h>
void main()
{
    int x[10];
    int i,val;
    // Accepting values for the Array from the User
    for(i=0;i<10;i++)
    {
        printf("Enter Value:");
        scanf("%d",&x[i]);
    }
    // Taking Search Element from the user
    printf("Enter Search Element:");
    scanf("%d",&val);
    for(i=0;i<10;i++)
    {
        if(x[i]==val)
        {
            printf("\nValue found on %d position", i+1);
            break;
        }
    }
    if(i==10)
    {
        printf("\nValue Does not Exists:");
    }
}
