#include "lib/_tabC/_tabC.hpp"
#include "lib/_bigInt/_bigInt.hpp"
#include <map>
// #include "tests/tempTests.hpp"

using namespace std;

int main() {
    try{
        _bigInt a(_tabC("1000")), b(_tabC("10000"));
        if(a > b) cout << "a > b" << endl;
       cout << (a+b) << endl;
       b += b;
       cout << b << endl;
    }
    catch(int a) {
        cout << "Error: " << a << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }


 
    return 0;
} //main