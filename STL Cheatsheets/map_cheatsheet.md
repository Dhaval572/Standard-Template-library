# 🗺️ C++ STL Map Cheatsheet

*Complete guide to std::map, multimap, unordered_map & unordered_multimap*

## 📦 Includes & Types

```cpp
#include <map>              // map, multimap
#include <unordered_map>    // unordered_map, unordered_multimap
using namespace std;

// 4 Types of Maps
map<string, int> m1;                    // Ordered keys, unique keys
multimap<string, int> m2;               // Ordered keys, duplicate keys allowed
unordered_map<string, int> m3;          // Hash-based, unique keys
unordered_multimap<string, int> m4;     // Hash-based, duplicate keys allowed
```

## 🔍 Map Types Comparison

| Feature | `map` | `multimap` | `unordered_map` | `unordered_multimap` |
|---------|-------|------------|-----------------|---------------------|
| **Key Order** | ✅ Sorted | ✅ Sorted | ❌ No order | ❌ No order |
| **Duplicate Keys** | ❌ Unique only | ✅ Allowed | ❌ Unique only | ✅ Allowed |
| **Access Operator** | ✅ `map[key]` | ❌ No `[]` | ✅ `map[key]` | ❌ No `[]` |
| **Time Complexity** | O(log n) | O(log n) | O(1) avg | O(1) avg |
| **Memory** | Tree-based | Tree-based | Hash table | Hash table |

## 🚀 Creating Maps

### Basic Declaration
```cpp
map<string, int> m1;                           // Empty map
map<string, int> m2 = {{"apple", 5}, {"banana", 3}};  // Initialize with pairs
map<string, int> m3{{"orange", 8}, {"grape", 12}};    // Uniform initialization
map<string, int> m4(m2);                       // Copy constructor
```

### Using make_pair
```cpp
map<string, int> fruits;
fruits.insert(make_pair("apple", 5));
fruits.insert({"banana", 3});                 // C++11 brace initialization
```

### Custom Comparator (Ordered Maps)
```cpp
// Descending order by key
map<string, int, greater<string>> desc_map;
desc_map["zebra"] = 1;
desc_map["apple"] = 2;      // Will be ordered: zebra, apple

// Custom comparator
auto cmp = [](const string& a, const string& b) {
    return a.length() < b.length();  // Sort by string length
};
map<string, int, decltype(cmp)> len_map(cmp);

// Case-insensitive string map
auto case_cmp = [](const string& a, const string& b) {
    return lexicographical_compare(a.begin(), a.end(),
                                 b.begin(), b.end(),
                                 [](char c1, char c2) {
                                     return tolower(c1) < tolower(c2);
                                 });
};
map<string, int, decltype(case_cmp)> ci_map(case_cmp);
```

## 🔧 Basic Operations

### Adding Elements
```cpp
map<string, int> m;

// Method 1: Using [] operator (creates if doesn't exist)
m["apple"] = 5;
m["banana"] = 3;

// Method 2: Using insert
m.insert({"orange", 8});
m.insert(make_pair("grape", 12));
m.insert(pair<string, int>("kiwi", 6));

// Method 3: Using emplace (construct in place)
m.emplace("mango", 7);
m.emplace(make_pair("peach", 4));

// Insert with hint (optimization for ordered insertion)
auto hint = m.end();
m.insert(hint, {"strawberry", 15});

// Insert range
map<string, int> other = {{"lemon", 2}, {"lime", 3}};
m.insert(other.begin(), other.end());
```

### Accessing Elements
```cpp
map<string, int> m = {{"apple", 5}, {"banana", 3}};

// Method 1: [] operator (creates if doesn't exist!)
int apples = m["apple"];        // 5
int oranges = m["orange"];      // 0 (creates new entry!)

// Method 2: at() method (throws if doesn't exist)
try {
    int apples = m.at("apple");     // 5
    int oranges = m.at("orange");   // Throws std::out_of_range
} catch (const out_of_range& e) {
    cout << "Key not found!" << endl;
}

// Method 3: find() method (safe, no creation)
auto it = m.find("apple");
if (it != m.end()) {
    cout << "Found: " << it->second << endl;  // 5
} else {
    cout << "Not found!" << endl;
}
```

