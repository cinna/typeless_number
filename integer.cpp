#include <iostream>   
#include <string> 
#include "number.h"
#include "integer.h"
#include <sstream>
#include "fraction.h"
#include <limits>
#include <cstdlib>

using namespace std;

//----------------------Constructors-------------------------
Integer::Integer(int _value): Number() {
	value = _value;
}

Integer::Integer(string s) : Number() {	
	value = 0;
	if (s=="inf") Number::inf = true;
	else if (s=="neg_inf") Number::neg_inf = true;
	else Number::nan = true;
}

//--------------------------Interface-------------------
int Integer::get_value() const{
	if (value == NULL ) {//|| this->is_nan() || this->is_neg_inf() || this->is_inf()){
		return NULL;
	}
	else {
	return value;
	}
}

void Integer::set_value(int _value){
	if (_value != NULL){
		value=_value;
	}
}

string Integer::to_string(int i){
     ostringstream ss;
     ss << i;
     return ss.str();
}
//-------------------------------------------------------------
// assign the display string after validating the variable's value
bool Integer::validate(int const value){	
	if (value == NULL) return false;
	else if (this->is_nan()) {
		this->to_display = "nan"; return false;}
	else if (this->is_inf()) {
		this->to_display = "inf"; return false;}
	else if (this->is_neg_inf()){
		this->to_display = "-inf"; return false;}
	else this->to_display =  to_string(value);
	return true;
}

// assignment override operator =
Integer& Integer::operator =(const Integer &rhs){
	this->inf=rhs.is_inf();
	this->neg_inf=rhs.is_neg_inf();
	this->nan=rhs.is_nan();
	this->value=rhs.get_value();
	validate(this->value);
	return *this;
}

/* adding Integers */
Integer& Integer::operator +=(const Integer &rhs){
	// Check for error codes/error handling first
	if ((rhs.is_neg_inf() && this->is_inf())
		|| (rhs.is_inf() && this->is_neg_inf())) 
			{this->set_nan(); return (*this);}
	else if (rhs.is_inf() || this->is_inf()) 
			{this->set_inf(); return (*this);}
	else if (rhs.is_neg_inf() || this->is_neg_inf())
			{this->set_neg_inf(); return (*this);}
	else if (rhs.is_nan() || this->is_nan()) 
			{this->set_nan(); return (*this);}
	//check the overflow
	else if ( (rhs.get_value() < 0) == (this->get_value() < 0.0)
   			 && std::abs( rhs.get_value() ) > numeric_limits<int>::max() - std::abs( this->get_value() ) ) {
    //  Addition would overflow...
		this->set_overflow(); return(*this);
		}
	else{
		this->value=rhs.value+this->value;
		return (*this); }
}

Integer operator +(const Integer& lhs, const Integer &rhs){	
	Integer result=lhs;
	result +=rhs;
	return result;
}



// Adding Integer to Fraction
Fraction operator +(const Integer& lhs, const Fraction &rhs){
	// Check for error codes/error handling first
	if ((rhs.is_neg_inf() && lhs.is_inf())
		|| (rhs.is_inf() && lhs.is_neg_inf())) 
			{ return *(new Fraction("nan"));}
	else if (rhs.is_inf() || lhs.is_inf()) 
			{ return *(new Fraction("inf"));}		
	else if (rhs.is_neg_inf() || lhs.is_neg_inf())
			{ return *(new Fraction("-inf"));}
	else if (rhs.is_nan() || lhs.is_nan()) 
			{ return *(new Fraction("nan"));}
	//check the overflow
	else if ( (rhs.get_denumerator()*lhs.get_value() < 0) == (rhs.get_numerator() < 0)
   			 && abs( rhs.get_denumerator()*lhs.get_value() ) > numeric_limits<int>::max() - abs( rhs.get_numerator() ) ) {
    //  Addition would overflow...
		 return(*(new Fraction("overflow")));
		}		
	else { // else return true value
		return *(new Fraction(rhs.get_denumerator()*lhs.get_value()+rhs.get_numerator(),rhs.get_denumerator())); 
		 //check the overflow
	}


}

//-------------  equality operator ---------------------------------
bool operator ==(const Integer& lhs,const Integer &rhs) {
	if (rhs.is_inf() && lhs.is_inf() ||
		rhs.is_nan() && lhs.is_nan() ||
		rhs.is_neg_inf() && lhs.is_neg_inf() ) 
	   return (true);
	else
	   return (rhs.get_value()==lhs.get_value());
} 

bool operator ==(const Integer& lhs,const Fraction &rhs) {
	if (rhs.is_inf() && lhs.is_inf() ||
		rhs.is_nan() && lhs.is_nan() ||
		rhs.is_neg_inf() && lhs.is_neg_inf() ) 
	   return (true);
	else
	return (rhs.get_denumerator()*lhs.get_value()==rhs.get_numerator());
} 

bool operator ==(const Integer& lhs,const int &rhs){
return (operator ==(lhs,*(new Integer(rhs))));
}

//--------------Displaying the variable-----------------------------
string Integer::operator ~() {
	validate(this->value);
	return Number::operator ~();
	
};

string Integer::display() {
	 return ~(*this);
};


/*std::ostream &operator<<(std::ostream &os, Integer const &I) { 
	if (I.validate(I.get_value()))
	    	return os << I.display();
}*/

