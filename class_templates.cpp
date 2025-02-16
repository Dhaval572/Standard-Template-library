// Class templates
#include <iostream>
using namespace std;

// Template of class
template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    void show() { cout << "Value: " << value << endl; }
};

int main()
{
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);
    Box<char> charBox('c');

    intBox.show();    
    doubleBox.show(); 
    charBox.show();

    return 0;
}
