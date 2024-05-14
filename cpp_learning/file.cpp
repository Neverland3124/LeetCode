#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // 1. Open and Close a File
    ofstream my_file("example.txt");
    if (!my_file) {
        cout << "Error opening the file." << endl;
        return 1;
    }
    my_file.close();

    // 2. Check File for Errors (using is_open)
    my_file.open("example.txt");
    if (!my_file.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }
    my_file.close();

    // 3. Write to a File
    my_file.open("example.txt");
    if (!my_file) {
        cout << "Error: Unable to open the file." << endl;
        return 1;
    }
    my_file << "Line 1" << endl;
    my_file << "Line 2" << endl;
    my_file << "Line 3" << endl;
    my_file.close();

    // 4. Read from a File
    ifstream read_file("example.txt");
    if (!read_file) {
        cout << "Error: Unable to open the file." << endl;
        return 1;
    }
    string line;
    while (getline(read_file, line)) {
        cout << line << endl;
    }
    read_file.close();

    // 5. Append to a File
    my_file.open("example.txt", ios::app);
    if (!my_file) {
        cout << "Failed to open the file for appending." << endl;
        return 1;
    }
    my_file << "Line 4" << endl;
    my_file << "Line 5" << endl;
    my_file << "Line 6" << endl;
    my_file.close();

    // 6. Using fstream for multiple operations
    fstream file("example.txt", ios::out);
    if (file) {
        file << "This is a test line." << endl;
        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }

    file.open("example.txt", ios::in);
    if (file) {
        while (getline(file, line)) {
            cout << "Read from file: " << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading." << endl;
        return 1;
    }

    file.open("example.txt", ios::app);
    if (file) {
        file << "This is another test line, appended to the file." << endl;
        file.close();
    } else {
        cout << "Unable to open file for appending." << endl;
        return 1;
    }

    return 0;
}
