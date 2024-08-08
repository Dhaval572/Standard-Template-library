// About template
#include <iostream>
using namespace std;

template <class T>
T Product(T a, T b) // T used as data type template
{
	return a * b;
}

int main()
{
	int a, b;
	float x, y;
	double p, q;
	cout << "Enter two numbers(integer): ";
	cin >> a >> b;
	cout << "Enter two numbers(float): ";
	cin >> x >> y;
	cout << "Enter two numbers(double): ";
	cin >> p >> q;
	cout << "Product of int: " << Product(a, b) << endl;
	cout << "Product of float: " << Product(x, y) << endl;
	cout << "Product of double: " << Product(p, q) << endl;
	return 0;
}

/*

Syntax:

template<class template_name> (Note: You can use typename instead of class in templates)

Use of templates:

1. Write functions that can operate on any data type it means you don't need to create different functions for each data type.

Example:
int Product(int a, int b);
float Product(float a, float b);
double Product(double a, double b);

2. This is also use in class(user defined data type)

3. Avoid multiple versions of the same function for different types

*/
