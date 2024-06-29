// Pointer to Constant Integer (const int *ptr):
// The integer value cannot be modified through the pointer.
// const int *ptr = &value;

// Constant Pointer to Integer (int *const ptr):
// The pointer itself cannot be changed, but the integer value it points to can be modified.
// int *const ptr = &value;

// Constant Pointer to Constant Integer (const int *const ptr):
// Neither the pointer nor the integer value it points to can be changed.
// const int *const ptr = &value;
// Example for Constant Pointer to Integer

#include <iostream>
int main() {
    /***  Pointer to Constant Integer ***/
    int value = 10;
    const int *ptr = &value;

    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // *ptr = 20;  // This will cause a compilation error because ptr points to a const int

    value = 20;  // This is allowed because value itself is not const
    std::cout << "Modified value: " << *ptr << std::endl;

    int value4 = 30;
    ptr = &value4;  // This is allowed because ptr itself is not const
    std::cout << "value4 value: " << *ptr << std::endl;

    /***  Constant Pointer to Integer ***/
    int value1 = 10;
    int value2 = 20;
    int *const ptr2 = &value1;

    std::cout << "Value pointed to by ptr2: " << *ptr2 << std::endl;

    *ptr2 = 30;  // This is allowed
    std::cout << "Modified value: " << *ptr2 << std::endl;

    // ptr2 = &value2;  // This will cause a compilation error because ptr is a constant pointer
    // cannot change to point to another memory location

    /***  Constant Pointer to Constant Integer ***/
    int value3 = 10;
    const int *const ptr3 = &value3;

    std::cout << "Value pointed to by ptr: " << *ptr3 << std::endl;

    // *ptr3 = 20;  // This will cause a compilation error because ptr points to a const int
    // ptr3 = &value2;  // This will also cause a compilation error because ptr is a constant
    // pointer

    return 0;
}
