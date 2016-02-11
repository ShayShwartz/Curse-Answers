#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>
#include <string>


class Exceptions : public std::exception
{
public:
	Exceptions(std::string error) : err(error) {}
	const char* what() const throw() { return err.c_str(); }

private:
	std::string err;
};

#endif