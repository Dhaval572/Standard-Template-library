// About multiset in c++
#include <iostream>
#include <set>
using namespace std;

// Print multiset elements using for-each loop
void printMethod1(multiset<int> &mSet)
{
	cout << "Element of multiset is: ";

	for(int i : mSet)
		cout << i << ' ';
	
	cout << endl;
}		

// Print multiset elements using iterator
void printMethod2(multiset<int> &mSet)
{
	cout << "Element of multiset is: ";
	multiset<int> :: iterator it; // Declaration of iterators

	// For loop to print all elements
	for(it = mSet.begin(); it != mSet.end(); it++)
		cout << *it << ' ';

	cout << endl;
}

int main()
{
	multiset<int> s1; // Declaration of multiset

	s1.insert(27);
	s1.insert(27);	
	s1.insert(27);	
	s1.insert(28);	
	s1.insert(29);	
	s1.insert(30);	

	cout << "Before deletion:\n "; 
	printMethod2(s1); 

	cout << "After deletion:\n ";
	s1.erase(27);
	printMethod1(s1);

	return 0;
}
/*
About Multiset in C++

	A multiset is a container that stores a collection of elements, where duplicates are allowed, and the elements are kept in a specific order.

	Syntax of multiset:

		multiset <data_type> multiset_name;

	Characteristics of multiset:

		1).	Duplicate Elements:

			A multiset allows multiple occurrences of the same element.

			Unlike a set, if you try to insert a duplicate element, it will be added to the multiset.

		2).	Ordered Elements:

			The elements in a multiset are stored in a sorted order.

			By default, multisets are ordered in ascending order.

		3).	Efficient Search:

			Multisets provide logarithmic time complexity (O(log n)) for searching, insertion, and deletion operations, as they are typically implemented as balanced binary search trees (e.g., Red-Black trees).

	Basic Operations on a multiset:

		Insert: Adds an element to the multiset (duplicates allowed).

		Erase: Removes an element from the multiset.

		Find: Searches for an element.

		Size: Returns the number of elements in the multiset.

		Empty: Checks if the multiset is empty.

		Lower Bound/Upper Bound: Finds the first element that is not less than a given value or the first element greater than a given value.

	Count: Returns the number of occurrences of an element.

	Time complexity of multiset methods:

		Insert: O(log n)
		Erase: O(log n)
		Find: O(log n)
		Empty: O(1)
		Size: O(1)
		Iterate: O(n)
		Count: O(log n)

	So, this was some information about multiset in C++.

	So, I hope you understand!
*/
