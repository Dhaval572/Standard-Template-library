// Find the Longest Consecutive Sequence
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    // Store elements in a hash set
    unordered_set<int> numSet(nums.begin(), nums.end());

    int longest = 0;

    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end())
            {
                // Count the sequence length
                currentNum++;
                currentStreak++;
            }

            longest = max(longest, currentStreak); // Update longest sequence length
        }
    }

    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}

/*
Dry Run Table:
+------+--------+---------------+--------------------+----------------+------------------+
| Step | Number | num-1 Exists? | Start of Sequence? | Sequence Found | Longest Updated? |
|----------------------------------------------------------------------------------------|
| 1    | 100    | No            | Yes                | [100]          | No               |
| 2    | 4      | No            | Yes                | [4]            | No               |
| 3    | 200    | No            | Yes                | [200]          | No               |
| 4    | 1      | No            | Yes                | [1, 2, 3, 4]   | Yes (longest = 4)|
| 5    | 3      | Yes (2)       | No                 | -              | No               |
| 6    | 2      | Yes (1)       | No                 | -              | No               |
+------+--------+---------------+--------------------+----------------+------------------+
Final Output: 4
*/
