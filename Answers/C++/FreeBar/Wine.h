#pragma once

#ifndef _WINE_H_
#define _WINE_H_

#include "Drink.h"

class Wine : public Drink
{
public:
	virtual std::string getName()const;
	virtual void prepare()const = 0;
	virtual	void ordered()const = 0;

};

std::string Wine::getName()const { return "Just a Wine"; }

#endif
