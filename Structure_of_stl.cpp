/*
Basic structure of c++ stl

	Components of stl:

		1. Containers:

			Containers are used to store collections of objects.
			They are the core structure of STL.

			There are a three types of containers:

				1. Sequence containers

					Store elements in linear order.
					Example: vector, deque, list, array

				2. Associative containers

					store elements in a sorted order based on keys
					Example: set, multiset, map, multimap

				3. Unordered containers

					store elements in an unordered way
					Example: unordered_set, unordered_multiset, unordered_map, unordered_multimap

		2. Iterators:

			Iterators are used to traverse elements in containers.

			In shortly, An iterator is like a pointer that points to elements in containers.

		3. Algorithms:

			STL provides generic algorithms that work with any container.

			Types of algorithms:

				1. sorting
				2. searching
				3. manipulation
				4. modification
				5. Searching and replacing
	
		4. Functors( Function object ):

			Function object is a function that is converted into object.

			STL algorithms often use function objects as customizable behaviors.

		5. Allocaters:

			Allocators manage memory allocation and deallocation for containers.

			Example: std::allocator<T>

		

	So, this was main components of standard template library.
*/	
