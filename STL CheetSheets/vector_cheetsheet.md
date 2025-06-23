**# C++ `std::vector` Cheat Sheet**

A comprehensive guide from fundamentals to advanced usage of `std::vector` in C++.

---

## 📦 1. Introduction

* **Header**: `#include <vector>`
* **Namespace**: `std::vector`
* **Definition**: Dynamic array that manages contiguous storage.

---

## 🛠 2. Declaration & Initialization

```cpp
// Empty vector of ints
std::vector<int> v1;

// With size and optional default value
std::vector<int> v2(5);           // size = 5, all elements = 0
std::vector<int> v3(5, 42);       // size = 5, all elements = 42

// From initializer list
std::vector<int> v4 = {1, 2, 3, 4};
std::vector<std::string> v5 {"a","b","c"};

// From another container or range
std::vector<int> v6(v4.begin(), v4.end());
std::vector<int> v7 = v4;
```

---

## 🔍 3. Element Access

| Method      | Returns        | Bounds-checked? |
| ----------- | -------------- | --------------- |
| `v[i]`      | Reference      | No              |
| `v.at(i)`   | Reference      | Yes (throws)    |
| `v.front()` | Reference      | No              |
| `v.back()`  | Reference      | No              |
| `v.data()`  | Pointer to raw | No              |

```cpp
int x = v4[2];         // OK
int y = v4.at(2);      // Throws out_of_range if invalid
v4.front() = 10;
std::cout << v4.back();
int* raw = v4.data();
```

---

## 🔧 4. Capacity & Size

```cpp
v1.size();         // number of elements
v1.capacity();     // allocated storage
v1.empty();        // true if size()==0
v1.max_size();     // theoretical max elements

v1.reserve(n);     // allocate capacity >= n
v1.resize(n);      // change size to n (value-init new elements)
v1.shrink_to_fit(); // request to reduce capacity to size
```

---

## ✏️ 5. Modifiers

```cpp
v.push_back(x);                 // append
v.emplace_back(args...);        // in-place construct at end
v.insert(pos, x);               // insert element
v.insert(pos, n, x);            // insert n copies
v.emplace(pos, args...);        // in-place insert
v.erase(pos);                   // remove at pos
v.erase(first, last);           // remove range
v.pop_back();                   // remove last
v.clear();                      // remove all
v.swap(other_vector);           // swap contents
```

**Notes**:

* `emplace` avoids unnecessary copies.
* Insertion/erasure in middle → linear time.

---

## 🔄 6. Iterators & Loops

```cpp
for (auto it = v.begin(); it != v.end(); ++it) { /* *it */ }
for (auto& x : v) { /* x */ }
for (size_t i = 0; i < v.size(); ++i) { /* v[i] */ }

// Reverse iterate
for (auto it = v.rbegin(); it != v.rend(); ++it) { }
```

---

## ⚡ 7. Algorithms Integration

```cpp
#include <algorithm>

std::sort(v.begin(), v.end());
auto it = std::find(v.begin(), v.end(), value);
std::reverse(v.begin(), v.end());
v.erase(std::remove(v.begin(), v.end(), x), v.end());  // remove-erase idiom
```

---

## 📊 8. Performance & Complexity

| Operation               | Complexity |
| ----------------------- | ---------- |
| `v[i]`, `v.at(i)`       | O(1)       |
| `push_back` (amortized) | O(1)       |
| `pop_back`              | O(1)       |
| `front`, `back`         | O(1)       |
| `insert/erase` at end   | O(1)\*     |
| `insert/erase` middle   | O(n)       |
| `reserve`               | O(n)       |
| `resize`                | O(n)       |
| `shrink_to_fit`         | O(n)       |

*\* might invalidate iterators when reallocating*

---

## 🚀 9. Advanced Topics

### 9.1 Move Semantics & Swap

```cpp
std::vector<std::string> a = {/*...*/};
std::vector<std::string> b = std::move(a); // steals storage

std::swap(a, b); // constant-time swap of internals
```

### 9.2 Custom Allocators

```cpp
template <typename T>
using MyVec = std::vector<T, MyAllocator<T>>;
```

### 9.3 `vector<bool>` Specialization

* Optimized bit-packing → not a real container of `bool`s.
* Use `std::bitset` or `vector<char>` if you need direct bool references.

### 9.4 Memory Layout

* Elements are contiguous → pointer arithmetic, interop with C arrays.

### 9.5 Thread Safety

* Concurrent reads ✔
* Mutating operations ✖ (unless externally synchronized)

### 9.6 Emplace vs Insert

* `emplace` constructs in-place; `insert` copies/moves an existing object.

---

## 🎯 10. Best Practices

* **Prefer `reserve()`** when size is known to avoid reallocations.
* **Use `emplace_back`** for constructing in-place.
* **Avoid mixing** iterator invalidation pitfalls.
* **Leverage algorithms** (`<algorithm>`) with iterators.
* **Document** when capacity changes may be costly.

---

*End of Cheat Sheet – Happy Coding!*
