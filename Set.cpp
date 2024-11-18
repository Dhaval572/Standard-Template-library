// About Set in c++
#include <iostream>
#include <set>
using namespace std;

// Traversing the set
void traverseSet(set<int> &s)
{
	cout << "Elements of the Set: ";
	
	// Printing element of set using for-each loop
	for(int ele : s)
		cout << ele << ' ';

	cout << endl;
}

int main()
{
	set<int> s; // Declaration of set 

	s.insert(27); 
	s.insert(28); 
	s.insert(29); 
	s.insert(30); 

	cout << "Before deletion: \n";
	traverseSet(s);

	cout << "After deletion: \n";
	s.erase(30);
	traverseSet(s);

	cout << "Size of set is : " << s.size(); // Will return 3
	cout << "\nIs Set is empty? " << s.empty(); // Will return 0 means false

	return 0;
}
/*
About Set in c++

	A set is a container that stores a collection of unique elements in a specific order.

	Syntax of set:

		set <data_type> set_name;

	Characteristics of set:

		1).	Unique Elements: 

			A set will automatically remove duplicates.

			If you try to insert a duplicate element, it won't be added.

		2).	Ordered Elements: 

			The elements in a set are stored in a sorted order.

			By default, sets are ordered in ascending order.

		3).	Efficient Search:

			Sets provide logarithmic time complexity (O(log n)) for searching, insertion, and deletion operations, as they are typically implemented as balanced binary search trees (e.g., Red-Black trees).

	Basic Operations on a set:

		Insert: Adds an element to the set.

		Erase: Removes an element from the set.

		Find: Searches for an element.

		Size: Returns the number of elements in the set.

		Empty: Checks if the set is empty.

		Lower Bound/Upper Bound: Finds the first element that is not less than a given value or the first element greater than a given value.

	Time complexity of set methods:

		Insert: O(log n)
		Erase: O(log n)
		Find: O(log n)
		Empty: O(1)
		Size: O(1)
		Iterate: O(n)

	So, this was some information about set in c++.

	So, i hope you understand!
*/
