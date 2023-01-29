#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template <class T> class Array
{
	public:
		Array();
		Array(int newSize);
		~Array();
		
		int GetSize() const;
		int GetCapacity() const;
		
		T& At(int pos);
		void Clear();
		void PushBack(T newElement);
		T PopBack();
		int Find(T val);
		void Reserve();
		void Erase(int pos);
		
	private:
		T *pArray;
		int size;
		int capacity;
};

#endif
