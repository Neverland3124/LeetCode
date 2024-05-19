## C++

### links

- https://www.programiz.com/cpp-programming/getting-started

### What should i learn?

- difference of c and c++
- basic types
  - arrays
    - int x[] = {1, 2, 3, 4, ...};
  - strings
    - cstrings
      - char str[] = "C++";
    - get string functions
      - cin >> str
      - cin.get(str, 100);
      - if use string str; we can use getline(cin, str);
    - c++ string class
      - find(), rfind() - find the last occur substring, append(), insert(), erase(), replace(), compare()
  - pointer
    - int\* point_var = &var;
    - ptr = &arr[0] **same as** ptr = arr
    - \*(arr + i) **equivalent to** cin >> arr[i]
    - sring& ref_city = city; (create a reference to alias ref_city with city)
      - We must initialize references at the time of declaration.
    - int\* point_var = new int{45};
      - **new** allocate memory in run time
      - because the new expression returns the address of the memory location
      - delete[] ptr; (use the square brackets [] in order to denote that the memory deallocation is that of an array)
  - struct
    - Member Functions in C++ Structures
    - Person p {"John", "Doe", 22, 145000}; // initialize the structure variable
    - (\*ptr).x = ptr->x
  - enumeration
    - enum season { spring, summer, autumn, winter };
    - enum designFlags {xxx} button; (variable button with type denum designFlags)
- classes

  - access modifiers
    - default is private
    - public
    - protected
      - used for inherit class to access the method or variable
      - don't allow to call the method or use the varible directly
    - private
    ```
    | Specifiers | Same Class | Derived Class | Outside Class |
    |------------|------------|---------------|---------------|
    | public     | Yes        | Yes           | Yes           |
    | private    | Yes        | No            | No            |
    | protected  | Yes        | Yes           | No            |
    ```
  - constructor
    - default constructor
      - Wall() = default;
      - double length {5.5};
    - constructor list
      - Wall(double len, double hgt)
      - : length{len}
      - , height{hgt} {
      - }
    - copy constructor
      - Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {}
      - If we don't define any copy constructor, move constructor, or move assignment in our class, then the C++ compiler will automatically create a default copy constructor that does memberwise copy assignment.
    - copy assignment operator
      - Buffer& operator=(const Buffer& other) {}
      - operator is a keyword
        - can overload like bool operator>(const Point& other) const {}
  - data hiding
    - using getter and setter to make variable private
  - friend function
    - friend function can access the private and protected data of a class
    - ClassA and ClassB have declared add() as a friend function. Thus, this function can access private data of both classes
  - friend class
    - a class is declared a friend class, all the member functions of the friend class become friend functions
  - inherenit
    - inherenit <==> is-a relationship
    - dog inherenit animal <==> dog is an animal
  - access modes

    - public: If a derived class is declared in public mode, then the members of the base class are inherited by the derived class just as they are.
    - private: In this case, all the members of the base class become private members in the derived class.
    - protected: The public members of the base class become protected members in the derived class.

    ```cpp
    class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
    };

    class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
    };

    class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
    };

    class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
    };
    ```

  - multiple inheritance

    - in cpp, a class can be derived from more than one parent. For example, A class Bat is derived from base classes Mammal and WingedAnimal
    - class Bat: public Mammal, public WingedAnimal {};
    - ambiguity
      - If you try to call the function using the object of the derived class, the compiler shows error. It's because the compiler doesn't know which function to call. For example,
      - solution:

    ```cpp
    int main() {
        obj.base1::someFunction( );  // function of base1 class is called
        obj.base2::someFunction();   // function of base2 class is called.
    }
    ```

  - virtual inheritance

    ```cpp
    class Base {
    ... .. ...
    };

    class Derived1 : virtual public Base {
    ... .. ...
    };

    class Derived2 : virtual public Base {
    ... .. ...
    };

    class Derived3 : public Derived1, public Derived2 {
    ... ... ...
    };
    ```

  - Overload function
    - default is to call the shadow function from derived class
    - to call the base function, will need derived.Base::function()
    - or in the derived class function, call overridden function Base::function();
    - or to use a base pointer:
      - Derived derived1; Base\* ptr = &derived1; ptr->print();
  - virtual

    - allow a member function of a class to be overridden in derived classes
    - used similar as abstract in java
    - also remember virtual destructure
    - ~ in cpp is destructure
      - virtual ~Shape() = default;
      - use virtual in destructor allows deallocate the derived class memory instead of base class when we use base class pointer

    ```cpp
    #include <iostream>
    using namespace std;

    class Base {
    public:
        virtual void print() {
            cout << "Base Function" << endl;
        }
    };

    class Derived : public Base {
    public:
        void print() override {
            cout << "Derived Function" << endl;
        }
    };

    int main() {
        Derived derived1;

        // pointer of Base type that points to derived1
        Base* base1 = &derived1;

        // calls member function of **Derived class**
        base1->print();

        return 0;
    }
    ```

  - override keyword
    - C++ 11 provides a new specifier override that is very useful to avoid common mistakes while using virtual functions.
    - If we use function prototype in Derived class, then we use override specifier in the function declaration only, not in the definition.
  - pure virtual function
    - A pure virtual function doesn't have the function body and it must end with = 0.
    - virtual void calculateArea() = 0;
  - Abstract Class:
    - A class that contains a pure virtual function is known as an abstract class.

