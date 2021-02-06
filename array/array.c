#include <stdio.h>
#include <stdlib.h>
#include "fwk.h"

void printArray(  int *arr, int n ){ 
	printf("\n{ ");
	for ( int i=0; i < n; i++ ) {
		printf("%d, ", arr[ i ] );
	}
	printf("\b\b }\n");
}

void swap( int *a, int *b ) {
	int temp = *a;
	*a=*b;
	*b=temp;
}
void rearrangeArray( int *arr, int n ) {
	int index=0;
	for ( int i=0; i<n; i++ ) {
		if ( arr[ i ] < 0 ) {
			if ( i != index )
				swap( &arr[ i ] , &arr[ index ] );
			index++;
		}

	}	
}
void test_rearrangeArray( ) {
	printf(__func__);	
	int arr [] = {-1, 2, -5, 4, 5 };	
	int n = sizeof(arr)/sizeof(*arr); 
	printf("\nBefore");
	printArray( arr, n);
	rearrangeArray( arr, n );
	printf("After");
	printArray( arr, n);


}

bool isKeyPresentInSegments( int *arr, int n,int key, int seg ) {
	for ( int i=0; i<n ; i+=seg ){
		bool isKey=false;
		for( int j=i; j<(i+seg); j++ ) {
			if ( key == arr[ j ] )
				isKey=true;
		}
		if (  isKey == false )
			return false;
	}	
	return true;
}

void findDuplicates( int *arr, int n ) {
    for ( int i=0;i<n;i++ ) {
	    arr[ arr[ i ] % n ] = arr[ arr[ i ] % n ] + n;
    }
    
    for ( int i=0;i<n;i++ ) {
	    if ( arr[ i ] >= 2*n ) {
	    	printf( "%d ",  i  );
	    }
    }

}

void test_findDuplicates( ) {
	int arr[ ] = { 1, 1, 25, 4,25, 5,2 };
	int n = sizeof( arr )/sizeof(*arr);
	findDuplicates( arr, n );
}

int main ( int argc, char **argv ) {
	/*
	//int arr [] = { 3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3 };
	int arr[] = { 21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25};
	//int arr[] = { 5, 8, 7, 12, 14, 3, 9};
	int n = sizeof(arr)/sizeof(*arr); 
	
	if ( isKeyPresentInSegments( arr, n, 23, 5 ) ) {
		printf("isKeyPresentInSegments: true\n");	
	} else 
		printf("isKeyPresentInSegments: false\n");	
	*/
	//test_rearrangeArray();	
	test_findDuplicates();
	//return from main
	return (0);
}
