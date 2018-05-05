#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
      if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }

    bigint object1; //first object of bigint
    bigint object2; //second object of bigint
    bigint result; //third object of bigint to store the result of the two bigints being added together

    while(in >> object1 >> object2) //while loop to read two bigints
      {
        result = object1 + object2; //adding the two bigints and storing the to result

        std::cout << "Object 1: " << object1 << std::endl; //prints out object 1
        std::cout << "Object 2: " << object2 << std::endl; //prints out object 2
        std::cout << "Result:   " << result << std::endl << std::endl; //prints out the final result
     }
    //while loop will get two new bigints until it reaches the end of the file

    in.close();
    return 0;
}
