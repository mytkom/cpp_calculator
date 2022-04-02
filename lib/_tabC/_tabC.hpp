#pragma once
#include <cstdint>
#include <iostream>

class _tabC {
    uint64_t _length;
    char* _number;

    void _init(const uint64_t); 
    void _fill(const char*); 
public:
    _tabC(const uint64_t, const char); //repeats char
    _tabC(const uint64_t = 0, const char* = nullptr); //rewrite const char to tabC
    _tabC(const _tabC&);
    ~_tabC();
    uint64_t length() const;
    char operator[](uint64_t) const;
    char& operator[](uint64_t);
    _tabC& operator=(const _tabC&);
    //_tabC& operator+(const _tabC&);

    friend _tabC operator+(const _tabC&, const _tabC&);
    _tabC& operator+=(const _tabC&);

    friend bool operator==(const _tabC&, const _tabC&);
    friend bool operator!=(const _tabC&, const _tabC&);
    friend std::ostream& operator<<(std::ostream&, const _tabC&);
    //friend std::istream& operator>>(std::istream&, _tabC&);
};