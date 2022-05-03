#define MAX_SYSTEM 16

#include "_bigInt.hpp"
#include <iostream>

using namespace std;

bool _bigInt::_belongsToSystem(const _number& src) const {
    if(_numberSystem > src._getVal()) return true;
    return false;
}

void _bigInt::_getRidOfZeros() {
    if(_string == _tabC()) return;
    if(_string.length() == 1 && _string[0] == _number()) return;
    uint64_t i = 0;
    while(i < _string.length() && _string[i] == _number()) 
        i++;
    if(i == _string.length()) {
        _string = _tabC("0");
        return;
    }
    uint64_t curr = i;
    _tabC temp(_string.length() - curr);
    while(i < _string.length()) {
        temp[i - curr] = _string[i];
        i++;
    }
    _string = temp;
}

_bigInt::_bigInt(const _tabC& src, uint16_t system): _numberSystem{(system <= static_cast<uint16_t>(MAX_SYSTEM)) ? system : static_cast<uint16_t>(MAX_SYSTEM)} {
    for(int i = 0; i < src.length(); i++)
        if(!_belongsToSystem(src[i]))
            throw 2;
    _string = src;
    _getRidOfZeros();
}

_tabC _bigInt::_getString() const {
    return _string;
}

_tabC& _bigInt::_changeSystem(uint16_t newSystem) {
    if(_numberSystem == newSystem || newSystem > MAX_SYSTEM) return this -> _string;
    //TODO po arytmetycznych

}

_number& _bigInt::operator[](uint64_t i) {
    return _string[i];
}

_number _bigInt::operator[](uint64_t i) const {
    return _string[i];
}

_bigInt operator+(const _bigInt& a, const _bigInt& b) {
    if(a._numberSystem != b._numberSystem) throw 3;
    if(a._string.length() < b._string.length()) return (b + a);

    _bigInt result(_tabC(), a._numberSystem);

    uint16_t mem{0};
    uint16_t sum{0};
    for(int i = 0; i < a._string.length(); i++) {
        sum = (a[a._string.length() - 1 - i] +
                ((i < b._string.length()) ? b[b._string.length() - 1 - i] : (uint16_t) 0) + mem)._getVal();

        if(sum >= a._numberSystem) {
            mem = 1;
            sum = sum % a._numberSystem;
        }
        else {
            mem = 0;
        }
        
        result._string = _tabC(1, _number(sum)._getChar()) + result._string;
    }
    if(mem) result._string = _tabC(1, _number(mem)._getChar()) + result._string;
    return result;
}

_bigInt& _bigInt::operator+=(const _bigInt& a) {
    *(this) = *(this) + a;
    return *(this);
}

ostream& operator<<(ostream& out, const _bigInt& src) {
    out << src._string;
    return out;
}

bool operator==(const _bigInt& a, const _bigInt& b) {
    if(a._string == b._string && a._numberSystem == b._numberSystem)
        return true;
    return false;
}

bool operator!=(const _bigInt& a, const _bigInt& b) {
    return !(a == b);
}

bool operator>(const _bigInt& a, const _bigInt& b) {
    if(a._string.length() > b._string.length()) 
        return true;

    if(a._string.length() < b._string.length())
        return false;

    for(int i = 0; i < a._string.length(); ++i) {
        if(a[i] > b[i])
            return true;
        if(a[i] < b[i])
            return false;

    }
}

bool operator>=(const _bigInt& a, const _bigInt& b) {
    if(a == b || a > b) return true;
}

bool operator<=(const _bigInt& a, const _bigInt& b) {
    return !(a > b);
}

bool operator<(const _bigInt& a, const _bigInt& b) {
    return !(a >= b);
}

_bigInt operator-(const _bigInt& a, const _bigInt& b) {
    if(a._numberSystem != b._numberSystem) throw 3;
    if(a._string.length() < b._string.length()) throw 4;

    _bigInt result(_tabC(), a._numberSystem);

    uint16_t mem{0};
    uint16_t sum{0};
    for(int i = 0; i < a._string.length(); i++) {
        sum = (a[a._string.length() - 1 - i] +
                ((i < b._string.length()) ? b[b._string.length() - 1 - i] : '0') + mem)._getVal();

        if(sum >= a._numberSystem) {
            mem = 1;
            sum = sum % a._numberSystem;
        }
        else {
            mem = 0;
        }
        
        result._string = _tabC(1, _number(sum)._getChar()) + result._string;
    }
    if(mem) result._string = _tabC(1, _number(mem)._getChar()) + result._string;
    return result;
}

 _bigInt& _bigInt::operator-=(const _bigInt& a) {
    *(this) = *(this) - a;
    return *(this);
 }


/*
_bigInt operator/(const _bigInt&, const _bigInt&) {

}
*/