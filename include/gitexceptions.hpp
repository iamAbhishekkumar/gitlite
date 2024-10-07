#ifndef GITEXCEPTIONS_H
#define GITEXCEPTIONS_H
#include <exception>
#include <iostream>
#include <string>

class GitException : public std::exception {
   private:
    std::string message;

   public:
    // Constructor accepts a const char* that is used to set
    // the exception message
    GitException(const std::string& msg) : message(msg) {}

    // Override the what() method to return our message
    const char* what() const throw();
};
#endif