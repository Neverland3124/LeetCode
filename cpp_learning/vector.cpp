#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;  // Declare a vector of integers

    // Adding elements to the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Accessing elements
    std::cout << "First element: " << vec[0] << std::endl;
    // 10 20 30

    // Using iterators to access elements
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Size of the vector
    std::cout << "Size of the vector: " << vec.size() << std::endl;

    // // Removing an element from the end
    // vec.pop_back();
    // // Size of the vector after pop_back()
    // std::cout << "Size after pop_back: " << vec.size() << std::endl;

    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    vec.swap(vec2);
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::vector<double> vec3 = {1.1, 2.2, 3.3, 4.4, 5.5};
    for(auto it = vec3.begin(); it != vec3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