- cpp stl (C++ Standard Template Library)

  - vector
    - vector<T>
      - can use int, double, custom class, and pointer (pointer is weird)
    - vector<int> vector1 = {1, 2, 3, 4, 5};
    - vector<int> vector3(5, 12); // size 5, value 12
    - vector<int> num {1, 2, 3, 4, 5};
      - num.push_back(6);
      - num.at(0)
      - num[0]
      - num.pop_back();
      - size() returns the number of elements present in the vector
      - clear() removes all the elements of the vector
      - front() returns the first element of the vector
      - back() returns the last element of the vector
      - empty() returns 1 (true) if the vector is empty
      - capacity() check the overall size of a vector
    - iterator for vector
      - vector<int>::iterator iter;
      - iter = num.begin(); // first element
      - iter = num.end() - 1; // last element
  - iterator
    - vector<int>::iterator it;
    - vector<int> numbers = {3, 2, 5, 1, 4};
    - vector<int>::iterator itr1 = numbers.begin();
    - vector<int>::iterator itr2 = numbers.end();
  - set
    - #include <set>
    - set<int> numbers = {1, 100, 10, 70, 100};
    - property
      - numbers are sorted in ascending order with duplicate numbers removed
      - unique elements
      - immutable (cannot change the value of existing)
      - sorted order
      - associative (by key not position)
    - To get the elements of a set sorted in descending order
      - set<int, greater<int>> my_set;
    - methods
      - insert() Insert elements into a set.
      - erase() Delete elements from a set.
      - clear() Remove all the elements from a set.
      - empty() Check if the set is empty.
      - size() Returns the size of the set.
  - unordered_set
    - #include <unordered_set>
    - unordered_set<int> numbers = {1, 100, 10, 70, 100};
  - stack
    - #include <stack>
    - stack<int> numbers;
    - numbers.push(1);
    - numbers.top()
    - numbers.pop();
  - array
    - #include <array>
    - std::array<T, N> array_name;
      - T - Type of element to be stored
      - N - Number of elements in the array
    - std::array<int, 5> n = {1, 2, 3, 4, 5};
      - n[0] // returns 1
      - n.at(0) // returns 1
    - n.empty(); // return true or false
    - n.size();
    - n.fill(0); // fill the array with zeros
    - sort(age.begin(), age.end());
    - auto found = find(age.begin(), age.end(), 5); // check if the number 5 is present or not
    - int sum = std::accumulate(age.begin(), age.end(), 0); // get the sum
  - list
    - A doubly linked list
    - look like linklist, have two links one to previous, one to next
    - #include<list>
    - std::list<Type> list_name = {value1, value2, ...};
    - add element
      - push_front(), push\_\_back()
    - access elements
      - front(), back()
    - delete
      - pop_front(), pop_back()
      - reverse() Reverses the order of the elements.
      - sort() Sorts the list elements in a particular order.
      - unique() Removes consecutive duplicate elements.
      - empty() Checks whether the list is empty.
      - size() Returns the number of elements in the list.
      - clear() Clears all the values from the list
      - merge() Merges two sorted lists.
  - forward list
    - A singly linked list.
    - Each element points only to its next element.
    - compare
      - sequence containers ordered in a strict linear sequence
      - add or remove elements anywhere in the sequence with constant time efficiency
      - more efficient in insertion, moving, and extracting elements compared to containers like array, vectors, etc
      - direct random access is not supported in forward lists
      - Does not support push_back and pop_back because it’s singly linked.
    - #include <forward_list>
    - std::forward_list<data_type> forward_list_name = {value1, value2, value3, ...};
    - front() Access the front element.
    - push_front() Add an element to the start of the list.
    - insert_after() Add an element at the position right after the given position.
    - assign() Assign new contents to the list by replacing the current contents.
    - pop_front() Remove the element at the front.
    - remove() Remove elements with specific values.
    - clear() Delete all the contents of the list.
  - queue
    - FIFO
    - #include <queue>
    - queue<type> q;
    - push() Inserts an element at the back of the queue.
    - pop() Removes an element from the front of the queue.
    - front() Returns the first element of the queue.
    - back() Returns the last element of the queue.
    - size() Returns the number of elements in the queue.
    - empty() Returns true if the queue is empty.
  - deque
    - a double-ended queue
    - we can insert and remove elements from both the front and rear
    - #include <deque>
    - deque<type> dq;
    - push_back() inserts element at the back
    - push_front() inserts element at the front
    - pop_back() removes element from the back
    - pop_front() removes element from the front
    - front() returns the element at the front
    - back() returns the element at the back
    - at(x) sets/returns the element at specified index
      - same as nums[x]
    - size() returns the number of elements
    - empty() returns true if the deque is empty
  - priority queue
    - removed on the basis of priority
    - priority_queue.cpp
  - stack
    - LIFO
    - #include <stack>
    - stack<type> st;
    - push() adds an element into the stack
    - pop() removes an element from the stack
    - top() returns the element at the top of the stack
    - size() returns the number of elements in the stack
    - empty() returns true if the stack is empty
  - map
    - #include <map>
    - std::map<key_type, value_type> map_name = {{key1, value1},{key2, value2}, ...};
      - can also initialize map elements without using the assignment operator =
      - std::map<int, string> student = {{1,"Jacqueline"}, {2,"Blake"}, {3,"Denise"}};
      - std::map<int, string> student {{1,"Jacqueline"}, {2,"Blake"}, {3,"Denise"}};
    - add value
      - insert() adds an element (key-value pair) to the map
      - std::map<int, string> student;
      - use student[x] = "xxx" to add key-value pairs
      - or student.insert(std::make_pair(3, "Denise"));
    - erase() removes an element or range of elements from the map
      - can erase by key or iterator or a range
      - student_rank.erase("Rachel");
      - student_rank.erase(itr);
      - my_map.erase(itr_first, itr_last)
    - clear() removes all the elements from the map
    - find() searches the map for the given key
      - map_name.find(key);
    - size() returns the number of elements in the map
    - empty() returns true if the map is empty
    - iterator
      - student[1] = "Jacqueline";
      - map<int, string>::iterator iter;
      - cout << (\*iter).first << " - "; // Output: 1
      - cout << (\*iter).second; // Output: Jacqueline
  - multimap
    - std::multimap<key_type, value_type> multimap_name = { {key1, value1}, {key2, value2}, ...};
    - multimap can have a key have different value
    - methods
      - insert() inserts one or more key-value pairs
      - count() returns total number of occurrences of the specified key
      - find() returns the iterator to the element with the specified key
        - iterator to the element if the key is found
        - iterator to the end of the container (the end() iterator) if the key is not found
        - used the find() method to check if the key 27 exists
        ```cpp
        if (students.find(27) != students.end()) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        ```
      - size() returns the number of elements
      - empty() returns true if the multimap is empty
      - erase() removes elements with specified key
      - clear() removes all elements
  - multiset
    - property
      - associative (by key not position)
      - sorted order
      - equivalent keys
      - immutable (cannot change the value of existing)
    - #include <set>
    - std::multiset<data_type> multiset_name = {key1, key2, key3, ...};
    - decreasing order: multiset<int, greater<int>> my_multiset ;
    - insert, erase, clear, empty, size
  - unordered map
    - the unordered map is implemented as a hash table data structure whereas the regular map is a binary search tree data structure
    - Starting from C++17, you can use structure bindings to simplify this code further:
      - for(const auto& [key, value]: unordered_map1) {
      -             cout << key << " -  " << value << endl;
      - }
    - insert, count, find, at, size, empty, erase, clear
  - unordered_multiset
  - unordered_multimap

