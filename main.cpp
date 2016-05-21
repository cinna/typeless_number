/*
 	Author: Cinna Soltanpur
 	Purpose: To test Integer and Fraction objects
 	Day Created: 3/13/16
*/



#include <iostream>
#include <limits.h>
//#include "test.cpp"
#include "number.h" 
//#include "fraction.h" 	
//#include "integer.h" 	
#include "anynumber.h"

using namespace std;



int main(int argc, char const *argv[])
{


	//Quick and dirty test
	//_test(); Costructions: pointer

	AnyNumber N(3);
	AnyNumber N1(-1,0);
	AnyNumber N2(1,0);
	//N=N1;
	cout << ~N <<endl;
	cout << ~N1 <<endl;
	cout << (N1+N1) <<endl;
	cout << N+N+N1+N1 <<endl;
	cout << N+N+N+N <<endl;
	cout << N1 <<endl;
	cout << (N1+N2) <<endl;
	cout << (N==N1) <<endl;
	cout << (N==3) <<endl;
	//Fracton to integer
	AnyNumber N3(1,2); 
	cout << (N3+N3);


	return 0;
}