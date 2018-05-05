#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>

const int BIG_INT = 500; //global constant

class bigint
     {
       private:

       //m_just means its a member variable
       int m_maxInt[BIG_INT];

       //function for initialixing the m_maxInt array
       void initializeMaxIntA();

       //Finding character length "strlen function"
       int stringLength(char[]);

       //converting character array to an integer array
       void stringToBigint(char[]);

       public:

       //default constructor
       bigint();

       //constructor to initialize bigint to int
       bigint(int);

       //constructor to initialize bigint to char
       bigint(char[]);

       //overload output operator
       friend  std::ostream& operator<<(std::ostream&, const bigint&);

       //equal operator
       bool operator==(const bigint&) const;

       //overload input operator>>()
       friend std::istream& operator>>(std::istream&, bigint&);

       //overload add(+)
       bigint operator+(const bigint&)const;

       //overload subscript operator[]
       int operator[](int) const;

       //overloaded factoral(!)
       int operator!();


};

#endif
