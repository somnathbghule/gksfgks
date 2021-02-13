#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 6
struct stack  {
	int top1;
	int top2;
	int buffer[ MAX_BUF ];
};

stack s={ -1, MAX_BUF};

void push1( int x ) {
	if( s.top1+1  == s.top2  ) {
		printf("stack overflow %s \n", __func__);
	} else {
		s.top1++;
		s.buffer[ s.top1 ]=x;
		printf("%s pushed %d \n", __func__, x);
	}
}

void push2( int x ) {
	if( s.top1 + 1 == s.top2  ) {
		printf("stack overflow %s \n", __func__);
	} else {
		s.top2--;
		s.buffer[ s.top2 ]=x;
		printf("%s pushed %d \n", __func__, x);
	}
}

int pop1( ) {
	int x=-1;
	if( s.top1 < 0 )
		printf("stack empty %s \n", __func__);
	else {
		x=s.buffer[ s.top1-- ];
		printf("%s popped %d \n", __func__, x);
	}
	return x;
}
int pop2( ) {
	int x=-1;
	if( s.top2 > MAX_BUF - 1 )
		printf("stack empty %s \n", __func__);
	else {
		x = s.buffer[ s.top2++ ];
		printf("%s popped %d \n", __func__, x);
	}
	return x;
}

void two_stacks_in_one_array( ) {
	for ( int i=0;i<MAX_BUF/2+1;i++) {
		push1(i+1);
		push2(i+1);
	}
	for ( int i=0;i<MAX_BUF/2+1;i++){
		pop1();
		pop2();
	}
}
