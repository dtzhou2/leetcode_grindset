// Learning C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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
#include "chapter9.h"

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
// All these function prototypes exist in the global namespace
// Function prototypes tells the program about the existence of a function before actually defining it

int main()
{
    //// C++ Has many different ways to intialize variables
    //[[maybe_unused]] int a; 
    //// Default Initialization: When value is not specified for a it will be set to an
    //// undefined value
    //// [[maybe_unused]] is a compiler flag that lets it know that these variables might not be used
    //// and it tells it not to complain when they arent
    //[[maybe_unused]] int e{};
    //// Value Initialization: Different from above initialization because it guarantees the value is
    //// set to 0 rather than being an underfined value 
    //int b = 3;
    //// Copy Initialization: Inherited from C, sets variable equal to value on the right side
    //// Inefficient and doesnt work for some data types but *mostly* gets the job done
    //int c(4);
    //// Direct Initialization: Faster than copy init, works for all data types
    //// Confusing syntax which is why it isnt used much in modern C++
    //int d{ 5 };
    //// List Initialization: PREFERRED METHOD FOR MODERN C++
    //// Works well and fast for all data types and prevents lossy conversions
    //// int e, f, g;
    //// Dont do this it confuses the hell out of everyone and u can confuse yourself
    //std::cout << b << "+" << c << "+" << d << "\n";
    //// Prefer ‘\n’ over std::endl when outputting text to the console.
    //// More efficient since it doesnt force buffer flush
    //a = 5; //  Assignment
    //[[maybe_unused]] int i; // Unintialized 
    //[[maybe_unused]] int l{}; // Intialized

    //std::cout << 5 << "\n";
    //// Side effect of the << is outputting 5 to cout
    //// Return value of << is the left operand or 5

    //a = b = c = 5;
    //// Side effect of the = is assigning c to 5,
    //// Return value of the = is the left operand or 5 again

    //int x{ 5 + 3 };
    //std::cout << x << "\n";
    //// Expressions cannot be compiled unless they are wrapped in a statement

    //int num{};
    //// Number that we want to double 
    //std::cout << "Enter an integer ";
    //// Prompt to double expression
    //std::cin >> num;
    //// Takes user input and stores it into num
    //std::cout << "Double " << num << " is: " << num * 2 << "\n";
    //std::cout << "Triple " << num << " is: " << num * 3 << "\n";
    //// Outputs that number
    //// This solution is best because wrapping num*2 in an expression will
    //// mean that the variable num will actually not be altered

    //int num2{};
    //// First number in expression
    //int num3{};
    //// Second number in expression
    //std::cout << "Enter the first number ";
    //std::cin >> num2;
    //std::cout << "Enter the second number ";
    //std::cin >> num3;
    //std::cout << num2 << " + " << num3 << " is " << num2 + num3 << "\n";
    //std::cout << num2 << " - " << num3 << " is " << num2 - num3 << "\n";
    //// Basic demonstrate of input/output and expressions 

    //std::cout << "Ending ";
    //doPrint();
    //std::cout << "main"; 
    ////Example for how functions break up program execution / computer leaves scope of main to execute function then comes back

    ////void foo()
    ////{
    ////    std::cout << "Foo \n";
    ////}
    //// Nested functions are NOT ALLOWED in C++

    //num = getValueFromUserUB() ;
    //// This calls a function that implements the user input functionality from our previous program
    //std::cout << num <<  " double is : " << num * 2 << "\n";
    //std::cout << "double is: " << doubleNum(num) << "\n"; 
    //// This calls a function that will implement the same functionality as the previous line

    //std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
    //// Simple example of multi file program, calls a function defined in another file

    //int x{ getInteger() };
    //int y{ getInteger() };

    //    std::cout << x << " + " << y << " is " << x + y << "\n";
    //    // Simple demonstration of a multifile program, by isolating input function to a seperate file 
    //
    //#define PRINT_DANIEL
    //
    //#ifdef PRINT_DANIEL
    //    std::cout << "Daniel \n"; 
    //    // Ifdef states that if this identifier has been defined compille it
    //#endif  
    //
    //#ifdef PRINT_YO_MAMA
    //    std::cout << "YO MAMA \n";
    //    // Since this identifier has not been identified you dont compile this code
    //#endif // 
    //
    //#ifndef YO_MAMA
    //    std::cout << "MAMMA MIA \n"; 
    //    // Ifndef does the opposite of ifdef, compiling the code if the identifier was never defined
    //#endif // !YO_MAMA
    //
    //#if 0
    //    std::cout << "This code will never be compiled \n";
    //    // This code will never be compiled because if 0 is always false 
    //    // This file structure provides a slightly more efficient way to writing multiblock comments
    //#endif // 0

    //int x{ readAnswer() };
    //int y{ readAnswer() };
    //writeAnswer(x+y);
    //// Basic Example of using header files and multi file programs

    //std::cout << static_cast<int>(5.5);
    //// Static cast is how we can explicity tell the program to convert between different fundamental types

    //const double gravity{ 9.8 };
    //// Placing const before the variable is more idiomatic and easier to read
    //// This is a type of variable whose value cannot be changed through the life of the program

    //int x{ 3 + 4 };
    //std::cout << x << '\n';
    //// Compiler will compile 4+3, and use it as 7
    //// That way when the program is run computer will not have to contstantly add 4+3, only having to do it 
    //// once when the program is compiled
    //// Expressions that have a constant value like this are called: constant expressions **shocking**

    //const int x{ getValueFromUserUB() };
    //const int y{ 3 };
    //const int z{ 3 + 4 };
    //// X is a run-time constant since the compiler has to wait until runtime to know X's value
    //// Y is a compile time constant since compiler knows its value at compile time
    //// Z is a compile time constant since it always evaluates to the same value

    //constexpr double gravity{ 9.8 };
    //// Constexpr tells the compiler that the variable is a runtime constant and evaluate it like so
    //constexpr int userInput{ readAnswer() };
    //// On the other hand if you do constexpr on something that is not a compile time constant the program will fail to compile

    //int number{ 3 };
    //std::string name{ "Daniel Zhou" };
    //// Proper way to do strings in C++, allows much more manipulation than C style strings
    //std::cout << "Enter your name once ";
    //std::cin >> name;
    //// This cin does not work very well since it will break upon white space, only allowing you to enter a first or a last name but not both
    //std::cout << "Pick 1 or 2 ";
    //std::cin >> number;
    //std::cout << "Enter your name ";
    //std::getline(std::cin, name);
    //// This works slightly better because now you can do full line entries. 
    //// HOWEVER, this gets tricky because getline DOES NOT ignore leading whitespace >> does 
    //// In this case it breaks the getLine used here because the extra entry key would get processed into cin and the getline would not work
    //// THUS, we use the std::ws extraction keyword to ensure that leading whitespace gets processed  
    //std::cout << "Your name is" << name << "\n";
    //std::cout << "Enter your name thrice ";
    //std::getline(std::cin >> std::ws, name);
    //// This is the best way to do it and will catch all edge cases 
    //std::cout << "The length of your name  is" << static_cast<int>(name.length()) << "\n";

    //using namespace std::literals;
    //// This using clause is ok because the items in this namespace are unlikely to conflict with any user generated code
    //std::cout << "Bah! Humbug "s;
    //// The s at the end makes the compiler treat the string inside the double quotes as an std::string, instead of a c style string
    //std::cout << "Nah Fam I'm Gucci\n"sv;
    //// The sv at the end makes the compiler treat the string inside the double quotes as an std::string_view, instead of a c style string
    //// DONT PASS std::string's into functions USE std::string_view INSTEAD 

    //std::string name{};
    //int num{};
    //std::cout << "Enter your full name ";
    //std::getline(std::cin >> std::ws, name);
    //std::cout << "Enter a number ";
    //std::cin >> num;
    //std::cout << "The sum of the letters in your name and the number is " << num + static_cast<int>(name.length()) << "\n";

    //std::string_view s{ "Hello World" };
    //// String_views are read-only versions of strings that are much less expensive to intialize and copy
    //printSV(s);
    //std::string t{ "Lorem Ipsum" };
    //printSV(t);
    //// You can implicitly convert std::string into std::string_view in the context of a function
    //// You CANNOT IMPLICITLY convert std::string_view into std::string

    //double first_num{ enterDouble() };
    //double second_num{ enterDouble() };
    //char operation{ getOperator() };
    //printResult(first_num, second_num, operation);

    //double height{ height::inputHeight() };
    //double grav{ 9.8 };
    //height::printHeight(0, height, grav);
    //height::printHeight(1, height, grav);
    //height::printHeight(2, height, grav);
    //height::printHeight(3, height, grav);
    //height::printHeight(4, height, grav);
    //height::printHeight(5, height, grav);
    //
    //int arr[3]{ 1,2,3 };

    //for(int i = 0 ; i< 3; ++i){
    //    std::cout << i << '\n';
    //}

    //int smaller{};
    //int larger{};

    //std::cout << "Enter an integer: ";
    //std::cin >> smaller;
    //std::cout << "Enter a larger integer: ";
    //std::cin >> larger;

    //if (smaller > larger) {
    //    // Temp created and destroyed within these brackets
    //    int temp{ smaller };
    //    smaller = larger;
    //    larger = temp;
    //}

    //std::cout << "The smaller value is " << smaller << "\n";
    //std::cout << "The larger value is " << larger << "\n";

    //int apples{ 5 }; // We define apples in the main scope

    //{
    //    std::cout << apples << '\n'; // Since apples only has one definition rn, it will display that one definition

    //    int apples{ 0 }; // Apples now refers to the nested block apples, and the outer one is temporarily hidden

    //    apples = 10; // This variable intialization will set the inner block apples to 10

    //    std::cout << apples << '\n'; // Now, the inner block takes precendence so it will display inner block value
    //}

    //std::cout << apples << '\n'; // Inner block apples has been destroyed so it will now print outer block variable

    //std::cout << "The value of the variable is: " << constants::x << " and the variable g_y is: " << constants::y << "\n";
    //std::cout << "The value of the variable is: " << constants2::x << " and the variable g_y is: " << constants2::y << "\n";
    //std::cout << "The value of the variable is: " << constants3::x << " and the variable g_y is: " << constants3::y << "\n";

    //staticFunctionTest();
    //staticFunctionTest();
    //staticFunctionTest();

    doPrint();

    //using std::cout; // The using statement aliases cout to std::cout, giving it a qualified name 
    //cout << "Hello world !\n"; 

    //std::cout << "How many students are in your class? ";
    //int students{};
    //std::cin >> students;

    //if (students > constants::max_class_size)
    //    std::cout << "There are too many students in this class";
    //else
    //    std::cout << "This class isn't too large";

    std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

    int x{ 3 };
    
    switch (x)
    {
    case 1:
        std::cout << "one" << '\n';
        break;
    case 2:
        std::cout << "two" << '\n';
        break;
    case 3:
        std::cout << "three" << '\n';
        break;
    default:
        std::cout << "unknown" << '\n';
        break;
    }

    // y here is an L value, which is an identifiable object that has a longer lifetime
    // 3 * 4 + 3 is an R value, which means it is short lived and is not identifiable past execution
    // The R value gets stored into the L value here
    auto y{ 3 * 4 + 3 };

    // This DOES NOT refer to an address of operator
    // This refers to a lvalue reference, which means that this variable acts as a reference to another lvalue
    auto& ref_y{ y };

    std::cout << "The value of Y is: " << y << '\n';
    std::cout << "The value of ref_Y is: " << ref_y << '\n';

    // When you modify the value of a reference you indirectly modify the value of the referent
    ref_y = ref_y * 2;

    std::cout << "The value of Y is: " << y << '\n';
    std::cout << "The value of ref_Y is: " << ref_y << '\n';

    // You CANNOT change the variable that a reference is pointed to
    // If you try to like here, you will actually modifiy the value of the referent
    ref_y = x;

    std::cout << "The value of Y is: " << y << '\n';
    std::cout << "The value of ref_Y is: " << ref_y << '\n';

    {
        auto& ref_z = x;
        std::cout << "The value of ref_Z is: " << ref_z << '\n';
    }
    
    // The referent (LValue that reference is pointing to) does not care if / when the reference gets destroyed
    std::cout << "The value of Y is: " << y << '\n';
    // On the other hand, if the referent is destroyed, the value of the reference is now undefined.

    const auto ab{ 7 };
    const auto& ab_ref = ab;

    std::cout << "The value of ab is " << ab << '\n'; 
    std::cout << "The value of ab_ref is " << ab_ref << '\n';

    std::cout << "The value of x is " << x << '\n';
    // The function passed by reference changes the value of X 
    addOne(x);
    std::cout << "The value of x is " << x << '\n';
    // However, when you dont pass the function by reference, the value of x remains unchanged
    // Reference does not make a copy of the variable, rather just passing an alias to that variable
    addTwo(x);
    std::cout << "The value of x is " << x << '\n';

    // Here the & operator DOES NOT create a reference. Instead it returns the memory address for y
    std::cout << "The memory address of y is " << &y << '\n';

    // This is a POINTER which is DIFFERENT from a reference. This POINTER gives the direct memory address for the variable Y
    // ALWAYS intialize your pointers
    auto* address_y{ &y };

    // In this case the * operator returns the value at the memory address given by the pointer
    std::cout << "The value contained @ memory address of y is " << *address_y << '\n';

    // By modifying a dereferenced pointer, we are changing the value at that address, so in essence, changing Y
    *address_y = 6;
    std::cout << "The value contained @ memory address of y is " << *address_y << '\n';

    // If you are creating an empty pointer make sure it is created as a null pointer so you dont create undefined behavior 
    int* null_ptr{ null_ptr };

    if (null_ptr == nullptr) 
        std::cout << "This pointer is null \n";
    
    // Alternative test for null ptr, null will automatically convert to false
    if (!null_ptr)
        std::cout << "This pointer is also null \n";

    const auto value = 10;
    // To create a pointer that points to a const value, put the const before the type
    const auto* ptr{ &value };
    // To create a pointer with a fixed address, put the const value after the type
    auto* const ptr{ &value };



    return 0;
    // Your main function should always return 0 if it ran normally

}

int staticFunctionTest()
{
    int a{ 0 };
    static int b{ 0 };

    ++a;
    ++b;

    std::cout << "The value of int a is " << a << "\n";
    // Since a has automatic duration, it is destroyed and recreated
    // everytime the function is called, which means each time it will
    // print 1
    std::cout << "The value of int b is " << b << "\n";
    // Since b has static duration, it is only destroyed at the end of the file
    // that means that B will increment one more each time the function is called
    // Static variables are only ever intialized once
    // YOU CAN STILL ONLY CALL B WITHIN THE SCOPE OF staticFunctionTest
    // B is still scope limited, it just isnt destroyed 

    return b;
}

void printSV(std::string_view s)
// Static keyword means function is internally linked //
// Cannot be used outside the file its defined in
{
    std::cout << s << " Printed!\n";
}

static void doPrint()
{
    std::cout << "In doPrint()\n";
    // Basic demonstration of how a function works in C++ 
}

int getValueFromUserUB()
{
    int input{};
    std::cout << "Enter an integer: ";
    std::cin >> input;

    return input;
    // Always explain what the function returns in a comment:
    // In this case it returns a number inputted by the user 
}

int doubleNum(int input) {
    return input * 2;
    // Returns the double of the input number 
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
