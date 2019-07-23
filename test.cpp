/*
 * test.cpp
 *
 *  CEricsson Tech Task: create vector class based on dynamic array for int
 *
 *  Created on: Jul 22, 2019
 *      Author: Oleksandr Zavalnyi
 */


#include <iostream>
#include "int_vector.h"
using namespace std;

void print_vector(const vector &vec)
{
	vector vec1(vec);
	cout<<"vector size: "<< vec1.get_size()<<endl;
	cout<<"vector elements: ";
	for(int i = 0; i < vec1.get_size(); i ++)
				cout<<vec1[i]<<" ";
	cout<<endl;
	cout<<endl;
}

int main(){
	cout << "Test results: "<<endl<<endl;

	// create vector
	vector vec;

	// 1 Додати в кінець масиву
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	print_vector(vec);

	// 2 Вставити по індексу.
	vec.insert_at(2, 12);
	vec.insert_at(7, 10);
	print_vector(vec);

	// 3 Видалити один елемент за індексом.
	vec.delete_at(1);
	vec.delete_at(4);
	print_vector(vec);

	// 4 Видалити всі елементи.
	vec.delete_all();
	print_vector(vec);

	// 5 Знайти індекс елементу за значенням.
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	print_vector(vec);

	int index = vec.find_elem_index(3);
	if(index != -1)
		cout<<"index of the element with value " << 3 << " is "<< index<<endl;
	else
		cout<<"element " << 3 << " is not in the vector" << endl;

	index = vec.find_elem_index(6);
	if(index != -1)
		cout<<"index of the element with value " << 6 << " is "<< index<<endl;
	else
		cout<<"element " << 6 << " is not in the vector" << endl;

	cout<< endl;


	// 6 Перегрузити оператор присвоєння.
	vector vec1 = vec;
	print_vector(vec1);


	// 7 Реалізувати конструктор копіювання.
	vector vec2(vec);
	print_vector(vec2);

	return 0;
}

