#pragma once
#include "../_tabC/_tabC.hpp"

class _bigInt {
    _tabC _string;
    uint16_t _numberSystem;

    bool _belongsToSystem(const char&) const;
    void _getRidOfZeros();
public:
    //constructors
    _bigInt(const _tabC& = _tabC(), uint16_t = 10);
    // _bigInt(const _bigInt&);

    //methods

    _tabC& _changeSystem();
    _tabC _getString() const;


    // _bigInt& operator=(const _bigInt&);

    //sum
    // friend _bigInt operator+(const _bigInt&, const _bigInt&);
    // _bigInt& operator+=(const _bigInt&);

    // friend std::ostream& operator<<(std::ostream&, const _bigInt&);

    // //compare
    // friend bool operator==(const _bigInt&, const _bigInt&);
    // friend bool operator!=(const _bigInt&, const _bigInt&);
    // friend bool operator>=(const _bigInt&, const _bigInt&);
    // friend bool operator<=(const _bigInt&, const _bigInt&);
    // friend bool operator>(const _bigInt&, const _bigInt&);
    // friend bool operator<(const _bigInt&, const _bigInt&);
};
