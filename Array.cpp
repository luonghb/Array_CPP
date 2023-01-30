#include "Array.h"
template <class T> Array<T>::Array() {
	pArray = new T;
	size = 0;
	capacity = 1;
}

template <class T> Array<T>::Array(int newSize) {
	pArray = NULL;
	if (newSize > 0) {
		capacity = 1;
		while (capacity <= newSize) { capacity *= 2; }
		pArray = new T[capacity];
		if (pArray == NULL) {
			size = 0;
			capacity = 0;
		}
		else { size = newSize; }
	}
	else {
		pArray = new T;
		size = 0;
		capacity = 1;
	}
}

template <class T> Array<T>::~Array() {
	Clear();
}

template <class T> int Array<T>::GetSize() const { return size; }

template <class T> int Array<T>::GetCapacity() const { return capacity; }
		
template <class T> T& Array<T>::At(int pos) { return pArray[pos]; }

template <class T> void Array<T>::Clear() {
	if (capacity > 1) {
		delete[] pArray;
	}
	else {
		delete pArray;
	}
	pArray = NULL;
	size = 0;
}

template <class T> void Array<T>::PushBack(T newElement) {
	if (size + 1 >= capacity) {
		capacity *= 2;
		T *tmp = new T[capacity];
		for (int i = 0; i < size; ++i) {
			tmp[i] = pArray[i];
		}
		tmp[size] = newElement;
		++size;
		delete[] pArray;
		pArray = tmp;
	}
	else {
		pArray[size] = newElement;
		++size;
	}
}
template <class T> T Array<T>::PopBack() {
	if (size > 0) --size;
	return pArray[size];
}
template <class T> int Array<T>::Find(T val) {
	for (int i = 0; i < size; ++i) {
		if (pArray[i] == val) return i;
	}
	return -1;
}

template <class T> void Array<T>::Reserve() {
	if (pArray != NULL && size > 1) {
		T *tmp = new T[capacity];
		for (int i = 0, j = size - 1; j >= 0; ++i, --j) {
			tmp[i] = pArray[j];
		}
		delete[] pArray;
		pArray = tmp;
	}
}
template <class T> void Array<T>::Erase(int pos) {
	if (pos > 0 && pos < size) {
		for (int i = pos; i < size - 1; ++i) {
			pArray[i] = pArray[i + 1];
		}
		--size;
	}
}


template class Array<int>;
