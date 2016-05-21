/* 
This class is the base class for Integer and Fraction class
Class Hierarchy
  	  Number
 	/		\
Integer		Fraction
*/

#include <string>
#include <sstream>
#include <iostream>
class Integer;
class Fraction;

class Number{
	protected:		
		bool inf,neg_inf,nan, overflow, underflow;  // Bounndary conditions 
		std::string to_display;
	public:	
		//Interface
		bool is_inf() const {return inf;};  
		bool is_neg_inf() const {return neg_inf;};
		bool is_nan() const {return nan;};    //  nan = not a number
		bool is_overflow() const {return overflow;};  //overflow
		bool is_underflow() const {return underflow;};  //underflow
		void set_inf() {inf=true;};  
		void set_neg_inf() {neg_inf=true;};
		void set_nan(){nan=true;}; //nan = not a number
		void set_overflow() {overflow=true;};  
		void set_underflow() {underflow=true;};  

		//Constructor
		Number(): inf(false), neg_inf(false), nan(false), overflow(false), underflow(false) {};
		~Number(){};

		//Main operations
		//virtual Number& operator +=(const Integer &) =0;

		//Display operator "~" shows value or error code 
		//example: ~(variable), output : value string  or error code
		virtual std::string operator ~() {	if (overflow) return "overflow";
							else if (underflow) return "underflow";
							else if (to_display.empty()) return "null";
							else if (nan) return "nan";
							else if (neg_inf) return "-inf";
							else if (inf) return "inf";
							else return to_display;}; // to display the value
		void copy_flags(Number* no){ if (no->is_neg_inf()) set_neg_inf();
									if (no->is_inf()) set_inf();
									if (no->is_nan()) set_nan();
									if (no->is_overflow()) set_overflow();
									};							
		std::string display() {return ~(*this);};	

		//Some tools (not needed for C++11 compiler)
		virtual int is_integer() const =0;
		virtual int get_numerator() const =0;
		virtual int get_denumerator() const =0;

		template<typename T> friend std::string to_string(T i){std::ostringstream ss;
     								ss << i;
     								return ss.str();};

};


