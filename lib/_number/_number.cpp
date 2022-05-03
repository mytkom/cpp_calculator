#include "_number.hpp"

using namespace std;

_number::_number() : _letter{'0'}, _value{0} {}
_number::_number(const char& src) : _letter{src}, _value{getValueOfChar(src)} {}
_number::_number(const uint16_t& src) : _letter{getCharOfInt(src)}, _value{src} {}

_number operator+(const _number& a, const _number& b) {
    return (uint16_t) (a._getVal() + b._getVal());
}

_number& _number::operator+=(const _number& a) {
    (*this) = (*this) + a;
    return (*this);
}
_number& _number::operator++() {
    (*this) += (uint16_t) 1;
    return (*this);
}
_number _number::operator++(int) {
    _number temp{(*this)};
    ++(*this);
    return temp;
}

_number operator-(const _number& a, const _number& b) {
    return (uint16_t) (a._getVal() - b._getVal());
}

_number& _number::operator-=(const _number& a) {
    (*this) = (*this) - a;
    return (*this);
}
_number& _number::operator--() {
    (*this) -= (uint16_t) 1;
    return (*this);
}
_number _number::operator--(int) {
    _number temp{(*this)};
    --(*this);
    return temp;
}

bool operator==(const _number& a, const _number& b) {
    if(a._getVal() == b._getVal() && a._getChar() == b._getChar()) return true;
    return false;
}

bool operator!=(const _number& a, const _number& b) {
    return !(a == b);
}

bool operator>=(const _number& a, const _number& b) {
    if(a._getVal() >= b._getVal()) return true;
    return false;
}

bool operator<(const _number& a, const _number& b) {
    return !(a >= b);
}

bool operator<=(const _number& a, const _number& b) {
    return (a == b && a < b);
}

bool operator>(const _number& a, const _number& b) {
    return !(a <= b);
}

std::ostream& operator<<(std::ostream& out, const _number& src) {
    out << src._getChar();
    return out;
}

uint16_t getValueOfChar(const char& src) {
    uint16_t res{0};
    if(src >= '0' && src <= '9') res = src - '0';
    else if(src >= 'A' && src <= 'Z') res = src - 'A' + 10;
    else res = UINT16_MAX;
    return res;
}

char getCharOfInt(const uint16_t& src) {
    char res{'\0'};
    if(src >= 0 && src <= 9) res = (char) (src + (uint16_t) '0');
    else if(src >= 10 && src <= 36) res = (char) (src - 10 + (uint16_t) 'A');
    return res;
}