// Find the Longest Consecutive Sequence
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int n : numSet)
    {
        if (numSet.find(n - 1) == numSet.end())
        {
            int length = 1;
            while (numSet.find(n + length) != numSet.end())
            {
                length++;
            }
            longest = max(longest, length);
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
// Find the Longest Consecutive Sequence
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int n : numSet)
    {
        if (numSet.find(n - 1) == numSet.end())
        {
            int length = 1;
            while (numSet.find(n + length) != numSet.end())
            {
                length++;
            }
            longest = max(longest, length);
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

+-----+--------+--------------+-------------------+-------------------+------------------+
| Step| Number | num-1 Exists?| Start of Sequence?|   Sequence Found  |Longest Updated?  |
+-----+--------+--------------+-------------------+-------------------+------------------+
|  1  |  100   |     No       |       Yes         |       [100]       |  No (longest=1)  |
|  2  |   4    |   Yes (3)    |        No         |         -         |        No        |
|  3  |  200   |     No       |       Yes         |       [200]       |  No (longest=1)  |
|  4  |   1    |     No       |       Yes         |  [1, 2, 3, 4]     | Yes (longest=4)  |
|  5  |   3    |   Yes (2)    |        No         |         -         |        No        |
|  6  |   2    |   Yes (1)    |        No         |         -         |        No        |
+-----+--------+--------------+-------------------+-------------------+------------------+

*/

Final Output: 4
*/
