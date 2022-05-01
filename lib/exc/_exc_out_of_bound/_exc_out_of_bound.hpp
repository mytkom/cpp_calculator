#pragma once
#include <exception>

//exception class for debugging purposes
class _exc_out_of_bound : public std::exception {
    const char* what() const throw () {
        return "Tried to access variable, which don't exist!";
    }
};