#pragma once

#ifndef _REDWINE_H_
#define _REDWINE_H_

#include "Wine.h"
class RedWine :	public Wine
{
public:
	RedWine(std::string name, int year);
	virtual std::string getName()const;
	virtual void prepare()const;
	void ordered()const;

private:
	std::string m_name;
	int m_year;
};



RedWine::RedWine(std::string name, int year) : m_name(name) , m_year(year) {}

std::string RedWine::getName()const
{
	std::string returnedName;
	char yearStr[5];
	_itoa(m_year, yearStr, 10);
	returnedName += m_name;
	returnedName += " (";
	returnedName += yearStr;
	returnedName += ").";

	return returnedName;
}

void RedWine::prepare()const { std::cout << "One " << m_name << " Coming up, sir" << std::endl; }

void RedWine::ordered()const { std::cout << "You ordered " << m_name << ".\nI serve you your wine in room temperature, sir." << std::endl; }


#endif