- iterators
  - notations
    - \*itr returns the element at the current position
    - itr->m returns the member value m of the object pointed by the iterator and is equivalent to (\*itr).m
    - ++itr moves iterator to the next position
    - -–itr moves iterator to the previous position
    - itr + i moves iterator by i positions
    - itr1 == itr2 returns true if the positions pointed by the iterators are the same
    - itr1 != itr2 returns true if the positions pointed by the iterators are not the same
    - itr = itr1 assigns the position pointed by itr1 to the itr iterator
  - input iterator
    - istream_iterator<int> input_itr(cin);
    - ++ \* -> == !=
  - output iterator
    - ++ 8 ->
  - forward iterator
    - for forward_list
    - ++ \* -> == !=
  - Bidirectional Iterator
    - list, set, multiset, map, multimap
    - ++ -- \* -> == !=
  - Random Access Iterator
    - vector, deque, array
    - ++ -- \* [] -> + - < <= > >= == !=
- operaters
  - & Binary AND
  - | Binary OR
  - ^ Binary XOR
  - ~ Binary One's Complement
  - << Binary Shift Left
  - \>> Binary Shift Right
  - & represents memory address of the operand &num; // address of num
  - . accesses members of struct variables or class objects s1.marks = 92;
  - -> used with pointers to access the class or struct variables ptr->marks = 92;
  - << prints the output value cout << 5;
  - \>> gets the input value cin >> num;
