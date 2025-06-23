# 🚀 C++ STL Array Cheatsheet

*Complete guide to std::array - fixed-size arrays in C++*

## 📦 Include & Declaration

```cpp
#include <array>
#include <algorithm>  // For algorithms
using namespace std;

array<int, 5> arr;                      // 5 elements, default-initialized (0 for int)
array<int, 5> arr1{};                   // All elements zero-initialized
array<int, 5> arr2{1, 2, 3, 4, 5};     // Initialize with values
array<int, 5> arr3 = {1, 2, 3, 4, 5};  // Initialize with values
array<int, 5> arr4{1, 2};               // {1, 2, 0, 0, 0} - remaining default-initialized
```

## 🎯 Array vs Vector vs C-Array

| Feature | `std::array` | `std::vector` | `C-array` |
|---------|--------------|---------------|-----------|
| **Size** | Fixed at compile-time | Dynamic | Fixed |
| **Memory** | Stack | Heap | Stack |
| **Bounds Check** | `at()` method | `at()` method | None |
| **STL Algorithms** | ✅ Full support | ✅ Full support | ⚠️ Limited |
| **Performance** | Fastest | Slight overhead | Fastest |
| **Size Info** | `size()` method | `size()` method | Manual tracking |
| **Zero Overhead** | ✅ Yes | ❌ No | ✅ Yes |

## 🔧 Creating Arrays

### Basic Creation
```cpp
array<int, 5> arr1;                           // Uninitialized (undefined values)
array<int, 5> arr2{};                         // Zero-initialized
array<int, 5> arr3{1, 2, 3, 4, 5};           // Initialize with values
array<int, 5> arr4 = {1, 2, 3, 4, 5};        // Alternative syntax
array<int, 5> arr5{1, 2};                     // {1, 2, 0, 0, 0}
```

### Template Argument Deduction (C++17)
```cpp
array arr = {1, 2, 3, 4, 5};                 // Deduced as array<int, 5>
array arr2 = {1.5, 2.5, 3.5};                // Deduced as array<double, 3>
```

### Copy and Assignment
```cpp
array<int, 5> arr1 = {1, 2, 3, 4, 5};
array<int, 5> arr2 = arr1;                   // Copy constructor
array<int, 5> arr3;
arr3 = arr1;                                 // Copy assignment
```

### Aggregate Initialization
```cpp
// C++11 style
array<int, 3> arr1{{1, 2, 3}};               // Double braces (safe)
array<int, 3> arr2{1, 2, 3};                 // Single braces (C++11+)

// Multi-dimensional
array<array<int, 3>, 2> matrix = {{
    {{1, 2, 3}},
    {{4, 5, 6}}
}};
```

## 📏 Size Information

### Size Methods
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

cout << arr.size() << endl;                  // 5 (number of elements)
cout << arr.max_size() << endl;              // Same as size() for arrays
cout << arr.empty() << endl;                 // false (only true for size 0)

// Compile-time size
constexpr size_t size = arr.size();          // Can be used in constant expressions
static_assert(arr.size() == 5);              // Compile-time check
```

### Zero-sized Arrays
```cpp
array<int, 0> empty_arr;                     // Valid, but unusual
cout << empty_arr.empty() << endl;           // true
cout << empty_arr.size() << endl;            // 0
// empty_arr.front();                        // Undefined behavior!
// empty_arr.back();                         // Undefined behavior!
```

## 🔍 Accessing Elements

### Safe Access
```cpp
array<int, 5> arr = {10, 20, 30, 40, 50};

// at() - with bounds checking (throws std::out_of_range)
try {
    cout << arr.at(2) << endl;               // 30
    cout << arr.at(10) << endl;              // Throws exception
} catch (const out_of_range& e) {
    cout << "Index out of range!" << endl;
}
```

### Direct Access (No Bounds Check)
```cpp
array<int, 5> arr = {10, 20, 30, 40, 50};

// [] operator - fastest, no bounds check
cout << arr[0] << endl;                      // 10
cout << arr[2] << endl;                      // 30

// front() and back()
cout << arr.front() << endl;                 // 10 (first element)
cout << arr.back() << endl;                  // 50 (last element)

