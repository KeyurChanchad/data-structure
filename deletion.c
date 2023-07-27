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
void delete(int arr[], int size, int index){
    for (int i = index; i <= size-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    
}
int main()
{
    int arr[10] = {12, 16, 18, 25};
    int size, element,index, capacity;
    size = 4;
    element = 22;
    index = 2;
    capacity  = 10;
    insert(arr, size, 22 , 2 ,100 );
    size += 1;
    display(arr, size);
    index = 1;
    delete(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}