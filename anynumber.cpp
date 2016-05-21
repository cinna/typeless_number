#include "number.h"
#include "integer.h"
#include "fraction.h"
#include "anynumber.h"

AnyNumber::AnyNumber(int i){
 ptr_number =dynamic_cast<Number*> (new Integer(i)); 
}

AnyNumber::AnyNumber(int numerator, int denumerator) {
 ptr_number = dynamic_cast<Number*> (new Fraction(numerator,denumerator)); 
}

AnyNumber::AnyNumber(Number *ptr_number_) { 
	ptr_number = ptr_number_;
}		

AnyNumber::AnyNumber(Integer number_) {
	Integer *I=new Integer();
	*I=number_; ptr_number = dynamic_cast<Number*> (I);
}		

AnyNumber::AnyNumber(Fraction number_) {
	Fraction *F=new Fraction();
	*F=number_; ptr_number = dynamic_cast<Number*> (F);
}		

AnyNumber::~AnyNumber(){
	delete ptr_number;
}

Number* AnyNumber::get_ptr() const{
	return ptr_number;
}

AnyNumber& AnyNumber::operator =(const AnyNumber &number_) {//Swap
	Fraction *ptr_fraction=dynamic_cast<Fraction*>(number_.get_ptr());
	Integer *ptr_integer=dynamic_cast<Integer*>(number_.get_ptr());													 

    //if it is an integer then it is an "Integer" 
	if (number_.ptr_number->is_integer()!=NULL)
	if (ptr_fraction)
		ptr_number=dynamic_cast<Number*> 
			(new Integer(ptr_fraction->get_numerator()/ptr_fraction->get_denumerator()));
	else				
		ptr_number=dynamic_cast<Number*> 
			(new Integer(ptr_integer->get_numerator()/ptr_integer->get_denumerator()));
	else 
		if(ptr_fraction)
		ptr_number=dynamic_cast<Number*> 
			(new Fraction(ptr_fraction->get_numerator(),ptr_fraction->get_denumerator()));
		else
			ptr_number = NULL;
	ptr_number->copy_flags(number_.get_ptr());
		//hiding the data type														 
}

AnyNumber& AnyNumber::operator +=(const AnyNumber &lhs) { 	
	Fraction *ptr_fraction=dynamic_cast<Fraction*>(lhs.ptr_number);
	Integer *ptr_integer=dynamic_cast<Integer*>(lhs.ptr_number);
	Fraction *rhs_fraction=dynamic_cast<Fraction*>(ptr_number);
	Integer *rhs_integer=dynamic_cast<Integer*>(ptr_number);
	if (ptr_fraction!=NULL && rhs_fraction!=NULL) (*this)=AnyNumber((*ptr_fraction)+(*rhs_fraction));
	else if (ptr_integer!=NULL && rhs_fraction!=NULL) (*this)=AnyNumber((*ptr_integer)+(*rhs_fraction));
	else if (ptr_fraction!=NULL && rhs_integer!=NULL) (*this)=AnyNumber((*ptr_fraction)+(*rhs_integer));
	else if (ptr_integer!=NULL && rhs_integer!=NULL) (*this)=AnyNumber((*ptr_integer)+(*rhs_integer));	
	else {ptr_number=NULL; return *this;}
}

bool operator ==(const AnyNumber &lhs, const AnyNumber &rhs) { 	
	Fraction *ptr_fraction=dynamic_cast<Fraction*>(lhs.get_ptr());
	Integer *ptr_integer=dynamic_cast<Integer*>(lhs.get_ptr());
	Fraction *rhs_fraction=dynamic_cast<Fraction*>(rhs.get_ptr());
	Integer *rhs_integer=dynamic_cast<Integer*>(rhs.get_ptr());
	if (ptr_fraction!=NULL && rhs_fraction!=NULL) return ((*ptr_fraction)==(*rhs_fraction));
	else if (ptr_integer!=NULL && rhs_fraction!=NULL) return ((*ptr_integer)==(*rhs_fraction));
	else if (ptr_fraction!=NULL && rhs_integer!=NULL) return ((*ptr_fraction)==(*rhs_integer));
	else if (ptr_integer!=NULL && rhs_integer!=NULL) return ((*ptr_integer)==(*rhs_integer));	
	else {return 0;}
}


AnyNumber operator +(const AnyNumber& lhs, const AnyNumber&rhs){
	AnyNumber result=lhs;
	result +=rhs;
	return result;
}

std::ostream &operator<<(std::ostream &os, const AnyNumber &ptr_number) { 
	    	return os << ~(ptr_number);
}