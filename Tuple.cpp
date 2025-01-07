// About tuple in c++
#include <iostream>
#include <tuple>
using namespace std; 

int main()
{
	// Declaration
	tuple<int, float, char> tup;

	// Initialization
	get<0>(tup) = 10;
	get<1>(tup) = 35.332f;
	get<2>(tup) = 'K';

	// Printing elements of tuples
	cout << "Tuple values: " << get<0>(tup) << ", "
	<< get<1>(tup) << ", " << get<2>(tup) << endl;

	// Declaration and initializaion of tuple
	tuple<int, string> game(1, "God of war");

	// printing elements
	cout << "Tuple values: " << get<0>(game) << ", " << get<1>(game) << endl;

	return 0;
}
/*
Explanation:

	A tuple can hold elements of different types and allows you to access them in a type-safe manner.

	Syntax of declaration:

		tuple<data_type1, data_type2, data_type3, ... > tuple_name;

	Syntax of initialization:

		We can initialize tuple in two way; 1. When declare and 2. After declare

		1. When declaration

			tuple<data_type1, data_type2, ... > tuple_name(element1, element2, ...);

		2. After declaration

			In this method, you must have to initialize values one by one by indexing.

			get<index> (tuple_name1) = value1;
			get<index> (tuple_name2) = value2;
			get<index> (tuple_name3) = value3;

	Characterstics of tuple:

		=> A tuple can hold elements of different types.

		=> The size of a tuple is fixed at compile time.

		=> You can access the elements in a tuple by index or by type.

		=> You can modify individual elements of a tuple, but you cannot change 
		   the number of elements or remove elements once the tuple is created.
*/