// data() - get pointer to underlying array
int* raw_data = arr.data();
cout << raw_data[0] << endl;                 // 10

// get<N>() - compile-time indexed access
cout << get<0>(arr) << endl;                 // 10
cout << get<2>(arr) << endl;                 // 30
// cout << get<10>(arr) << endl;             // Compile error!
```

### Structured Bindings (C++17)
```cpp
array<int, 3> arr = {1, 2, 3};
auto [a, b, c] = arr;                        // Decompose array
cout << a << " " << b << " " << c << endl;   // 1 2 3

// With references
auto& [x, y, z] = arr;
x = 10;                                      // Modifies arr[0]
```

## 🔄 Modifying Elements

### Fill All Elements
```cpp
array<int, 5> arr;

arr.fill(42);                                // All elements = 42
// arr = {42, 42, 42, 42, 42}
```

### Individual Assignment
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

arr[0] = 10;                                 // Direct assignment
arr.at(1) = 20;                              // Safe assignment
arr.front() = 100;                           // First element
arr.back() = 500;                            // Last element
```

### Swap
```cpp
array<int, 5> arr1 = {1, 2, 3, 4, 5};
array<int, 5> arr2 = {6, 7, 8, 9, 10};

arr1.swap(arr2);                             // Swap contents
// arr1 = {6, 7, 8, 9, 10}, arr2 = {1, 2, 3, 4, 5}

// Or using std::swap
swap(arr1, arr2);                            // Swap back
```

## 🔄 Iteration

### Range-based For Loop (C++11) - Preferred
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

// Read-only iteration
for (const auto& element : arr) {
    cout << element << " ";
}

// Modify elements
for (auto& element : arr) {
    element *= 2;                            // Double each element
}

// With index using enumerate (C++20)
for (auto [i, element] : arr | views::enumerate) {
    cout << "Index " << i << ": " << element << endl;
}
```

### Traditional Loops
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

// Index-based loop
for (size_t i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
}

// Iterator loop
for (auto it = arr.begin(); it != arr.end(); ++it) {
    cout << *it << " ";
}

// Reverse iteration
for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
    cout << *it << " ";                      // Prints: 5 4 3 2 1
}

// C-style loop (compile-time size)
for (int i = 0; i < 5; ++i) {
    cout << arr[i] << " ";
}
```

### Iterators
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

// Forward iterators
auto begin = arr.begin();
auto end = arr.end();
auto cbegin = arr.cbegin();                  // Const iterator
auto cend = arr.cend();                      // Const iterator

// Reverse iterators
auto rbegin = arr.rbegin();
auto rend = arr.rend();
auto crbegin = arr.crbegin();                // Const reverse iterator
auto crend = arr.crend();                    // Const reverse iterator
```

## 🔍 Searching & Finding

### Linear Search
```cpp
array<int, 7> arr = {1, 3, 5, 7, 9, 3, 11};

// Find first occurrence
auto it = find(arr.begin(), arr.end(), 3);
if (it != arr.end()) {
    cout << "Found at index: " << distance(arr.begin(), it) << endl;  // 1
}

// Find with condition
auto it2 = find_if(arr.begin(), arr.end(), 
                   [](int x) { return x > 5; });
if (it2 != arr.end()) {
    cout << "First element > 5: " << *it2 << endl;  // 7
}

// Count occurrences
int count = count(arr.begin(), arr.end(), 3);       // 2
int count_condition = count_if(arr.begin(), arr.end(), 
                              [](int x) { return x % 2 == 0; });
```

### Binary Search (Requires Sorted Array)
```cpp
array<int, 7> arr = {1, 3, 5, 7, 9, 11, 13};

// Check if element exists
bool found = binary_search(arr.begin(), arr.end(), 7);  // true

// Find position for insertion
auto pos = lower_bound(arr.begin(), arr.end(), 6);      // Points to 7
auto pos2 = upper_bound(arr.begin(), arr.end(), 7);     // Points to 9

// Equal range
auto range = equal_range(arr.begin(), arr.end(), 7);
// range.first == lower_bound, range.second == upper_bound
```

## 🔄 Sorting & Algorithms

### Sorting
```cpp
array<int, 6> arr = {5, 2, 8, 1, 9, 3};

