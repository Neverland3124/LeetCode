## C++

### links

-   https://www.programiz.com/cpp-programming/getting-started

### What should i learn?

-   difference of c and c++
-   basic types
    -   arrays
        -   int x[] = {1, 2, 3, 4, ...};
    -   strings
        -   cstrings
            -   char str[] = "C++";
        -   get string functions
            -   cin >> str
            -   cin.get(str, 100);
            -   if use string str; we can use getline(cin, str);
        -   c++ string class
            -   find(), rfind() - find the last occur substring, append(), insert(), erase(), replace(), compare()
    -   pointer
        -   int\* point_var = &var;
        -   ptr = &arr[0] **same as** ptr = arr
        -   \*(arr + i) **equivalent to** cin >> arr[i]
        -   sring& ref_city = city; (create a reference to alias ref_city with city)
            -   We must initialize references at the time of declaration.
        -   int\* point_var = new int{45};
            -   **new** allocate memory in run time
            -   because the new expression returns the address of the memory location
            -   delete[] ptr; (use the square brackets [] in order to denote that the memory deallocation is that of an array)
    -   struct
        -   Member Functions in C++ Structures
        -   Person p {"John", "Doe", 22, 145000}; // initialize the structure variable
        -   (\*ptr).x = ptr->x
    -   enumeration
        -   enum season { spring, summer, autumn, winter };
        -   enum designFlags {xxx} button; (variable button with type denum designFlags)
-   classes

    -   access modifiers
        -   default is private
        -   public
        -   protected
            -   used for inherit class to access the method or variable
            -   don't allow to call the method or use the varible directly
        -   private
        ```
        | Specifiers | Same Class | Derived Class | Outside Class |
        |------------|------------|---------------|---------------|
        | public     | Yes        | Yes           | Yes           |
        | private    | Yes        | No            | No            |
        | protected  | Yes        | Yes           | No            |
        ```
    -   constructor
        -   default constructor
            -   Wall() = default;
            -   double length {5.5};
        -   constructor list
            -   Wall(double len, double hgt)
            -   : length{len}
            -   , height{hgt} {
            -   }
        -   copy constructor
            -   Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {}
            -   If we don't define any copy constructor, move constructor, or move assignment in our class, then the C++ compiler will automatically create a default copy constructor that does memberwise copy assignment.
        -   copy assignment operator
            -   Buffer& operator=(const Buffer& other) {}
            -   operator is a keyword
                -   can overload like bool operator>(const Point& other) const {}
    -   data hiding
        -   using getter and setter to make variable private
    -   friend function
        -   friend function can access the private and protected data of a class
        -   ClassA and ClassB have declared add() as a friend function. Thus, this function can access private data of both classes
    -   friend class
        -   a class is declared a friend class, all the member functions of the friend class become friend functions
    -   inherenit
        -   inherenit <==> is-a relationship
        -   dog inherenit animal <==> dog is an animal
    -   access modes

        -   public: If a derived class is declared in public mode, then the members of the base class are inherited by the derived class just as they are.
        -   private: In this case, all the members of the base class become private members in the derived class.
        -   protected: The public members of the base class become protected members in the derived class.

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

    -   multiple inheritance

        -   in cpp, a class can be derived from more than one parent. For example, A class Bat is derived from base classes Mammal and WingedAnimal
        -   class Bat: public Mammal, public WingedAnimal {};
        -   ambiguity
            -   If you try to call the function using the object of the derived class, the compiler shows error. It's because the compiler doesn't know which function to call. For example,
            -   solution:

        ```cpp
        int main() {
            obj.base1::someFunction( );  // function of base1 class is called
            obj.base2::someFunction();   // function of base2 class is called.
        }
        ```

    -   virtual inheritance

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

    -   Overload function
        -   default is to call the shadow function from derived class
        -   to call the base function, will need derived.Base::function()
        -   or in the derived class function, call overridden function Base::function();
        -   or to use a base pointer:
            -   Derived derived1; Base\* ptr = &derived1; ptr->print();
    -   virtual

        -   allow a member function of a class to be overridden in derived classes
        -   used similar as abstract in java
        -   also remember virtual destructure
        -   ~ in cpp is destructure
            -   virtual ~Shape() = default;
            -   use virtual in destructor allows deallocate the derived class memory instead of base class when we use base class pointer

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

    -   override keyword
        -   C++ 11 provides a new specifier override that is very useful to avoid common mistakes while using virtual functions.
        -   If we use function prototype in Derived class, then we use override specifier in the function declaration only, not in the definition.
    -   pure virtual function
        -   A pure virtual function doesn't have the function body and it must end with = 0.
        -   virtual void calculateArea() = 0;
    -   Abstract Class:
        -   A class that contains a pure virtual function is known as an abstract class.

