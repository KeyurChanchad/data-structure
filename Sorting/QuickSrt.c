/* Quick Sort */
#include <stdio.h>
//Prototype declaration of Function split and quick sort
int split ( int*, int, int ) ;
void quicksort ( int *, int , int);
//Main function
void main( )
{
	int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
	int i ;

	printf ( "Quick sort.\n" ) ;
	printf ( "\nArray before sorting:\n") ;

	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;
//Calling quicksort function and passing base address of the array, start and end index of the array
	quicksort ( arr, 0, 9 ) ;

	printf ( "\nArray after sorting:\n") ;

	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;

}

void quicksort ( int *a, int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ; //Recursion of quick sort function from lower to mid -1
		quicksort ( a, i + 1, upper ) ; //Recursion of quick sort function from mid+1 to upper
	}
}

int split ( int a[ ], int lower, int upper )
{
	int pivot, p, q, t ;

	p = lower + 1 ;
	q = upper ;
	pivot = a[lower] ;
//Variable I which is initialized as 0th element is a pivot element
//Start loop of P variable from 1 and loop of Q from 9

	while ( q >= p )
	{
		//if Pth element is smaller than pivot element then continue the loop
		while ( a[p] < pivot )
			p++ ;
        //If Qth element is greater than pivot element then continue the loop
		while ( a[q] > pivot )
			q-- ;
        //When program comes out of both loop swap Pth and Qth elements
		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}
//Finally swap Qth element with pivot element and return the value of Q
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}
