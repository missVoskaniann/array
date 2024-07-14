#include <iostream>
#include "array.h"

int main() {
    array<int, 5> arr1;
    
    // Fill array with value
    arr1.fill(5);
    std::cout << "arr1 after fill: " << arr1 << std::endl;
    
    // Access elements
    std::cout << "First element (front): " << arr1.front() << std::endl;
    std::cout << "Last element (back): " << arr1.back() << std::endl;
    std::cout << "Element at index 2: " << arr1.at(2) << std::endl;
    
    // Modify elements
    arr1[2] = 10;
    std::cout << "arr1 after modifying index 2: " << arr1 << std::endl;
    
    // Iterators
    std::cout << "Elements using begin and end: ";
    for(auto it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Reverse iterators
    std::cout << "Elements using rbegin and rend: ";
    for(auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Copy constructor
    array<int, 5> arr2(arr1);
    std::cout << "arr2 (copy of arr1): " << arr2 << std::endl;

    // Copy assignment
    array<int, 5> arr3;
    arr3 = arr1;
    std::cout << "arr3 after copy assignment from arr1: " << arr3 << std::endl;

    // Move constructor
    array<int, 5> arr4(std::move(arr1));
    std::cout << "arr4 after move from arr1: " << arr4 << std::endl;

    // Move assignment
    array<int, 5> arr5;
    arr5 = std::move(arr2);
    std::cout << "arr5 after move assignment from arr2: " << arr5 << std::endl;

    // Swap
    arr4.swap(arr5);
    std::cout << "arr4 after swap with arr5: " << arr4 << std::endl;
    std::cout << "arr5 after swap with arr4: " << arr5 << std::endl;

    // Compare arrays
    if (arr4 == arr5) {
        std::cout << "arr4 and arr5 are equal" << std::endl;
    } else {
        std::cout << "arr4 and arr5 are not equal" << std::endl;
    }

    if (arr4 != arr3) {
        std::cout << "arr4 and arr3 are not equal" << std::endl;
    } else {
        std::cout << "arr4 and arr3 are equal" << std::endl;
    }
    
    arr4[4] = 1;
    std::cout << "arr4 after changing last element: " << arr4 << std::endl;
    std::cout << "arr3's entity: " << arr3 << std::endl;
    std::cout << "arr5's entity: " << arr5 << std::endl;

    // Compare arrays
    if (arr4 == arr5) {
        std::cout << "arr4 and arr5 are equal" << std::endl;
    } else {
        std::cout << "arr4 and arr5 are not equal" << std::endl;
    }

    if (arr4 != arr3) {
        std::cout << "arr4 and arr3 are not equal" << std::endl;
    } else {
        std::cout << "arr4 and arr3 are equal" << std::endl;
    }

    return 0;
}

