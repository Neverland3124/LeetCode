// Link: https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
// int foo() {return 2;}

// int main() {
//     foo() = 2;
//     return 0;
//     // will get error: lvalue required as left operand of assignment
// }

// Definition:
// - lvalue: An lvalue (locator value) represents an object that occupies some identifiable location
// in memory (i.e., has an address).

// - rvalue: defined by exclusion, i.e., an rvalue is an expression that is not an lvalue.
//   an expression that does not represent an object occupying some identifiable location in memory.

// int var;
// var = 42; // var is an lvalue, 42 is an rvalue

// 42 = var;
// (var + 1) // error: 42 and (var + 1) is an rvalue
// They are not lvalus because both are temporary results of expressions, which do not have an
// identifiable memory location.

// Working: foo() returns a reference, which is an lvalue, so it can be assigned to.
// #include <iostream>
// int globalvar = 20;

// int& foo() { return globalvar; }

// int main() {
//     foo() = 10;
//     // here foo() returns a reference to globalvar, so it can be assigned to.
//     // we call foo() and assign 10 to it.
//     std::cout << globalvar << std::endl;
//     // 10
//     std::cout << foo() << std::endl;
//     // 10
//     return 0;
// }

// conversions between lvalues and rvalues

// lvalues to rvalues
// int a = 1;     // a is an lvalue
// int b = 2;     // b is an lvalue
// int c = a + b; // + needs rvalues, so a and b are converted to rvalues
//                // and an rvalue is returned

// the unary '*' (dereference) operator takes an rvalue argument but produces an lvalue as a result.
// Consider this valid code: int arr[] = {1, 2}; // arr is lvalue and {1, 2} is rvalue

// int* p = &arr[0];   // 'arr[0]' is an lvalue because it refers to the first element of 'arr'.
// '&arr[0]' is an rvalue because it represents the address of 'arr[0]', which is a temporary value
// not associated with a storage location. 'p' is an lvalue because it is a variable that can store
// a memory address.

// *(p + 1) = 10;
// 'p + 1' is an rvalue because it results in a temporary value representing
// an address (the address of the second element of 'arr'). However, '*(p + 1)' is an lvalue because
// it refers to the location that 'p + 1' points to, allowing us to assign a value to it.

// #include <iostream>

// int main() {
//     int arr[] = {1, 2};
//     int* p = &arr[0];  // p points to the first element of arr

//     std::cout << "Value of arr[0]: " << arr[0] << std::endl;     // Output: 1
//     std::cout << "Address of arr[0]: " << &arr[0] << std::endl;  // Output: Address (e.g.,
//     0x1000) std::cout << "Value of p: " << p << std::endl;  // Output: Same address as above
//     (e.g., 0x1000) std::cout << "Value pointed to by p: " << *p << std::endl;  // Output: 1

//     // Value of arr[0]: 1
//     // Address of arr[0]: 0x7ffd3b16add0
//     // Value of p: 0x7ffd3b16add0
//     // Value pointed to by p: 1
//     *(p + 1) = 10;
//     std::cout << "Value of arr[1]: " << arr[1] << std::endl;  // Output: 10

//     return 0;
// }

// Conversely, the unary address-of operator '&' takes an lvalue argument and produces an rvalue:
// int var = 10;
// int* bad_addr = &(var + 1);
// var is lvalue, var + 1 is rvalue, so it will get error because & needs lvalue
// // ERROR: lvalue required as unary '&' operand
// int* addr = &var;
// here it's var is lvalue, so &var is rvalue
// // OK: var is an lvalue
// &var = 40;
// &var is rvalue, so it will get error
// // ERROR: lvalue required as left operand of assignment

// #include <iostream>
// #include <utility>

// using namespace std;
// class Intvec {
//    public:
//     explicit Intvec(size_t num = 0) : m_size(num), m_data(new int[m_size]) {
//         // explicit constructor, prevent implicit conversion
//         // parameter num
//         // initialize m_size with num
//         // allocate an array of integers of size m_size
//         log("constructor");
//     }

//     ~Intvec() {
//         log("destructor");
//         if (m_data) {
//             delete[] m_data;
//             m_data = 0;
//         }
//     }

//     Intvec(const Intvec& other) : m_size(other.m_size), m_data(new int[m_size]) {
//         // copy constructor
//         // takes a constant reference to another Intvec object (other) as its paramete
//         log("copy constructor");
//         for (size_t i = 0; i < m_size; ++i) {
//             m_data[i] = other.m_data[i];
//         }
//     }

//     Intvec& operator=(const Intvec& other) {
//         // const T& allowing the copy assignment operator to be invoked with a temporary object
//         as
//         // its argument
//         log("copy assignment operator");
//         Intvec tmp(other);
//         // Creates a temporary Intvec object as a copy of the source object using the copy
//         // constructor (Intvec tmp(other)).
//         std::swap(m_size, tmp.m_size);
//         std::swap(m_data, tmp.m_data);
//         return *this;
//     }

