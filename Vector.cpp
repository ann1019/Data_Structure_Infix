#include "Vector.h" // include definition of class Vector 

// Member-function definitions for class Vector.
#ifndef VECTOR_CPP
#define VECTOR_CPP

template< typename T >
Vector< T >::~Vector()
{
   delete [] ptr;
}

template< typename T >
Iterator< T > Vector< T >::begin()
{
   return Iterator< T >( ptr );
}

template< typename T >
Iterator< T > Vector< T >::end()
{
   return Iterator< T >( ptr + size );
}

template< typename T >
unsigned int Vector< T >::getSize() const
{
   return size;
}

template< typename T >
bool Vector< T >::empty() const
{
   return ( size == 0 );
}

template< typename T >
T& Vector< T >::back()
{
   return ptr[ size - 1 ];
}

template< typename T >
void Vector< T >::pop_back()
{
   size--;
}

/*-----------------------------------------------------*/

template< typename T >
Vector<T>::Vector(unsigned int n, const T val)
{
	if (n > 0)
	{
		size = capacity = n;
		ptr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			ptr[i] = val;
	}
	else
	{
		size = 0;
		capacity = 0;
		ptr = new T[0];
	}
}

template< typename T >
Vector<T>::Vector(const Vector< T > &vectorToCopy)
{
	size = vectorToCopy.size;
	capacity = vectorToCopy.capacity;
	ptr = new T[capacity];
	for (T *p1 = ptr, *p2 = vectorToCopy.ptr; p2 < (vectorToCopy.ptr + size); p1++, p2++)
		*p1 = *p2;

}

template< typename T >
const Vector< T > & Vector<T>::operator=(const Vector< T > &right)
{
	size = right.size;
	capacity = right.capacity;
	delete[] ptr;
	ptr = new T[capacity];
	//for (iterator p1 = ptr, p2 = right.ptr; p1 < ptr + getSize(); p1++, p2++)
		//*p1 = *p2;
	for (int i = 0; i < size; i++)
		ptr[i] = right[i];

	return *this;
}

template< typename T >
T & Vector<T>::operator[](unsigned int n)
{
	if (n<0 || n >= size)
	{
		cout << "ptr[n], n is error!" << endl;
		exit(1);
	}
	return ptr[n];
}

template< typename T >
T Vector<T>::operator[](unsigned int n) const
{
	if (n<0 || n >= size)
	{
		cout << "ptr[n], n is error!" << endl;
		exit(1);
	}
	return ptr[n];
}

template< typename T >
void Vector<T>::push_back(const T val)
{
	Vector<T> temp(*this);
	delete[] ptr;
	size++;
	capacity++;
	ptr = new T[capacity];
	//for (iterator p1 = ptr, p2 =temp.ptr; p2 < ptr + temp.getSize(); p1++, p2++)
		//*p1 = *p2;
	for (T *p1 = ptr, *p2 = temp.ptr; p2 < (temp.ptr + temp.size); p1++, p2++)
		*p1 = *p2;
	ptr[size - 1] = val;
}

#endif