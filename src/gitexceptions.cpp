#include "gitexceptions.hpp"

// Override the what() method to return our message
const char* GitException::what() const throw() { return message.c_str(); }
