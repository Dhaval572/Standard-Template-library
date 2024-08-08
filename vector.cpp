//About vector in standerd template library
#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v) // for display vector
{
	for (int i = 0; i < v.size(); i++) // v.size() can provide the size of vector
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec1; // Declaration of vector
	int element, size;
	cout << "Enter the size of your vector: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter (" << i + 1 << ") element: ";
		cin >> element;
		vec1.push_back(element); // adding element in vector
	}
	cout << "You entered: ";
	display(vec1);
	return 0;
}