## 🔍 Finding & Checking

```cpp
map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};

// Check if key exists
bool exists = m.find("b") != m.end();
bool exists2 = m.count("b") > 0;        // Returns 1 if exists, 0 if not

// Get value with default
int value = m.count("d") ? m["d"] : -1;  // -1 if "d" doesn't exist

// Safe access with default
auto getValue = [&](const string& key, int defaultVal = 0) {
    auto it = m.find(key);
    return it != m.end() ? it->second : defaultVal;
};
int val = getValue("x", 999);  // Returns 999 if "x" not found
```

## 🎯 Bounds & Ranges (Ordered Maps)

```cpp
map<int, string> m = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}};

// Lower bound (first element with key >= given key)
auto lb = m.lower_bound(3);     // Points to {3, "three"}
auto lb2 = m.lower_bound(4);    // Points to {5, "five"}

// Upper bound (first element with key > given key)
auto ub = m.upper_bound(3);     // Points to {5, "five"}
auto ub2 = m.upper_bound(4);    // Points to {5, "five"}

// Equal range
auto range = m.equal_range(3);  // pair of iterators
// range.first == lower_bound(3), range.second == upper_bound(3)

// Range iteration
auto start = m.lower_bound(3);
auto end = m.upper_bound(7);
for (auto it = start; it != end; ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

## ❌ Removing Elements

```cpp
map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}};

// Remove by key
size_t removed = m.erase("b");      // Returns number of elements removed (0 or 1)
if (removed > 0) {
    cout << "Key 'b' was removed" << endl;
}

// Remove by iterator
auto it = m.find("c");
if (it != m.end()) {
    m.erase(it);                    // Remove the element pointed by iterator
}

// Remove range
auto start = m.find("a");
auto end = m.find("d");
m.erase(start, end);                // Removes [start, end) - "a", "b", "c" but not "d"

// Clear all
m.clear();
```

## 🔄 Multimap Specifics

```cpp
multimap<string, int> mm;

// Insert multiple values for same key
mm.insert({"fruit", 1});
mm.insert({"fruit", 2});
mm.insert({"fruit", 3});
mm.insert({"vegetable", 10});

// Count elements with specific key
cout << mm.count("fruit") << endl;      // Output: 3

// Find all values for a key
auto range = mm.equal_range("fruit");
for (auto it = range.first; it != range.second; ++it) {
    cout << it->second << " ";          // Output: 1 2 3
}

// Remove all elements with specific key
mm.erase("fruit");                      // Removes all "fruit" entries

// Remove only first occurrence
auto it = mm.find("vegetable");
if (it != mm.end()) {
    mm.erase(it);                       // Removes only one "vegetable" entry
}
```

## 🔧 Unordered Maps

```cpp
unordered_map<string, int> um = {{"apple", 5}, {"banana", 3}};

// Same basic operations as map
um["orange"] = 8;
um.insert({"grape", 12});
bool found = um.find("apple") != um.end();

// Hash table specific operations
cout << "Bucket count: " << um.bucket_count() << endl;
cout << "Load factor: " << um.load_factor() << endl;
cout << "Max load factor: " << um.max_load_factor() << endl;

// Performance tuning
um.reserve(100);                        // Reserve space for 100 elements
um.rehash(50);                          // Set bucket count to at least 50
um.max_load_factor(0.75);               // Set maximum load factor

// Bucket operations
cout << "Bucket for 'apple': " << um.bucket("apple") << endl;
cout << "Bucket size: " << um.bucket_size(um.bucket("apple")) << endl;
```

## 🔄 Iteration

```cpp
map<string, int> m = {{"apple", 5}, {"banana", 3}, {"cherry", 8}};