- function
  - inline function in cpp
    - this will copy the function itself to where the argument are to make running faster
  - auto function: can use as function return type and lambda function input parameter type
- algorithm
  - sort() Sort the elements of the container.
    - sort(first, last);
    - first - iterator specifying the beginning of the sorting range (inclusive)
    - last - iterator specifying the end of the sorting range (exclusive)
  - copy() Copy elements within a given range.
    - copy(first, last, result);
    - first - iterator specifying the beginning of the range to copy (inclusive)
    - last - iterator specifying the end of the range to copy (exclusive)
    - result - iterator specifying the position in the destination vector where the elements will be copied
  - move() Move the given range of elements.
    - move(first, last, result);
  - swap() Exchange values of two objects.
    - swap(x, y);
  - merge() Merge sorted ranges.
    - merge(first1, last1, first2, last2, result);
    - first1, last1 - iterators specifying the first input range.
    - first2, last2 - iterators specifying the second input range.
    - result - iterator specifying the beginning of the destination range.
  - replace() Replace the value of an element.
    - replace(first, last, old_value, new_value);
    - first, last - iterators specifying the range to transform.
    - old_value - value to be replaced.
    - new_value - replacement value.
  - remove() Remove an element.
    - remove(first, last, val);
    - first, last - iterators specifying the range to transform
    - val - value to be removed
- Functor
  - overloaded the function call operator ()
  - void operator()() {}
  - int operator()(int a, int b) { return a + b; }
  - C++ Predefined Functors
    - #include <functional>
    - plus returns the sum of two parameters
    - minus returns the difference of two parameters
    - multiplies returns the product of two parameters
    - divides returns the result after dividing two parameters
    - modulus returns the remainder after dividing two parameters
    - negate returns the negated value of a parameter
    - equal_to returns true if the two parameters are equal
    - not_equal_to returns true if the two parameters are not equal
    - greater returns true if the first parameter is greater than the second
    - greater_equal returns true if the first parameter is greater than or equal to the second
    - less returns true if the first parameter is less than the second
    - less_equal returns true if the first parameter is less than or equal to the second
    - logical_and returns the result of Logical AND operation of two booleans
    - logical_or returns the result of Logical OR operation of two booleans
    - logical_not returns the result of Logical NOT operation of a boolean
