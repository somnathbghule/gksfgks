#include <iostream>
#include <stack>
#include <string>
#include "evaluation_of_postfix_expression.h"
#define isoperator( ch ) ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) 
using namespace std;

int evaluation_of_postfix_expression( string str ) {
	stack <int>st;
	for ( string::iterator it=str.begin(); it!=str.end(); ++it ) {
		char ch=*it;
		if( isdigit( ch ) ) {
			int number=0;
			string::iterator tit=it;
			for( tit=it; *tit != ' ' && tit != str.end(); tit++ ) {
				ch=*tit;
				number= number*10 + ch-'0';
			}
			it=tit;
			st.push( number );
			continue;
		} else if ( isoperator( ch ) ) {
			int result=0;
			int number1=st.top();
			st.pop();
			int number2=st.top();
			st.pop();
			//cout<<"number1 "<<number1<<endl;
			//cout<<"operator "<<ch<<endl;
			//cout<<"number2 "<<number2<<endl;
			switch ( ch ) {
				case '+':
					result=number2+number1;
					break;
				case '-':
					result=number2-number1;
					break;
				case '*':
					result=number2*number1;
					break;
				case '/':
					result=number2/number1;
					break;
			}		
			//cout<<"result: "<<result<<endl;
			st.push( result );
		}
	}
	return st.top();
}

void test_evaluation_of_postfix_expression( ) {
	//string str="100 200 + 2 / 5 * 7 +";
	string str="2 3 1 * + 9 -";
	cout<< "eval: "<< evaluation_of_postfix_expression( str ) <<endl;
}

int main( int argc, char **argv ) {
	test_evaluation_of_postfix_expression();
	//return 
	return (0);
}
