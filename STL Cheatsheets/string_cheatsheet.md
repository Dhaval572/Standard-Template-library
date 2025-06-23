# 🚀 C++ STL String Cheatsheet

*Quick reference for std::string operations*

## 📦 Include & Declaration

```cpp
#include <string>
using namespace std;

string str;           // Empty string
string str = "Hello"; // Initialize with text
string str("Hello");  // Constructor syntax
```

## 🔧 Basic Operations

### Creating Strings
```cpp
string s1;                    // Empty: ""
string s2 = "Hello";          // From literal
string s3("World");           // Constructor
string s4(5, 'A');            // Repeat char: "AAAAA"
string s5 = s2;               // Copy
```

### Getting Info
```cpp
s.length()     // Length of string
s.size()       // Same as length()
s.empty()      // true if empty
s.capacity()   // Current capacity
```

## 🎯 Accessing Characters

```cpp
string s = "Hello";

s[0]           // 'H' (no bounds check)
s.at(0)        // 'H' (with bounds check)
s.front()      // 'H' (first character)
s.back()       // 'o' (last character)
```

## ➕ Adding Content

### Append (Add to End)
```cpp
s += " World";           // Append string
s += '!';                // Append character
s.append(" More");       // Append method
s.push_back('.');        // Add single character
```

### Insert (Add at Position)
```cpp
s.insert(5, " there");   // Insert at position 5
s.insert(0, "Hi ");      // Insert at beginning
```

## ✂️ Removing Content

```cpp
s.pop_back();            // Remove last character
s.erase(5, 3);           // Remove 3 chars starting at pos 5
s.erase(5);              // Remove everything from pos 5 onwards
s.clear();               // Remove everything
```

## 🔍 Finding & Searching

```cpp
string s = "Hello World Hello";

s.find("World")          // Returns position (6) or string::npos
s.find('o')              // Find first 'o' (position 4)
s.find("lo", 3)          // Find "lo" starting from position 3
s.rfind("Hello")         // Find last occurrence of "Hello"
s.find_first_of("aeiou") // Find first vowel
s.find_last_of("aeiou")  // Find last vowel
```

### Check if Found
```cpp
if (s.find("World") != string::npos) {
    // Found!
}
```

## ✏️ Modifying

### Replace
```cpp
s.replace(6, 5, "Universe");  // Replace 5 chars at pos 6
```

### Substring
```cpp
s.substr(0, 5)           // Get first 5 characters
s.substr(6)              // Get from position 6 to end
s.substr(6, 5)           // Get 5 chars starting at pos 6
```

## 🔄 Comparing

```cpp
string a = "apple";
string b = "banana";

a == b              // Equal?
a != b              // Not equal?
a < b               // Lexicographically less?
a.compare(b)        // Returns: <0, 0, or >0
```

## 🔀 Useful Algorithms

### Transform Case
```cpp
#include <algorithm>
#include <cctype>

// To uppercase
transform(s.begin(), s.end(), s.begin(), ::toupper);

// To lowercase  
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

### Reverse
```cpp
#include <algorithm>
reverse(s.begin(), s.end());
```

### Sort
```cpp
#include <algorithm>
sort(s.begin(), s.end());
```

## 🎨 String Streams

```cpp
#include <sstream>

// Convert to string
int num = 42;
string s = to_string(num);

// Parse from string
string s = "123";
int num = stoi(s);        // string to int
double d = stod(s);       // string to double

// String stream
stringstream ss;
ss << "Number: " << 42;
string result = ss.str();
```

## 🔧 Common Patterns

### Check if Empty
```cpp
if (s.empty()) { /* handle empty string */ }
```

### Iterate Through String
```cpp
// Method 1: Range-based for
for (char c : s) {
    cout << c << " ";
}

// Method 2: Traditional for
for (size_t i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}

// Method 3: Iterators
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

### Split String (Manual)
```cpp
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
```

### Remove Whitespace
```cpp
#include <algorithm>

// Remove leading whitespace
s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
    return !isspace(ch);
}));

// Remove trailing whitespace
s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
    return !isspace(ch);
}).base(), s.end());
```

## ⚡ Quick Examples

```cpp
// Example 1: Count vowels
int countVowels(const string& s) {
    int count = 0;
    for (char c : s) {
        if (string("aeiouAEIOU").find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Example 2: Check palindrome
bool isPalindrome(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

// Example 3: Replace all occurrences
void replaceAll(string& s, const string& from, const string& to) {
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != string::npos) {
        s.replace(pos, from.length(), to);
        pos += to.length();
    }
}
```

## 💡 Pro Tips

- Use `string::npos` to check if something wasn't found
- `at()` throws exception for invalid index, `[]` doesn't
- String concatenation with `+` creates new string, `+=` modifies existing
- Use `reserve()` if you know final size to avoid reallocations
- C-style strings: use `.c_str()` to get `const char*`

## 🎯 Memory Management

```cpp
s.reserve(100);     // Reserve capacity
s.shrink_to_fit();  // Reduce capacity to size
s.resize(50);       // Change size (pad with null chars if growing)
s.resize(50, 'x');  // Change size (pad with 'x' if growing)
```

---
*Happy coding! 🎉*