- Exception Handling

  - try, throw, catch

  ```cpp
  try {

      // code that may raise an exception
      throw argument;
  }

  catch (exception) {
      // code to handle exception
  }
  ```

  - standard
    - std::exception The parent class of all C++ exceptions.
    - std::bad_alloc Thrown when a dynamic memory allocation fails.
    - std::bad_cast Thrown by C++ when an attempt is made to perform a dynamic_cast to an invalid type.
    - std::bad_exception Typically thrown when an exception is thrown and it cannot be rethrown.
    - in exception header file

- File Handling
  - #include <fstream>
    - include two classes ifstream & ofstream
  - std::ofstream my_file("example.txt");
  - std::ofstream my_file.open("example.txt");
  - my_file.close();
  - ofstream my_file("example.txt");
  - my_file.is_open()
  - my_file.fail()
  - while (!my_file.eof()) {}
  - getline(my_file, line);
  - append
    - ofstream my_file("example.txt", ios::app);
    - ios::in / ios::out / ios::app
- Loop
  - int var : num - Copies each element of num to the var variable in each iteration. This is not good for computer memory.
  - int &var : num - Does not copy each element of num to var. Instead, accesses the elements of num directly from num itself. This is more efficient.
- Templates
  - template <typename T>
  - T add(T num1, T num2) {}
  - a single function to work with different data types by using a template.
  - When an argument of a data type is passed to functionName(), the compiler generates a new version of functionName() for the given data type.
- class templates
  - template <class T>;
  - Number<int> numberInt(7);
  - Number<double> numberDouble(7.7);
  - multiple parameters
    - template <class T, class U, class V = int>;
- type convension
  - static_cast
    - for standard type conversions, such as converting from float to int
    - int my_int = static_cast<int>(my_float);
  - dynamic_cast
    - for polymorphic type conversions, especially when dealing with inheritance hierarchies
    - Derived _derived_ptr = dynamic_cast<Derived_>(base_ptr);
  - const_cast
    - cast away the const qualifier from a variable
    - used to remove const and allow modification
    - int* mutable_ptr = const_cast<int*>(ptr);
  - reinterpret_cast
    - convert one pointer type to another pointer type or one reference type to another reference type
    - int\* ptr_to_int = &x;
    - char* ptr_to_char = reinterpret_cast<char*>(ptr_to_int);
    - the memory location pointed by ptr_to_int still holds an integer value. But it will be treated as a characteru
- C++11, ISO/IEC 14882:2011

  - auto keyword
  - range based for loops
  - lambda expression
    ```cpp
    [capture_clause] (parameter_list) -> return_type {
        // lambda body: Code to be executed
    }
    ```
  - smart pointers
    - a smart pointer automatically releases the memory it manages when it goes out of scope
    - need to import the <memory> header
    - unique pointers
      - have exclusive ownership of the objects they point to
      - std::unique_ptr<data_type> unique_pointer = std::make_unique<data_type>(args...);
    - shared pointers
      - allow multiple shared pointers to own a single object
      - std::shared_ptr<Type> shared_pointer = std::make_shared<data_type>(args...);
  - move semantics
    - move()
    - the resources owned by an object to be moved into another object instead of copying them
    - vector<int> source = {1, 2, 3};
    - vector<int> destination = move(source);
  - constexpr
    - specify that a variable or function can be evaluated at compile-time
    - constexpr int square(int x) { return x \* x; }
    - int result = square(5); // computed at compile-time
  - null pointer
    - int\* ptr = nullptr;
    - Always prefer nullptr over NULL because of the safety nullptr provides over NULL.
  - class templates / function templates
  - thread support
    - #include <thread>
    - std::thread t(sayHello);
    - t.join();
  - Delegating Constructors
    - a constructor may call another constructor of the same class
    - Complex(int i, int r) : img(i), real(r) {}
    - Complex() : Complex(0, 0) { }
  - deleted function
    - prevent certain operations on your class
      - prevent copy constructor
        - NonCopyable(const NonCopyable&) = delete; // Disable copy constructor
        - NonCopyable& operator=(const NonCopyable&) = delete; // Disable copy assignment
      - prevent dynamic allocation
        - void\* operator new(size_t) = delete; // Prevent dynamic allocation
        - void\* operator new[](size_t) = delete; // Prevent array dynamic allocation
    - My_Class() = delete;
    - void do_something() = delete;
  - defaulted function
    - // use the compiler-generated default constructor
    - Another_Class() = default;
      - will assign int to 0
      - string to empty string
      - array to indeterminate values

