// Make template of stack ds
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
	vector<T> data;

public:
	void push(const T &value)
	{
		data.push_back(value);
	}

	void pop()
	{
		if (!data.empty())
		{
			data.pop_back();
		}
	}

	T top() const
	{
		if (!data.empty())
		{
			return data.back();
		}
		throw out_of_range("Stack is empty");
	}

	bool empty() const
	{
		return data.empty();
	}
};

int main()
{
	Stack<int> intStack;
	intStack.push(10);
	intStack.push(20);
	cout << "Top element: " << intStack.top() << endl;
	intStack.pop();
	cout << "Top element after pop: " << intStack.top() << endl;

	Stack<string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	cout << "Top element in string stack: " << stringStack.top() << endl;

	return 0;
}
