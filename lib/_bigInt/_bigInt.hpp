#pragma once
#include "../_tabC/_tabC.hpp"

class _bigInt {
    _tabC _string;
    uint16_t _numberSystem;

    bool _belongsToSystem(const _number&) const;
    void _getRidOfZeros();
public:
    _bigInt(const _tabC& = _tabC(), uint16_t = 10);

    _tabC& _changeSystem(uint16_t = 10);
    _tabC _getString() const;

    // generated automatically
    // _bigInt& operator=(const _bigInt&);
    // _bigInt(const _bigInt&);

    _number& operator[](uint64_t);
    _number operator[](uint64_t) const;

    //sum
    friend _bigInt operator+(const _bigInt&, const _bigInt&);
    _bigInt& operator+=(const _bigInt&);
    friend _bigInt operator-(const _bigInt&, const _bigInt&);
    _bigInt& operator-=(const _bigInt&);

    //friend _bigInt operator*(const _bigInt&, const _bigInt&);


    // TODO first
    //subtraction
    //friend _bigInt operator/(const _bigInt&, const _bigInt&);
    //_bigInt& operator/=(const _bigInt&);

    friend std::ostream& operator<<(std::ostream&, const _bigInt&);

    // //compare
    friend bool operator==(const _bigInt&, const _bigInt&);
    friend bool operator!=(const _bigInt&, const _bigInt&);
    friend bool operator>(const _bigInt&, const _bigInt&);
    friend bool operator>=(const _bigInt&, const _bigInt&);
    friend bool operator<=(const _bigInt&, const _bigInt&);
    friend bool operator<(const _bigInt&, const _bigInt&);
};
