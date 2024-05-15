#include <algorithm>
#include <vector>
#include <iostream>

void sum_cpp_lambda1()
{
    // [captures](parameters) -> return_type { // body }
    // captures: [] - no capture
    // parameters: int c, int d - two integers
    // return type: void
    // body: sum of c and d
    int a = 1;
    int b = 2;
    // the auto keyword is used for type inference, allowing the compiler to automatically deduce the type of a variable from its initialize
    // here it is used to give the lambda function a name
    auto sumAll = [](int c, int d) -> void
    {
        int sum = c + d;
        // a and b are not accessible
        std::cout << "The sum of c, d: " << sum << std::endl; // expect sum = 7
    };
    sumAll(3, 4);
}

void sum_cpp_lambda2()
{
    // [captures](parameters) -> return_type { // body }
    // captures: [=] - capture all variables by value (read-only)
    int a = 1;
    int b = 2;
    auto sumAll = [=](int c, int d) -> void
    {
        int sum = a + b + c + d; // a = 1, b = 2
        // a = 5; is not allowed here because a is read-only in capture [=]
        std::cout << "The sum of all a, b, c, d: " << sum << std::endl;
    };
    sumAll(3, 4);
}

void sum_cpp_lambda3()
{
    // [captures](parameters) -> { // body }
    // captures: [&] - capture all variables by reference (read-write)
    int a = 1;
    int b = 2;
    auto sumAll = [&](int c, int d)
    {
        a = 2;                   // assign new value to a
        b = 3;                   // assign new value to b
        int sum = a + b + c + d; // a = 2, b = 3
        std::cout << "The sum of all a, b, c, d: " << sum << std::endl;
    };
    sumAll(3, 4);
}

void sum_cpp_lambda4()
{
    // [captures](parameters) -> { // body }
    // captures: [a, &b] - capture a by value and b by reference
    int a = 1;
    int b = 2;
    auto sumAll = [a, &b](int c, int d)
    {
        b = 3;
        int sum = a + b + c + d;                                        // a = 1, b = 3
        std::cout << "The sum of all a, b, c, d: " << sum << std::endl; // expect sum = 11
    };
    sumAll(3, 4);
}

void sum_cpp_lambda5()
{
    // [captures](parameters) -> { // body }
    // captures: [=, &b] - capture all other variables by value and b by reference
    int a = 1;
    int b = 2;
    int e = 10;
    auto sumAll = [=, &b](int c, int d)
    {
        b = 3;
        int sum = a + b + c + d + e;                                    // a = 1, b = 3, e = 10
        std::cout << "The sum of all a, b, c, d: " << sum << std::endl; // expect sum = 21
    };
    sumAll(3, 4);
}

void sum_cpp_lambda6()
{
    // [captures](parameters) -> { // body }
    // captures: [&, a] - capture all other variables by reference and a by value
    int a = 1;
    int b = 2;
    int e = 10;
    auto sumAll = [&, a](int c, int d)
    {
        b = 3;
        e = 11;
        int sum = a + b + c + d + e;                                    // a = 1, b = 3, e = 11
        std::cout << "The sum of all a, b, c, d: " << sum << std::endl; // expect sum = 22
    };
    sumAll(3, 4);
}

void sort_ascending(std::vector<int> &nums)
{
    // [captures](parameters) -> return_type { // body }
    // captures: [] - no capture
    // parameters: (int a, int b) - two integers
    // return_type: bool
    // body: return true if a > b, false otherwise
    std::sort(nums.begin(), nums.end(), [](int a, int b) -> bool
              {
                  return a < b; // Ascending order
              });

    std::cout << "Ascending order: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

void module_by_2(std::vector<int> &nums)
{
    // [captures](parameters) -> return_type { // body }
    // captures: [] - no capture
    // parameters: int& num - reference to an integer
    // return_type: void
    // body: assign num to num % 2
    std::for_each(nums.begin(), nums.end(), [](int &num) -> void
                  { num = num % 2; });

    std::cout << "Module by 2: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

int main()
{

    /********************* Using capture [] **************************/
    sum_cpp_lambda1(); // expect sum = 7

    /********************* Using capture [=] *************************/
    sum_cpp_lambda2(); // expect sum = 10

    /********************* Using capture [&] *************************/
    sum_cpp_lambda3(); // expect sum = 12

    /********************* Using capture [x, &y] *********************/
    sum_cpp_lambda4(); // expect sum = 11

    /********************* Using capture [=, &y] *********************/
    sum_cpp_lambda5(); // expect sum = 21

    /********************* Using capture [&, x] **********************/
    sum_cpp_lambda6(); // expect sum = 22

    /********************* Advance Examples **************************/
    std::vector<int> nums = {3, 1, 4, 1, 5, 9};
    sort_ascending(nums); // expect output: 1 1 3 4 5 9
    module_by_2(nums);    // expect output: 1 1 1 0 1 1

    return 0;
}
