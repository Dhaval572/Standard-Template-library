# 🚀 C++ STL Vector Cheatsheet

*Complete guide to std::vector - dynamic arrays in C++*

## 📦 Include & Declaration

```cpp
#include <vector>
#include <algorithm>  // For algorithms
using namespace std;

vector<int> v;              // Empty vector
vector<int> v1(10);         // 10 elements, default-initialized (0 for int)
vector<int> v2(10, 5);      // 10 elements, all set to 5
vector<int> v3 = {1, 2, 3, 4, 5};  // Initialize with values
vector<int> v4{1, 2, 3, 4, 5};     // Uniform initialization (C++11)
vector<int> v5(v3);         // Copy constructor
```

## 🎯 Vector vs Array

| Feature | `vector` | `array` | `C-array` |
|---------|----------|---------|-----------|
| **Size** | Dynamic | Fixed | Fixed |
| **Memory** | Heap | Stack/Heap | Stack |
| **Bounds Check** | `at()` method | `at()` method | None |
| **STL Algorithms** | ✅ Full support | ✅ Full support | ⚠️ Limited |
| **Performance** | Slight overhead | Fastest | Fastest |

## 🔧 Creating Vectors

### Basic Creation
```cpp
vector<int> v1;                           // Empty
vector<int> v2(5);                        // Size 5, values = 0
vector<int> v3(5, 10);                    // Size 5, all values = 10
vector<int> v4 = {1, 2, 3, 4, 5};        // Initializer list
vector<int> v5{1, 2, 3, 4, 5};           // Uniform initialization
```

### From Other Containers
```cpp
// From another vector
vector<int> original = {1, 2, 3, 4, 5};
vector<int> copy(original);               // Copy constructor
vector<int> copy2 = original;             // Copy assignment

// From iterators (range constructor)
vector<int> v(original.begin() + 1, original.end() - 1);  // {2, 3, 4}

// From array
int arr[] = {1, 2, 3, 4, 5};
vector<int> v_from_array(arr, arr + 5);

// From string
string s = "hello";
vector<char> v_from_string(s.begin(), s.end());
```

### Template Argument Deduction (C++17)
```cpp
vector v = {1, 2, 3, 4, 5};              // Deduced as vector<int>
vector v2 = {1.5, 2.5, 3.5};             // Deduced as vector<double>
```

## ➕ Adding Elements

### At the End
```cpp
vector<int> v;

// push_back - add single element
v.push_back(10);
v.push_back(20);
v.push_back(30);          // v = {10, 20, 30}

// emplace_back - construct in place (C++11)
v.emplace_back(40);       // Slightly more efficient for complex types

// For custom objects
vector<pair<int, string>> pairs;
pairs.push_back({1, "one"});              // Creates temporary pair
pairs.emplace_back(2, "two");             // Constructs directly in vector
```

### At Specific Position
```cpp
vector<int> v = {1, 2, 4, 5};

// insert single element
v.insert(v.begin() + 2, 3);               // v = {1, 2, 3, 4, 5}

// insert multiple copies
v.insert(v.begin(), 3, 0);                // Insert three 0's at beginning

// insert range
vector<int> other = {10, 11, 12};
v.insert(v.end(), other.begin(), other.end()); // Append other vector

// insert from initializer list (C++11)
v.insert(v.begin() + 1, {100, 101, 102});

// emplace at position (C++11)
v.emplace(v.begin() + 2, 999);
```

## 🔍 Accessing Elements

### Safe Access
```cpp
vector<int> v = {10, 20, 30, 40, 50};

// at() - with bounds checking (throws std::out_of_range)
try {
    cout << v.at(2) << endl;              // 30
    cout << v.at(10) << endl;             // Throws exception
} catch (const out_of_range& e) {
    cout << "Index out of range!" << endl;
}
```

### Direct Access (No Bounds Check)
```cpp
vector<int> v = {10, 20, 30, 40, 50};

// [] operator - fastest, no bounds check
cout << v[0] << endl;                     // 10
cout << v[2] << endl;                     // 30

// front() and back()
cout << v.front() << endl;                // 10 (first element)
cout << v.back() << endl;                 // 50 (last element)

// data() - get pointer to underlying array
int* raw_data = v.data();
cout << raw_data[0] << endl;              // 10
```

