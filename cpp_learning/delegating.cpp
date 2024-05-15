#include <iostream>
using namespace std;

class Complex {
    int img;
    int real;

public:

    // constructor #1 (target constructor)
    Complex(int i, int r) : img(i), real(r) {}

    // constructor #2 (delegating constructor)
    // pass two zeroes as arguments to target constructor 
    Complex() : Complex(0, 0) {
        cout << "Delegating constructor" << endl;
        cout << "img = " << img << endl;
        cout << "real  = " << real << endl;
    }
};

int main() {

    // create an instance of class Complex
    // using the delegating constructor
    Complex obj; 

    return 0;
}