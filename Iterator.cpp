#include"Iterator.h"

template< typename T >
Iterator<T>::Iterator(T* p)
:ptr(p)
{}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iteratorToCopy)
{
	ptr = iteratorToCopy.ptr;
}

template<typename T>
T& Iterator<T>::operator*() const
{
	return *ptr;
}

template<typename T>
Iterator< T >& Iterator<T>::operator=(const Iterator< T > &right)
{
	if (&right != this)
		ptr = right.ptr;
	return *this;
}

template<typename T>
Iterator< T >& Iterator<T>::operator++()
{
	++ptr;
	return *this;
}

template<typename T>
Iterator< T > Iterator<T>::operator++(int)
{
	Iterator<T> temp(*this);
	++ptr;
	return temp;
}

template<typename T>
unsigned int Iterator<T>::operator-(Iterator< T > &right) const
{
	return (ptr - right.ptr);
}

template<typename T>
bool Iterator<T>::operator<(const Iterator< T > &right) const
{
	if (ptr < right.ptr)
		return true;
	else
		return false;
}