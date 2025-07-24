# 🚀 Ultimate C++ STL Containers Cheatsheet

*Master the Standard Template Library with this comprehensive reference guide*

---

## 📋 Table of Contents
- [🔸 Sequence Containers](#-sequence-containers)
- [🔹 Associative Containers](#-associative-containers-ordered)
- [🔸 Unordered Containers](#-unordered-associative-containers-hash-based)
- [🔹 Container Adaptors](#-container-adaptors)
- [⚡ Performance Comparison](#-performance-comparison-matrix)
- [🎯 Selection Guide](#-container-selection-guide)
- [🛠️ Advanced Features](#️-advanced-features--best-practices)
- [📚 Code Examples](#-essential-code-examples)

---

## 🔸 Sequence Containers

### `std::vector<T>`
**Dynamic contiguous array - The workhorse of STL**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Random access (`[]`, `at()`) | **O(1)** | Cache-friendly, bounds checking with `at()` |
| Push/Pop back | **O(1) amortized** | Automatic reallocation when needed |
| Insert/Erase middle | **O(n)** | Requires element shifting |
| Size/Capacity | **O(1)** | `size()` vs `capacity()` distinction |

**✅ Best for:** Random access, cache performance, frequent back operations  
**❌ Avoid when:** Frequent middle insertions/deletions needed

---

### `std::deque<T>`
**Double-ended queue with chunked memory**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Random access (`[]`, `at()`) | **O(1)** | Slightly slower than vector |
| Push/Pop front/back | **O(1)** | No reallocation of existing elements |
| Insert/Erase middle | **O(n)** | Better than vector for large objects |
| Iterator stability | **Partial** | Valid until insertion/deletion |

**✅ Best for:** Frequent operations at both ends, when vector reallocation is costly  
**❌ Avoid when:** Maximum cache performance needed

---

### `std::list<T>`
**Doubly-linked list for flexible insertion/deletion**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Access | **O(n)** | No random access, only sequential |
| Insert/Erase anywhere | **O(1)** | With valid iterator position |
| Splice operations | **O(1)** | Move elements between lists |
| Sort | **O(n log n)** | Stable merge sort implementation |

**✅ Best for:** Frequent insertions/deletions, iterator stability  
**❌ Avoid when:** Random access or cache performance critical

---

### `std::forward_list<T>`
**Singly-linked list - minimal memory overhead**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Access | **O(n)** | Forward iteration only |
| Insert after | **O(1)** | `insert_after()`, `emplace_after()` |
| Erase after | **O(1)** | `erase_after()` |
| Memory | **Minimal** | Smallest node size among linked containers |

**✅ Best for:** Memory-constrained environments, forward-only traversal  
**❌ Avoid when:** Bidirectional access needed

---

### `std::array<T, N>`
**Fixed-size array wrapper**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| All operations | **Same as C array** | Zero overhead abstraction |
| Size | **Compile-time constant** | Template parameter |
| Bounds checking | **O(1)** | With `at()` method |

**✅ Best for:** Fixed-size data, C compatibility, stack allocation  
**❌ Avoid when:** Dynamic sizing needed

---

## 🔹 Associative Containers (Ordered)

### `std::set<T>` / `std::multiset<T>`
**Self-balancing binary search tree (Red-Black Tree)**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Search (`find`, `count`) | **O(log n)** | Logarithmic in all cases |
| Insert/Erase | **O(log n)** | Automatic rebalancing |
| Iteration | **O(n)** | Always in sorted order |
| Range queries | **O(log n + k)** | k = number of elements in range |

**Key Differences:**
- `set`: Unique elements only
- `multiset`: Allows duplicate elements

**✅ Best for:** Maintaining sorted unique/duplicate elements, range queries  
**❌ Avoid when:** Frequent random access needed, hash performance acceptable

---

### `std::map<K,V>` / `std::multimap<K,V>`
**Key-value pairs with ordered keys**

| Operation | Complexity | Notes |
|-----------|------------|-------|
| Access (`[]`, `at()`) | **O(log n)** | `[]` creates if not exists (map only) |
| Search (`find`) | **O(log n)** | Returns iterator |
| Insert/Erase | **O(log n)** | Maintains key ordering |
| Lower/Upper bound | **O(log n)** | Efficient range operations |

**Key Differences:**
- `map`: Unique keys, `operator[]` available
- `multimap`: Multiple values per key, no `operator[]`

**✅ Best for:** Key-value relationships, ordered iteration by key  
**❌ Avoid when:** Hash table performance sufficient, key ordering not needed

---

## 🔸 Unordered Associative Containers (Hash-Based)

### `std::unordered_set<T>` / `std::unordered_multiset<T>`
**Hash table implementation**

| Operation | Average | Worst Case | Notes |
|-----------|---------|------------|-------|
| Search/Insert/Erase | **O(1)** | **O(n)** | Depends on hash quality |
| Rehashing | **O(n)** | **O(n)** | Automatic load factor management |
| Bucket operations | **O(1)** | **O(bucket_size)** | `bucket_count()`, `load_factor()` |

**Hash Requirements:**
- `std::hash<T>` specialization or custom hasher
- Equality comparison (`operator==`)

**✅ Best for:** Fast lookups, insertions when order not important  
**❌ Avoid when:** Ordered iteration required, worst-case guarantees needed

---

### `std::unordered_map<K,V>` / `std::unordered_multimap<K,V>`
**Hash table for key-value pairs**

| Operation | Average | Worst Case | Notes |
|-----------|---------|------------|-------|
| Access (`[]`, `at()`) | **O(1)** | **O(n)** | `[]` available for unordered_map only |
| Search (`find`) | **O(1)** | **O(n)** | Hash-based lookup |
| Insert/Erase | **O(1)** | **O(n)** | May trigger rehashing |

**Load Factor Management:**
- Default max load factor: 1.0
- Automatic rehashing when exceeded
- Manual control via `rehash()`, `reserve()`

**✅ Best for:** Fast key-value lookups, cache implementations  
**❌ Avoid when:** Memory usage critical, ordered key iteration needed

---

## 🔹 Container Adaptors

### `std::stack<T, Container>`
**LIFO (Last In, First Out) adapter**

| Operation | Complexity | Default Container |
|-----------|------------|-------------------|
| `push()`, `pop()` | **O(1)** | `std::deque` |
| `top()` | **O(1)** | Access top element |
| `empty()`, `size()` | **O(1)** | Status queries |

**Underlying Container Options:** `vector`, `deque`, `list`

---

### `std::queue<T, Container>`
**FIFO (First In, First Out) adapter**

| Operation | Complexity | Default Container |
|-----------|------------|-------------------|
| `push()`, `pop()` | **O(1)** | `std::deque` |
| `front()`, `back()` | **O(1)** | Access front/back elements |
| `empty()`, `size()` | **O(1)** | Status queries |

**Underlying Container Options:** `deque`, `list`

---

### `std::priority_queue<T, Container, Compare>`
**Heap-based priority queue**

| Operation | Complexity | Default Container |
|-----------|------------|-------------------|
| `push()` | **O(log n)** | `std::vector` |
| `pop()` | **O(log n)** | Remove top element |
| `top()` | **O(1)** | Access highest priority |

**Default Behavior:** Max-heap (largest element on top)  
**Custom Comparator:** Use `std::greater<T>` for min-heap

---

## ⚡ Performance Comparison Matrix

| Container | Random Access | Insert Front | Insert Back | Insert Middle | Search | Memory Overhead |
|-----------|---------------|--------------|-------------|---------------|--------|-----------------|
| `vector` | ⭐⭐⭐⭐⭐ | ❌ | ⭐⭐⭐⭐⭐ | ⭐ | ⭐ | ⭐⭐⭐⭐⭐ |
| `deque` | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐ | ⭐ | ⭐⭐⭐⭐ |
| `list` | ❌ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐ | ⭐⭐⭐ |
| `set` | ❌ | ⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ |
| `unordered_set` | ❌ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐ |

---

## 🎯 Container Selection Guide

### **Use `vector` when:**
- Random access to elements needed
- Cache performance is critical
- Primarily adding/removing from the end
- Memory efficiency is important

### **Use `deque` when:**
- Need fast insertion/removal at both ends
- Random access required but some overhead acceptable
- Avoiding iterator invalidation on growth

### **Use `list` when:**
- Frequent insertion/deletion in the middle
- Iterator stability is crucial
- No random access needed

### **Use `set`/`map` when:**
- Elements must be sorted
- Logarithmic performance is acceptable
- Range queries are common

### **Use `unordered_set`/`unordered_map` when:**
- Fastest possible lookup/insertion
- Order doesn't matter
- Good hash function available

### **Use container adaptors when:**
- Need specific access patterns (LIFO, FIFO, priority)
- Want to restrict interface of underlying container

---

## 🛠️ Advanced Features & Best Practices

### **Iterator Categories**
```cpp
// Random Access: vector, deque, array
// Bidirectional: list, set, map
// Forward: forward_list, unordered_*
// Input/Output: specialized iterators
```

### **Custom Comparators**
```cpp
// For ordered containers
std::set<int, std::greater<int>> desc_set;
auto cmp = [](int a, int b) { return a > b; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
```

### **Custom Hash Functions**
```cpp
struct CustomHash {
    std::size_t operator()(const MyType& obj) const {
        return std::hash<std::string>{}(obj.key);
    }
};
std::unordered_set<MyType, CustomHash> my_set;
```

### **Memory Management**
- **Capacity vs Size:** `vector` and `deque` distinguish between allocated space and used elements
- **Reserve:** Use `reserve()` to avoid reallocations when final size is known
- **Shrink to fit:** Use `shrink_to_fit()` to release unused capacity

### **Exception Safety**
- STL containers provide strong exception safety guarantees
- `push_back()` and `emplace_back()` are exception-safe
- Move semantics reduce copy overhead and exception risk

---

## 📚 Essential Code Examples

### **Vector Operations**
```cpp
std::vector<int> v{1, 2, 3};
v.reserve(100);              // Avoid reallocations
v.emplace_back(4);          // Construct in place
v.insert(v.begin() + 1, 10); // Insert at position
```

### **Map Usage**
```cpp
std::map<std::string, int> m;
m["key"] = 42;              // Insert or update
auto it = m.find("key");    // Safe lookup
if (it != m.end()) {
    std::cout << it->second;
}
```

### **Unordered Map with Custom Hash**
```cpp
std::unordered_map<std::string, int> um;
um.reserve(1000);           // Optimize for known size
um.max_load_factor(0.75);   // Control rehashing
```

### **Algorithm Integration**
```cpp
std::vector<int> v{3, 1, 4, 1, 5};
std::sort(v.begin(), v.end());
auto pos = std::lower_bound(v.begin(), v.end(), 3);
```

---

## 📊 Container Properties Reference

| Container | Header | Ordered | Duplicates | Random Access | Iterators | Thread Safety |
|-----------|--------|---------|------------|---------------|-----------|---------------|
| `vector` | `<vector>` | ❌ | ✅ | ✅ | Random Access | Read-only safe |
| `deque` | `<deque>` | ❌ | ✅ | ✅ | Random Access | Read-only safe |
| `list` | `<list>` | ❌ | ✅ | ❌ | Bidirectional | Read-only safe |
| `forward_list` | `<forward_list>` | ❌ | ✅ | ❌ | Forward | Read-only safe |
| `array` | `<array>` | ❌ | ✅ | ✅ | Random Access | Read-only safe |
| `set` | `<set>` | ✅ | ❌ | ❌ | Bidirectional | Read-only safe |
| `multiset` | `<set>` | ✅ | ✅ | ❌ | Bidirectional | Read-only safe |
| `map` | `<map>` | ✅ | ❌ | ❌ | Bidirectional | Read-only safe |
| `multimap` | `<map>` | ✅ | ✅ | ❌ | Bidirectional | Read-only safe |
| `unordered_set` | `<unordered_set>` | ❌ | ❌ | ❌ | Forward | Read-only safe |
| `unordered_multiset` | `<unordered_set>` | ❌ | ✅ | ❌ | Forward | Read-only safe |
| `unordered_map` | `<unordered_map>` | ❌ | ❌ | ❌ | Forward | Read-only safe |
| `unordered_multimap` | `<unordered_map>` | ❌ | ✅ | ❌ | Forward | Read-only safe |

---

## 🎓 Key Takeaways

1. **Default Choice:** `std::vector` for most use cases
2. **Performance:** Profile before optimizing container choice
3. **Algorithms:** STL containers work seamlessly with `<algorithm>`
4. **Modern C++:** Prefer `emplace` over `insert`, use range-based for loops
5. **Exception Safety:** STL provides strong guarantees, leverage RAII
6. **Memory:** Understand capacity vs size, use `reserve()` when appropriate

---

> **💡 Pro Tip:** The STL is designed for composability. Combine containers with algorithms, iterators, and function objects to write expressive, efficient C++ code.

### 🚀 *Master these containers and unlock the full power of Modern C++!*
