// Insertion and Deletion in map
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, string> gameName;

	// Insert using subscript operator []
	gameName["Valorant"] = "Compatitive Gaming";
	gameName["Fortnite"] = "Battle Royale";
	gameName["Hitman"] = "Game series";

	// Insert using insert()
	gameName.insert(make_pair("God of war", "Action Game series")); // Syntax 1
	
	gameName.insert( {"GTA", "Open World game"} ); // Syntax 2
	map<string, string> :: iterator it; // Declaration of iterator 

	// Print all elements of map
	cout << "Before deletion:\n";
	for(it = gameName.begin(); it != gameName.end(); it++)
	{
		cout << (*it).first << " : "  << (*it).second << endl;
	}

	gameName.erase("GTA"); // Delete gta key pair

	// Seprate for before deletion and after deletion
	for(int i = 0; i < 100; i++)
		cout << "-";

	cout << "\nAfter deletion:\n";

	// Print all elements of map
	for(it = gameName.begin(); it != gameName.end(); it++)
	{
		cout << (*it).first << " : "  << (*it).second << endl;
	}

	cout << "( GTA deleted )";

	return 0;
}
/*
Insert in map:

	There are two way to insert key and value in map:

		1). Using subscript operator '[]'

			map_name[Key] = value; 							( Line no. 10 )

		2).	Using insert()

			There are two syntax to use insert():

			1).	map_name.insert(make_pair( key, value )); 	( Line no. 16 )

			2). map_name.insert( { Key, value } );			( Line no. 18 )		

Deletion in map:

	To delete in map there are used erase()

		Syntax:

			map_name.erase(key);							( Line no. 28 )


	So, this was inserion and deletion methods in map.

	So I hope you understand everything and enjoying coding!👩‍💻
*/
