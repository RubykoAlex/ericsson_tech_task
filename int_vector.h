/*
 * int_vector.h
 *
 *
 * Ericsson Tech Task: create vector class based on dynamic array for int
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
 *  	- some new features of  c++11, such as auto type, have not been used to make
 *  	  the code more easy to read for the test application
 *
 *  	- exceptions handling was not addressed in details
 *
 */


#ifndef INT_VECTOR_H_
#define INT_VECTOR_H_



#include <iostream>

// a constant to define initial and increment value of the array capacity
const int CAPACITY_INCR = 7;

class vector
{
public:

	// constructor and destructor
	vector();
	~vector();

	// REQUIRED FUNCTIONALITY:

	// Додати в кінець масиву. Add an element to the end of the array
	void push_back(int elem);

	// Вставити по індексу. Insert an element to the array at the location given by an index
	void insert_at(size_t index, int elem);

	// Видалити один елемент за індексом. Delete one
	// element from the array at the location given by an index
	void delete_at(size_t index);

	// Видалити всі елементи. Delete all elements of the array
	void delete_all();

	// Знайти індекс елементу за значенням. Find the index of an element by the given value
	// Returns index if the element is found, and returns -1 if the element is not found
	int  find_elem_index(int elem);

	// Перегрузити оператор присвоєння. Overload assignment operator
	const vector &operator=(const vector &obj);

	// Реалізувати конструктор копіювання. Realize copy constructor
	vector(const vector& obj);





	// FOR THE TEST PURPOSES ONLY
	int &operator[](int index) {

		return *(m_array + index); // a reference to the element
	}
	int get_size(){return m_array_size;}



private:
	int *m_array; // an array to store the data
	size_t m_array_size; // number of elements in the array
	size_t m_capacity; // current capacity of the array

	void initialize_array(size_t start_index); // used to  initialize the array starting from the given index
	void expand_array();// used to expand the capacity of the array by CAPACITY_INCR
};


#endif /* INT_VECTOR_H_ */
