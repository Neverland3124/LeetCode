/**
 * @file unique_ptr.cpp
 * @author Abigale Kim (abigalek)
 * @brief Tutorial code for usage of a unique pointer.
 */

// A smart pointer is a type of data structure used for memory management (and
// sometimes other features) in languages that don't have memory management
// built in (e.g C++) An example of a language that has memory management built
// in is any language with garbage collection, like Java or Python. Two of the
// modern C++ standard library's smart pointers (and the ones that you will use
// in class) are std::unique_ptr and std::shared_ptr. Both std::unique_ptr and
// std::shared_ptr handle memory allocation and deallocation automatically, and
// contain raw pointers under the hood. In other words, they are wrapper classes
// over raw pointers. In this file, we'll talk about std::unique_ptr.
// std::unique_ptr is a type of smart pointer that retains sole ownership of an
// object This means that no two instances of std::unique_ptr can manage the
// same object.

// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes std::unique_ptr functionality.
#include <memory>
// String library for printing help for demo purposes.
#include <string>
// Including the utility header for std::move.
#include <utility>

// Basic point class. (Will use later)
class Point {
 public:
  Point() : x_(0), y_(0) {}
  Point(int x, int y) : x_(x), y_(y) {}
  inline int GetX() { return x_; }
  inline int GetY() { return y_; }
  inline void SetX(int x) { x_ = x; }
  inline void SetY(int y) { y_ = y; }

 private:
  int x_;
  int y_;
};

// Function that takes in a unique pointer reference and changes its x value to
// 445.
// Parameter is a reference to a unique pointer
void SetXTo445(std::unique_ptr<Point> &ptr) { ptr->SetX(445); }
// void SetXTo445(std::unique_ptr<Point> ptr) { ptr->SetX(445); }

int main() {
  // This is how to initialize an empty unique pointer of type
  // std::unique_ptr<Point>.
  std::unique_ptr<Point> u1;
  // This is how to initialize a unique pointer with the default constructor.
  std::unique_ptr<Point> u2 = std::make_unique<Point>();
  // Note: make_unique from c++14
  // std::unique_ptr<int> ptr(new int(42)); // C++11 way, without std::make_unique

  // This is how to initialize a unique pointer with a custom constructor.
  std::unique_ptr<Point> u3 = std::make_unique<Point>(2, 3);
  // std::unique_ptr<Point> u3(new Point(2, 3));

  // Here, for std::unique_ptr instance u, we use the statement (u ? "not empty"
  // : "empty") to determine if the pointer u contains managed data. The main
  // gist of this is that the std::unique_ptr class has a conversion function on
  // its objects to a boolean type, and so this function is called whenever we
  // treat the std::unique_ptr as a boolean. For instance, this can be used in
  // the following example.

  // We can use the unique pointer instance as a boolean to check if it is empty
  if (u1) {
    // This won't print because u1 is empty.
    std::cout << "u1's value of x is " << u1->GetX() << std::endl;
  }

  if (u2) {
    // This will print because u2 is not empty, and contains a managed Point
    // instance.
    std::cout << "u2's value of x is " << u2->GetX() << std::endl;
  }

  // Note that u1 is empty and u2 and u3 are not empty, since they were
  // initialized with a Point instance.
  std::cout << "Pointer u1 is " << (u1 ? "not empty" : "empty") << std::endl;
  std::cout << "Pointer u2 is " << (u2 ? "not empty" : "empty") << std::endl;
  std::cout << "Pointer u3 is " << (u3 ? "not empty" : "empty") << std::endl;

  // Since instances of std::unique_ptr can have only one owner, it has no copy
  // constructor. Therefore, this code won't compile. Uncomment it to try!
  // std::unique_ptr<Point> u4 = u3;
  // std::unique_ptr<Point> u4(u3); // same as above

  // Notes: unique pointer, therefore we cannot have both pointer u3 and u4 point to the same object, that's why std::unique_ptr<Point> u4 = u3 will be wrong
  // use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Point;
  // _Dp = std::default_delete<Point>]’
  // the copy operator= is deleted

  // However, it's possible to transfer ownership of unique pointers via
  // std::move.
  // u3 is lvalue at first, now it's a rvalue so we can set u4 to u3
  std::unique_ptr<Point> u4 = std::move(u3);

  // Note that because u3 is an lvalue, it no longer contains any managed
  // object. It is an empty unique pointer. Let's retest for emptyness.
  std::cout << "Pointer u3 is " << (u3 ? "not empty" : "empty") << std::endl;  // empty
  std::cout << "Pointer u4 is " << (u4 ? "not empty" : "empty") << std::endl;  // not empty

  // Lastly, let's talk about how to pass std::unique_ptr instances as arguments
  // to functions. Mainly, you should pass it as a reference so that the
  // ownership doesn't change. You can see this as an example in the function
  // SetXTo445 (line 44 in this file).
  std::unique_ptr<Point> &u5 = u4;
  std::cout << "Pointer u5's x value is " << u5->GetX() << std::endl;
  // SetXTo445(u4);
  // Notes: cpp different from c where we don't need to include & when call the function of parameter is reference, in
  // c, we will need to call by SetXTo445(&u4); and in function parameter, we need SetXTo445(type *ptr)
  SetXTo445(u5);
  // initial value of reference to non-const must be an lvalue

  // Now, let's print the x value of u4 to confirm that the change occured, but
  // the ownership of the Point instance has been retained to u4.
  std::cout << "Pointer u4's x value is " << u4->GetX() << std::endl;
  std::cout << "Pointer u5's x value is " << u5->GetX() << std::endl;

  return 0;
}