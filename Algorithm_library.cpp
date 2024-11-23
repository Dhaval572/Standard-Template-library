// Algorithm methods in stl
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Prints all elements of vector
void printVec(vector<int> &v)
{
	cout << "Elements of vector: ";

	for(int ele : v)
		cout << ele << ' ';

	cout << endl;
}

int main()
{
	vector<int> v = {43,45,56,34,78,89,34,33,34};

	cout << "Before sort: " << endl;
	printVec(v);

	sort(v.begin(), v.end()); // Sort in ascending order
	
	cout << "After sort: " << endl;
	printVec(v);

	int i = count(v.begin(), v.end(), 34); // Finds that how many 34 are there
	cout << "Count occurrences of '34' is: " << i << endl;

	return 0;
}
/*
About algorithm library:

	This library provides some algorithms like searching, sorting etc.

	Here are some algorithm functions: 

	1).	sort():

		This function sorts the elements of given containers like array, vector etc;

		Syntax:

			sort(begin_iterator, end_iterator);

	2). count():

		counts the number of occurrences of a specific value in a range of elements.

		Syntax:

			count(begin_iterator, end_iterator, value_to_count);

	So, this was some algorithm functions which is widely used in c++.

	So, i hope you understand!!

*/
