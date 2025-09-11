#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    int result;
    std::string filePath = "../../../../Download/Programming/C++/Programs/Array/0AR1.cpp";
    std::cout << "Enter the path of the .cpp file to compile: ";
    //std::getline(std::cin, filePath);

    std::string command = "clang++ " + filePath + " -o ArrayOps";
    result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Compilation successful. Executable created: ./output" << std::endl;
    } else {
        std::cerr << "Compilation failed." << std::endl;
        goto label;
    }

    std::system("./ArrayOps");
    
    label:
    
    return 0;
}
