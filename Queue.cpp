// Queue implimentation using stl lib
#include <iostream>
#include <queue>
using namespace std;

// prints all elements of queue
void printQueue(queue<int> q1)
{
	cout << "Elements of queue: ";

	while (!q1.empty())
	{
		cout << q1.front() << ' '; // Print the front element
		q1.pop();				   // Remove the front element
	}

	cout << endl;
}

int main()
{
	queue<int> q1;

	q1.push(27);
	q1.push(28);
	q1.push(29);
	q1.push(30);

	cout << "Before dequeue: " << endl;
	printQueue(q1);

	q1.pop();

	cout << "After dequeue: " << endl;
	printQueue(q1);

	cout << "The size of queue is: " << q1.size() << endl; // Will return 3
	cout << "Is Queue is empty? " << q1.empty() << endl;   // Will return 0 means false
	cout << "Front element is: " << q1.front() << endl;    // Will return front element

	return 0;
}
/*
About queue:

	If you have learned the concepts of data structures, then you already know what a queue is.

	So, we will look again at what a queue is:

		Queue is a non-primitive linear data structure that follows the FIFO (First In, First Out) principle.

		This means that the element which was added first to the queue will be removed first.

		If you don't know about queue than you should learn first data structure and algorithm.

	push():

		This function is used to enqueue(push) elements in queue.( Line no. 24 to 27 )

		Syntax: 

			queue_name.push(value);

	pop():

		This function is used to dequeue(pop) elements from queue.( Line no. 32 )

		Syntax:

			queue_name.pop();

	size():

		This function returns the size of queue. ( Line no. 37 )

		Syntax: 

			queue_name.size(); 

	empty():

		This function checks that queue is empty or not; if is empty than it will return 1 else it will return 0 ( Line no. 38 )

		Syntax: 

			queue_name.empty();

	front():

		Returns the value of front element. ( Line no. 39 )

		Syntax:

			queue_name.front();

	So, this was implimentation of queue using stl lib.

	I hope you understand!!
*/
