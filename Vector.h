#include "Iterator.h" // include definition of class Iterator

// Vector class definition.
#ifndef VECTOR_H
#define VECTOR_H

template< typename T >
class Vector
{
public:
   typedef Iterator< T > iterator;

   Vector( unsigned int n = 0, const T val = 0 ); // Constructs a container with n elements. Each element is a copy of val.
   Vector( const Vector< T > &vectorToCopy ); // Constructs a container with a copy of each of the elements in x, in the same order.
   ~Vector(); // Destroys the container object.

   const Vector< T > &operator=( const Vector< T > &right ); // assignment operator
   
   T &operator[]( unsigned int ); // subscript operator for non-const objects returns modifiable lvalue

   T operator[]( unsigned int ) const; // subscript operator for const objects returns rvalue

   Iterator< T > begin(); // Returns a pointer pointing to the first element in the vector.
                             // If the container is empty, the returned pointer shall not be dereferenced.

   Iterator< T > end(); // Returns an pointer referring to the past-the-end element in the vector container.
               // The past-the-end element is the theoretical element that would follow the last element in the vector.
               // It does not point to any element, and thus shall not be dereferenced. 

   unsigned int getSize() const; // Returns the number of elements in the vector.

   bool empty() const; // Returns whether the vector is empty (i.e. whether its size is 0).

   T& back(); // Returns a reference to the last element in the vector.
                // Calling this function on an empty container causes undefined behavior. 

   void push_back( const T val ); // Adds a new element at the end of the vector, after its current last element.
                                    // The content of val is copied to the new element.
                                    // This effectively increases the container size by one,
                                    // which causes an automatic reallocation of the allocated storage space
                                    // if -and only if- the new vector size surpasses the current vector capacity.

   void pop_back(); // Removes the last element in the vector, effectively reducing the container size by one.
private:
   unsigned int size; // the number of elements in the vector
                      // This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
   unsigned int capacity; // the size of the storage space currently allocated for the vector, expressed in terms of elements.
                          // This capacity is not necessarily equal to the vector size. It can be equal or greater,
                          // with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
   T *ptr; // points to a dynamically allocated array which is used to store the elements of the vector
}; // end class Vector

#endif