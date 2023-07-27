/* Program of Selection Sort */
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
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(x[i]>x[j])
            {
                //If Ith element is Greater than Jth element then swap the value
                tmp=x[i];
                x[i]=x[j];
                x[j]=tmp;
            }
        }
    }
    //Printing Sorted Array
    printf("\n Array After Sorting:\n");
    for(i=0;i<5;i++)
        printf("\t%d",x[i]);
}
