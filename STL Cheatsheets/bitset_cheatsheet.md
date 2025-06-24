# 🧠 `std::bitset` in C++

`std::bitset<N>` is a fixed-size sequence of bits used for efficient storage and manipulation of binary data. It's part of the C++ Standard Library and offers many bit-level operations.

---

## 📌 Key Features

* Stores bits compactly (memory efficient)
* Allows direct manipulation of individual bits
* Supports logical and bitwise operations
* Fast and useful for problems involving binary states or flags

---

## 🚀 Getting Started

### ➤ Include Header

```cpp
#include <bitset>
```

### ➤ Basic Syntax

```cpp
std::bitset<8> bits;            // 8 bits, all initialized to 0
std::bitset<8> bits("10101010"); // initialized with binary string
```

---

## 🔧 Common Methods

| Method         | Description                                | Example                      |
| -------------- | ------------------------------------------ | ---------------------------- |
| `.set()`       | Sets **all** bits to `1`                   | `bits.set();`                |
| `.set(pos)`    | Sets bit at position `pos` to `1`          | `bits.set(2);`               |
| `.reset()`     | Sets **all** bits to `0`                   | `bits.reset();`              |
| `.reset(pos)`  | Sets bit at position `pos` to `0`          | `bits.reset(2);`             |
| `.flip()`      | Toggles **all** bits                       | `bits.flip();`               |
| `.flip(pos)`   | Toggles bit at position `pos`              | `bits.flip(2);`              |
| `.count()`     | Returns number of bits set to `1`          | `bits.count();`              |
| `.any()`       | Returns `true` if **any** bit is `1`       | `bits.any();`                |
| `.none()`      | Returns `true` if **all** bits are `0`     | `bits.none();`               |
| `.all()`       | Returns `true` if **all** bits are `1`     | `bits.all();`                |
| `.size()`      | Returns number of bits (`N`)               | `bits.size();`               |
| `.test(pos)`   | Returns `true` if bit at `pos` is `1`      | `bits.test(3);`              |
| `.to_string()` | Converts the bitset to a `std::string`     | `bits.to_string();`          |
| `.to_ulong()`  | Converts bitset to an `unsigned long`      | `bits.to_ulong();`           |
| `.to_ullong()` | Converts bitset to an `unsigned long long` | `bits.to_ullong();`          |
| `operator[]`   | Access or modify individual bits           | `bits[2] = 1;` or `bits[2];` |

---

## 🧪 Example Code

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> b("10101010");

    cout << "Initial: " << b << endl;

    b.set(0);      // Set bit 0 to 1
    b.reset(1);    // Reset bit 1 to 0
    b.flip(2);     // Flip bit 2

    cout << "Modified: " << b << endl;
    cout << "Count of 1s: " << b.count() << endl;
    cout << "As number: " << b.to_ulong() << endl;

    return 0;
}
```

---

## 📊 Comparison with `vector<bool>`

| Feature           | `std::bitset<N>`      | `std::vector<bool>`        |
| ----------------- | --------------------- | -------------------------- |
| Size              | Fixed at compile-time | Dynamic at runtime         |
| Performance       | Very fast             | Slower in comparison       |
| Memory efficiency | Extremely compact     | Compact (uses bit-packing) |
| Bit operations    | Built-in              | Requires manual logic      |

---

## 💡 Use Cases

* Binary flags and toggles
* Subset generation
* Graph problems (e.g., adjacency matrix)
* Prime number sieve (e.g., Sieve of Eratosthenes)
* Efficient bitmasking in competitive programming

---

## 🧭 Final Thoughts

`std::bitset` is a powerful and efficient tool in C++. It offers compact storage and rich bitwise operations, making it ideal for many performance-critical tasks involving binary logic.

---