### Checking Before Access
```cpp
vector<int> v;

if (!v.empty()) {
    cout << v.front() << endl;            // Safe access to first element
}

if (v.size() > 2) {
    cout << v[2] << endl;                 // Safe indexed access
}
```

## ❌ Removing Elements

### From the End
```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.pop_back();                             // Remove last element
// v = {1, 2, 3, 4}
```

### From Specific Position
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// erase single element
v.erase(v.begin() + 2);                   // Remove element at index 2
// v = {1, 2, 4, 5}

// erase range
v.erase(v.begin() + 1, v.begin() + 3);   // Remove elements [1, 3)
// v = {1, 5}

// erase all elements
v.clear();                                // v = {}
```

### Remove by Value
```cpp
vector<int> v = {1, 2, 3, 2, 4, 2, 5};

// Remove all occurrences of value 2
v.erase(remove(v.begin(), v.end(), 2), v.end());
// v = {1, 3, 4, 5}

// Remove elements satisfying condition
v.erase(remove_if(v.begin(), v.end(), 
                 [](int x) { return x % 2 == 0; }), v.end());
// Removes all even numbers
```

## 📏 Size & Capacity

### Size Information
```cpp
vector<int> v = {1, 2, 3, 4, 5};

cout << v.size() << endl;                 // 5 (number of elements)
cout << v.empty() << endl;                // false (0)
cout << v.max_size() << endl;             // Maximum possible size
```

### Capacity Management
```cpp
vector<int> v;

cout << v.capacity() << endl;             // Current capacity (may be 0)

// Reserve space (optimization)
v.reserve(100);                           // Reserve space for 100 elements
cout << v.capacity() << endl;             // At least 100

// Resize vector
v.resize(10);                             // Resize to 10 elements (default value)
v.resize(15, 42);                         // Resize to 15, new elements = 42

// Shrink capacity to fit size
v.shrink_to_fit();                        // Reduce capacity to current size
```

## 🔄 Iteration

### Range-based For Loop (C++11) - Preferred
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Read-only iteration
for (const auto& element : v) {
    cout << element << " ";
}

// Modify elements
for (auto& element : v) {
    element *= 2;                         // Double each element
}

// With index (C++20)
for (auto [i, element] : v | views::enumerate) {
    cout << "Index " << i << ": " << element << endl;
}
```

### Traditional Loops
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Index-based loop
for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}

// Iterator loop
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// Reverse iteration
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " ";                   // Prints: 5 4 3 2 1
}
```

### Structured Bindings with enumerate (C++20)
```cpp
vector<string> names = {"Alice", "Bob", "Charlie"};

for (auto [index, name] : names | views::enumerate) {
    cout << index << ": " << name << endl;
}
```

## 🔍 Searching & Finding

### Linear Search
```cpp
vector<int> v = {1, 3, 5, 7, 9, 3, 11};

// Find first occurrence
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) {
    cout << "Found at index: " << distance(v.begin(), it) << endl;  // 1
}

// Find with condition
auto it2 = find_if(v.begin(), v.end(), 
                   [](int x) { return x > 5; });
if (it2 != v.end()) {
    cout << "First element > 5: " << *it2 << endl;  // 7
}

// Count occurrences
int count = count(v.begin(), v.end(), 3);          // 2
int count_condition = count_if(v.begin(), v.end(), 
                              [](int x) { return x % 2 == 0; });
```

### Binary Search (Requires Sorted Vector)
```cpp
vector<int> v = {1, 3, 5, 7, 9, 11, 13};

// Check if element exists
bool found = binary_search(v.begin(), v.end(), 7);  // true

// Find position for insertion
auto pos = lower_bound(v.begin(), v.end(), 6);     // Points to 7
auto pos2 = upper_bound(v.begin(), v.end(), 7);    // Points to 9

// Equal range
auto range = equal_range(v.begin(), v.end(), 7);
// range.first == lower_bound, range.second == upper_bound
```

## 🔄 Sorting & Algorithms

### Sorting
```cpp
vector<int> v = {5, 2, 8, 1, 9, 3};

// Sort in ascending order
sort(v.begin(), v.end());                 // {1, 2, 3, 5, 8, 9}

