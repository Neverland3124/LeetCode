# LeetCode

My LeetCode Path and C++ language learning

## Purpose

- get familiar with algorithms
- start with using java but later start to use c++

## Focus Topics

- ## loops
- linklist
  - how it different from c as have new
  - nullptr use
  - usually return headNode->next to get rid of the default 0 pointer
- trees
- Dynamic Programming
  1. state the subproblem to solve
  2. solving the original problem by subproblems
  3. recursive formula to computer the subproblem
  - 1D array or 2D array both possible
- vector use
  - string manipulation
  - integer / string change
  - double vector (2D array)
- integer
  - overflow handle
  - INT_MAX, INT_MIN
  - module and divide
  - palindrome
- binary search
  - find mid and update low / high
  - try more use <= since = is most time handled seperately in next loop
  - try one some base case like 1/2/3 element as input
  - rotated sorted array have a part of the array sorted
- divide and conquer
  - calculate some thing about this case
  - then call max/min of three cases (left, this, right)
- priority queue
  - implemented using a heap to get the min/max
  - default is max, if want min need
  - priority_queue<int, vector<int>, greater<int>> heap;
    - std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    - push, pop, top
- backtrack problems
  - **Use the for loop approach** if the problem involves combinations, permutations, or if there is a need to manage **duplicates** within the loop. It often results in more concise and efficient code.
    - for loop with each loop call backtrack once
  - **Use the include/exclude approach** if you want to explicitly model the decision process in your recursion, or if the problem naturally fits into a binary decision tree.
    - call backtrack twice once exclude the element, once include
