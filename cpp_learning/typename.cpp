// https://mariusbancila.ro/blog/2021/03/15/typename-or-class/
#include <iostream>

// below template <typename T> can use class and typename interchangeably
template <typename T>
struct wrapper {
  using value_type = T;
  // using will make value_type a type alias for T

  value_type value;
};

template <typename T>
struct foo {
  T wrapped_value;

  // this specific one we cannot use class
  // the typename keyword is necessary here to tell the compiler that value_type is a type defined within T
  typename T::value_type get_wrapped_value() { return wrapped_value.value; }
  // You cannot use class in place of typename in this context because class
  // is used to define new types or as a template parameter keyword to indicate
  // that a template parameter is a type.
  // It does not serve the same purpose as typename in indicating that
  // a dependent name should be treated as a type.
};

int main() {
  foo<wrapper<int>> f{{42}};
  std::cout << f.get_wrapped_value() << '\n';
}