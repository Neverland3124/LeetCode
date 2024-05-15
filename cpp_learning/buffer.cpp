#include <iostream>
using namespace std;

int main() {

    // define the buffer size
    const int buffer_size = 1024; 
    
    // declare a character buffer
    char *buffer = new char[buffer_size]; 

    // prompt the user for input
    cout << "Enter a line of text: ";

    // read data into the buffer
    cin.getline(buffer, buffer_size);

    // display the content read from the buffer
    cout << "You entered: " << buffer;
    
    // deallocate the dynamically allocated memory
    delete[] buffer;
    
    return 0;
}