//     // Intvec& operator=(Intvec& other) {
//     //     // const T& allowing the copy assignment operator to be invoked with a temporary
//     object
//     //     as
//     //     // its argument
//     //     log("copy assignment operator not const");
//     //     Intvec tmp(other);
//     //     // Creates a temporary Intvec object as a copy of the source object using the copy
//     //     // constructor (Intvec tmp(other)).
//     //     std::swap(m_size, tmp.m_size);
//     //     std::swap(m_data, tmp.m_data);
//     //     return *this;
//     // }

//     Intvec& operator=(Intvec&& other) {
//         // && gives us a reference to an rvalue, which is goign to be destroyed after the call
//         log("move assignment operator");
//         cout << *this << endl;
//         cout << other << endl;
//         std::swap(m_size, other.m_size);
//         std::swap(m_data, other.m_data);
//         cout << *this << endl;
//         cout << other << endl;
//         return *this;
//     }

//     friend ostream& operator<<(ostream& out, const Intvec& v) {
//         for (size_t i = 0; i < v.m_size; ++i) {
//             out << v.m_data[i] << " ";
//         }
//         return out;
//     }

//    private:
//     void log(const char* msg) { cout << "[" << this << "] " << msg << "\n"; }

//     size_t m_size;
//     int* m_data;
// };

// int main() {
//     Intvec v1(20);
//     Intvec v2;

//     cout << "start assigning lvalue...\n";
//     // if we have the not const, it will call the not const version
//     v2 = v1;
//     cout << "ended assigning lvalue...\n";

//     // // start assigning lvalue...
//     // // because we have = operator, so it will call copy assignment operator
//     // // [0x7ffcee5d9420] copy assignment operator
//     // // in copy assignment operator, we have Intvec tmp(other), so it will call copy
//     constructor
//     // // [0x7ffcee5d93d0] copy constructor
//     // // when the copy is done, it will call destructor for tmp
//     // // [0x7ffcee5d93d0] destructor
//     // // ended assigning lvalue...

//     cout << "start assigning rvalue...\n";
//     v2 = Intvec(33);
//     // Intvec(33) is an rvalue, so it will call (Intvec&& other) constructor
//     cout << "ended assigning rvalue...\n";

//     cout << v1 << endl;
//     cout << v2 << endl;

//     // start assigning rvalue...
//     // Intvec(33) called the normal constructor
//     // [0x7ffdddf55f70] constructor
//     // = called copy assignment operator
//     // [0x7ffdddf55f60] copy assignment operator
//     // in call assignment operator, we have Intvec tmp(other), so it will call copy constructor
//     // [0x7ffdddf55f10] copy constructor
//     // [0x7ffdddf55f10] destructor
//     // [0x7ffdddf55f70] destructor
//     // ended assigning rvalue...
// }

// std::move and std::forward

// std::vector<int> vec1 = {1, 2, 3};
// std::vector<int> vec2 = std::move(vec1);
// // move vec1 to vec2, vec1 will be empty

#include <iostream>
template <typename Func, typename... Args>
// paramter: function, Args&&... args is a parameter pack of universal references,
auto wrapper(Func&& func, Args&&... args) -> decltype(func(std::forward<Args>(args)...)) {
    // The decltype keyword in C++ is used to query the type of an expression

    // It uses decltype to deduce the return type of calling func with args.... This is necessary
    // because the return type depends on the callable and its arguments.

    // return type will be the type of apply func to std::forward<Args>(args)...

    // std::forward<Args>(args)... perfectly forwards the arguments to func

    // Perfect Forwarding: Achieved using std::forward, it allows the function to forward arguments
    // to another function such that the original value category (lvalue or rvalue) of the arguments
    // is preserved.
    return func(std::forward<Args>(args)...);
}

int add(int a, int b) { return a + b; }
int add2(int&& a, int&& b) { return a + b; }

int main() {
    int result = wrapper(add, 1, 2);  // perfect forwarding 1 and 2 to add
    std::cout << result << std::endl;
    int x = 1, y = 2;
    int result2 = wrapper(add, x, y);  // perfect forwarding x and y to add
    std::cout << result2 << std::endl;

    int result3 = wrapper(add2, 1, 2);  // perfect forwarding 1 and 2 to add2
    std::cout << result3 << std::endl;
    int x2 = 1, y2 = 2;
    // int result4 = wrapper(add2, x2, y2);  // perfect forwarding x and y to add2
    // std::cout << result4 << std::endl;
    // error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
    // need to use std::move
    return 0;
}