// Sort in ascending order
sort(arr.begin(), arr.end());                // {1, 2, 3, 5, 8, 9}

// Sort in descending order
sort(arr.begin(), arr.end(), greater<int>());  // {9, 8, 5, 3, 2, 1}

// Custom comparator
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b);                  // Sort by absolute value
});

// Partial sort (sort only first n elements)
partial_sort(arr.begin(), arr.begin() + 3, arr.end());

// Check if sorted
bool is_sorted_asc = is_sorted(arr.begin(), arr.end());
```

### Other Useful Algorithms
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};

// Reverse
reverse(arr.begin(), arr.end());             // {5, 4, 3, 2, 1}

// Rotate
rotate(arr.begin(), arr.begin() + 2, arr.end()); // Move first 2 to end

// Random shuffle
random_shuffle(arr.begin(), arr.end());      // C++14 and earlier
// shuffle(arr.begin(), arr.end(), rng);     // C++11+ (need random generator)

// Transform
transform(arr.begin(), arr.end(), arr.begin(), 
          [](int x) { return x * x; });     // Square all elements

// Fill
fill(arr.begin(), arr.end(), 42);           // Set all elements to 42

// Generate
generate(arr.begin(), arr.end(), []() { return rand() % 100; });

// Copy
array<int, 5> arr2;
copy(arr.begin(), arr.end(), arr2.begin());
```

## 🔧 Array Operations

### Comparison
```cpp
array<int, 3> arr1 = {1, 2, 3};
array<int, 3> arr2 = {1, 2, 3};
array<int, 3> arr3 = {1, 2, 4};

bool equal = (arr1 == arr2);                // true
bool not_equal = (arr1 != arr3);            // true
bool less_than = (arr1 < arr3);             // true (lexicographic comparison)
bool greater = (arr3 > arr1);               // true
bool less_equal = (arr1 <= arr2);           // true
bool greater_equal = (arr1 >= arr2);        // true
```

### Hash Support
```cpp
array<int, 3> arr = {1, 2, 3};

// Can be used as key in unordered containers
unordered_set<array<int, 3>> set_of_arrays;
set_of_arrays.insert(arr);

unordered_map<array<int, 3>, string> map_with_array_key;
map_with_array_key[arr] = "one-two-three";
```

## 🎨 Advanced Examples

### Multi-dimensional Arrays
```cpp
// 2D array (3x4 matrix)
array<array<int, 4>, 3> matrix = {{
    {{1, 2, 3, 4}},
    {{5, 6, 7, 8}},
    {{9, 10, 11, 12}}
}};

// Access elements
matrix[1][2] = 100;                          // Set element at row 1, col 2

// Alternative initialization
array<array<int, 4>, 3> matrix2;
for (size_t i = 0; i < matrix2.size(); ++i) {
    for (size_t j = 0; j < matrix2[i].size(); ++j) {
        matrix2[i][j] = i * 4 + j + 1;
    }
}

// Iterate through 2D array
for (const auto& row : matrix) {
    for (const auto& element : row) {
        cout << element << " ";
    }
    cout << endl;
}
```

### Arrays of Custom Objects
```cpp
struct Point {
    int x, y;
    Point() : x(0), y(0) {}                  // Default constructor needed
    Point(int x, int y) : x(x), y(y) {}
    
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

array<Point, 3> points = {{
    Point(1, 2),
    Point(3, 4),
    Point(5, 6)
}};

// Sort points
sort(points.begin(), points.end());

// Find point
auto it = find(points.begin(), points.end(), Point(3, 4));
if (it != points.end()) {
    cout << "Point found at index: " << distance(points.begin(), it) << endl;
}
```

### Compile-time Operations
```cpp
// Constexpr array operations
constexpr array<int, 5> make_array() {
    array<int, 5> arr = {};
    // Fill with squares (C++14 relaxed constexpr)
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = i * i;
    }
    return arr;
}

constexpr auto carr = make_array();          // Computed at compile time
static_assert(carr[2] == 4);                // Compile-time check

// Constexpr algorithms (C++20)
constexpr array<int, 5> sorted_array() {
    array<int, 5> arr = {5, 2, 8, 1, 9};
    sort(arr.begin(), arr.end());
    return arr;
}
```

