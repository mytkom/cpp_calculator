//includes
#include "lib/_tabC/_tabC.hpp"
#include "lib/_bigInt/_bigInt.hpp"
#include <map>
// #include "tests/tempTests.hpp"

//namespaces
using namespace std;

int main() {
    // test__tabC_Class();
    // test__bigInt_Class();
    // map<char, uint16_t> a = {{'a', 1}, {'b', 2}};
    // cout << a['a'] << a['b'];
    try{
        _bigInt a(_tabC("1")), b(_tabC("99999"));
       cout << (a+b)._getString() << endl;
       b += b;
       cout << b._getString() << endl;
    }
    catch(int a) {
        cout << "Error: " << a << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }


 
    return 0;
} //main