// More important methods in map
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, string> fullForm;

	fullForm["STL"] = "Standard Template Library";
	fullForm["OOP"] = "Object Oriented Programming";
	fullForm["DSA"] = "Data Structure and Algorithm";

	cout << "Size of map is: " << fullForm.size() << endl;	  // Will return size of map
	cout << "Is map is empty?: " << fullForm.empty() << endl; // Returns 0 means false

	fullForm.clear(); // Removes all elements from the map, making it empty

	fullForm["DSA"]; // Will not return value because map is empty ( Line no. 17 )

	map<int, string> storyGame;

	storyGame.insert( {1, "Valorant"} );
	storyGame.insert( {2, "CS:GO"} );
	storyGame.insert( {3, "Combat master"} );

	map<int, string> compatitiveGame;

	compatitiveGame.insert( {1, "Hitman"} );
	compatitiveGame.insert( {2, "God of war"} );
	compatitiveGame.insert( {3, "Tomb Raider"} );

	// Saprate line
	for(int i = 0; i < 100; i++)
		cout << "-";

	cout << "\nNow storyGame contains: \n";
	map<int, string> :: iterator it;

	// Swapping two maps
	storyGame.swap(compatitiveGame);

	for(it = storyGame.begin(); it != storyGame.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}

	cout << "\nAnd compatitiveGame contains: \n";

	for(it = compatitiveGame.begin(); it != compatitiveGame.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}

	return 0;
}
/*
About size():

	This function returns the size of map ( Line no. 14 )

		Syntax:
	
			map_name.size();

About empty()

	This function checks that map is empty or not; if map in empty than it will return 1 otherwise it will return 0

		Syntax:

			map_name.empty();

About clear()

	This function removes all elements from map.

		Syntax: 

			map_name.clear();

About swapping:

	In map you can swap two maps easily using swap() ( Line no. 41 )

		Syntax:

			map_name1.swap(map_name2);

	So, this was some set methods which are very usefull.

	So, i hope you are enjoying coding.
*/
