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
		for (int i = 0; i < capacity; i++)
		{
			vec[i] = 0;
		}
	}
	Vector(const Vector& vecToCopy)
	{
		std::cout << "copy constructor called" << std::endl;
		int copySize = vecToCopy.Size();

		capacity = copySize;
		vec = alloc.allocate(copySize);
		for (int i = 0; i < copySize; i++)
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


	const T& at(int index) const
	{
		try
		{
			return vec[index];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	T& at(int index)
	{
		try 
		{
			return vec[index];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	const T& operator[](int index) const
	{
		return vec[index];
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
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	myVec.push_back(4);
	myVec.push_back(5);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	myVec.push_back(6);
	for (int i = 0; i < myVec.Size(); i++) std::cout << myVec.at(i);


}
