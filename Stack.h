#include "Vector.cpp" // include definition of class Vector

// Stack class definition.
#ifndef STACK_H
#define STACK_H

template< typename T >
class Stack
{
public:
   explicit Stack(); // Constructs a stack container adaptor object, which is initially empty.
   bool empty() const; // Returns whether the stack is empty.
   unsigned int size() const; // Returns the number of elements in the stack.
   T& top(); // Returns a reference to the top element in the stack.
   const T& top() const; // Inserts a new element at the top of the stack, above its current top element.
                         // The content of this new element is initialized to a copy of val.
   void push( const T &val );
   void pop(); // Removes the element on top of the stack, effectively reducing its size by one.

//private:
   Vector< T > stack; // a vector which is used to store the elements of the stack
}; // end class Stack

#endif