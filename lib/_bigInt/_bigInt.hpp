#pragma once
#include <map>
#include "../_tabC/_tabC.hpp"

class _bigInt {
    //TODO rozwin by > 16 dzialaly i nie bylo to sztywne
    //stworz funkcje ktora bedzie zwracac, powinno byc w miare szybkie
    inline static const std::map<char, uint16_t> _values = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
    inline static const char _letters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    _tabC _string;
    uint16_t _numberSystem;

    bool _belongsToSystem(const char&) const;
    void _getRidOfZeros();
public:
    //constructors
    _bigInt(const _tabC& = _tabC(), uint16_t = 10);
    // _bigInt(const _bigInt&);

    //methods


    _tabC& _changeSystem(uint16_t = 10);
    _tabC _getString() const;

    // generated automatically
    // _bigInt& operator=(const _bigInt&);

    char& operator[](uint64_t);
    char operator[](uint64_t) const;

    //sum
    friend _bigInt operator+(const _bigInt&, const _bigInt&);
    _bigInt& operator+=(const _bigInt&);

    friend std::ostream& operator<<(std::ostream&, const _bigInt&);

    // //compare
    friend bool operator==(const _bigInt&, const _bigInt&);
    friend bool operator!=(const _bigInt&, const _bigInt&);
    // friend bool operator>(const _bigInt&, const _bigInt&);
    // friend bool operator>=(const _bigInt&, const _bigInt&);
    // friend bool operator<=(const _bigInt&, const _bigInt&);
    // friend bool operator<(const _bigInt&, const _bigInt&);
};
