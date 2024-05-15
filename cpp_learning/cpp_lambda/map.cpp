#include <algorithm>
#include <vector>
#include <iostream>

void increase_cpp_map_1()
{
    // OutputIt transform(InputIt first1, InputIt last1,
    //                    OutputIt d_first, UnaryOp unary_op)
    // InputIt first1: elements.begin()
    // InputIt last1: elements.end()
    // OutputIt d_first: result_increase_list.begin()
    // UnaryOp unary_op: [](int a) { return a + 1; }
    std::vector<int> elements = {1, 2, 3, 4, 5};
    std::vector<int> result_increase_list(elements.size());
    std::transform(elements.begin(), elements.end(),
                   result_increase_list.begin(),
                   [](int a)
                   { return a + 1; });

    // print output
    std::cout << "The result increase list: {";
    for (size_t i = 0; i < result_increase_list.size(); ++i)
    {
        std::cout << result_increase_list[i];
        if (i != result_increase_list.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void sum_cpp_map_2()
{
    // OutputIt transform(InputIt first1, InputIt last1,
    //                    InputIt first2, OutputIt d_first, BinaryOp binary_op)
    // InputIt first1: l1.begin()
    // InputIt last1: l1.end()
    // InputIt first2: l2.begin()
    // OutputIt d_first: result_sum_list.begin()
    // BinaryOp binary_op: [](int a, int b) { return a + b; }
    std::vector<int> l1 = {1, 2, 3, 4, 5};
    std::vector<int> l2 = {7, 8, 9, 10, 11, 12};
    // the map will only iterate through the first 5 elements of l2
    // the size of the second list must NOT be less than the first list

    std::vector<int> result_sum_list(l1.size());
    std::transform(l1.begin(), l1.end(),
                   l2.begin(), result_sum_list.begin(),
                   [](int a, int b) -> int
                   { return a + b; });

    // print output
    std::cout << "The sum of l1 and l2: {";
    for (size_t i = 0; i < result_sum_list.size(); ++i)
    {
        std::cout << result_sum_list[i];
        if (i != result_sum_list.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void sum_cpp_map_twice_3()
{
    std::vector<int> l1 = {1, 2, 3};
    std::vector<int> l2 = {4, 5, 6};
    std::vector<int> l3 = {7, 8, 9};

    std::vector<int> container(l1.size());
    std::vector<int> res(l1.size());

    std::transform(l1.begin(), l1.end(),
                   l2.begin(), container.begin(),
                   [](int a, int b)
                   { return a + b; });
    std::transform(container.begin(), container.end(),
                   l3.begin(), res.begin(),
                   [](int a, int b)
                   { return a + b; });

    // print output
    std::cout << "The sum of l1, l2, l3: {";
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i];
        if (i != res.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void sum_cpp_map_advance_4()
{
    std::vector<int> l1 = {1, 2, 3};
    std::vector<int> l2 = {4, 5, 6};
    std::vector<int> l3 = {7, 8, 9};

    std::vector<int> res(l1.size());

    int index = 0;

    std::transform(l1.begin(), l1.end(),
                   l2.begin(), res.begin(),
                   [l3, &index](int a, int b)
                   { return a + b + l3[index++]; });

    // print output
    std::cout << "The sum of l1, l2, l3: {";
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i];
        if (i != res.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

void sum_cpp_map_subrange_5()
{
    std::vector<int> l1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> l2 = {7, 8, 9, 10, 11, 12, 13};
    std::vector<int> result_sum_list(l1.size() - 2); // make output size 5

    std::transform(l1.begin() + 1, l1.end() - 1,
                   l2.begin() + 2, result_sum_list.begin(),
                   [](int a, int b) -> int
                   { return a + b; });
    // {2, 3, 4, 5, 6} + {9, 10, 11, 12, 13} = {11, 13, 15, 17, 19}

    // print output
    std::cout << "The subrange sum of l1 and l2: {";
    for (size_t i = 0; i < result_sum_list.size(); ++i)
    {
        std::cout << result_sum_list[i];
        if (i != result_sum_list.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main()
{

    /********************* Unary Example **************************/
    increase_cpp_map_1(); // expect result list: {2, 3, 4, 5, 6}

    /********************* Binary Example *************************/
    sum_cpp_map_2(); // expect result list = {8, 10, 12, 14, 16}

    /********************* Ternary Example ************************/
    // Notice that std::transform() does NOT have a ternary version,
    //  achieve this by using std::transform() twice
    sum_cpp_map_twice_3(); // expect result list = {12, 15, 18}

    /********************* Advance Examples ***********************/
    // An advance example of apply transformation once to sum three lists
    // This use the capture feature of lambda function
    sum_cpp_map_advance_4(); // expect result list = {12, 15, 18}

    /********************* Example of Subrange ********************/
    sum_cpp_map_subrange_5(); // expect result list = {11, 13, 15, 17, 19}

    return 0;
}
