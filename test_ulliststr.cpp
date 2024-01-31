#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    std::string values[] = {
        "cat",
        "dog",
        "car",
        "bus",
        "sun",
        "moon",
        "tree",
        "bird",
        "fish",
        "lion",
        "bear",
        "duck",
        "frog",
        "rose",
        "blue",
        "red",
        "gold",
        "lamp",
        "book",
        "pen",
        "ball",
        "tree",
        "cake",
        "desk",
        "fork",
        "dish",
        "lamp",
        "bell",
        "door",
        "bird",
        "frog",
        "boat",
        "tree",
        "lion",
        "cat",
        "dog",
        "moon",
        "star",
        "rose",
        "blue"
    };

    ULListStr str;
    for (int i = 0; i < 40; i++) {
        str.push_back(values[i]); 
    }
    str.push_back("angle");
    std::cout << "back is " << str.back() << std::endl;
    std::cout << "size is " << str.size() << std::endl;
    str.pop_front();
    std::cout << "front is " << str.front() << std::endl;

    for (int i = 0; i < 10; i++) {
        str.pop_front();
        std::cout << "size is " << str.size() << std::endl;
        std::cout << "front is " << str.front() << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        str.pop_back();
        std::cout << "size is " << str.size() << std::endl;
        std::cout << "back is " << str.back() << std::endl;
    }

    for (int i = 0; i < str.size(); i++) {
        std::cout << str.get(i) << std::endl;
    }
}
