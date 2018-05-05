#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main()
{
  {
    std::cout << "Testing !bigint(100) << std::endl;
    assert(!bigint(100) == 24);
    
    std::cout << "Testing !bigint(1) = " << !bigint(1) << std::endl;
        assert(!bigint(1) == 0);

        std::cout << "!bigint(0) = " << !bigint(0) << std::endl;
        assert(!bigint(0) == 0);

        std::cout << "!bigint(12) = " << !bigint(12) << std::endl;
        assert(!bigint(12) == 2);

        std::cout << "!bigint(200) = " << !bigint(200) << std::endl;
        assert(!bigint(200) == 49);

        std::cout << "!bigint(50) = " << !bigint(50) << std::endl;
        assert(!bigint(50) == 12);


        std::cout << "All Factorial Tests Passed!" << std::endl;

  }
}