-   cpp stl (C++ Standard Template Library)
    -   vector
        -   vector<T>
            -   can use int, double, custom class, and pointer (pointer is weird)
        -   vector<int> vector1 = {1, 2, 3, 4, 5};
        -   vector<int> vector3(5, 12); // size 5, value 12
        -   vector<int> num {1, 2, 3, 4, 5};
            -   num.push_back(6);
            -   num.at(0)
            -   num[0]
            -   num.pop_back();
            -   size() returns the number of elements present in the vector
            -   clear() removes all the elements of the vector
            -   front() returns the first element of the vector
            -   back() returns the last element of the vector
            -   empty() returns 1 (true) if the vector is empty
            -   capacity() check the overall size of a vector
        -   iterator for vector
            -   vector<int>::iterator iter;
            -   iter = num.begin(); // first element
            -   iter = num.end() - 1; // last element
    -   iterator
        -   vector<int>::iterator it;
        -   vector<int> numbers = {3, 2, 5, 1, 4};
        -   vector<int>::iterator itr1 = numbers.begin();
        -   vector<int>::iterator itr2 = numbers.end();
    -   algorithm
        -   #include <algorithm>
        -   sort(numbers.begin(), numbers.end());
    -   set
        -   #include <set>
        -   set<int> numbers = {1, 100, 10, 70, 100};
        -   numbers are sorted in ascending order with duplicate numbers removed
    -   unordered_set
        -   #include <unordered_set>
        -   unordered_set<int> numbers = {1, 100, 10, 70, 100};
    -   stack
        -   #include <stack>
        -   stack<int> numbers;
        -   numbers.push(1);
        -   numbers.top()
        -   numbers.pop();
    -   array
        -   #include <array>
        -   std::array<T, N> array_name;
            -   T - Type of element to be stored
            -   N - Number of elements in the array
        -   std::array<int, 5> n = {1, 2, 3, 4, 5};
            -   n[0] // returns 1
            -   n.at(0) // returns 1
        -   n.empty(); // return true or false
        -   n.size();
        -   n.fill(0); // fill the array with zeros
        -   sort(age.begin(), age.end());
        -   auto found = find(age.begin(), age.end(), 5); // check if the number 5 is present or not
        -   int sum = std::accumulate(age.begin(), age.end(), 0); // get the sum
    -   list
        -   #include<list>
        -   std::list<Type> list_name = {value1, value2, ...};

-   operaters
    -   & Binary AND
    -   | Binary OR
    -   ^ Binary XOR
    -   ~ Binary One's Complement
    -   << Binary Shift Left
    -   \>> Binary Shift Right
    -   & represents memory address of the operand &num; // address of num
    -   . accesses members of struct variables or class objects s1.marks = 92;
    -   -> used with pointers to access the class or struct variables ptr->marks = 92;
    -   << prints the output value cout << 5;
    -   \>> gets the input value cin >> num;
-   function
    -   inline function in cpp
        -   this will copy the function itself to where the argument are to make running faster
    -   auto function: can use as function return type and lambda function input parameter type
-   what is objective c
-   start on the project
-   some fancy way of using cpp
