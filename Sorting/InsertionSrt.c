/* Program of Insertion Sort */
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
    //Sorting an array (Remember the loop of I starts from 1
    for(i=1;i<5;i++)
    {
        //Copying x[i] element to variable tmp
        tmp=x[i];
        //If J is greater than 0 and x[J-1]th element is greater than tmp then bring J-1th element to Jth position.
        //Remember the loop of J starts from I and J will be decremented on every iteration.
        for(j=i; j>0 && x[j-1]>tmp; j--)
            x[j]=x[j-1];
        //place tmp to proper position that is Jth position
        x[j]=tmp;

    }
    //Printing Sorted Array
    printf("\n Array After Sorting:\n");
    for(i=0;i<5;i++)
        printf("\t%d",x[i]);
}
