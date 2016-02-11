#ifndef _FRACTION_H_
#define _FRACTION_H_

class Fraction
{
public:
	//c'tors & d'tor
	Fraction(int nominator , int denominator);
	Fraction();
	~Fraction(void);

	//set & get
	int getNominator()const;
	void setNominator(int nominator);
	int getDenominator()const;
	void setDenominator(int de_nominator);

	//print func
	void print() const;

	//Negative
	Fraction getNegative()const;
	void setNegative();

	//Zero value check
	bool isZero()const;

	//get & print decimal fraction
	float getDecimal()const;
	void printDecimalFraction()const;
	
	//operator = overloading
	Fraction& operator=(const Fraction& fraction) ;

	//operator + overloading
	Fraction operator+(const Fraction& second) const;
	Fraction operator+(const int& second)const;

	//operator - overloading
	Fraction operator-(const Fraction& second) const;
	Fraction operator-(const int& second) const;

	//operator * overloading
	Fraction operator*(const Fraction& second) const;
	Fraction operator*(const int& second) const;

	//operator / overloading
	Fraction operator/(const Fraction& second) const;
	Fraction operator/(const int& second) const;

	//operator += overloading
	Fraction& operator+=(const Fraction& second);
	Fraction& operator+=(const int& second);

	//operator -= overloading
	Fraction& operator-=(const Fraction& second);
	Fraction& operator-=(const int& second);

	//operator *= overloading
	Fraction& operator*=(const Fraction& second);
	Fraction& operator*=(const int& second);

	//operator /= overloading
	Fraction& operator/=(const Fraction& second);
	Fraction& operator/=(const int& second);

	
private:
	int m_nominator;
	int m_denominator;
};


//================<GLOBAL FUNCTION>=================
//operator + overloading
Fraction operator+(int second, const Fraction& frac);

//operator - overloading
Fraction operator-(int second, const Fraction& frac);

//operator * overloading
Fraction operator*(int second, const Fraction& frac);

//operator / overloading
Fraction operator/(int second, const Fraction& frac);

//operator += overloading
int& operator+=(int& second, const Fraction& frac);

//operator -= overloading
int& operator-=(int& second, const Fraction& frac);

//operator *= overloading
int& operator*=(int& second, const Fraction& frac);

//operator /= overloading
int& operator/=(int& second, const Fraction& frac);
//================<\GLOBAL FUNCTION>================


#endif