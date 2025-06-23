# 🎯 C++ STL Set Cheatsheet

*Complete guide to std::set, multiset, unordered_set & unordered_multiset*

## 📦 Includes & Types

```cpp
#include <set>              // set, multiset
#include <unordered_set>    // unordered_set, unordered_multiset
using namespace std;

// 4 Types of Sets
set<int> s1;                    // Ordered, unique elements
multiset<int> s2;               // Ordered, duplicate elements allowed
unordered_set<int> s3;          // Hash-based, unique elements
unordered_multiset<int> s4;     // Hash-based, duplicate elements allowed
```

## 🔍 Set Types Comparison

| Feature | `set` | `multiset` | `unordered_set` | `unordered_multiset` |
|---------|-------|------------|-----------------|---------------------|
| **Order** | ✅ Sorted | ✅ Sorted | ❌ No order | ❌ No order |
| **Duplicates** | ❌ Unique only | ✅ Allowed | ❌ Unique only | ✅ Allowed |
| **Time Complexity** | O(log n) | O(log n) | O(1) avg | O(1) avg |
| **Memory** | Tree-based | Tree-based | Hash table | Hash table |

## 🚀 Creating Sets

### Basic Declaration
```cpp
set<int> s1;                        // Empty set
set<int> s2 = {1, 2, 3, 4, 5};      // Initialize with values
set<int> s3{10, 20, 30};            // Uniform initialization
set<int> s4(s2);                    // Copy constructor
```

### Custom Comparator (Ordered Sets)
```cpp
// Descending order
set<int, greater<int>> desc_set = {1, 2, 3}; // {3, 2, 1}

// Custom comparator
auto cmp = [](int a, int b) { return a > b; };
set<int, decltype(cmp)> custom_set(cmp);

// For strings by length
auto len_cmp = [](const string& a, const string& b) {
    return a.length() < b.length();
};
set<string, decltype(len_cmp)> str_set(len_cmp);
```

### From Range
```cpp
vector<int> vec = {1, 2, 3, 2, 1};
set<int> s(vec.begin(), vec.end());     // {1, 2, 3} - duplicates removed
```

## ➕ Adding Elements

```cpp
set<int> s;

// Insert single element
s.insert(10);               // Returns pair<iterator, bool>
s.insert(20);
s.insert(10);               // Won't insert duplicate

// Insert with hint (optimization)
auto it = s.insert(s.end(), 30);

// Insert range
vector<int> vec = {40, 50, 60};
s.insert(vec.begin(), vec.end());

// Emplace (construct in place)
s.emplace(70);

// Check if insertion succeeded
auto result = s.insert(80);
if (result.second) {
    cout << "Inserted successfully at position " 
         << distance(s.begin(), result.first) << endl;
}
```

## 🔍 Finding Elements

```cpp
set<int> s = {1, 2, 3, 4, 5};

// Find element
auto it = s.find(3);
if (it != s.end()) {
    cout << "Found: " << *it << endl;
} else {
    cout << "Not found" << endl;
}

// Count occurrences (0 or 1 for set, 0+ for multiset)
int count = s.count(3);     // 1 if exists, 0 if not

// Check if element exists
bool exists = s.count(3) > 0;
// or
bool exists2 = s.find(3) != s.end();
```

## 🎯 Bounds & Ranges

```cpp
set<int> s = {1, 3, 5, 7, 9};

// Lower bound (first element >= value)
auto lb = s.lower_bound(5);     // Points to 5
auto lb2 = s.lower_bound(4);    // Points to 5 (first >= 4)

// Upper bound (first element > value)
auto ub = s.upper_bound(5);     // Points to 7
auto ub2 = s.upper_bound(4);    // Points to 5 (first > 4)

// Equal range (range of elements equal to value)
auto range = s.equal_range(5);  // pair of iterators
// range.first == lower_bound(5)
// range.second == upper_bound(5)

// Find range of values
auto start = s.lower_bound(3);
auto end = s.upper_bound(7);
for (auto it = start; it != end; ++it) {
    cout << *it << " ";         // Prints: 3 5 7
}
```

