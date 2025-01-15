// Use of map in recursion

// ( Note: Here, map is used to store previously computed Fibonacci values, making the recursive algorithm efficient by avoiding redundant calls. )

#include <iostream>
#include <map>
using namespace std;

map<int, long long> memorization;
long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    // Check if result is already computed
    if (memorization.find(n) != memorization.end())
        return memorization[n];

    // Calculate and store the result in the map
    memorization[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memorization[n];
}

int main()
{
    int n = 50; // Calculate Fibonacci of 50
    cout << "Fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}
