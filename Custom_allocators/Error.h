#ifndef ERROR_H
#include <exception>
#include <string>
class Error : public std::exception{
private:
	std::string msg;
public:
	Error(std::string msg) : msg{ msg } {}
	const char* what() const noexcept override { return msg.c_str(); };
};
#endif // !ERROR_H
