# Tips & Tricks for `std::array`

`std::array` is a lightweight container introduced in C++11 that wraps fixed-size C-style arrays with a standardized interface. Here are some tips and tricks to make the most of `std::array`:

---

## 1. Compile-time Size

Because the size is part of the type, you get compile-time guarantees and optimizations:

```cpp
#include <array>

std::array<int, 5> arr;      // Size is fixed at compile time
static_assert(arr.size() == 5, "Must have 5 elements");

---

## 2. Uniform Initialization

Use brace initialization to avoid narrowing conversions and ensure all elements are initialized:

```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
// Or zero-initialize:
std::array<int, 5> zeros{};
```

---

## 3. Automatic `begin()` and `end()`

Provides seamless interoperability with STL algorithms:

```cpp
#include <algorithm>

std::array<int, 5> arr = {5, 3, 1, 4, 2};
std::sort(arr.begin(), arr.end());  // sorts in place
```

---

## 4. Access Safety

- Use `.at()` for bounds-checked access (throws `std::out_of_range`).
- Use `operator[]` for unchecked, faster access.

```cpp
try {
    int val = arr.at(10);  // throws
} catch (const std::out_of_range &e) {
    // handle error
}
```

---

## 5. Structured Bindings (C++17)

Unpack small arrays elegantly:

```cpp
std::array<int, 3> rgb = {255, 128, 64};
auto [r, g, b] = rgb;
```

---

## 6. `fill()` Member Function

Quickly set all elements to the same value:

```cpp
std::array<int, 5> arr;
arr.fill(42);
```

---

## 7. `data()` for Interoperability

Retrieve raw pointer to underlying array for C APIs:

```cpp
int *ptr = arr.data();
```

---

## 8. Comparison Operators

Built-in lexicographical comparisons:

```cpp
std::array<int, 3> a = {1,2,3};
std::array<int, 3> b = {1,2,4};
bool less = (a < b);  // true
```

---

## 9. Compile-time Algorithms (C++20)

Use `constexpr` to manipulate `std::array` at compile time:

```cpp
#include <array>
#include <algorithm>

constexpr std::array<int, 4> make_sorted(std::array<int,4> in) {
    std::sort(in.begin(), in.end());
    return in;
}

static_assert(make_sorted({3,1,4,2}) == std::array<int,4>{1,2,3,4});
```

---

## 10. Avoid Decay to Pointer

Unlike raw arrays, passing by reference keeps the size information:

```cpp
void printArray(const std::array<int,5>& arr) {
    for (auto v : arr) std::cout << v << ' ';
}
```