## ❌ Removing Elements

```cpp
set<int> s = {1, 2, 3, 4, 5};

// Remove by value
s.erase(3);                     // Removes 3, returns count of removed elements

// Remove by iterator
auto it = s.find(4);
if (it != s.end()) {
    s.erase(it);                // Removes 4
}

// Remove range
auto start = s.find(2);
auto end = s.find(5);
s.erase(start, end);            // Removes [2, 5) - so removes 2

// Clear all
s.clear();
```

## 🔄 Multiset Specifics

```cpp
multiset<int> ms = {1, 2, 2, 3, 3, 3, 4};

// Count specific element
cout << ms.count(3) << endl;    // Output: 3

// Remove all occurrences of a value
ms.erase(3);                    // Removes all 3's
cout << ms.count(3) << endl;    // Output: 0

// Remove only one occurrence
auto it = ms.find(2);
if (it != ms.end()) {
    ms.erase(it);               // Removes only one 2
}

// Equal range for multiset
auto range = ms.equal_range(2);
cout << "Count of 2: " << distance(range.first, range.second) << endl;
```

## 🔧 Unordered Sets

```cpp
unordered_set<int> us = {1, 2, 3, 4, 5};

// Same operations as set, but no ordering
us.insert(6);
us.erase(3);
bool found = us.find(4) != us.end();

// Hash table specific operations
cout << "Bucket count: " << us.bucket_count() << endl;
cout << "Load factor: " << us.load_factor() << endl;
cout << "Max load factor: " << us.max_load_factor() << endl;

// Rehash
us.reserve(100);                // Reserve space for 100 elements
us.rehash(50);                  // Set bucket count to at least 50
```

## 📊 Set Operations

```cpp
set<int> s1 = {1, 2, 3, 4};
set<int> s2 = {3, 4, 5, 6};
set<int> result;

// Union (merge two sets)
set_union(s1.begin(), s1.end(),
          s2.begin(), s2.end(),
          inserter(result, result.begin()));
// result: {1, 2, 3, 4, 5, 6}

result.clear();

// Intersection (common elements)
set_intersection(s1.begin(), s1.end(),
                s2.begin(), s2.end(),
                inserter(result, result.begin()));
// result: {3, 4}

result.clear();

// Difference (s1 - s2)
set_difference(s1.begin(), s1.end(),
               s2.begin(), s2.end(),
               inserter(result, result.begin()));
// result: {1, 2}

result.clear();

// Symmetric difference (elements in either but not both)
set_symmetric_difference(s1.begin(), s1.end(),
                        s2.begin(), s2.end(),
                        inserter(result, result.begin()));
// result: {1, 2, 5, 6}
```

## 🔄 Iteration

```cpp
set<int> s = {1, 2, 3, 4, 5};

// Range-based for loop (C++11)
for (const auto& elem : s) {
    cout << elem << " ";
}

// Traditional iterator
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}

// Reverse iteration
for (auto it = s.rbegin(); it != s.rend(); ++it) {
    cout << *it << " ";         // Prints: 5 4 3 2 1
}

// C++20 ranges (if available)
// for (auto elem : s | views::reverse) {
//     cout << elem << " ";
// }
```

## 📏 Size & Capacity

```cpp
set<int> s = {1, 2, 3};

cout << s.size() << endl;       // 3
cout << s.empty() << endl;      // false (0)
cout << s.max_size() << endl;   // Maximum possible size

// For unordered_set only
unordered_set<int> us;
cout << us.bucket_count() << endl;
cout << us.load_factor() << endl;
```

## 🎨 Advanced Examples

### Custom Objects in Set
```cpp
struct Person {
    string name;
    int age;
    
    // Required for set (or provide custom comparator)
    bool operator<(const Person& other) const {
        return age < other.age;  // Sort by age
    }
};

set<Person> people;
people.insert({"Alice", 25});
people.insert({"Bob", 30});
people.insert({"Charlie", 20});

for (const auto& person : people) {
    cout << person.name << " (" << person.age << ")" << endl;
}
// Output: Charlie (20), Alice (25), Bob (30)
```

