#include <iostream>

int main() {

    // bool: true/false 1bit
    bool boolean = 1 == 0; // b1 = false

    // int: integer size depends on compiler (at least 16)
    int integer = 0;
    std::cout << "While loop:\n";
    // break: causes the enclosing for, range-for, while or do-while loop or
    // switch statement to terminate
    // while: loops as long as the condition is met
    while(!boolean) { // condition is always true
        integer += 1;
        std::cout << integer << ' ';
        if (integer == 10) {
            break;
        }
    }
    std::cout << "\n\nSwitch:\n";
    // case: used in switch
    // default: if none of cases work
    switch(integer) {
        case 10:
            std::cout << "Case from switch\n";
            break;
        case 9:
            std::cout << "Maybe something is wrong\n";
            break;
        default:
            std::cout << "Default\n";
            break;
    }

    // const: can't change the value
    // double: double precision floating-point type

    const double E = 2.718281828459045;

    // E = 3.14 - will cause compiler error
    
    std::cout << "\nDo-while loop:\n";
    // do-while: does 1 iteration then checks the condition
    // short: integer with less bits
    short sh = 6;
    do {
        std::cout << sh << std::endl;
    } while (sh < 5);

    // continue: skips iteration
    // for (init; condition; action)
    // init is executed once before execution of the code block
    // condition is checked before each iteration
    // action (iteration-expression) is executed after every iteration
    std::cout << "\nFor loop:\n";
    for (char ch = 'a'; ch < 'd'; ++ch) {
        if (ch == 'b') {
            continue;
        }
        std::cout << ch << ' ';
    }
    std::cout << '\n';

    // long: integer with at least 32 bits
    long l = 300000;

    // return: terminates the current function and returns the specified value (if any) to the caller
    return 0;
}