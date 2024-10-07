#include <../include/gitexceptions.hpp>

Exception::Exception(const std::string& msg) : message(msg) {}

// Override the what() method to return our message
const char* Exception::what() const throw() { return message.c_str(); }
