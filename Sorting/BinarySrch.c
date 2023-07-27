// Program of Binary Search (Can be used only on Sorted Array)
#include<stdio.h>
void main()
{
    int x[10];
    int i,beg,end, mid,val;
    // Accepting values for the Array from the User
    printf("Enter Array elements in Sorted order:\n");
    for(i=0;i<10;i++)
    {
        printf("Enter Value:");
        scanf("%d",&x[i]);
    }
    printf("\nEnter Search Element:");
    scanf("%d",&val);

    //Searching Array elements in the array
    beg=0;
    end=9;
    for(mid=(beg+end)/2;beg<=end;mid=(beg+end)/2)
    {
        if(x[mid]==val)
        {
            printf("\nValue found on %d position:",mid+1);
            break;
        }
        else if(x[mid]<val)
        {
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }

    //If value does not Exists
    if(beg > end)
    {
        printf("\nValue does not Exists:");
    }
}
