//Jessica Gehring
//cs23001
//6-15-2017

#include "bigint.hpp"
#include <iostream>


int bigint::stringLength(char characters[])
//finding the length of the string
{
 int  length  = 0;
 while(characters[length] != '\0')//looping through to find the length of the string
    {
      length++; //incrementing length to next index
        }
 return length; //returning the length of the string
}

void bigint::initializeMaxIntA()
{
  //initializes the m_maxInt[] array to 0;
  for(int i = 0; i < BIG_INT; ++i)
    {
      m_maxInt[i] = 0;
    }
}

//default constructor
bigint::bigint()
{
  initializeMaxIntA();
}

bigint::bigint(int number)
{

  initializeMaxIntA();

  //index for the array
  int i = 0;


  while(number > 0)
    {
      m_maxInt[i] = number % 10; //using the remainder of number and adding it to index i
       number = number / 10; //assigning to number
      ++i; //incrementing i
    }
}

bigint::bigint(char characters[])
{
  stringToBigint(characters);
}

void bigint::stringToBigint(char characters[])
{
  initializeMaxIntA();

  int y = 0;  //initializing y

  for(int x = stringLength(characters) - 1; x >= 0; x--) //loop to find the length of the st\
ring
    {
      m_maxInt[y] = characters[x] - '0'; //assignint characters[x]-1 array to m_maxInt[y]
      ++y; //incrementing y
    }

std::ostream& operator<<(std::ostream& ostr, const bigint& myBigint)
{
  int start = 0; //initializing start
  int count = 0; //initializing count

  //for loop to find the first non-zero element
  for(int i = BIG_INT - 1 ; i >= 0; i--)
    {
      start = i; //assigning i to start
      if(myBigint.m_maxInt[start] != 0) //comparing myBigint.m_maxInt[start] to see whether it is not = to 0
        {
          break; //if it is not equal to zero, then break out of the for loop
        }
    }

  //loop printing out
  for(int i = start; i >= 0 ; i--)
    {
      count++; //increments count by 1
       ostr << myBigint.m_maxInt[i]; //prints out the value stored at index i

      if(count == 50) //determines whether count is equal to 50
        {

          // add a new line if cout equals 50
          ostr << '\n';
          count = 0; //then initializes count back to 0 to start over
        }
    }

  return ostr; //after the loop is finished, becomes false, it returnes ostr
}

bool bigint::operator==(const bigint& bigintR) const
{
  for(int i = 0; i < BIG_INT; i++) //if i is less than 500 perform the body of the loop
    {
      if(m_maxInt[i] != bigintR.m_maxInt[i]) //determines whether the two bigints are the same or not
    {
      return false; //if the two bigints are not the same it returns false
    }
    }
  return true; //if the two bigints are both the same it will return true
}

std::istream& operator>>(std::istream& istr, bigint& myBigint)
{
  char temp[BIG_INT + 1] = {'\0'}; //creating a temporary character array, the index is 501 t\
o include null, and assiging a null to each index of the array
  int i = 0; //initializing i to be 0
  char number; //declaring a character variable for input
do
  {
    istr >> number; //obtaining input

    if(number >= '0' && number <= '9') //to determine the string of characters from 0 to 9
      {
        temp[i] = number; //storing number to the character array at a certain index
        i++; //incrementing the index
      }
  }while(number != ';'); //while loop to determine if there is a semicolon, if true then loop stops

myBigint.stringToBigint(temp); //passing the character array into the function stringToBigint\
 to change the character to integer. uses the object myBigint

 return istr; //returing istream
}

bigint bigint::operator+(const bigint& bigintR)const
{
  bigint result; //creating a bigint object to store the result of the two added bigints in
  int carry = 0; //initializing carry to zero

  for(int index = 0; index < BIG_INT; index++) //loop for indexing through the arrays
    {
      result.m_maxInt[index] = (m_maxInt[index] + bigintR.m_maxInt[index] + carry) %10; //adding the two bigints togehter along with carry and finding the remainder and storing it to result.m_maxInt[index]
      carry = (m_maxInt[index] + bigintR.m_maxInt[index] + carry) /10; //finding carry
    }
  //assert(carry == 0); can use to test the function, if it results in false it will  break out of the loop
  return result; //returning bigint object result
    }

int bigint::operator[](int digit) const
{
  return m_maxInt[digit]; //returning m_maxInt[digit]

  //assert(digit < BIG_INT); can use this to test the function
}

int bigint::operator!()
{
  //extracting the factor out of the array
  int factor = 0;
  int mult = 1;
  for(int index = 0; index < BIG_INT; index++)
    {
      factor += m_maxInt[index] * mult; //adding factor and initializing the result to factor\
 after the element of the array is multiplied by mult
      mult *= 10; //multiplying mult by 10 to increase the size
     }
  initializeMaxIntA(); //initializing the array back to 0 after the for loop

  if(factor == 0) //if the condition is true, if facotr is 0 you then return 0
    {
  return 0;
    }
  m_maxInt[0] = 1; //when condition is not true, initialize the first element of the array to be 1

  for(int currentFact = 1; currentFact <= factor; currentFact++) //for loop to determine when to quit
    {
      int carry = 0;
      for(int index = 0; index < BIG_INT; index++) // for loop for indexing through the array
        {
          int result = (m_maxInt[index] * currentFact + carry); //multiplying the element of the array to the currentFact and adding to carry
          m_maxInt[index]= result %10; // finding the remainder or result and storing it in the array

          carry = result /10; //dividing result by 10 to find carry
          }
    }
  for(int index = 0; index < BIG_INT; index++)
    {
      if(m_maxInt[index]!= 0) //indexes through each element of the array to find the first 0
        {
          return index; //if condition is true. doesnt find a 0, then it returns an index
        }
    }
  return -1;
}





