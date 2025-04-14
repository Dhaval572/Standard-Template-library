// Arrange the array in given way
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void veryEfficientArrang(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), [](int a, int b)
         {
             if (((a & 1) == 0) && ((b & 1) == 0))
                 return a < b;                      // even numbers ascending
             if (((a & 1) == 1) && ((b & 1) == 1))
                 return a > b;                      // odd numbers descending
             return (a & 1) == 0;                   // evens first
         });
}

// Optimized trick (Space complexity O(1))
void sortEvenAscOddDescOptimized(vector<int> &arr)
{
    auto it = partition(arr.begin(), arr.end(), [](int x)
                        { return (x & 1) == 0; });

    // Sort evens ascending
    sort(arr.begin(), it);

    // Sort odds descending
    sort(it, arr.end(), greater<int>());
}

// Normal trick (Space complexity O(n))
void sortEvenAscOddDesc(vector<int> &arr)
{
    vector<int> evenVec, oddVec;

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] & 1)
            oddVec.push_back(arr[i]);
        else
            evenVec.push_back(arr[i]);
    }

    sort(evenVec.begin(), evenVec.end());               // Sort evens ascending
    sort(oddVec.begin(), oddVec.end(), greater<int>()); // Sort odds descending

    arr.clear();
    arr.insert(arr.end(), evenVec.begin(), evenVec.end());
    arr.insert(arr.end(), oddVec.begin(), oddVec.end());
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 6, 4};

    // sortEvenAscOddDesc(arr);
    // sortEvenAscOddDescOptimized(arr);
    veryEfficientArrang(arr);

    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
