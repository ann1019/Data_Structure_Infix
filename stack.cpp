#include"Stack.h"
#include"Vector.h"

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::empty() const
{
	if (stack.empty())
		return true;
	else
		return false;
}

template<typename T>
unsigned int Stack<T>::size() const
{
	return stack.getSize();
}

template<typename T>
T& Stack<T>::top()
{
	return stack.back();
}

template<typename T>
const T& Stack<T>::top() const
{
	return stack.back();
}

template<typename T>
void Stack<T>::push(const T &val)
{
	stack.push_back(val);
}

template<typename T>
void Stack<T>::pop()
{
	stack.pop_back();
}