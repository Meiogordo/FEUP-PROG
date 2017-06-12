/*
 * Vector.h
 *
 *  Created on: 31/05/2017
 *      Author: miguel
 */

#pragma once
#include <cstddef>
#include <stdexcept>
#include <stdlib.h>

template<class T>
class Vector {
public:
	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T &initial);
	Vector(const Vector<T> & v);
	~Vector();
	size_t size() const;
	bool empty() const;
	T & front();
	T & back();
	T & at(size_t index);
	void push_back(const T & value);
	void pop_back();
	void clear();
	//extra enhancements
	T & operator[](size_t i);
	const T & operator[](size_t i) const;
	void push_back(const Vector<T> &v);
	//7b
	size_t capacity() const;
	void reserve(size_t newSize);
private:
	T * buffer;
	size_t bufferSize;
	size_t bufferCapacity;
};

//Template stuff so it must be all in the header... feelsbadman

//Changing to C memory allocation to be able to use realloc for easier reallocation
//Note that we should check if realloc and malloc returned NULL (or nullptr I'm not sure) but that is skipped only because of lazyness

//--------------------------------------
//Would be in a .cpp if I could

template<class T>
Vector<T>::Vector() :
		bufferSize(0), bufferCapacity(0) {
	//Starts as nullptr because the vector is empty
	buffer = nullptr;
}

template<class T>
Vector<T>::Vector(unsigned int size) :
		bufferSize(size), bufferCapacity(size) {
	buffer = (T*) std::malloc(bufferSize * sizeof *buffer);
}

template<class T>
Vector<T>::Vector(unsigned int size, const T &initial) :
		bufferSize(size), bufferCapacity(size) {
	buffer = (T*) std::malloc(bufferSize * sizeof *buffer);
	for (unsigned int i = 0; i < bufferSize; ++i) {
		buffer[i] = initial;
	}
}

template<class T>
Vector<T>::Vector(const Vector<T> &v) :
		buffer(v.buffer), bufferSize(v.bufferSize), bufferCapacity(
				v.bufferCapacity) {
}

template<class T>
Vector<T>::~Vector() {
	//Freeing allocated memory
	free(buffer);
	//setting buffer to nullptr in case there is an attempted access to a pointer to buffer
	buffer = nullptr;
}

template<class T>
size_t Vector<T>::size() const {
	return bufferSize;
}

template<class T>
size_t Vector<T>::capacity() const {
	return bufferCapacity;
}

template<class T>
bool Vector<T>::empty() const {
	return bufferSize == 0; //If size is 0 vector is empty, else it is not
}

template<class T>
T& Vector<T>::front() {
	return buffer[0];
}

template<class T>
T& Vector<T>::back() {
	return buffer[bufferSize - 1];
	//Would also be possible to return *(buffer + bufferSize - 1) I believe
}

template<class T>
T& Vector<T>::at(size_t index) {
	if (index < bufferSize)
		return buffer[index];
	else
		throw std::out_of_range("Vector out of range"); // out of bounds m8? u high or smth??
}

template<class T>
void Vector<T>::push_back(const T &value) {

	//Since 2*0 = 0, special case for that
	if(bufferCapacity == 0){
		//Since we are only allocating one value at a time we only need to allocate for 1 element (the one we are inserting)
		buffer = (T*) std::malloc(sizeof *buffer);
		//Changing size and capacity to 1
		bufferCapacity = 1;
		bufferSize = 1;
		//Setting the value
		buffer[0] = value;
		//Exiting the function
		return;
	}

	//Checking if there is available capacity to insert the element directly
	if (bufferSize + 1 <= bufferCapacity) {
		//+1 to point at last element +1, -1 to show that we are working with indexes, so -1
		buffer[bufferSize + 1 - 1] = value;
		++bufferSize; //Increasing the size by 1 (nr of added elements)
		return; //Exiting the function
	}

	//If the vector does not have enough size to hold the new element, allocate double the allocated space at the time
	buffer = (T*) std::realloc(buffer, 2 * bufferCapacity * sizeof *buffer);
	//Doubling the bufferCapacity to match the newly allocated space
	bufferCapacity *= 2;

	//Now that the space is allocated and the capacity updated, add the element at the end of the array
	buffer[bufferSize + 1 - 1] = value;
	//One more element was allocated, updating size
	++bufferSize;

}

template<class T>
void Vector<T>::pop_back() {
	//Since we do not know what type T is, we cannot do something like
	//buffer[bufferSize - 1] = 0;
	//To clear the last element

	//As such, we only reduce the size by 1 to "magically" remove the element

	//Decrementing size by 1;
	--bufferSize;
}

template<class T>
void Vector<T>::clear() {
	//Freeing allocated memory
	free(buffer);
	//setting buffer to nullptr in case there is an attempted access to a pointer to buffer
	buffer = nullptr;
	//Setting size to 0
	bufferSize = 0;
	//Setting capacity to 0
	bufferCapacity = 0;
}

template<class T>
T& Vector<T>::operator [](size_t i) {
	//Sneaky way
	//return this->at(i);
	//Legit way
	if (i < bufferSize)
		return buffer[i];
	else
		throw std::out_of_range("Vector out of range"); //u wot m8 wanna get out of bounds??!?
}

template<class T>
const T& Vector<T>::operator[](size_t i) const {
	if (i < bufferSize)
		return (const T&) buffer[i];
	else
		throw std::out_of_range("Vector out of range");
}

//Because pushing back only an item is too mainstream
//Note: does not work if the vector to add is larger than the capacity that the vector already has because the memory to allocate would have to be more than double the existing capacity

template<class T>
void Vector<T>::push_back(const Vector<T> &v) {
	//Checking if the vector can hold the extra size
	if (bufferSize + v.bufferSize <= bufferCapacity) {
		//It can, so we just copy the elements
		for (unsigned int i = 0; i < v.bufferSize; ++i) {
			buffer[bufferSize + i] = v.buffer[i];
		}
		//Updating size
		bufferSize += v.bufferSize;
		//Exiting function
		return;
	}

	//If the vector does not have enough size to hold the new element, allocate double the allocated space at the time
	buffer = (T*) std::realloc(buffer, 2 * bufferCapacity * sizeof *buffer);
	//Doubling the bufferCapacity to match the newly allocated space
	bufferCapacity *= 2;

	//Now that the space is allocated and the capacity updated, we just copy the elements
	for (unsigned int i = 0; i < v.bufferSize; ++i) {
		buffer[bufferSize + i] = v.buffer[i];
	}
	//Incrementing size by the size of the added vector
	bufferSize += v.bufferSize;
}

