#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main()
{
  std::ifstream in("data1-1.txt");
  if(!in)
  {
    std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
    exit(1);
  }
  in.close();
  return 0;
}
