#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SortPosAscEvenDsc(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), [](int a, int b)
         {
             // Assending Order
             if (a < 0 && b < 0)
                 return a < b; 
                 
             // Descending order
             if (a >= 0 && b >= 0)
                 return a > b;

             return a < 0; // Negative first
         });
}

int main()
{
    vector<int> vec = {-5, 7, -3, 2, -8, 1, 0, -1};

    SortPosAscEvenDsc(vec);

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }

    return 0;
}
