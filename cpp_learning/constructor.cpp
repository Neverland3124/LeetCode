#include <algorithm>  // For std::copy
#include <iostream>
using namespace std;

class Buffer {
   private:
    int* data;
    size_t size;

   public:
    // Constructor
    Buffer(size_t sz) : size(sz), data(new int[sz]) {
        cout << "Buffer of size " << sz << " created." << endl;
    }

    // Copy Constructor
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        // copy start, end, result
        cout << "Buffer copied. Size: " << size << endl;
    }

    // Copy Assignment Operator
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;  // Free the existing resource.
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        cout << "Buffer destroyed." << endl;
    }

    // Utility function to print the contents of the buffer
    void print() const {
        cout << "Buffer contents: ";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Function to modify an element in the buffer
    void set(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }
};

int main() {
    Buffer buf1(5);   // Create a Buffer of size 5
    buf1.set(0, 10);  // Set first element to 10
    buf1.print();

    Buffer buf2 = buf1;  // Use copy constructor
    buf2.set(0, 20);     // Change first element of buf2
    buf2.print();
    buf1.print();

    Buffer buf3(3);
    buf3.print();
    buf3 = buf2;  // Use copy assignment operator
    buf3.print();

    return 0;
}
