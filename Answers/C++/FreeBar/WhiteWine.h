#pragma once

#ifndef _WHITEWINE_H_
#define _WHITEWINE_H_

#include "Wine.h"
class WhiteWine : public Wine
{
public:
	WhiteWine(std::string name, int year);
	virtual std::string getName()const;
	virtual void prepare()const;
	void ordered()const;

private:
	std::string m_name;
	int m_year;
};

WhiteWine::WhiteWine(std::string name, int year) : m_name(name) , m_year(year) {}

std::string WhiteWine::getName()const
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

void WhiteWine::prepare()const { std::cout << "One " << m_name << " Coming up, sir" << std::endl; }

void WhiteWine::ordered()const { std::cout << "You ordered " << m_name << ".\nI served you your wine cold, sir." << std::endl; }



#endif