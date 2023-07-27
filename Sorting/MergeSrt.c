/*Merge sort */
#include<stdio.h>
//Prototype declaration
void mrg(int *,int, int, int);
void merge_sort(int *, int, int);
//Main function
void main()
{
    int x[10],i,j,k,n;
    printf("Enter Number of Elements you want to Enter:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element for X[%d]",i);
        scanf("%d",&x[i]);
    }
    printf("\nArray Before Sorting:\n");
    for(i=0;i<n;i++)
        printf("\t%d",x[i]);
    //Sorting an array
    merge_sort(x,0,n-1);
     printf("\nArray After Sorting:\n");
    for(i=0;i<n;i++)
        printf("\t%d",x[i]);
}
void merge_sort(int *x, int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        //After calculating MID split the array recursively
        merge_sort(x,beg,mid);
        merge_sort(x,mid+1,end);
        //After completing SPLIT start MERGE process
        mrg(x,beg,mid,end);
    }
}
void mrg(int *x,int beg, int mid, int end)
{
    int i=beg, j=mid+1, k=beg, temp[10];
    /* Array1 is an array from beg to mid, Array2 is an Array from mid+1 to end
    Compare Ith element of the Array1 to Jth element of Array2 and copy the
    smaller element to the temp array at Kth position. */
    while((i<=mid) && (j<=end))
    {
        if(x[i]<x[j])
        {
            temp[k]=x[i];
            i++;
        }
        else
        {
            temp[k]=x[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        //Copying all remaining elements of Array2 to temp array
        while(j<=end)
        {
            temp[k]=x[j];
            k++;
            j++;
        }
    }
    else
    {
        //Copying all remaining elements of Array1 to temp array
        while(i<=mid)
        {
            temp[k]=x[i];
            i++;
            k++;
        }
    }
    //Copy temp array to original array X
    for(i=beg;i<k;i++)
    {
        x[i]=temp[i];
    }
}