### Using Sets for Algorithms
```cpp
// Remove duplicates from vector
vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
set<int> unique_set(vec.begin(), vec.end());
vec.assign(unique_set.begin(), unique_set.end());
// vec is now {1, 2, 3, 4}

// Check if two ranges have common elements
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {3, 4, 5};
set<int> s1(v1.begin(), v1.end());
bool has_common = any_of(v2.begin(), v2.end(), 
                        [&s1](int x) { return s1.count(x) > 0; });
```

### Set as Dictionary Keys
```cpp
map<set<int>, string> setMap;
setMap[{1, 2, 3}] = "First set";
setMap[{4, 5, 6}] = "Second set";

// Access
set<int> key = {1, 2, 3};
if (setMap.find(key) != setMap.end()) {
    cout << setMap[key] << endl;  // "First set"
}
```

## 🔥 Modern C++ Features

### Structured Bindings (C++17)
```cpp
set<int> s = {1, 2, 3};
auto [it, inserted] = s.insert(4);
if (inserted) {
    cout << "Inserted " << *it << endl;
}
```

### Template Argument Deduction (C++17)
```cpp
// No need to specify template argument
set s = {1, 2, 3, 4, 5};  // Deduced as set<int>
```

### Init with Custom Comparator (C++11)
```cpp
auto cmp = [](int a, int b) { return a > b; };
set<int, decltype(cmp)> desc_set({1, 2, 3}, cmp);
```

## ⚡ Performance Tips

### Choose the Right Set Type
```cpp
// Use set when:
// - Need sorted order
// - Need range queries
// - Deterministic iteration order required

// Use unordered_set when:
// - Only need existence checking
// - Don't care about order
// - Want average O(1) operations
```

### Optimize Insertions
```cpp
set<int> s;

// Bad: Multiple single insertions
for (int x : {1, 2, 3, 4, 5}) {
    s.insert(x);
}

// Good: Batch insertion
vector<int> vec = {1, 2, 3, 4, 5};
s.insert(vec.begin(), vec.end());
```

### Use Hints for Ordered Insertion
```cpp
set<int> s;
auto hint = s.end();
for (int i = 1; i <= 100; ++i) {
    hint = s.insert(hint, i);  // O(1) amortized when inserting in order
}
```

## 🎯 Common Patterns

### Find Closest Element
```cpp
set<int> s = {1, 5, 10, 15, 20};
int target = 7;

auto it = s.lower_bound(target);
int closest = *it;  // 10 (first >= 7)

// Find truly closest (could be smaller)
if (it != s.begin()) {
    auto prev = prev(it);
    if (abs(*prev - target) < abs(*it - target)) {
        closest = *prev;  // 5 is closer to 7 than 10
    }
}
```

### Set Union in Place
```cpp
set<int> s1 = {1, 2, 3};
set<int> s2 = {3, 4, 5};

// Merge s2 into s1
s1.insert(s2.begin(), s2.end());
// s1 is now {1, 2, 3, 4, 5}
```

### Convert Between Set Types
```cpp
set<int> ordered = {3, 1, 4, 1, 5};
unordered_set<int> unordered(ordered.begin(), ordered.end());
```

## 💡 Pro Tips

- **Memory**: Sets use more memory than vectors due to tree/hash overhead
- **Cache**: Ordered sets have better cache locality than unordered sets
- **Iteration**: Never modify elements during iteration (undefined behavior)
- **Custom Hash**: For unordered_set with custom types, provide hash function
- **Comparator**: For ordered sets with custom types, provide comparison function
- **Performance**: Use `count()` instead of `find() != end()` for existence check
- **Multiset**: Use `equal_range()` to get all elements with same value

---
*Master the sets! 🎉*
