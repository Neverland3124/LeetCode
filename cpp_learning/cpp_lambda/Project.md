# CSCC24 Exercise 6 

## Topic
- Using (equivalents of) lambda, map, filter, and fold in C++.

## Introduction
- During the lecture and assignment, we learned lambda function in  racket, haskell, python and java, we are interested in how those functions appears in C++ so we choose this topic to explore relative knowledge.

## Part 1: Lambda in C++
- Recall lambda in racket
- \<lambda> ::= (lambda (\<arg> ...) \<expr> ...)
```racket
;;; lec example
> (lambda (x y) (+ x y))
#<procedure>
> ((lambda (x y) (+ x y)) 1 2)
3

;;; lab example
; (add m1 m2) -> list?
; m1, m2: list of list of numbers of same dimensions
; return m1 + m2 for matrices m1, m2
(define (add m1 m2)
  (map (λ (row1 row2) (map + row1 row2)) m1 m2)
```
- Recall Lambda in Haskell
```haskell
-- Lab Example

-- |mult m1 m2
-- return the product of matrices m1 and m2
mult :: Num a => [[a]] -> [[a]] -> [[a]]
mult a b = map (\row -> map (f row) (g b)) a
 where
      f = dotProduct  
      g = transposeMatrix 
```

- Definition of Lambda Expressions in C++ ([from cppreference](https://en.cppreference.com/w/cpp/language/lambda)): Constructs an unnamed function object capable of capturing variables in scope. 
- Lambda Structure in C++
    - [captures ] front-attr <sub>(optional)</sub> (params ) specs  <sub>(optional)</sub> exception  <sub>(optional)</sub> back-attr  <sub>(optional)</sub> trailing-type  <sub>(optional)</sub> requires  <sub>(optional)</sub> { body }
    - Some common ways to define a lambda expression
        - `[captures](parameters) -> return_type { // body }`
        - `[captures](parameters) -> { // body }`
- Here captures can have different values that affect how variables connected between inside the lambda function and outside the lambda function.
    1. [=] means within this lambda function body, we can have the access of the value of all the outside variables, but instead direct use it, we make copy of it and use the values inside the lambda function. By doing this, outside variables values can be accessed and also outside variables are safe from being direct modified.
    2. [&] means within this lambda function body, we can have the direct access to all outside variables, unlike [=], this time, we do not make copy of them but direct use these variabes. Therefore, all the outside variables can be affect inside lambda function body operations. 
    3. [] means within this lambda function body, we do not have the any access to outside variables in any ways. The only variables we can use within the body are passed in parameters.
    4. [x, &y] is a combination of copy of value and direct access. This means within this lambda function body, x means we can have the value of outside vairable x by copying x then we can use it value but we can not affect real variable x outside. &y means we can have the direct access to outside variable y and we can direct use it not just value, which means outside variable y can be affected inside the lambda function body.
    5. [=, &y] this is similar to the [x, &y], everything else is the same but this time, inside the lambda function, we can copy all the outside variables and use the values.
    6. [&, x] this means we can have the direct access to all the outside variables and we can affect these variables within the body but except for outside variable x, we can only copy of its value.

- Our code example:
```C++
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
```
- Connection of C++ lambda expression with Hakell / Racket
    - Similar as Haskell and racket, C++ allow other variables to be used in the lambda expression body by the `[capture]` feature, and in all three langugages they are initially anonymous, although in C++ we are allowed to use auto to give the lambda expression a name.
    - The main differences we think except is the syntax, type and `[capture]` feature. Syntax is obversely different, type doesn't appear hakell, hacket have implicit type which we don't annotate a return_type, but for C++, we have the optional return_type which we can include or not, this allow we both have flexibility and type safety if needed. For `[capture]` in racket and haskell, other varaibles are automatically be readable and writable in the body but in C++ we can disable some and enable some which give us more flexibility. 

## Part 2: map function in C++ (transform)
- Recall map function in lecture
```racket
;; lab example
;; (add m1 m2) -> list?
;; m1, m2: list of list of numbers of same dimensions
;; return m1 + m2 for matrices m1, m2
;; no recursion! suggestion: use map
(define (add m1 m2)
  (map (λ (row1 row2) (map + row1 row2)) m1 m2))
;; (map proc l1 l2 ... ln) where proc is an n-ary produce
```
```haskell
-- lab example

-- haskell map returns a list constructed by appling a function
--  to all items in a list passed as the second argument
-- |scalarVectorMult k v
-- return the result of scalar multiplication of vector v by scalar k
scalarVectorMult :: Num a => a -> [a] -> [a]
-- scalarVectorMult k list = map (k *) list
-- scalarVectorMult k = map (k *)
-- scalarVectorMult k = map ((*) k)
scalarVectorMult = map . (*)

-- for binary, need to use zipwith
vectorAdd :: Num a => [a] -> [a] -> [a]
-- vectorAdd v1 v2 = zipWith (+) v1 v2
vectorAdd = zipWith (+)
```

- Transform function is C++ severs the same function as Map in Racket.
- Transform Definition From: [Office transform function doc  ](https://en.cppreference.com/w/cpp/algorithm/transform)
```C++
// Type1: one input item takes an unary operation.
template <class InputIt, class OutputIt, class UnaryOp>
OutputIt transform(InputIt first1, InputIt last1, 
    OutputIt d_first, UnaryOp unary_op)

// Type2: two input items takes a binary operation.
template <class InputIt1, class InputIt2, class OutputIt, class BinaryOp>
OutputIt transform(InputIt1 first1, InputIt1 last1, 
    InputIt2 first2, OutputIt d_first, BinaryOp binary_op )
```
- Function Explanation
    - first1: The beginning of the first input range to transform.
    - first2: The beginning of the second input range to transform.
    - last1: The ending of the fiest input range to transform.
    - d_first: The beginning of the result range.
    - unary_op: It is a unary operation that takes one input and apply operation on it.
    - binary_op: It is a binary operation that takes two inputs from first input and second input and apply operation on them.
   
- Our code example:
```C++
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

```
- Connection C++ to racket and haskell (other than syntax)
    - The biggest difference of map (map procedure, map function, transform function) in these three language is the number of parameters that they can take. For racket, it can take a list of n parameters as long as the procedure is the n-ary. For haskell, map is just a unary function that take a list and apply a function of each of them. In C++ transform, it's like a limit size racket map procedure or a combination of map function and zipwith function in haskell. C++ like a middle ground of them may more suit for boarder use cases.
    - One another signficant difference is that C++ use Input Iterator in the parameter for transform, so as we did in example, we need to fill in `list.begin()` or `list.end()` for the list. In our funtion `sum_cpp_map_subrange_5`, we can also fill in `l1.begin() + 1`, `l1.end() - 1` which give us the freedom and flexibility that both racket and haskell do not have.

## Part 3: filter function in C++ (copy_if)
- We didn't meet filter in racket and haskell in lec or lab, but here is some basic usage of filter 
- racket
```racket
(define (even? x) (= (modulo x 2) 0))
(define nums (list 1 2 3 4 5 6 7 8 9 10))

(filter even? nums); Returns: '(2 4 6 8 10)
```
- hakell
```haskell
filter even [1, 2, 3, 4, 5, 6]  -- Returns: [2, 4, 6]
```
- **copy_if** function can achieve the same purpose like filter in Racket.
- copy_if Definition From: [Office copy_if function doc](https://en.cppreference.com/w/cpp/algorithm/copy)
```C++
template <class InputIt, class OutputIt, class UnaryPred>
OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first, UnaryPred pred );
```
- Function Explanation
    - first: The beginning of the input range to copy.
    - last: The ending of the input range to copy.
    - d_first: The begining of the result range.
    - pred: an unary predicate that return a boolean value in the case of current input element satisfied the requirment or not.
- Our code example:
```C++
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
```
- Connection
    - For filter(copy-if), there isn't much difference other than syntax, except a similar iterator way that C++ choose like the transform function. This allows more flexibility and more compatable with different use case.

## Part 4: fold function in C++ (accumulate)
- Recall fold in racket and haskell
```racket
;; (foldr op id lst)
;; lec example
(foldr op id '()) ⇒ id
(foldr op id '(e)) ⇒ (op e id)
(foldr op id '(e1 e2 ... en))
⇒ (op e1 (op e2 (op ... (op en id))))
    
;; (foldl op id lst)
(foldl op id '()) ⇒ id
(foldl op id '(e)) ⇒ (op id e)
(foldl op id '(e1 e2 ... en))
⇒ (op ... (op (op id e1) e2) ...) en )
```
```haskell
-- my haskell example: summing a list of numbers
sumList :: [Int] -> Int
sumList xs = foldl (\acc x -> acc + x) 0 xs
-- really similar to racket
```
- accumulate function can achieve the same purpose like filter in Racket.
- accumulate Definition From: [Office accumulate function doc](https://en.cppreference.com/w/cpp/algorithm/accumulate)
```C++
// type1: not given binary operation, defalut is addition:
template <class InputIt, class T>
T accumulate( InputIt first, InputIt last, T init );
// type2: given an binary operation:
template <class InputIt, class T, class BinaryOperation>
T accumulate( InputIt first, InputIt last, T init,
              BinaryOperation op);
```
- Function Explanation
    - first: The beginning iterator of the input range to accumulate.
    - last: The ending iterator of the input range to accumulate.
    - init: The Initial value of the operation.
    - op (optional): The binary operation that will apply on the two elements.
- Our code example
```C++
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
```
- Connection
    - Even though in C++, accumulate function is very similair to fold function in Racket, but there are still have some differences and common places:
    - First, in C++, accumulate have a default operation to apply which is addition, but in Racket, we do not have this, we must provide operation for the fold function.
    - Second, in C++, accumulate only start to apply operation from left to right only, meaning, always the first element of the list and the initial value will be applied with operation first. However, this accumulator is same thing as foldl, but in Racket, we also have foldr, that can give us the ability to apply operation from right to left. But accumulate function does not have this ability.
    
## Conclusion
- The design philosophy of C++ incorporates flexible lambda expressions, transformation, filtering (copy-if), and accumulation operations, emphasizing iterator-based parameters to maximize flexibility in data handling. Furthermore, C++ frequently employs function overloading, allowing the same function name to be used in various contexts with different behaviors. This approach, in conjunction with its (sometimes optional) type system, manages to maintain safety and robustness in the language while affording programmers considerable freedom in implementation.

## Source
- https://en.cppreference.com/w/cpp/language/lambda
- https://en.cppreference.com/w/cpp/algorithm/transform
- https://en.cppreference.com/w/cpp/algorithm/copy
- https://en.cppreference.com/w/cpp/algorithm/accumulate

