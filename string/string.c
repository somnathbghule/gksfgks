#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print( char *string, int si, int ei ) {
	
	for ( int j=si;j<ei;j++) {
		printf( "%c", string[ j ]);
	}
	printf("\n");
} 

void firstEvenLengthWord( char *string ) {
	int si=0;
	int i=0;
	int len=strlen( string );
	for ( i=0;i<len; i++ ) {
		if ( string[ i ] == ' ' || string[ i ] == '.' || string[ i ] == ',' ) {
			if ( i != si && ( i - si) %2 == 0 ) {
				print( string, si, i );
				break;
			} 
			si=i+1;
		}
	}	
}

void maxEvenLengthWord( char *string ) {
	int si=0;
	int i=0;
	int max=-1;
	int start=0;
	int end=0;
	int len=strlen( string );
	int wLen=0;
	for ( i=0;i<=len; i++ ) {
		if ( string[ i ] == ' ' || string[ i ] == '.' || string[ i ] == ',' || string[ i ] =='\0' ) {
			wLen=i-si;
			if ( i != si && ( i - si) % 2 == 0 ) {
				if ( max < wLen ) {
					start=si;
					end=i;	
					max=wLen;
				}
			} 
			si=i+1;
		}
	}	

	print( string, start, end );
}

char*  removeDuplicates( char str[], int n ) {
	int index=0;
	int i=0;
	char chars_hash[ 256 ]={0};	
	while ( str [ i ] ) {
		char ch = str[ i ];
		if( chars_hash[ ch ]  == 0 ) {
			str[ index++ ] = ch;
			chars_hash[ ch ] = 1;
		}	
		i++;
	}
	printf("index: %d\n", index);
	str[ index ]='\0';
	return str;
} 

int main( int argc, char **argv ) {
	
	char string_[ ] = "my nameee";
	int n=strlen(string_);
	//maxEvenLengthWord( string_ );	
	print( string_ , 0, n );
	char *str=removeDuplicates( string_, strlen( string_ ));
	print( str , 0, n );

	//return (0);
	return (0);
}
