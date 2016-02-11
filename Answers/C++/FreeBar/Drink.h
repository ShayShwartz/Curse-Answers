#pragma once
#ifndef _DRINK_H_
#define _DRINK_H_

#include <string>
#include <iostream>

class Drink
{
public:
	virtual std::string getName()const;
	virtual void prepare()const = 0;
	virtual void ordered()const = 0;
};

std::string Drink::getName()const { return "just a Drink"; }

#endif