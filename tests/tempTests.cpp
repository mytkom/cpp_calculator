#include "tempTests.hpp"

inline void test__tabC_Class() {
        try {
        _tabC a(10, "siemanowit"), b(10, "siemanowit");
        // cout << "wprowadz b: ";
        // cin >> b;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "a + b" << a + b << endl;
        a += b;
        cout << "a += b: " << a << endl;
        if(a == b) cout << "sa rowne" << endl;
        else cout << "nie sa rowne" << endl;
        if(a != b) cout << "nie sa rowne" << endl;
        else cout << "sa rowne" << endl;
        cout << "a[0]: " << a[0] << endl;
        a[0] = 'J';
        a[1] = 'D';
        cout << "a: " << a << endl;
        cout << a.length() << endl;
        _tabC c(a);
        cout << "c(a): " << c << endl;
        _tabC d(10, '!');
        cout << "d(10, '!'): " << d << endl;
    }
    catch(int& a) {
        cout << " ERROR NR.: " << a << endl;
    }
}

inline void test__bigInt_Class() {
    try
    {
        _bigInt f(_tabC(10, "0000000011"));
        cout << "length: " << f._getString().length() << endl;
        cout << "_bigInt a: " << f._getString() << endl;
    }
    catch(int& e) {
        cout << endl << "blad: " << e << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }
}