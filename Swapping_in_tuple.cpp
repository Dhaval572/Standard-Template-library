// Swapping two tuples
#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple<int, float, char> tup1(1, 1.1, 'a');
	tuple<int, float, char> tup2(2, 2.2, 'b');

	cout << "Before swap\ntup1 is: ( " << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup2) << " )\n";

	cout << "Before swap\ntup2 is:( " << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << " )\n";

	tup1.swap(tup2); // Swapes two tuples

	cout << "After swap\ntup1 is: ( " << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup2) << " )\n";

	cout << "After swap\ntup2 is:( " << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << " )\n";

	return 0;
}
