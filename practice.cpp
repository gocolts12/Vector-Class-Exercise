// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vld.h>

template <typename T>
class Vector
{
private: 
	std::allocator<T> alloc; 
	T* vec;
	int capacity;
	int numValuesFilled;

public:
	Vector()
	{
		std::cout << "default constructor called" << std::endl;
		capacity = 0;
		numValuesFilled = 0;
	}

	Vector(const int &designatedSize)
	{
		std::cout << "size-defined constructor called" << std::endl;
		capacity = designatedSize;
		numValuesFilled = 0;
		vec = alloc.allocate(capacity);
	}

	Vector(Vector& vecToCopy)
	{
		std::cout << "copy constructor called" << std::endl;
		numValuesFilled = vecToCopy.Size();

		capacity = vecToCopy.getCapacity();
		vec = alloc.allocate(capacity);
		for (int i = 0; i < numValuesFilled; i++)
		{
			vec[i] = vecToCopy[i];
		}
	}

	void push_back(T val)
	{
		if (capacity == 0)
		{
			capacity = 1;
			vec = alloc.allocate(1);
			vec[0] = val;
			++numValuesFilled;
		}
		else if (numValuesFilled >= capacity)
		{
			resize();
			vec[numValuesFilled] = val;
			numValuesFilled++;
		}
		else
		{
			vec[numValuesFilled] = val;
			numValuesFilled++;
		}
		
	}

	void pop_back()
	{
		if (capacity == 0) return;
		alloc.destroy(back());
		--numValuesFilled;
	}

	T* back()
	{
		T* backPointer = &vec[numValuesFilled];
		return backPointer;
	}

	void resize()
	{
		T* tempVec;
		tempVec = alloc.allocate(capacity * 2);
		memcpy(tempVec, vec, numValuesFilled * sizeof(T));
		alloc.deallocate(vec, capacity);
		vec = tempVec;
		capacity *= 2;
	}

	int Size()
	{
		return numValuesFilled;
	}

	int getCapacity()
	{
		return capacity;
	}

	const T& at(int index)
	{
		//Using exception handling just so we don't segfault and crash during execution
		//I know it's probably bad. Please don't yell at me 
		try 
		{
			return vec[index];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	const T& operator[](int index)
	{
		return vec[index];
	}

	~Vector()
	{
		alloc.deallocate(vec, capacity);
		alloc.destroy(vec);
	}
};

int main()
{
	Vector<int> myVec;
	myVec.pop_back();
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	myVec.push_back(4);
	myVec.push_back(5);
	myVec.push_back(6);
	for (int i = 0; i < myVec.Size(); i++) std::cout << myVec.at(i);
	std::cout << std::endl;
	myVec.pop_back();
	for (int i = 0; i < myVec.Size(); i++) std::cout << myVec.at(i);
	std::cout << std::endl;
	myVec.push_back(6);
	for (int i = 0; i < myVec.Size(); i++) std::cout << myVec.at(i);
	std::cout << std::endl;

	//Test copy  constructor

	Vector<int> myVec2(myVec);

	for (int i = 0; i < myVec2.Size(); i++) std::cout << myVec2.at(i);

	return 0;


}