// Sort in descending order
sort(v.begin(), v.end(), greater<int>());  // {9, 8, 5, 3, 2, 1}

// Custom comparator
sort(v.begin(), v.end(), [](int a, int b) {
    return abs(a) < abs(b);               // Sort by absolute value
});

// Partial sort (sort only first n elements)
partial_sort(v.begin(), v.begin() + 3, v.end());

// Check if sorted
bool is_sorted_asc = is_sorted(v.begin(), v.end());
```

### Other Useful Algorithms
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Reverse
reverse(v.begin(), v.end());              // {5, 4, 3, 2, 1}

// Rotate
rotate(v.begin(), v.begin() + 2, v.end()); // Move first 2 to end

// Random shuffle
random_shuffle(v.begin(), v.end());       // C++14 and earlier
// shuffle(v.begin(), v.end(), rng);      // C++11+ (need random generator)

// Transform
transform(v.begin(), v.end(), v.begin(), 
          [](int x) { return x * x; });   // Square all elements

// Fill
fill(v.begin(), v.end(), 42);             // Set all elements to 42

// Generate
generate(v.begin(), v.end(), []() { return rand() % 100; });
```

## 🔧 Vector Operations

### Comparison
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {1, 2, 3};
vector<int> v3 = {1, 2, 4};

bool equal = (v1 == v2);                  // true
bool not_equal = (v1 != v3);              // true
bool less_than = (v1 < v3);               // true (lexicographic comparison)
```

### Swapping
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6, 7, 8};

v1.swap(v2);                              // Fast swap (O(1))
// v1 = {4, 5, 6, 7, 8}, v2 = {1, 2, 3}

// Or using std::swap
swap(v1, v2);                             // Swap back
```

## 🎨 Advanced Examples

### 2D Vector (Vector of Vectors)
```cpp
// Create 2D vector
vector<vector<int>> matrix(3, vector<int>(4, 0));  // 3x4 matrix filled with 0

// Initialize with values
vector<vector<int>> matrix2 = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Access elements
matrix2[1][2] = 100;                      // Set element at row 1, col 2

// Add row
matrix2.push_back({13, 14, 15, 16});

// Iterate through 2D vector
for (const auto& row : matrix2) {
    for (const auto& element : row) {
        cout << element << " ";
    }
    cout << endl;
}
```

### Custom Objects in Vector
```cpp
struct Person {
    string name;
    int age;
    
    Person(const string& n, int a) : name(n), age(a) {}
    
    // For sorting
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

vector<Person> people;

// Add people
people.push_back(Person("Alice", 25));
people.emplace_back("Bob", 30);           // More efficient - constructs in place
people.emplace_back("Charlie", 20);

// Sort by age
sort(people.begin(), people.end());

// Sort by name
sort(people.begin(), people.end(), 
     [](const Person& a, const Person& b) {
         return a.name < b.name;
     });
```

### Vector as Stack
```cpp
vector<int> stack;

// Push
stack.push_back(10);
stack.push_back(20);
stack.push_back(30);

// Pop
while (!stack.empty()) {
    cout << stack.back() << " ";          // Top element
    stack.pop_back();                     // Remove top
}
// Output: 30 20 10
```

### Vector as Queue (Not Recommended - Use deque)
```cpp
vector<int> queue;

// Enqueue (inefficient for large vectors)
queue.push_back(10);
queue.push_back(20);
queue.push_back(30);

// Dequeue (very inefficient - O(n))
while (!queue.empty()) {
    cout << queue.front() << " ";         // Front element
    queue.erase(queue.begin());           // Remove front (expensive!)
}
```

## 🔥 Modern C++ Features

### Initializer Lists (C++11)
```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.assign({10, 20, 30});                   // Replace contents
v.insert(v.begin(), {100, 101, 102});     // Insert multiple elements
```

### Move Semantics (C++11)
```cpp
vector<int> create_vector() {
    vector<int> v = {1, 2, 3, 4, 5};
    return v;                             // Automatic move (RVO)
}

vector<int> v1 = create_vector();         // Move constructor
vector<int> v2 = move(v1);                // Explicit move (v1 becomes empty)
```