### Arrays as Function Parameters
```cpp
// Pass by reference (preferred)
void process_array(array<int, 5>& arr) {
    for (auto& elem : arr) {
        elem *= 2;
    }
}

// Pass by const reference (read-only)
void print_array(const array<int, 5>& arr) {
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

// Template for different sizes
template<size_t N>
void generic_process(array<int, N>& arr) {
    fill(arr.begin(), arr.end(), 42);
}

// Using auto for deduction (C++20)
void auto_process(auto& arr) {
    static_assert(is_same_v<decay_t<decltype(arr)>, array<int, 5>>);
    // Process array
}
```

## 🔥 Modern C++ Features

### Structured Bindings (C++17)
```cpp
array<int, 3> arr = {1, 2, 3};

// Decompose array
auto [first, second, third] = arr;
cout << first << " " << second << " " << third << endl;  // 1 2 3

// With references for modification
auto& [a, b, c] = arr;
a = 10;  // Modifies arr[0]

// In range-based for with enumerate
for (auto [index, value] : arr | views::enumerate) {
    cout << "arr[" << index << "] = " << value << endl;
}
```

### Template Argument Deduction (C++17)
```cpp
// Compiler deduces type and size
array arr1 = {1, 2, 3, 4, 5};               // array<int, 5>
array arr2 = {1.5, 2.5, 3.5};               // array<double, 3>
array arr3 = {"hello", "world"};             // array<const char*, 2>

// Deduction guides work with various initialization forms
array arr4{1, 2, 3};                        // array<int, 3>
```

### constexpr Everything (C++11/14/17/20)
```cpp
// constexpr array creation
constexpr array<int, 5> fibonacci = {1, 1, 2, 3, 5};

// constexpr operations
constexpr int sum = accumulate(fibonacci.begin(), fibonacci.end(), 0);
static_assert(sum == 12);

// constexpr sorting (C++20)
constexpr array<int, 5> sorted = []() {
    array<int, 5> arr = {5, 2, 8, 1, 9};
    sort(arr.begin(), arr.end());
    return arr;
}();
```

### to_array Helper (C++20)
```cpp
// Convert C-array to std::array
int c_array[] = {1, 2, 3, 4, 5};
auto std_array = to_array(c_array);          // array<int, 5>

// Create array from initializer list
auto arr = to_array({1, 2, 3, 4, 5});       // array<int, 5>

// Works with move-only types
auto arr_strings = to_array<string>({"hello", "world"});
```

## ⚡ Performance Tips

### Stack Allocation
```cpp
// Arrays are stack-allocated - very fast
array<int, 1000> fast_array;                // Stack allocation
vector<int> slow_vector(1000);              // Heap allocation

// No dynamic memory management overhead
auto start = high_resolution_clock::now();
for (int i = 0; i < 1000000; ++i) {
    fast_array[i % 1000] = i;               // Direct memory access
}
auto end = high_resolution_clock::now();
```

### Cache Locality
```cpp
// Excellent cache locality due to contiguous memory
array<int, 1000> arr;
iota(arr.begin(), arr.end(), 1);

// Sum using cache-friendly iteration
int sum = 0;
for (const auto& value : arr) {             // Sequential access
    sum += value;
}
```

### Compile-time Optimizations
```cpp
// Size known at compile time enables optimizations
template<size_t N>
constexpr int sum_array(const array<int, N>& arr) {
    int sum = 0;
    for (size_t i = 0; i < N; ++i) {        // Loop can be unrolled
        sum += arr[i];
    }
    return sum;
}

// Compiler can optimize based on known size
constexpr array<int, 4> small_arr = {1, 2, 3, 4};
constexpr int result = sum_array(small_arr);  // Computed at compile time
```

## 🎯 Common Patterns

### Buffer/Window Operations
```cpp
// Sliding window with fixed size
template<typename T, size_t N>
class SlidingWindow {
private:
    array<T, N> buffer;
    size_t index = 0;
    size_t count = 0;
    
public:
    void push(const T& value) {
        buffer[index] = value;
        index = (index + 1) % N;
        if (count < N) ++count;
    }
    
    T average() const {
        return accumulate(buffer.begin(), buffer.begin() + count, T{}) / count;
    }
};

SlidingWindow<double, 10> window;
```

