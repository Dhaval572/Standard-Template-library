// Searching functions in algorithm lib
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> &v)
{
	cout << "Elements of vector: ";

	for(int i : v)
		cout << i << ' ';

	cout << endl;
}

int main()
{
	vector<int> vec = {223, 123, 211, 676, 890};

	sort(vec.begin(), vec.end()); // Sorts the element

	printVec(vec); // Prints all elments of vector

	bool found = binary_search(vec.begin(), vec.end(), 211);

	if(found)
		cout << "Element 211 found!" << endl;
	else
		cout << "Element not found!" << endl;

	auto it = find(vec.begin(), vec.end(), 211);

	if(it != vec.end())
		cout << "Element found at index no. " << distance(vec.begin(), it) << endl;
	else
		cout << "Element not found!" << endl;
	
	return 0;
}
/*
More functions in algorithm: 

	1). binary_search():

		Checks if a specific value exists in a sorted range. 

		Syntax:

			binary_search(vector_name.begin(), vector_name.end(), value_to_found);

	2).	find():

		Used to search for a specific value in a range of elements. It returns an iterator to the first occurrence of the element, or end() if the element is not found.

		Syntax:

			binary_search(vector_name.begin(), vector_name.end(), value_to_found);

	3). distance():

		Finds the index of particular element.

		Syntax:

			distance(vector_name.begin(), element);

	So, this was main and important searching functions in algorithm libs.

	So, i hope you understand!
*/
