
#include "_tabC.hpp"

using namespace std;

_tabC::_tabC(const uint64_t size, const char* msg) {
    _length = size;
    _init(size);
    _fill(msg);
}

_tabC::_tabC(const uint64_t size, const char repChar):_tabC{size} {
    if(_number) {
        for(int i = 0; i < _length; i++)
            _number[i] = repChar;
    }
}

_tabC::_tabC(const _tabC& src) {
    if(!src._number) {
        _number = nullptr;
        _length = 0;
    }
    else {
        _init(src._length);
        _length = src._length;
        for(int i = 0; i < _length; i++)
            _number[i] = src._number[i];
    }
}

_tabC::~_tabC() {
    delete[] _number;
}

uint64_t _tabC::length() const{
    return _length;
}

char _tabC::operator[](uint64_t i) const {
    if(i < _length)
        return _number[i];
    throw 1;
}

char& _tabC::operator[](uint64_t i) {
    if(i < _length)
        return _number[i];
    throw 1;
}

_tabC& _tabC::operator=(const _tabC& src) {
    if(!src._number) {
        _number = nullptr;
        _length = 0;
    }
    else {
        if(_number != src._number) {
            if(_number)
                delete[] _number;
            _init(src._length);
            _length = src._length;
            for(int i = 0; i < _length; i++)
                _number[i] = src._number[i];
        }
    }
}

/*
_tabC& _tabC::operator+(const _tabC& src) {
    char* tempNumber = _number;
    _init(_length + src._length);
    for(int i = 0; i < _length; i++)
        _number[i] = tempNumber[i];
    for(int i = _length - 1; i < _length + src._length; i++)
        _number[i] = src._number[i];
    _length += src._length;
    return *this;
}
*/

_tabC operator+(const _tabC& a, const _tabC& b) {
    _tabC result(a._length + b._length);
    for(int i = 0; i < a._length; i++)
        result[i] = a[i];
    for(int i = 0; i < b._length; i++)
        result[a._length - 1 + i] = b[i];
    return result;
}

_tabC& _tabC::operator+=(const _tabC& src) {
    *this = *this + src;
    return *this;
}

bool operator==(const _tabC& a, const _tabC& b) {
    if(a._length != b._length) return false;
    for(int i = 0; i < a._length; i++)
        if(a[i] != b[i]) return false;
    return true;
}

bool operator!=(const _tabC& a, const _tabC& b) {
    return !(a == b);
}

ostream& operator<<(ostream& out, const _tabC& src) {
    for(int i = 0; i < src._length; i++)
        out << src[i];
    return out;
}

// istream& operator>>(istream& in, _tabC& src) {
//     char* strIn;
//     scanf("%s", &strIn);
//     src = _tabC((uint64_t) strlen(strIn) - 1, strIn);
//     return in;
// }
// TODO: cin bez uzycia stringow


void _tabC::_init(const uint64_t size) {
    if(size == 0) return;
    try {
    _number = new char[size];
    }
    catch(const exception& e) {
        cout << e.what();
        _number = nullptr;
        _length = 0;
    }
}

void _tabC::_fill(const char* msg) {
    if(!msg) return;
    int i = 0;
    while(msg[i] != '\0' && i < _length) {
        _number[i] = msg[i];
        i++;
    }
}