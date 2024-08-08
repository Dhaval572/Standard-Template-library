// Creating linked list in c++ using standard template library
#include <iostream>
#include <list>
using namespace std;

void display(list<int> &lst) // for Display list
{
	list<int>::iterator it; // Creating iterater named it
	for (it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << " ";
	}
}

int main()
{
	list<int> list1; // Declaration of list
	int element, size;
	cout << "Enter the size of your list: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter (" << i + 1 << ") element: ";
		cin >> element;
		list1.push_back(element); // adding element in list
	}
	cout << "Element of list is: ";
	display(list1);
	return 0;
}

/*note:

Syntex to declare list using stl:
list<data_type> list_name;

-> if you want to create linked list using stl then you should have to include 'list' library (#inclue <list>)
-> iterator is special object which points to the element of linked list,vector etc
-> begin() points first element of list
-> end() points last element of list

for more information visit this website:
cplusplus.com
*/
