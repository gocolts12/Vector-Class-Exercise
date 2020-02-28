// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class Vector
{
private: 
	std::allocator<T> alloc; 
	T* vec;
	int size;

public:
	Vector()
	{
		std::cout << "default constructor called" << std::endl;
		
	}
	Vector(const int &designatedSize)
	{
		std::cout << "size-defined constructor called" << std::endl;
		size = designatedSize;
		vec = alloc.allocate(size);
		for (int i = 0; i < size; i++)
		{
			//alloc.construct(vec[i], 0);
			vec[i] = 0;
		}
	}
	Vector(const Vector& vecToCopy)
	{
		std::cout << "copy constructor called" << std::endl;
		int copySize = vecToCopy.Size();

		this.size = copySize;
		vec = alloc.allocate(copySize);
		for (int i = 0; i < copySize; i++)
		{
			vec[i] = vecToCopy[i];
		}
	}

	//Vector()
	//{
	//	std::cout << "move constructor called" << std::endl;
	//	
	//}



	int Size()
	{
		return size;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector& mikeVector);

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
		alloc.deallocate(vec, size);
		alloc.destroy(vec);
	}
};

int main()
{
	Vector<int> myVec(3);
	std::cout << myVec[0];

}
