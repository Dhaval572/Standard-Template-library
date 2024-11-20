// Find the Maximum and Minimum Elements in an Array
#include <iostream>
#include <vector>
using namespace std;

void findMax(vector<int> &vec)
{
	int max = vec.at(0); // Assume that first element is maximum
	for (int i = 1; i < vec.size(); i++)
	{
		// If you find maximum than max
		if (max < vec.at(i)) 
		{
			max = vec.at(i); // Update the max
		}
	}

	cout << "Maximum is: " << max << endl;
}

void findMin(vector<int> &vec)
{
	int min = vec.at(0); // Assume that first is minimum
	for(int i = 1; i < vec.size(); i++) 
	{
		// If you find minimum than min
		if(min > vec.at(i))
		{
			min = vec.at(i);
		}
	}

	cout << "Minimum is: " << min;
}

int main()
{
	int size, eleToAdd;
	cout << "Enter the size of vector: ";
	cin >> size;

	vector<int> v; // Declaration of vector

	for (int i = 0; i < size; i++) // Add element to vector
	{
		printf("Enter (%d) element: ", i);
		cin >> eleToAdd;
		v.push_back(eleToAdd);
	}

	findMax(v);
	findMin(v);

	return 0;
}
