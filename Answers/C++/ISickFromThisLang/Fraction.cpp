#include "Exceptions.h"
#include "Fraction.h"
#include <iostream>


//c'tors & d'tor
Fraction::Fraction(int nominator , int denominator) : m_nominator(nominator) , m_denominator(denominator) 
{
	if ( denominator == 0 && nominator != 0 )
		throw Exceptions("ERROR: Trying to create fraction with denominator 0.");
}

Fraction::Fraction() : m_nominator(0) , m_denominator(0) {}

Fraction::~Fraction(void) {}


//set & get
int Fraction::getNominator()const { return m_nominator; }

void Fraction::setNominator(int nominator) { m_nominator = nominator; }

int Fraction::getDenominator()const { return m_denominator; }

void Fraction::setDenominator(int denominator) { m_denominator = denominator; }


//print fraction
void Fraction::print()const{ std::cout << m_nominator << " / " << m_denominator << std::endl; }


//Set Negative & get Negative
Fraction Fraction::getNegative()const { return Fraction ( 0 - m_nominator , m_denominator ); }

void Fraction::setNegative() { m_nominator = 0 - m_nominator; }


// Zero value check
bool Fraction::isZero()const { return ( m_nominator == 0 ? true : false ); }


//get & print decimal fraction
float Fraction::getDecimal()const { return ( static_cast<float>(m_nominator) / m_denominator ); }

void Fraction::printDecimalFraction()const { std::cout << "Decimal Fraction: " << this->getDecimal() << std::endl; }


//operator = overloads
Fraction& Fraction::operator=(const Fraction& otherFraction)
{
	m_nominator = otherFraction.m_nominator;
	m_denominator = otherFraction.m_denominator;
	
	return *this;
}


//operator + overloads
Fraction Fraction::operator+(const Fraction& second)const
{
	if ( this->isZero() )
		return second;

	else if ( second.isZero() )
		return *this;
	
	return Fraction( m_nominator * second.m_denominator + second.m_nominator * m_denominator,
						m_denominator * second.m_denominator);
}
Fraction Fraction::operator+(const int& second)const
{
	return Fraction( m_nominator + second * m_denominator  , m_denominator );
}


//operator - overloading
Fraction Fraction::operator-(const Fraction& second)const
{
	if ( this->isZero() )
		return second.getNegative();

	else if ( second.isZero() )
		return *this;

	else
	{
		return Fraction( m_nominator * second.m_denominator - second.m_nominator * m_denominator,
							m_denominator * second.m_denominator);
	}
}
Fraction Fraction::operator-(const int& second)const
{
	return Fraction( m_nominator - m_denominator * second , m_denominator );
}


//operator * overloading
Fraction Fraction::operator*(const Fraction& second)const
{
	return Fraction( m_nominator * second.m_nominator ,
						m_denominator * second.m_denominator );
}
Fraction Fraction::operator*(const int& second)const
{
	return Fraction( m_nominator * second , m_denominator );
}


//operator / overloading
Fraction Fraction::operator/(const Fraction& second)const
{
	if ( second.isZero() )
		throw Exceptions("ERROR: Trying to divide by Zero.");
	
	else
	{
		return Fraction( m_nominator * second.m_denominator ,
							m_denominator * second.m_nominator );
	}
}
Fraction Fraction::operator/(const int& second)const
{
	if ( second == 0 )
		throw Exceptions("ERROR: Trying to divide by Zero.");
	else
		return Fraction( m_nominator , m_denominator * second );
}


//operator += overloading
Fraction& Fraction::operator+=(const Fraction& second)
{
	if ( this->isZero() )
	{
		m_nominator = second.m_nominator;
		m_denominator = second.m_denominator;
	}

	else if ( second.isZero() )
		return *this;

	else
	{
		m_nominator = m_nominator * second.m_denominator + second.m_nominator * m_denominator;
		m_denominator = m_denominator * second.m_denominator;
	}

	return *this;
}
Fraction& Fraction::operator+=(const int& second)
{
	if ( this->isZero() )
	{
		m_nominator = second;
		m_denominator = 1;
	}

	else if ( second == 0 )
		return *this;

	else
		m_nominator = m_nominator + m_denominator * second;

	return *this;
}


//operator -= overloading
Fraction& Fraction::operator-=(const Fraction& second)
{
	if ( this->isZero() )
		*this = second.getNegative();	
	
	else if ( second.isZero() )
		return *this;

	else
	{
		m_nominator = m_nominator * second.m_denominator - second.m_nominator * m_denominator;
		m_denominator = m_denominator * second.m_denominator;
	}

	return *this;
}
Fraction& Fraction::operator-=(const int& second)
{
	if ( this->isZero() )
	{
		m_nominator = 0 - second;
		m_denominator = 1;
	}
	else if ( second == 0 )
		return *this;

	else
		m_nominator = m_nominator - m_denominator * second;

	return *this;
}


//operator *= overloading
Fraction& Fraction::operator*=(const Fraction& second)
{
	m_nominator = m_nominator * second.m_nominator;
	m_denominator = m_denominator * second.m_denominator;

	return *this;
}
Fraction& Fraction::operator*=(const int& second)
{
	m_nominator = m_nominator * second;

	return *this;
}


//operator /= overloading
Fraction& Fraction::operator/=(const Fraction& second)
{
	if ( second.isZero() )
		throw Exceptions("ERROR: Trying to divide by Zero.");

	else
	{
		m_nominator = m_nominator * second.m_denominator;
		m_denominator = m_denominator * second.m_nominator;
	}

	return *this;
}
Fraction& Fraction::operator/=(const int& second)
{
	if ( second == 0 )
		throw Exceptions("ERROR: Trying to divide by Zero.");

	else
		m_denominator = m_denominator * second;

	return *this;
}


//================<GLOBAL FUNCTION>=================
//operator + overloading
Fraction operator+(int second, const Fraction& frac)
{
	return Fraction( frac.getNominator() + second * frac.getDenominator()  , frac.getDenominator() );
}

//operator - overloading
Fraction operator-(int second, const Fraction& frac)
{
	return Fraction( frac.getNominator() - frac.getDenominator() * second , frac.getDenominator() );
}

//operator * overloading
Fraction operator*(int second, const Fraction& frac)
{
	return Fraction( frac.getNominator() * second , frac.getDenominator() );
}

//operator / overloading
Fraction operator/(int second, const Fraction& frac)
{
	return Fraction( frac.getNominator() , frac.getDenominator() * second );
}

//operator += overloading
int& operator+=(int& second, const Fraction& frac)
{
	second = static_cast<int>( second + frac.getDecimal() );
	return second;
}

//operator -= overloading
int& operator-=(int& second, const Fraction& frac)
{
	second = static_cast<int>( second - frac.getDecimal() );
	return second;
}

//operator *= overloading
int& operator*=(int& second, const Fraction& frac)
{
	second = static_cast<int>( second * frac.getDecimal() );
	return second;
}

//operator /= overloading
int& operator/=(int& second, const Fraction& frac)
{
	if ( frac.isZero() )
		throw Exceptions("ERROR: Trying to divide by Zero.");

	second = static_cast<int>( second /  frac.getDecimal() );
	return second;
}
//================<\GLOBAL FUNCTION>================