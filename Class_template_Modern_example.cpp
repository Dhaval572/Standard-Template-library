// Class template example 
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
// Modern c++ approach
class Array
{
	unique_ptr<T[]> arr;
	size_t size;

public:
	Array(unique_ptr<T[]> &&a, size_t s) : arr(move(a)), size(s) {}

	void print()
	{
		for (size_t i = 0; i < size; i++)
			cout << arr[i] << ' ';

		printf("\n");
	}
};

int main()
{
	auto heapArr = make_unique<int[]>(3);

	// Setting elements
	heapArr[0] = 1;
	heapArr[1] = 2;
	heapArr[2] = 3;

	// Move ownership to Array
	Array<int> a1(move(heapArr), 3);
	a1.print();

	return 0;
}
