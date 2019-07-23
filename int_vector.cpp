/*
 * int_vector.cpp
 *
 *  Ericsson Tech Task: create vector class based on dynamic array for int
 *
 *  Created on: Jul 22, 2019
 *      Author: Oleksandr Zavalnyi
 *
 *
 *  To simplify the program and to highlight only main required functional features:
 *
 *
 *  	- the initial capacity of the array is simply defined as a const value CAPACITY_INCR
 *
 *  	- resizing of the array is made simply by expanding its capacity using
 *  	  CAPACITY_INCR value (we dodn't use explicit memory allocation)
 *
 *  	- we didn't use **int m_array instead of *int m_array to keep the program
 *  	  simpler even though it could make the program more efficient
 *
 *  	- some new features of c++11, such as auto type, have not been used to make
 *  	  the code more easy to read for the test application
 *
 *  	- exceptions handling was not addressed in details
 *
 */

#include <cstring>
#include "int_vector.h"


// constructor implementation
vector::vector() {
	m_array_size = 0;
	m_capacity = CAPACITY_INCR;
	m_array = new int[m_capacity];
	this->initialize_array(m_array_size);
}

// destructor implementation
vector::~vector(){
	delete [] m_array;
}


void vector::push_back(int elem){
	if (m_array_size >= m_capacity)
		expand_array();
	m_array[m_array_size++] = elem;
}


void vector::insert_at(size_t index, int elem){
	// check if the index lays within the range
	if (index < 0 || index >= m_array_size)
		throw("index out of range exception!");
	// make sure that there will be a free space in the array after the insertion
	if (m_array_size+1 >= m_capacity)
			expand_array();

	// create a space at the required position
	for(size_t i = m_array_size; i>index; i--)
	{
		m_array[i]=m_array[i-1];
	}
	m_array[index]=elem;
	m_array_size ++;
}


void vector::delete_at(size_t index){
	// check if the index lays within the range
	if (index < 0 || index >= m_array_size)
		throw("index out of range exception!");

	for(size_t i = index; i<m_array_size-1; i++)
	{
		m_array[i]=m_array[i+1];
	}
	m_array[m_array_size-1] = 0;
	m_array_size --;
}


void vector::delete_all(){
	delete [] m_array;
	m_array_size = 0;
	m_capacity = CAPACITY_INCR;
	m_array = new int[m_capacity];
	this->initialize_array(m_array_size);
}


int  vector::find_elem_index(int elem){
	for(size_t i = 0; i < m_array_size; i++)
		if (m_array[i]== elem) return i;
	return -1;
}


const vector &vector::operator=(const vector &obj){

	// used in case of self assignment
	if(this == &obj) return *this;
	// freeing  memory
	delete[] m_array;
	m_array = new int[obj.m_capacity];
	m_array_size = obj.m_array_size;
	m_capacity = obj.m_capacity;
	// copy all elements of the original array including zero values defined by the
	// size of m_capacity (as an alternative of using initialize_array() function)
	memcpy(m_array, obj.m_array, sizeof(int) * m_capacity);
	return *this;
}


vector::vector(const vector& obj){
	m_array = new int[obj.m_capacity];
	m_array_size = obj.m_array_size;
	m_capacity = obj.m_capacity;
	// copy all elements of the original array including zero values defined by the
	// size of m_capacity (as an alternative of using initialize_array() function)
	memcpy(m_array, obj.m_array, sizeof(int) * m_capacity);
}



// PRIVATE FUNCTIONS

void vector::initialize_array(size_t start_index){
	for(size_t i = start_index; i < m_capacity; i++)
	{
		m_array[i] = 0;
	}
}

void vector::expand_array(){

	 m_capacity = m_capacity + CAPACITY_INCR;
	 int *temp_array = new int[m_capacity];
	 // copy elements of the array to the temporary array
	 std::copy(m_array, m_array+m_array_size, temp_array);


	 // delete the original array
	 delete[] m_array;
	 m_array = temp_array;
	 initialize_array(m_array_size);
}






