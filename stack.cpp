// About Stack in stl
#include <iostream>
#include <stack>
using namespace std;

// Printing all elements
void printStack(stack<int> st)
{
	cout << "Elements of stack: ";
	// Temporary stack to hold elements while printing
	while (!st.empty())
	{
		cout << st.top() << " "; // Print the top element
		st.pop();				 // Remove the top element
	}
	cout << endl;
}

int main()
{
	stack<int> s1; // Declaration of stack in c++

	s1.push(12);
	s1.push(13);
	s1.push(14);
	s1.push(15);
	s1.push(16);

	cout << "Before pop: " << endl;
	printStack(s1);
	s1.pop();

	cout << "After pop: " << endl;
	printStack(s1);

	cout << "Is stack is empty? " << s1.empty() << endl; // Will return 0

	cout << "Size of stack is: " << s1.size() << endl; // Will return 4

	cout << "Top element: " << s1.top() << endl; // Displaying top element
	return 0;
}
/*
About stack:

	If you have learned the concepts of data structures, then you already know what a stack is.

	So, we will look again at what a stack is:

		Stack is non-primitive linear data structure that follows the LIFO ( Last in first out ) principle.

		This means that the element which was added last to the stack will be removed first.

		If you don't know about stack than you should learn first data structure and algorithm.

	push():

		This function is used to push elements in stack.( Line no. 23 to 27 )

		Syntax:

			stack_name.push(value);

	pop():

		This function is used to pop elements from stack.( Line no. 31 )

		Syntax:

			stack_name.pop();

	empty():

		This function checks that stack is empty or not; if is empty than it will return 1 else it will return 0 ( Line no. 36 )

		Syntax:

			stack_name.empty();

	size():

		This function returns the size of stack.

		Syntax:

			stack_name.size();

	So, this was implimentation of stack using stl lib.

	I hope you understand!!
*/
