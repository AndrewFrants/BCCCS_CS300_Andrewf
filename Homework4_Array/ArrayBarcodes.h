#pragma once
#include "ArrayFullException.h"

// Sample application of storing barcodes
// in an array
template <class T>
class ArrayBarcodes
{
	T* arrayList;
	long top;
	long count;
public:
	// designed to store billions of records
	ArrayBarcodes(long count)
	{
		initialize(count);
	}

	// initialize/reset array
	void initialize(long count)
	{
		arrayList = new T[count];
		top = 0;
		this->count = count;
	}

	// insert an item
	void insert(T& item)
	{
		if (top == count)
		{
			throw ArrayFullException("No space left in array! Allocate a larger array!");
		}

		arrayList[top] = item;
		top++;
	}

	// search for an item
	bool search(T& item)
	{
		for (int i = 0; i < top; i++)
		{
			if (this->arrayList[i] == item)
			{
				return true;
			}
		}

		return false;
	}
};