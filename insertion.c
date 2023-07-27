#include <stdio.h>
void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int size, int element, int index, int capacity){
    if (size>= capacity)
    {
        printf("Array is overflow:\n");
        return;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}
int main()
{
    int arr[10] = {12, 16, 18, 25};
    int size, element,index, capacity;
    size = 4;
    element = 22;
    index = 1;
    capacity  = 10;
    insert(arr, size, element, index,capacity);
    size += 1;
    display(arr, size);
    return 0;
}