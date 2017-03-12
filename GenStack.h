#include <iostream>
using namespace std;

template<class E> //Creating a template class of data type E.

class GenStack
{
	private:
		E *myArray; 	//Standard array of type E

		int max;		//Used to set max array size
		int top;		//Used to keep track of logical top of array
	public:
		GenStack(int maxSize);
		~GenStack();

		void push(E data);
		E pop();
		E peek();

		int getSize();
		int isEmpty();
		int isFull();
};

template<class E>
GenStack<E>::GenStack(int maxSize)
{
	myArray = new E[maxSize];
	max = maxSize;
	top = -1;
}

template<class E>
GenStack<E>::~GenStack()
{
	delete []myArray;
	cout << "Object destroyed." << endl;
}

template<class E>
void GenStack<E>::push(E data)
{
	if(isFull() == 1)
	{
		cout << "The stack is full; you cannot push any more elements in." << endl;
	}
	else
	{
		myArray[++top] = data; 	//Simultaneously assigns data to and increments the index of top.
	}
}

template<class E>
E GenStack<E>::pop()
{
	if(isEmpty() == 1)
	{
		cout << "The stack is empty; you cannot pop any more elements out." << endl;
	}
	else
	{
		return myArray[top--]; 	//Simultaneously returns and post decrements the index of rtop to simulate removal.
	}
}

template<class E>
E GenStack<E>::peek()			//Essentially same as pop() function but without changing the value of top.
{
	if(top == -1)
	{
		cout << "The stack is empty; there is nothing to peek." << endl;
	}
	else
	{
		return myArray[top];
	}
}

template<class E>
int GenStack<E>::getSize()
{
	return (top + 1);
}

template<class E>
int GenStack<E>::isEmpty()
{
	return(top == -1); 			//Returns binary values of true/false for the equation.
}

template<class E>
int GenStack<E>::isFull()
{
	return(top == (max - 1));
}