### emplace Operations (C++11)
```cpp
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

vector<Point> points;

// Less efficient - creates temporary object
points.push_back(Point(1, 2));

// More efficient - constructs directly in vector
points.emplace_back(3, 4);
```

## ⚡ Performance Tips

### Memory Management
```cpp
vector<int> v;

// Bad: Repeated reallocations
for (int i = 0; i < 1000; ++i) {
    v.push_back(i);                       // May cause multiple reallocations
}

// Good: Reserve space first
vector<int> v2;
v2.reserve(1000);                         // Allocate space once
for (int i = 0; i < 1000; ++i) {
    v2.push_back(i);                      // No reallocations
}

// Even better: Use constructor
vector<int> v3(1000);                     // Direct allocation
iota(v3.begin(), v3.end(), 0);            // Fill with 0, 1, 2, ..., 999
```

### Avoiding Copies
```cpp
// Bad: Unnecessary copy
vector<string> process_vector(vector<string> v) {  // Copy parameter
    // Process v
    return v;                             // Copy return
}

// Good: Use references and move
vector<string> process_vector(vector<string>&& v) {  // Move parameter
    // Process v
    return move(v);                       // Move return
}

// Best: Process in-place when possible
void process_vector_inplace(vector<string>& v) {
    // Process v directly
}
```

### Iterator Invalidation
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Bad: Iterator invalidated after insert/erase
auto it = v.begin() + 2;
v.push_back(6);                           // May invalidate 'it'
cout << *it << endl;                      // Undefined behavior!

// Good: Update iterator or use indices
size_t index = 2;
v.push_back(6);
cout << v[index] << endl;                 // Safe
```

## 🎯 Common Patterns

### Remove Duplicates
```cpp
vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 5};

// Method 1: Sort then unique
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// v = {1, 2, 3, 4, 5}

// Method 2: Using set (preserves order of first occurrence)
vector<int> v2 = {1, 2, 2, 3, 3, 3, 4, 4, 5};
set<int> seen;
v2.erase(remove_if(v2.begin(), v2.end(),
                  [&seen](int x) { return !seen.insert(x).second; }),
         v2.end());
```

### Partition Vector
```cpp
vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Partition into even and odd
auto partition_point = partition(v.begin(), v.end(), 
                                [](int x) { return x % 2 == 0; });

cout << "Even numbers: ";
for (auto it = v.begin(); it != partition_point; ++it) {
    cout << *it << " ";
}

cout << "\nOdd numbers: ";
for (auto it = partition_point; it != v.end(); ++it) {
    cout << *it << " ";
}
```

### Top K Elements
```cpp
vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

// Get top 3 largest elements
partial_sort(v.begin(), v.begin() + 3, v.end(), greater<int>());
vector<int> top3(v.begin(), v.begin() + 3);
// top3 = {9, 6, 5}

// Alternative: using nth_element
vector<int> v2 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
nth_element(v2.begin(), v2.begin() + 3, v2.end(), greater<int>());
// Elements before v2.begin() + 3 are >= v2[3]
```

## 💡 Pro Tips

- **Performance**: `vector` is usually the best container choice due to cache locality
- **Memory**: `reserve()` before adding many elements to avoid reallocations
- **Access**: Use `[]` for performance, `at()` for safety
- **Iteration**: Prefer range-based for loops over index-based loops
- **Removal**: Use erase-remove idiom for removing elements by value
- **Size**: Use `empty()` instead of `size() == 0`
- **Move**: Use move semantics for expensive-to-copy objects
- **Capacity**: `shrink_to_fit()` is not guaranteed to reduce capacity
- **Iterator Safety**: Be aware of iterator invalidation after modifications

## 🚨 Common Pitfalls

```cpp
// ❌ Don't do this
vector<int> v;
for (size_t i = 0; i < v.size() - 1; ++i) {  // Underflow if empty!
    // ...
}

// ✅ Do this instead
if (v.size() > 1) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
        // ...
    }
}

// ❌ Don't modify vector during iteration
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it == 0) {
        v.erase(it);  // Iterator invalidated!
    }
}

// ✅ Use erase-remove idiom
v.erase(remove(v.begin(), v.end(), 0), v.end());
```

---
*Vector mastery achieved! 🚀✨*
