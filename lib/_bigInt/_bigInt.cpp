#include "_bigInt.hpp"
#include <iostream>

bool _bigInt::_belongsToSystem(const char& src) const {
    if(src >= '0' && static_cast<int>(src) <= static_cast<int>('0') + _numberSystem - 1)
        return true;
    return false;
}

void _bigInt::_getRidOfZeros() {
    uint64_t i = 0;
    while(_string[i] == '0') 
        i++;
    uint64_t curr = i;
    _tabC temp(_string.length() - curr);
    while(i < _string.length()) {
        temp[i - curr] = _string[i];
        i++;
    }
    _string = temp;
}

_bigInt::_bigInt(const _tabC& src, uint16_t system):_numberSystem{system} {
    for(int i = 0; i < src.length(); i++)
        if(!_belongsToSystem(src[i]))
            throw 2;
    _string = src;
    _getRidOfZeros();
}

_tabC _bigInt::_getString() const {
    return _string;
}

_tabC& _changeSystem() {

}