//includes
#include "lib/_tabC/_tabC.hpp"
#include "lib/_bigInt/_bigInt.hpp"
// #include "tests/tempTests.hpp"

//namespaces
using namespace std;

int main() {
    // test__tabC_Class();
    try
    {
        _bigInt a(_tabC(10, "0000000001"));
        cout << "length: " << a._getString().length() << endl;
        cout << "_bigInt a: " << a._getString() << endl;
    }
    catch(int& e) {
        cout << endl << "blad: " << e << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }
    return 0;
} //main