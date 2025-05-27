#include <iostream>
#include <string>

int main() {
    char* name = "Cherno"; //  "Cherno" is a string literal and gets located in the read only section of memory, so it is immutable
    // name[2] = 'a'; // not allowed with char* 

    char name2[] = "Cherno"; // this is mutable
    name2[2] = 'a';
    std::cout << name2 << std::endl;

    char name3[5] = {'P', 'a', 'r', 'o', 0};
    std::cout << name3 << std::endl;

    const char* paragraph = R"(Hello world
            Line 2
            Line 3
            Line 4
            Line 5
            Line 6)";
    
    const char* paragraph2 = "hello"
                            " "
                            "this is a new line 1 "
                            "this is a new line 2";

    std::cout << paragraph << std::endl;
    std::cout << paragraph2 << std::endl;


    // ----------------------------------------------------
    // Study printf() behaviour
    printf("This is the value using mod d : %d\n", name); // decimal equivalent of starting address of name
    printf("This is the value using mod d and * : %d\n", *name); // ascii of C
    printf("This is the value using mod d and * : %d\n", *(name+1)); // ascii of h
    printf("This is the value mod s : %s\n", name);
    printf("This is the value mod p : %p\n", name);
    printf("This is the value mod p [1]: %c\n", name[1]);

    return 0;
}