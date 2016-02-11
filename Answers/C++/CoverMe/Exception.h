#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
	Exception(std::string error) : err(error) {}
	const char* what() const throw() { return err.c_str(); }

private:
	std::string err;
};

#endif~	