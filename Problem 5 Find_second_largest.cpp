// Find second largest number from the vector
#include <iostream>
#include <vector>
#include <limits> // To use numeric_limits<int>::min()
using namespace std;

// Time complexity: O(n) and Space complexity: O(1)
int findSecondLargest(vector<int> arr)
{
    if (arr.size() < 2)
        return -1; 

    // Both largest and secondLargest are initialized to the smallest possible integer value.
    int largest = numeric_limits<int>::min();
    int secondLargest = numeric_limits<int>::min();

    for (int num : arr)
    {
        // If current element is greater than largest
        if (num > largest)
        {
            secondLargest = largest; 
            largest = num;
        }

        // If current element is greter then second large and smaller than largest
        else if (num > secondLargest && num < largest)
        {
            secondLargest = num;
        }
    }

    return secondLargest == numeric_limits<int>::min() ? -1 : secondLargest;
}

int main()
{
    vector<int> arr;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << (i + 1) << " number: ";
        cin >> value;
        arr.push_back(value);
    }

    int result = findSecondLargest(arr);
    if (result == -1)
    {
        cout << "There is no second largest element." << endl;
    }
    else
    {
        cout << "The second largest element is: " << result << endl;
    }

    return 0;
}
