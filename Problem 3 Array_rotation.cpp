// Array rotation
#include <iostream>
#include <algorithm>
using namespace std;

// Print the elements of the array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Function to rotate the array
void rotateArray(int arr[], int numRotation, int size)
{
	if (size == 0 || size == 1) // If array has 0 or 1 element, rotation isn't needed
		return;

	// Normalize numRotation to be within the bounds of the array size
	numRotation = numRotation % size;

	// Reverse the entire array
	reverse(arr, arr + size);

	// Reverse the first numRotation elements
	reverse(arr, arr + numRotation);

	// Reverse the remaining size-numRotation elements
	reverse(arr + numRotation, arr + size);
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int numRotation = 2;

	int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

	// Print original array
	cout << "Original array: ";
	printArray(arr, size);

	// Rotate the array
	rotateArray(arr, numRotation, size);

	// Print rotated array
	cout << "Array after " << numRotation << " rotations: ";
	printArray(arr, size);

	return 0;
}
/*
( Note: To be contine from "https://github.com/Dhaval572/Standard-Template-librery/blob/main/Problem_explaination_(1).cpp" So, in this we will solve the problem of array rotation )

Explaination: 

	step 1: 

		Devide numRotation by size and get remainder and assign remainder into numRotation variable. ( Line no. 23 )

	step 2:

		Now reverse entire array. ( Line no. 26 )

		Now Array: {5, 4, 3, 2, 1}

	step 3:

		Now reverse array from first element to numRotation element. ( Note: numRotation value is now 2 ). ( Line no. 29 )

		Now Array: {4, 5, 3, 2, 1}

	step 4:

		Now reverse array from arr + numRotation to arr + size. ( Line no. 32 )

		This is final Array: {4, 5, 1, 2, 3}

	So, this was how program works.

	I hope you understand every steps!

*/
