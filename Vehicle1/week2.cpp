// week2.cpp
#include<iostream>
#include "Vehicle.h"

using namespace std;
using namespace CST8219;

int main(int argc, char** argv) {
    Vehicle original;
    Vehicle copy(original); // copy constructor by reference
    cout << "Original is: " << original << " copy is: " << copy << endl;
    cout << "Increment original: " << ++original << endl;
    cout << "Increment copy:" << ++copy << endl;
    cout << "Decrement original:" << --original << endl;
    cout << "Decrement copy:" << --copy << endl;
    // should be true :
    cout << "Compare equality 1: " << (original == copy) << endl;
    // should be false:
    cout << "Compare equality 2: " << (original == ++copy) << endl;
    // should be true:
    cout << "Compare inequality: " << (original != copy) << endl;
    // This should make original = copy, and then return a Vehicle for output:
    cout << "Assignment operator: " << (original = copy) << endl;
    return 0;
}