- Namespaces

  - naming conflict
    - int var; double var; // error
    - int var; { double var; } // working
  - use namespace keyword
    - namespace dbl { double var; }
    - dbl::var
  - using namespace std;
    - bypass of using ::
      - std::cout -> count
      - std::cin -> cin

- Preprocessors and Macros
  - #include <iostream>
  - all preprocessor directives begin with the # symbol.
    - For example, #include, #define, #if, and so on.
    - #include - to include header files
    - #define - to define macros
    - #if - to provide conditional compilation
  - #include <cmath>
    - The #include directive tells the preprocessor to replace the above line of code with the contents of the cmath header file.
      - then pow() / sqrt() can be used
  - #include "path_to_file/my_header.h"
    - for custom header file
  - #define
    - #define PI 3.1415 // value of pi
    - PI is known as a macro
    - function like macros
      - #define circleArea(r) (3.1415 _ r _ r)
  - #if
    - The if...else statements are tested during execution time to check if the block of code should be executed or not.
    - On the other hand, conditional directives are tested by the preprocessor before compilation to decide whether to include a block of code in the program or not.
    - #if (x > 0)
    - #else
    - #endif
    - reason
      - platform code
        - #ifdef \_WIN32
          - \_WIN32 - a macro defined by the Microsoft Visual C++ compiler on Windows platforms
        - #elif \_\_linux\_\_
          - \_\_linux\_\_ - a macro defined by GNU C Compiler on Linux systems
        - #else
        - #endif
      - debugging code
      - toggle feature of
      - ...
  - predefined macros
    - \_\_DATE\_\_ A string containing the current date.
    - \_\_FILE\_\_ A string containing the file name of the currently executing program.
    - \_\_LINE\_\_ An integer representing the current line number.
    - \_\_TIME\_\_ A string containing the current time (GMT).\
    - don't need to redefine them
- Storage Class
  - local variable
  - global variable
  - static local variable
    - static float a;
    - exists only inside a function where it is declared (similar to a local variable)
    - but its lifetime starts when the function is called and ends only when the **program** ends.
  - register variable (Deprecated in C++11)
  - thread local storage
    - Keyword thread_local
- Bitwise Operators
  - a & b;
  - a | b;
  - & Bitwise AND Operator
  - | Bitwise OR Operator
  - ^ Bitwise XOR Operator
  - ~ Bitwise Complement Operator
  - << Bitwise Shift Left Operator
  - > >     Bitwise Shift Right Operator
  - Bitwise operators can only be used alongside **char** and **int** data types.
  - https://www.programiz.com/cpp-programming/bitwise-operators
- Assert
  - #include <cassert>
  - assert(expression);
  - 0 (false) - the assert prints a message and terminates the program
  - 1 (true) - does nothing and continues normal execution of the program
  - disable assert
    - #define NDEBUG
    - #include <cassert>
  - Static Assert
    - assert macro used for runtime
    - used for assertion at compile time
    - static_assert(const_boolean_expression, message);
    - static_assert(sizeof(int) >= 4, "Size of integer must be greater than or equal to 4 bytes");
  - When to use
    - unreachable codes
    - document code
      - if (i % 2 == 0) {...}
      - else { assert(i % 2 == 1); ...}
  - when not to use
    - check public functions that may provided by user
      - should use try catch throw
    - evaluate expression that affect the program
      - assert(--n && n % 2 == 0); // this will change n
- Buffers
  - Instead of reading or writing data one byte at a time (which can be slow), you can work with larger chunks of data stored in a buffer.
  - char \*buffer = new char buffer_name[buffer_size]
  - stream buffers
  - file buffers
  - character buffers
  - custom buffers
- ... in cpp
  - TODO: add this
  - https://www.bilibili.com/list/watchlater?bvid=BV1KC4y1S7gX&oid=790875156
  - use auto...a
  - and call with a list of parameters
### Objective c

- what is objective c
  - is an extension of the C programming language, designed for adding object-oriented capabilities.
  - Objective-C uses a dynamic runtime for object-oriented features, while C++ is statically typed.
