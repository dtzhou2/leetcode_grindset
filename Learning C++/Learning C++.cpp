// Learning C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <assert.h>
// This causes the pre-processor to include the entire contents of the iostream pre-processed file 
// Angled brackets in this case signifies to the pre-processor that the header file was not written by us
// Causing it to first pull from the system include directories
#include "add.h"
// This inclusion means that the linker will pull in all the function prototypes / declerations from add.h
// This means we dont have to constantly retype function declarations, relying on the header files instead 
#include "io.h"
#include "double.h"
#include "height.h"
#include "globals.h"
#include "globals2.h"
#include "constants.h"
#include "passfail.h"

//using namespace std;
// This is a VERY VERY discouraged practice
// This means we cant define any functiosn with the same names as those in the standard library
// This also means that as the standard library changes our functions could accidently collide in the future
// Again a very bad idea

static void doPrint();
int getValueFromUserUB();
int doubleNum(int input);
int getInteger();
void printSV(std::string_view s);
int staticFunctionTest();
void printDivision(int a, int b);
// All these function prototypes exist in the global namespace
// Function prototypes tells the program about the existence of a function before actually defining it

int main()
{

    int x{ 3 };
    
    switch (x)
    {
    case 1:
        std::cout << "one \n";
        break;
    case 2:
        std::cout << "two \n";
        break;
    case 3:
        std::cout << "three \n";
        break; // Since there iks a control flow statement, execution stops after this case is reached
    default:
        std::cout << "unknown \n";
        break;
    }

    int y{ 2 };

    switch (y)
    {
    case 1:
        std::cout << "one \n"; // Statement is skipped because it doesnt match
        [[fallthrough]];
    case 2:
        std::cout << "two \n"; // Execution begins here
        [[fallthrough]];
    case 3:
        std::cout << "three \n"; // This also executes
        [[fallthrough]];
    case 4:
        std::cout << "four \n"; // This also executes
        [[fallthrough]];
    default:
        std::cout << "default \n"; // This also executes
    }

    double z{};
tryAgain: // This is a statement label 
    std::cout << "Enter a non-negative number: ";
    std::cin >> z;

    if (z < 0.0) {
        goto tryAgain; // This is a goto statement which will unconditionally jump to the statement label
    }

    std::cout << "The square root of " << z << " is " << std::sqrt(z) << '\n'; 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; i < 6; j++) {
            for (int k = 0; k < 7; k++) {
                for (int l = 0; l < 7; l++) {
                    if (l > 3) {
                        goto get_me_out; // Best/only use of goto statements, to break out of long complicated nested loops
                    }
                    std::cout << "Hello \n";
                }
            }
        }
    }
get_me_out:
    ;

    printDivision(4, 0);

    return 0;
    // Your main function should always return 0 if it ran normally
}

void printDivision(int a, int b) {
    assert(b != 0 && "Error could not divide by 0"); // Assert statement used to test for logical falllacies / impossibilities
    // Will immeditely abort and error out the program if it is false, useful trick is to && it with a useful error message as shown
    std::cout << static_cast<double>(a) / b;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
