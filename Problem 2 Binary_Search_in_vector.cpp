// Binary search using vector
#include <iostream>
#include <vector>
using namespace std;

void bSearch(vector<int> &vec, int target)
{
	int low = 0, high = (vec.size() - 1), mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(vec.at(mid) == target)
		{
			printf("Target found at index no. %d", mid);
			return;
		}

		if(vec.at(mid) < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << "Element doesn't found!";
	return;
}

int main()
{
	vector<int> v;
	int size, eleToAdd;
	cout << "Enter the size of vector: ";
	cin >> size;

	for(int i = 0; i < size; i++)
	{
		printf("Enter (%d) element: ", i + 1);
		cin >> eleToAdd;
		v.push_back(eleToAdd);
	}

	int target;
	cout << "\nEnter the target which you want to found: "; 
	cin >> target;

	bSearch(v, target);

	return 0;
}
