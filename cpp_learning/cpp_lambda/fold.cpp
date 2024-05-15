#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

void fold_sum_all_cpp_1()
{
    // T accumulate( InputIt first, InputIt last, T init );
    // InputIt first: l1.begin()
    // InputIt last: l1.end()
    // T init: 0
    std::vector<int> l1 = {1, 2, 3, 4, 5};

    int sum = std::accumulate(l1.begin(), l1.end(), 0);

    // print output
    std::cout << "The result of sum: " << sum << std::endl;
}

void fold_andCheck_cpp_2()
{
    // T accumulate( InputIt first, InputIt last, T init,
    //               BinaryOperation op);
    // InputIt first: l1.begin()
    // InputIt last: l1.end()
    // T init: true
    // BinaryOperation op: [](bool a, bool b) { return a && b; }
    std::vector<bool> l1 = {false, true, true, true, true};

    bool res = std::accumulate(l1.begin(), l1.end(), true,
                               [](bool a, bool b)
                               { return a && b; });

    // print output
    // here we use std::boolalpha to print out res in boolean value form, not 0 or 1.
    std::cout << "The result of res: " << std::boolalpha << res << std::endl;
}

int main()
{
    /********************* default operation addition example **************************/
    fold_sum_all_cpp_1(); // Expect: The result of sum: 15

    /********************* given custom operation example **************************/
    fold_andCheck_cpp_2(); // Expect: The result of res: false

    return 0;
}
