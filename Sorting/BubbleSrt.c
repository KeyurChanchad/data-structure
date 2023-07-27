/* Program of Bubble Sort */
#include<stdio.h>
void main()
{
    int x[5];
    int i,j,tmp;
    // Accepting values for the Array from the User
    for(i=0;i<5;i++)
    {
        printf("Enter Value:");
        scanf("%d",&x[i]);
    }
    //Printing unsorted array
    printf("\n Array Before Sorting:\n");
    for(i=0;i<5;i++)
        printf("\t%d",x[i]);

    //Sorting an array
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i;j++)
        {
            if(x[j] > x[j+1])
            {
                //If Jth element is Greater than J+1th element then swap the value
                tmp=x[j];
                x[j]=x[j+1];
                x[j+1]=tmp;
            }
        }
    }
    //Printing Sorted Array
    printf("\n Array After Sorting:\n");
    for(i=0;i<5;i++)
        printf("\t%d",x[i]);
}
