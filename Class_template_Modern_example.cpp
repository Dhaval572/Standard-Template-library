// Class template example 
#include <iostream>
#include <memory>
using namespace std;

/*
    +----------------------------------+
    | Advantages over the normal array |
    +----------------------------------+

    1. Same speed as raw arrays for access (arr[i]) But allocates from heap
    2. Automatic Memory Management
    3. Type Safety
    4. Zero-cost ownership transfer (O(1)) ( cause of move sementics )
    5. Exception Safety
    6. No ambiguity about who owns/deletes memory
    7. Zero overhead (compiler optimizes unique_ptr to raw pointer)
*/

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
