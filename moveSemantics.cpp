#include <cstring>
#include <iostream>

class String {
    char* data;

public:
    // default ctor
    String(const char* str =  "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Dtor
    ~String() {
        delete[] data;
    }

    // Copy ctor 
    String(const String& other) { // deep copy
        std::cout << "Copy ctor" << std::endl;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Move ctor
    String(String&& other) noexcept {
        std::cout << "Move ctor" << std::endl;
        // shallow copy
        if (&other != this) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
    }

    // Move assignment operator
    String& operator=(String&& other) {
        std::cout << "Move assignment operator" << std::endl;
        if (&other == this) return *this;

        delete[] data;

        data = other.data;
        other.data = nullptr;
        return *this;
    }

    char* getData() const {
        return this->data;
    }

    void printData() const {
        std::cout << data << std::endl;
    }

};

int main() {
    String s("Hello World");
    s.printData();

    // Move semantics example
    String s2("This is a new string");
    s = std::move(s2); // Move assignment operator called
    s.printData();

    String s3(std::move(s)); // move ctor to be called
    s3.printData();
    
    return 0;
}