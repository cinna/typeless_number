/*
 	Author: Cinna Soltanpur
 	Purpose: Fraction class for rational numbers with integer de/numerators
 	Day Created: 3/13/16
*/
#include <string>


class Fraction : public Number{
	private:
	 	int numerator,denumerator;
	public:
		//Constructors
		Fraction (): Number(), numerator(0), denumerator(1) {};
		Fraction (int numerator_, int denumerator_);//Fraction(1,2)=1/2
		Fraction (std::string ); //Fraction("inf")
		Fraction (int numerator_, std::string); //Fraction("inf")
		Fraction (std::string, int numerator_); //Fraction("inf")
		~Fraction(){};
		
		//Interface
		void set_numerator(int );
		void set_denumerator(int );
		virtual int get_numerator() const;
		virtual int get_denumerator() const;
		bool validate(int const _value);
		std::string to_string(int i);
		virtual int is_integer() const{if ((numerator%denumerator)==0 && !nan && !inf && !neg_inf) 
									return (numerator/denumerator);
									else return NULL;}

		//memeber function operators
		Fraction& operator =(Fraction& rhs);
		Fraction& operator =(Integer& rhs);
		Fraction& operator =(const int& rhs);	

		Fraction& operator +=(const Fraction& rhs);// a/b+c/d=(ad+bc)/bd   (have not used gcd for addition)
		Fraction& operator +=(const Integer& rhs);// a/b+c=(ad+c)/b  

	
		virtual std::string operator ~();
		virtual std::string display();	
};
//non-member operators
Fraction operator +(const Fraction& lhs,const Fraction& rhs);
Fraction operator +(const Fraction& lhs,const Integer& rhs);
bool operator ==(const Fraction& lhs,const Integer &rhs);
bool operator ==(const Fraction& lhs,const Fraction &rhs); 
bool operator ==(const Fraction& lhs,const int &rhs);
bool operator ==(const Fraction& lhs,const float &rhs);