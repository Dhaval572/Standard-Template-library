#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int> &arr, int k)
{
	int maxSum = INT_MIN, windowSum = 0, start = 0;

	// Step through the array
	for (int end = 0; end < arr.size(); end++)
	{
		windowSum += arr[end]; 

		cout << "Window: ";
		for (int i = start; i <= end; ++i)
			cout << arr[i] << " ";
		cout << "-> Sum = " << windowSum << endl;

		// If we've hit window size k, slide the window
		if (end >= k - 1)
		{
			maxSum = max(maxSum, windowSum); 
			windowSum -= arr[start];
			start++; 
		}
	}
	return maxSum;
}

int main()
{
	vector<int> arr = {1, 3, 5, 2, 8, 1, 5};
	int result = maxSumSubarrayOfSizeK(arr, 3);
	cout << "\nMaximum sum of a subarray is: " << result << endl;
	return 0;
}
