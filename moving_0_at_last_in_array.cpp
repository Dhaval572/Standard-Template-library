// Moving 0 to last in array
#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int lastNonZeroFoundAt = 0; // Pointer for the last non-zero element

    // Adding elements which is non-zero at front of array
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[lastNonZeroFoundAt] = nums[i];
            lastNonZeroFoundAt++;
        }
    }

    // Fill the remaining elements with zeros
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    // Printing array in which all 0 is at last
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}
