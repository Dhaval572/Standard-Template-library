// About multi map 
#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> enoName; // Declaraion of multimap

	enoName.insert( {147, "Dhaval"} );
	enoName.insert( {150, "Manthan"} );
	enoName.insert( {140, "XYZ"} );  
	enoName.insert( {140, "ABC"} );

	multimap<int, string> :: iterator it; // Declaration of iterator

	// Print all elements of multimap
	for(it = enoName.begin(); it != enoName.end(); it++)
		cout << (*it).first << ' ' << (*it).second << endl;

	return 0;
}
/*
About multimap:

	Multimap is similar to map but there are some difference which is below:

	Multimap: 

		=>	Allows multiple elements with the same key

		=>	Allows multiple values for the same key

	Map:

		=>	Does not allow duplicate keys

		=>	Replaces existing values for the same key

	So, this was main difference between map and multimap.
*/
