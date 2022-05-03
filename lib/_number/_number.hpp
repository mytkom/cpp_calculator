#pragma once
#include <cstdint>
#include <iostream>

class _number {
    char _letter;
    uint16_t _value;
public:
    _number();
    _number(const char&);
    _number(const uint16_t&);

    char _getChar() const { return _letter; }
    uint16_t _getVal() const { return _value; }

    //maybe it can be made by compilator
    //_number& operator=(const char&);

    friend _number operator+(const _number& a, const _number& b);
    _number& operator+=(const _number&);
    _number& operator++();
    _number operator++(int);

    friend _number operator-(const _number& a, const _number& b);
    _number& operator-=(const _number&);
    _number& operator--();
    _number operator--(int);

    friend bool operator==(const _number&, const _number&);
    friend bool operator!=(const _number&, const _number&);
    friend bool operator>=(const _number&, const _number&);
    friend bool operator<=(const _number&, const _number&);
    friend bool operator>(const _number&, const _number&);
    friend bool operator<(const _number&, const _number&);

    friend std::ostream& operator<<(std::ostream&, const _number&);
};

uint16_t getValueOfChar(const char&);
char getCharOfInt(const uint16_t&);