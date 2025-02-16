// More features in templates
// Specialization (Custom Behavior for Specific Type)
#include <iostream>
using namespace std;

// General templates for all data types ( Not for int )
template <typename T>
class Data
{
public:

    void show() { cout << "General Template\n"; }
};

// Special case for int
template <>
class Data<int>
{
public:

    void show() { cout << "Specialized Template for int\n"; }
};

int main()
{
    Data<float> d1;
    d1.show();

    Data<double> d2;
    d2.show(); 

    Data<int> d3;
    d3.show(); 
}
