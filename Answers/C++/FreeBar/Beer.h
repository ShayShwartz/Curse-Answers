#pragma once

#ifndef _BEER_H_
#define _BEER_H_

#include "Drink.h"


class Beer : public Drink
{
public:
	Beer(std::string name);
	virtual std::string getName()const;
	virtual void prepare()const;
	void ordered()const;

private:
	std::string m_name;
};

Beer::Beer(std::string name) : m_name(name) {}

std::string Beer::getName()const { return m_name; }

void Beer::prepare()const { std::cout << "One " << m_name << " Coming up, sir" << std::endl; }

void Beer::ordered()const { std::cout << "You ordered " << m_name << ".\nWell, all you need to do is pour it into a glass." << std::endl; }

#endif