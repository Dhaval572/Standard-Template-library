// Find the length of longest substring
#include <iostream>
#include <vector>
using namespace std;

int solution(string s)
{
    vector<int> dict(256, -1);
    int maxLength = 0, start = -1;
    
    for(int i = 0; i < s.size(); i++)
    {
        // If character was seen before and is within the current substring, update start
        if(dict[s[i]] > start)
            start = dict[s[i]];

        // Update the last seen index of the current character
        dict[s[i]] = i;

        // Update maxLength with the current substring length
        maxLength = max(maxLength, i - start);
    }

    return maxLength;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Length of longest substring is: " << solution(s) << endl;

    return 0;
}
