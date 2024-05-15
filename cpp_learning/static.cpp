#include <iostream>
using namespace std;

void test()
{
    // var is a static variable
    static int var = 0;
    // if not static output 11
    // if static output 1 2
    ++var;

    cout << var << endl;
}

int main()
{
    
    test();
    test();

    return 0;
}