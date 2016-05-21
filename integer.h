/*
 	Author: Cinna Soltanpur
 	Purpose: Extended Integer class with inf,-inf,nan
 	Day Created: 3/13/16
*/

#include <string>

class Integer: public Number{
	private:
	 	int value;	 	
	public:
	//Constructors
	Integer(): Number(), value(0) {};
	Integer(int _value);
	Integer(std::string _value); //example: Integer("inf")
	~Integer(){};

	//Interface
	void set_value(int _value);
	int get_value() const;
	std::string to_string(int i);
	bool validate(int const _value);	

	//memeber function operators
	Integer& operator =(const Integer &rhs); 
	Integer& operator +=(const Integer &rhs); 
	virtual int is_integer() const {return value;};
	virtual int get_numerator() const {return value;};
	virtual int get_denumerator() const {return 1;};

	//Cascading does not fully work with member functions
	//bool operator ==(const Integer& lhs,const Fraction &rhs); 
	//bool operator ==(const Integer& lhs,const Integer &rhs);
	//bool operator ==(const Integer& lhs,const int &rhs){return (operator ==(lhs,*(new Integer(rhs))));};

	//overloaded display operator
	virtual std::string operator ~();
	virtual std::string display();	
};

// non-member operators
Fraction operator +(const Integer& lhs, const Fraction &rhs); //adding Integer to Fraction
Integer operator +(const Integer& lhs, const Integer &rhs);
bool operator ==(const Integer& lhs, const Integer &rhs);
bool operator ==(const Integer& lhs, const Fraction &rhs); 
bool operator ==(const Integer& lhs, const int &rhs);