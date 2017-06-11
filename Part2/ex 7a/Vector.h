/*
 * Vector.h
 *
 *  Created on: 31/05/2017
 *      Author: miguel
 */

#pragma once
#include <cstddef>
#include <stdexcept>

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
private:
	T * buffer;
	size_t bufferSize;
};

//Template stuff so it must be all in the header... feelsbadman

//--------------------------------------
//Would be in a .cpp if I could

template<class T>
Vector<T>::Vector() :
		bufferSize(0) {
	//Starts as nullptr because the vector is empty
	buffer = nullptr;
}

template<class T>
Vector<T>::Vector(unsigned int size) :
		bufferSize(size) {
	buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T &initial) :
		bufferSize(size) {
	buffer = new T[size];
	for (unsigned int i = 0; i < bufferSize; ++i) {
		buffer[i] = initial;
	}
}

template<class T>
Vector<T>::Vector(const Vector<T> &v) :
		buffer(v.buffer), bufferSize(v.bufferSize) {
}

template<class T>
Vector<T>::~Vector() {
	//Freeing allocated memory
	delete[] buffer;
	//setting buffer to nullptr in case there is an attempted access to a pointer to buffer
	buffer = nullptr;
}

template<class T>
size_t Vector<T>::size() const {
	return bufferSize;
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
	//Allocating new, larger array
	T* temp = new T[bufferSize + 1];

	//Copying the values that were in buffer to the new array
	for (unsigned int i = 0; i < bufferSize; ++i) {
		temp[i] = buffer[i];
	}

	//Adding the last element, that is being pushed back
	//(+1-1 is used in order to be more explicit)
	temp[bufferSize + 1 - 1] = value;

	//Deleting old array and assigning the buffer pointer to the newly created array
	delete[] buffer;
	buffer = temp;
	//Incrementing size by 1
	++bufferSize;
}

template<class T>
void Vector<T>::pop_back() {
	//Allocating new, smaller array
	//(we could also just say that bufferSize was -1 but we have no way of differentiating buffer size from allocated size)
	T* temp = new T[bufferSize - 1];

	//Copying the values that were in buffer to the new array (except the last one)
	for (unsigned int i = 0; i < bufferSize - 1; ++i) {
		temp[i] = buffer[i];
	}

	//Since last element was not added, we only need to delete the old array and change the buffer pointer
	//And reduce bufferSize by 1

	//Deleting old array and assigning the buffer pointer to the newly created array
	delete[] buffer;
	buffer = temp;
	//Decrementing size by 1;
	--bufferSize;
}

template<class T>
void Vector<T>::clear() {
	//Freeing allocated memory
	delete[] buffer;
	//setting buffer to nullptr in case there is an attempted access to a pointer to buffer
	buffer = nullptr;
	//Setting size to 0
	bufferSize = 0;
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
		return (const T&) buffer[i]; //Does this not work?
	else
		throw std::out_of_range("Vector out of range");
}

//Because pushing back only an item is too mainstream
template<class T>
void Vector<T>::push_back(const Vector<T> &v) {
	//Allocating new, larger array (sum of both sizes)
	T* temp = new T[bufferSize + v.bufferSize];

	//Copying the values that were in original buffer to the new array
	for (unsigned int i = 0; i < bufferSize; ++i) {
		temp[i] = buffer[i];
	}

	//Also appending the other vector passed in
	for (unsigned int i = 0; i < v.bufferSize; ++i) {
		//Adding bufferSize to append, otherwise we would just be overwriting
		temp[bufferSize + i] = v[i]; //works since the [] operator is overloaded
		//also could use .at if we were to go with the default asked implementation
	}

	//Deleting old array and assigning the buffer pointer to the newly created array
	delete[] buffer;
	buffer = temp;
	//Incrementing size by the size of the added vector
	bufferSize += v.bufferSize;
}

