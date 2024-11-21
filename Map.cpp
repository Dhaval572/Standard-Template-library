// Map in c++
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> nameEno; // Declaration of map

	// Inserting value in map
	nameEno["Dhaval"] = 147; 	
	nameEno["Manthan"] = 150;
	nameEno["Dhruvil"] = 148;

	map<string, int>::iterator it; // Declaration of iterator

	// Printing all elements of map
	for(it = nameEno.begin(); it != nameEno.end(); it++)
	{
		cout << (*it).first << ' ' << (*it).second << endl; // Print key value pairs
	}

	return 0;
}
/*
About map:

	a map is a container from the Standard Template Library (STL) that stores elements as key-value pairs.

Characteristics of map:

	1).	Key-Value Pairs: Stores data as unique key-value pairs.

	2).	Automatic Sorting: Keys are automatically sorted (default: ascending order).

	3).	Unique Keys: Each key must be unique. 

	4).	Efficient Operations: Search, insert, and delete operations are O(log n) on average.

	5).	Associative: Elements are accessed by keys, not indices.

	6).	Underlying Structure: Typically implemented as a self-balancing binary search tree (like 
	Red-Black Tree).

Uses of map:

	1). Database Indexing: Storing records with unique IDs (keys) and associated data.

	2). Caching: Implementing a cache where keys are data requests and values are the cached results.

	3).	Configuration Settings: Storing configuration options where keys are setting names and values are their respective values.

	So, this was small explaination of map in c++.

	I hope you understand!!
*/
