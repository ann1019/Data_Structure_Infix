#include <iostream>
using namespace std;

// Iterator class definition.
#ifndef ITERATOR_H
#define ITERATOR_H

template< typename T >
class Iterator 
{
public:
   Iterator( T *p = 0 ); // default constructor
   Iterator( const Iterator< T > &iteratorToCopy ); // copy constructor
   T& operator*() const; // dereferencing operator
   Iterator< T >& operator=( const Iterator< T > &right ); // assignment operator
   Iterator< T >& operator++(); // prefix increment operator
   Iterator< T > operator++( int ); // postfix increment operator
   unsigned int operator-( Iterator< T > &right ) const; // subtraction operator; Iterator - Iterator
   bool operator<( const Iterator< T > &right ) const; // less than
private:
   T *ptr; // keep a pointer to Vector
}; // end class Iterator

#endif