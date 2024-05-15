#include <algorithm>
#include <vector>
#include <iostream>

void filter_bigger_cpp_1()
{
    // OutputIt copy_if( InputIt first, InputIt last,
    //                   OutputIt d_first, UnaryPred pred );
    // InputIt first: l1.begin()
    // InputIt last: l1.end()
    // OutputIt d_first: filteredL1.begin()
    // UnaryPred pred: [](int a) { return a > 3; }
    std::vector<int> l1 = {1, 2, 3, 4, 5};
    std::vector<int> filteredL1;
    // Here we use back_inserter because we can not pre define
    // how much space does the filtered list L1 really needed.
    // We want to do it dynamicly assign space.
    std::copy_if(l1.begin(), l1.end(),
                 std::back_inserter(filteredL1),
                 [](int a)
                 { return a > 3; });

    // print output
    std::cout << "The result filtered list: {";
    for (size_t i = 0; i < filteredL1.size(); ++i)
    {
        std::cout << filteredL1[i];
        if (i != filteredL1.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void filter_mod3_cpp_2()
{
    std::vector<int> l1 = {11, 52, 93, 24, 35, 888, 99, 21, 62};
    std::vector<int> filteredL1;

    std::copy_if(l1.begin(), l1.end(),
                 std::back_inserter(filteredL1),
                 [](int a)
                 { return a % 3 == 0; });

    // print output
    std::cout << "The result filtered list: {";
    for (size_t i = 0; i < filteredL1.size(); ++i)
    {
        std::cout << filteredL1[i];
        if (i != filteredL1.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main()
{

    /********************* First Example **************************/
    filter_bigger_cpp_1(); // Expect: The result filtered list: {4, 5}

    /********************* Second Example *************************/
    filter_mod3_cpp_2(); // Expect: The result filtered list: {24, 888, 21, 99, 21}

    return 0;
}