// Range-based for loop (C++11) - Preferred
for (const auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}

// Structured bindings (C++17) - Even better!
for (const auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}

// Traditional iterator
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

// Reverse iteration (ordered maps only)
for (auto it = m.rbegin(); it != m.rend(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

// Modify values during iteration
for (auto& [key, value] : m) {
    value *= 2;  // Double all values
}
```

## 📏 Size & Capacity

```cpp
map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};

cout << m.size() << endl;           // 3
cout << m.empty() << endl;          // false (0)
cout << m.max_size() << endl;       // Maximum possible size

// For unordered_map only
unordered_map<string, int> um;
cout << um.bucket_count() << endl;  // Number of buckets
cout << um.load_factor() << endl;   // Current load factor
```

## 🎨 Advanced Examples

### Custom Objects as Keys
```cpp
struct Person {
    string name;
    int age;
    
    // Required for ordered maps (or provide custom comparator)
    bool operator<(const Person& other) const {
        if (name != other.name) return name < other.name;
        return age < other.age;
    }
    
    // Required for unordered maps
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Hash function for unordered_map
struct PersonHash {
    size_t operator()(const Person& p) const {
        return hash<string>{}(p.name) ^ (hash<int>{}(p.age) << 1);
    }
};

// Usage
map<Person, string> person_map;
person_map[{"Alice", 25}] = "Engineer";

unordered_map<Person, string, PersonHash> person_umap;
person_umap[{"Bob", 30}] = "Designer";
```

### Map of Maps (Nested Maps)
```cpp
map<string, map<string, int>> nested_map;

// Add data
nested_map["fruits"]["apple"] = 5;
nested_map["fruits"]["banana"] = 3;
nested_map["vegetables"]["carrot"] = 7;
nested_map["vegetables"]["broccoli"] = 2;

// Access nested data
if (nested_map.count("fruits") && nested_map["fruits"].count("apple")) {
    cout << "Apples: " << nested_map["fruits"]["apple"] << endl;
}

// Iterate through nested map
for (const auto& [category, items] : nested_map) {
    cout << category << ":" << endl;
    for (const auto& [item, count] : items) {
        cout << "  " << item << ": " << count << endl;
    }
}
```

### Frequency Counter
```cpp
vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
map<string, int> frequency;

// Count frequencies
for (const string& word : words) {
    frequency[word]++;  // Creates entry with 0 if doesn't exist, then increments
}

// Alternative using insert
map<string, int> freq2;
for (const string& word : words) {
    auto [it, inserted] = freq2.insert({word, 1});
    if (!inserted) {
        it->second++;
    }
}

// Print sorted by frequency (descending)
vector<pair<string, int>> freq_vec(frequency.begin(), frequency.end());
sort(freq_vec.begin(), freq_vec.end(), 
     [](const auto& a, const auto& b) { return a.second > b.second; });

for (const auto& [word, count] : freq_vec) {
    cout << word << ": " << count << endl;
}
```

## 🔥 Modern C++ Features

### Template Argument Deduction (C++17)
```cpp
// No need to specify template arguments
map m = {make_pair("a", 1), make_pair("b", 2)};  // Deduced as map<const char*, int>
```

### try_emplace (C++17)
```cpp
map<string, int> m;

// Only inserts if key doesn't exist (doesn't overwrite)
auto [it, inserted] = m.try_emplace("apple", 5);
if (inserted) {
    cout << "Inserted apple" << endl;
}

// Won't overwrite existing value
m.try_emplace("apple", 10);  // "apple" still has value 5
```

### insert_or_assign (C++17)
```cpp
map<string, int> m;

// Insert if doesn't exist, assign if exists
auto [it, inserted] = m.insert_or_assign("apple", 5);
if (inserted) {
    cout << "Inserted" << endl;
} else {
    cout << "Assigned" << endl;
}

m.insert_or_assign("apple", 10);  // Now "apple" has value 10
```

### extract() and merge() (C++17)
```cpp
map<string, int> m1 = {{"a", 1}, {"b", 2}};
map<string, int> m2 = {{"c", 3}, {"d", 4}};

// Extract node (doesn't destroy the element)
auto node = m1.extract("a");
if (!node.empty()) {
    node.key() = "A";  // Modify key
    m2.insert(move(node));  // Insert into another map
}

// Merge maps
m1.merge(m2);  // Moves elements from m2 to m1
```

## ⚡ Performance Tips

### Choose the Right Map Type
```cpp
// Use map when:
// - Need sorted order
// - Need range queries
// - Consistent performance required

// Use unordered_map when:
// - Only need key-value lookup
// - Don't care about order
// - Want average O(1) operations
```

### Optimize Access Patterns
```cpp
map<string, int> m;

// Bad: Multiple [] accesses (creates entries)
if (m["key"] > 0) {
    m["key"]++;
}

// Good: Single lookup
auto it = m.find("key");
if (it != m.end() && it->second > 0) {
    it->second++;
}

// Best: Use structured bindings (C++17)
if (auto [it, found] = m.insert({"key", 1}); !found) {
    it->second++;
}
```

### Batch Operations
```cpp
// Bad: Multiple single insertions
map<int, string> m;
for (int i = 0; i < 1000; ++i) {
    m[i] = to_string(i);
}

// Good: Use hint for sequential insertion
map<int, string> m2;
auto hint = m2.end();
for (int i = 0; i < 1000; ++i) {
    hint = m2.emplace_hint(hint, i, to_string(i));
}
```

## 🎯 Common Patterns

### Default Values
```cpp
map<string, vector<int>> groups;

// Add to group (creates vector if doesn't exist)
groups["group1"].push_back(1);
groups["group1"].push_back(2);
groups["group2"].push_back(3);

// Safe access with default
auto getValue = [](const map<string, int>& m, const string& key, int def = 0) {
    auto it = m.find(key);
    return it != m.end() ? it->second : def;
};
```

### Map Inversion
```cpp
map<string, int> original = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
map<int, string> inverted;

for (const auto& [key, value] : original) {
    inverted[value] = key;
}
```

### Top K Elements
```cpp
map<string, int> frequency = {{"a", 5}, {"b", 3}, {"c", 8}, {"d", 1}};

// Get top 2 most frequent
vector<pair<string, int>> vec(frequency.begin(), frequency.end());
partial_sort(vec.begin(), vec.begin() + 2, vec.end(),
            [](const auto& a, const auto& b) { return a.second > b.second; });

for (int i = 0; i < 2; ++i) {
    cout << vec[i].first << ": " << vec[i].second << endl;
}
```

### Group By Pattern
```cpp
vector<pair<string, int>> data = {
    {"apple", 1}, {"banana", 2}, {"apple", 3}, {"cherry", 4}, {"banana", 5}
};

map<string, vector<int>> grouped;
for (const auto& [key, value] : data) {
    grouped[key].push_back(value);
}

// Result: {"apple": [1, 3], "banana": [2, 5], "cherry": [4]}
```

## 💡 Pro Tips

- **Key Type**: Keys must be comparable (for ordered maps) or hashable (for unordered maps)
- **Memory**: Maps store key-value pairs, so consider memory usage for large datasets
- **Iterator Stability**: Iterators remain valid after insertion/deletion (except for the deleted element)
- **Custom Hash**: Always provide hash function for custom types in unordered_map
- **[] vs at()**: Use `[]` for insertion/modification, `at()` for safe access
- **find() vs count()**: Use `find()` when you need the iterator, `count()` for existence check
- **emplace vs insert**: Use `emplace()` to construct objects in-place
- **Multimap Access**: No `[]` operator - use `find()`, `equal_range()`, or iterators

---
*Navigate your data like a pro! 🗺️✨*
