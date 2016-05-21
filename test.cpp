
#include <iostream>
#include "integer.h"
#include "fraction.h"
 
using namespace std;
string _test(bool t){
	if (t) return  "\t...Passed";
		else  return "\t...Failed";
}
void UNIT_TEST()
{
		//_test: adding inf+-inf
	//_test: test operations...
	//_test: add Fraction + Integer
	//_test: cascading effect I+I+I+I...
	//_test: cascading effect I+F == F+I...
	//_test: displaying
	//simple unit test

	//UNIT_TEST();
	//Fraction F(-1,1);
	/*Fraction G(3,2);
	Integer I(2);	
	Integer M(INT_MAX );
	Fraction Inf("inf");

	//Operators
	//operator:display		
	cout << ~(M+1) <<endl; //overflow test	
	cout << ~I <<endl;
	cout << ~F <<endl;	
	cout << ~G <<endl;	

	//operator:addition
	cout << ~(F+G) <<endl;	
	cout << ~(G+F) <<endl;	
	cout << ~(F+F+F+F+F) <<endl;
	cout << ~((F+F)+(G+F)) <<endl;
	cout << ~(I+F) <<endl;
	cout << ~(F+I) <<endl;	

	//operator:comparison
	cout << (F == F) <<endl;
	cout << ((F+I) == (I+F)) <<endl;
	cout << ((F+G) == (F+G)) <<endl;
	cout << (F+F == -1) <<endl;
	cout << (I == 2) <<endl; */
	
 	// Instatiating classes and testing the operators
	cout << "Comparison of Integer to int:";
	Integer F(1);
	int actual=1;
	cout << _test (F==actual);
	cout <<endl;

	cout << "Comparison of Integer to itself:";
	actual=1;
	cout << _test (F==F);
	cout <<endl;

	cout << "Comparison of Integer to Integer:";
	actual=1;
	Integer G(1);
	cout << _test (F==G) ;
	cout <<endl;

	cout << "Comparison of Integer to Fraction:";
	Integer F1(-1);
	Fraction G1(1,-1);
	cout << _test (F1==G1);
	cout <<endl;

	cout << "Comparison of Fraction to Integer to Fraction:";
	cout << _test (F==G);
	cout <<endl;

	cout << "Comparison of Fraction to Fraction:";
	actual=1;
	Integer F2(1);
	Integer G2(1);
	cout << _test (G2==F2);
	cout <<endl;

	cout << "Adding Integer to Integer:";
	actual=2;
	cout << _test (F2+G2==2);
	cout <<endl;

	cout << "Adding Fraction to Fraction:";
	actual=2;
	Fraction F3(1,-1);
	Fraction G3(1,-1);
	cout << _test (F3+G3==-2);
	cout <<endl;

	cout << "Adding Integer to Fraction:";
	actual=1.5;
	Fraction F4(1,1);
	Fraction G4(1,2);
	cout << _test (F4+G4== (float)1.5);
	cout <<endl;

	cout << "Adding Fraction to Integer:";
	actual=1.5;
	Fraction F5(1,2);
	Integer G5(1);
	cout << _test (F5+G5== (float)1.5);
	cout <<endl;

	cout << "display operator:Fraction:";
	Fraction F6(1,2);
	cout << _test (~F6=="1/2");
	cout <<endl;

	cout << "display operator:Integer:";
	Integer F7(1);
	cout << _test (~F7=="1");
	cout <<endl;

	cout << "Testing inf:";
	Fraction F8(1,0);
	cout << _test(~F8=="inf");
	cout <<endl;

	cout << "Testing inf+-inf:";
	Fraction F9(1,0);
	Fraction G9(-1,0);
	cout << _test(~(G9+F9)=="nan");
	cout <<endl;

	cout << "Cascading addition:";
	Integer F0(1);
	cout << _test(F0+F0+F0==3);
	cout <<endl;

	cout << "Cascading addition2:";
	cout << _test(~(F+G4)=="3/2");
	cout <<endl;
}