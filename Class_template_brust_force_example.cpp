// Class template example 
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
// Brust force approach
class Array
{
private:
    T *arr;
    int size;

public:
    // Brust force approach
    Array(T a[], int s) : arr(new T[s]), size(s)
    {
        // Use move sementic to avoid copy extra copy
        move(a, a + s, arr);

        // Brust force approach
        // for(size_t i = 0; i < size; i++)
        //     arr[i] = a[i];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        printf("\n");
    }

    ~Array() { delete[] arr; }
};

int main()
{
    // Integer
    int intArr[] = {1, 2, 3};
    Array<int> a1(intArr, 3);
    a1.print();

    // Double
    double doubleArr[] = {1.1, 2.2, 3.3};
    Array<double> a2(doubleArr, 3);
    a2.print();

    // Float
    float floatArr[] = {1.3f, 3.7f, 8.3f};
    Array<float> a3(floatArr, 3);
    a3.print();

    return 0;
}
