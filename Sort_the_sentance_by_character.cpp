// Sort all character of given sentance
#include <iostream>
#include <map>
using namespace std;

int main() 
{
    string text = "KJIHGFEDBCA";
    map<char, int> frequency;

    for (char ch : text) 
    {
        frequency[ch]++;
    }

    for (auto& pair : frequency) 
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
