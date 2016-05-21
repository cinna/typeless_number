#include <string>
#include <sstream>
#include <iostream>
//#include "number.h"
//#include "fraction.h"


//Wrapper class hiding the data types Integer and Fraction 

//class Number;

class AnyNumber{
	private:		
		Number *ptr_number;
	public:			
		
		//Constructor
		AnyNumber(){};
		AnyNumber(int i);
		AnyNumber(int numerator, int denumerator) ;
		AnyNumber(Number *ptr_number_) ;
		AnyNumber(Integer number_) ;		
		AnyNumber(Fraction number_) ;
		virtual ~AnyNumber();

		//Main operations
		Number* get_ptr() const;
		AnyNumber& operator =(const AnyNumber &number_) ;
		AnyNumber& operator +=(const AnyNumber &lhs);
		

		//Display operator "~" 
		virtual std::string operator ~() const {return ptr_number->operator ~();}; // to display the value
		std::string display() {return ~(*this);};	
};
//non member functions
bool operator ==(const AnyNumber& lhs, const AnyNumber&rhs);
AnyNumber operator +(const AnyNumber& lhs, const AnyNumber&rhs);
std::ostream &operator<<(std::ostream &os, const AnyNumber &ptr_number);