#include <iostream>   
#include <string> 
#include "number.h"
#include "integer.h"
#include <sstream>
#include "fraction.h"



using namespace std;

//----------------------Constructors-------------------------
Fraction::Fraction(int _numerator, int _denumerator): Number() {
	numerator = _numerator;
	denumerator = _denumerator;
	if (denumerator == 0) 
		if (numerator>0) this->set_inf();
		else this->set_neg_inf();
}

Fraction::Fraction(string s) : Number() {	
	numerator = 0;
	denumerator = 1;
	if (s=="inf") Number::inf = true;
	else if (s=="neg_inf") Number::neg_inf = true;
	else if (s=="overflow") Number::overflow = true;
	else Number::nan = true;
}

//--------------------------Interface-------------------
int Fraction::get_numerator() const{
	if (numerator == NULL || this->is_nan() || this->is_neg_inf() || this->is_inf())
		return 0;
	else 
	return numerator;
}

int Fraction::get_denumerator() const{
	if (denumerator  == NULL || this->is_nan() || this->is_neg_inf() || this->is_inf())
		return 1;
	else 
	return denumerator;
}

void Fraction::set_numerator(int _value){
	if (_value == NULL)
		numerator=_value;
	if (_value==0 && this->get_denumerator()==0) this->set_nan();
}

void Fraction::set_denumerator(int _value){
	if (_value == 0) 
		if (numerator>=0) this->set_inf(); else this->set_neg_inf();
	if (_value == NULL)
		denumerator=_value;	
}
//-------------------------------------------------------------
// assign the display string and validate the variable	
bool Fraction::validate(int const value){	
	if (value == NULL) return false;
	else if (this->is_nan()) {
		this->to_display = "nan"; return true;}
	else if (this->is_inf()) {
		this->to_display = "inf"; return true;}
	else if (this->is_neg_inf()){
		this->to_display = "-inf"; return true;}
	else this->to_display =   to_string(numerator) +"/"+ to_string(denumerator);
	return true;
}

string Fraction::to_string(int i){
     ostringstream ss;
     ss << i;
     return ss.str();
}

//assignment operator
Fraction& Fraction::operator =(Fraction &rhs){
	this->inf=rhs.is_inf();
	this->neg_inf=rhs.is_neg_inf();
	this->nan=rhs.is_nan();
	this->numerator=rhs.get_numerator();
	this->denumerator=rhs.get_denumerator();
	return *this;
}
//assignment operator for Integer type
Fraction& Fraction::operator =(Integer &rhs){
	this->inf=rhs.is_inf();
	this->neg_inf=rhs.is_neg_inf();
	this->nan=rhs.is_nan();
	this->numerator=rhs.get_value();
	this->denumerator=1;
	return *this;
}

Fraction& Fraction::operator =(const int& rhs) {
	return (operator =(*(new Integer(rhs))));
}

// adding Fractions and Fractions : member function 
Fraction& Fraction::operator +=(const Fraction &rhs){
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
	else {
		this->numerator=rhs.numerator*this->denumerator+rhs.denumerator*this->numerator;
		this->denumerator=rhs.denumerator*this->denumerator;
		return (*this); //check the overflow
	}
}

/* adding Fractions and Integers : member function */
Fraction& Fraction::operator +=(const Integer &rhs){
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
	else {
		this->numerator=rhs.get_value()*this->denumerator+this->numerator;
		this->denumerator=this->denumerator;
		return (*this); //check the overflow
	}
}

// addition operator non-member functions 
Fraction operator +(const Fraction& lhs,const Fraction& rhs){
	Fraction result=lhs;
	result +=rhs;
	return result;
}
// addition operator non-member functions Fraction+Integer
Fraction operator +(const Fraction& lhs,const Integer& rhs){
	Fraction result=lhs;
	result +=rhs;
	return result;
}

//------------- comparison operator ---------------------------
bool operator ==(const Fraction& lhs, const Integer &rhs) {
	return( rhs.get_value()*lhs.get_denumerator() == lhs.get_numerator());
} 

bool operator ==(const Fraction& lhs, const Fraction &rhs) {
	return (rhs.get_denumerator()*lhs.get_numerator()==rhs.get_numerator()*lhs.get_denumerator());
} 

bool operator ==(const Fraction& lhs,const int &rhs) {
return (operator ==(lhs,*(new Integer(rhs))));
}

bool operator ==(const Fraction& lhs,const float &rhs) {
return ((float)lhs.get_numerator()==rhs*lhs.get_denumerator());
}

//--------------Displaying the variable-------------------------------
string Fraction::operator ~() {
	//if (validate(this->numerator) && validate(this->denumerator))
	validate(this->numerator);
	validate(this->denumerator);
	return Number::operator ~();
};

string Fraction::display() {
	 return ~(*this);
};


/*std::ostream &operator<<(std::ostream &os, Fraction const &I) { 
	if (I.validate(I.get_value()))
	    	return os << I.display();
}*/