### State Machines
```cpp
enum class State { IDLE, RUNNING, PAUSED, STOPPED };

array<State, 4> state_transitions = {
    State::RUNNING,  // From IDLE
    State::PAUSED,   // From RUNNING  
    State::RUNNING,  // From PAUSED
    State::IDLE      // From STOPPED
};

State current_state = State::IDLE;
current_state = state_transitions[static_cast<int>(current_state)];
```

### Lookup Tables
```cpp
// Precomputed lookup table
constexpr array<int, 256> square_table = []() {
    array<int, 256> table{};
    for (size_t i = 0; i < table.size(); ++i) {
        table[i] = i * i;
    }
    return table;
}();

// Fast square lookup for small values
int fast_square(int x) {
    return (x >= 0 && x < 256) ? square_table[x] : x * x;
}
```

### Ring Buffers
```cpp
template<typename T, size_t N>
class RingBuffer {
private:
    array<T, N> buffer;
    size_t head = 0;
    size_t tail = 0;
    bool full = false;
    
public:
    void push(const T& item) {
        buffer[head] = item;
        head = (head + 1) % N;
        
        if (full) {
            tail = (tail + 1) % N;
        }
        full = (head == tail);
    }
    
    bool pop(T& item) {
        if (empty()) return false;
        
        item = buffer[tail];
        tail = (tail + 1) % N;
        full = false;
        return true;
    }
    
    bool empty() const {
        return (!full && (head == tail));
    }
};
```

## 💡 Pro Tips

- **Performance**: Arrays have zero overhead compared to C arrays
- **Size**: Size must be known at compile time - use `vector` for dynamic sizing
- **Initialization**: Always initialize arrays to avoid undefined behavior
- **Bounds**: Use `at()` for debug builds, `[]` for release builds
- **Iteration**: Range-based for loops are preferred and optimized
- **Comparisons**: Arrays support all comparison operators lexicographically
- **Templates**: Use template parameters for generic array functions
- **constexpr**: Arrays work great with compile-time computations
- **Memory**: Stack-allocated, so be careful with very large arrays
- **Structured Bindings**: Great for small, fixed-size arrays

## 🚨 Common Pitfalls

```cpp
// ❌ Don't do this - undefined behavior
array<int, 5> arr;                          // Uninitialized!
cout << arr[0] << endl;                     // Undefined behavior

// ✅ Do this instead
array<int, 5> arr{};                        // Zero-initialized
cout << arr[0] << endl;                     // 0

// ❌ Don't use very large arrays on stack
array<int, 10000000> huge_arr;              // May cause stack overflow!

// ✅ Use vector for large collections
vector<int> large_vec(10000000);            // Heap allocated

// ❌ Don't assume array decay
void func(int* ptr) { /* ... */ }
array<int, 5> arr = {1, 2, 3, 4, 5};
func(arr);                                  // Compile error!

// ✅ Use data() for C-style functions
func(arr.data());                           // OK

// ❌ Don't compare arrays of different sizes
array<int, 3> arr1 = {1, 2, 3};
array<int, 4> arr2 = {1, 2, 3, 4};
// bool equal = (arr1 == arr2);             // Compile error!

// ✅ Arrays must have same type and size for comparison
array<int, 3> arr3 = {1, 2, 3};
bool equal = (arr1 == arr3);                // OK
```

## 🔄 Migration from C Arrays

```cpp
// C-style array
int c_array[5] = {1, 2, 3, 4, 5};
int size = sizeof(c_array) / sizeof(c_array[0]);  // Manual size calculation

// std::array equivalent
array<int, 5> std_array = {1, 2, 3, 4, 5};
auto size = std_array.size();               // Built-in size method

// Function parameter (C-style - decays to pointer)
void func_c(int arr[]) {                    // Actually int* arr
    // sizeof(arr) == sizeof(int*) - wrong!
}

// Function parameter (std::array - preserves size)
void func_std(const array<int, 5>& arr) {
    cout << arr.size() << endl;             // Always 5
}

// Converting C array to std::array (C++20)
int c_arr[] = {1, 2, 3, 4, 5};
auto std_arr = to_array(c_arr);             // array<int, 5>
```

---
*Array mastery achieved! 🚀✨*
