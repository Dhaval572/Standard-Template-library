# 📚 C++ STL Stack Cheatsheet

*Complete guide to std::stack - Last In, First Out (LIFO) container adapter*

## 📦 Includes & Types

```cpp
#include <stack>
using namespace std;

// Stack is a container adapter - uses other containers internally
stack<int> s1;                          // Default: uses deque<int>
stack<int, vector<int>> s2;             // Uses vector as underlying container
stack<int, list<int>> s3;               // Uses list as underlying container
stack<int, deque<int>> s4;              // Explicitly uses deque
```

## 🔍 Stack Overview

| Feature | Details |
|---------|---------|
| **Access Pattern** | LIFO (Last In, First Out) |
| **Access Points** | Top only |
| **Underlying Containers** | `deque` (default), `vector`, `list` |
| **Time Complexity** | O(1) for all operations |
| **Header** | `<stack>` |
| **Iterator Support** | ❌ No iterators |

## 🚀 Creating Stacks

### Basic Declaration
```cpp
stack<int> s1;                          // Empty stack (uses deque)
stack<string> s2;                       // Stack of strings
stack<vector<int>> s3;                  // Stack of vectors

// With specific underlying container
stack<int, vector<int>> vec_stack;      // Uses vector
stack<int, list<int>> list_stack;       // Uses list
stack<int, deque<int>> deque_stack;     // Uses deque (same as default)
```

### Copy Constructor
```cpp
stack<int> original;
original.push(1);
original.push(2);

stack<int> copy(original);              // Copy constructor
stack<int> copy2 = original;            // Copy assignment
```

### From Underlying Container
```cpp
deque<int> d = {1, 2, 3, 4, 5};
stack<int> s(d);                        // Stack: top->5,4,3,2,1<-bottom

vector<int> v = {10, 20, 30};
stack<int, vector<int>> vs(v);          // Stack: top->30,20,10<-bottom
```

## ➕ Adding Elements

```cpp
stack<int> s;

// Push elements onto stack
s.push(10);                             // Stack: [10]
s.push(20);                             // Stack: [20, 10] (20 on top)
s.push(30);                             // Stack: [30, 20, 10]

// Emplace (construct in place) - C++11
s.emplace(40);                          // Stack: [40, 30, 20, 10]

// For complex objects
stack<pair<int, string>> ps;
ps.emplace(1, "first");                 // More efficient than push(make_pair(...))
ps.push({2, "second"});                 // Alternative syntax
```

## 🔍 Accessing Elements

```cpp
stack<int> s;
s.push(10);
s.push(20);
s.push(30);

// Access top element
cout << s.top() << endl;                // Output: 30

// Modify top element
s.top() = 100;                          // Stack: [100, 20, 10]
cout << s.top() << endl;                // Output: 100

// Safe access with size check
if (!s.empty()) {
    cout << "Top: " << s.top() << endl;
} else {
    cout << "Stack is empty!" << endl;
}
```

## ❌ Removing Elements

```cpp
stack<int> s;
s.push(10);
s.push(20);
s.push(30);

// Pop top element (no return value!)
s.pop();                                // Removes 30, Stack: [20, 10]
cout << s.top() << endl;                // Output: 20

// Get and remove pattern
if (!s.empty()) {
    int top_value = s.top();            // Get the value first
    s.pop();                            // Then remove it
    cout << "Popped: " << top_value << endl;
}

// Pop all elements
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
cout << endl;                           // Output: 10
```

## 📏 Size & Capacity

```cpp
stack<int> s;

// Check if empty
cout << s.empty() << endl;              // Output: 1 (true)

// Size
cout << s.size() << endl;               // Output: 0

s.push(10);
s.push(20);

cout << s.empty() << endl;              // Output: 0 (false)
cout << s.size() << endl;               // Output: 2

// Note: No capacity(), max_size(), or reserve() for stack
// These depend on the underlying container
```

## 🔄 Stack Operations

### Basic Stack Usage
```cpp
stack<int> s;

// Push multiple elements
for (int i = 1; i <= 5; ++i) {
    s.push(i * 10);
}
// Stack: [50, 40, 30, 20, 10]

// Process all elements
cout << "Stack contents (top to bottom): ";
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
cout << endl;
// Output: 50 40 30 20 10
```

### Swap Stacks
```cpp
stack<int> s1, s2;
s1.push(1); s1.push(2);
s2.push(10); s2.push(20);

s1.swap(s2);                            // Swap contents
// s1: [20, 10], s2: [2, 1]

// Alternative syntax
swap(s1, s2);                           // Swap back
```

## 🎨 Advanced Examples

### Balanced Parentheses Checker
```cpp
bool isBalanced(const string& expr) {
    stack<char> s;
    
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            
            char top = s.top();
            s.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.empty();
}

// Usage
cout << isBalanced("({[]})") << endl;   // Output: 1 (true)
cout << isBalanced("({[}])") << endl;   // Output: 0 (false)
```

### Reverse String Using Stack
```cpp
string reverseString(const string& str) {
    stack<char> s;
    
    // Push all characters
    for (char c : str) {
        s.push(c);
    }
    
    // Pop to create reversed string
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    
    return reversed;
}

// Usage
cout << reverseString("Hello") << endl; // Output: "olleH"
```

### Evaluate Postfix Expression
```cpp
int evaluatePostfix(const vector<string>& tokens) {
    stack<int> s;
    
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        } else {
            s.push(stoi(token));
        }
    }
    
    return s.top();
}

// Usage
vector<string> expr = {"2", "1", "+", "3", "*"};
cout << evaluatePostfix(expr) << endl;  // Output: 9 ((2+1)*3)
```

### Next Greater Element
```cpp
vector<int> nextGreaterElement(const vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> s; // Stack of indices
    
    for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}

// Usage
vector<int> nums = {4, 5, 2, 25};
vector<int> result = nextGreaterElement(nums);
// result: [5, 25, 25, -1]
```

## 🔧 Container Adapters Comparison

### Choosing Underlying Container
```cpp
// Vector-based stack (good for frequent push/pop at end)
stack<int, vector<int>> vec_stack;
// Pros: Good cache locality, minimal memory overhead
// Cons: Potential reallocation costs

// List-based stack (good for guaranteed O(1) operations)
stack<int, list<int>> list_stack;
// Pros: No reallocation, guaranteed O(1)
// Cons: Higher memory per element, poor cache locality

// Deque-based stack (default - balanced choice)
stack<int, deque<int>> deque_stack;
// Pros: Good balance of performance and memory usage
// Cons: Slightly more complex than vector
```

### Performance Comparison
```cpp
// Timing different stack types
auto time_stack = [](auto& stack_obj, int n) {
    auto start = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < n; ++i) {
        stack_obj.push(i);
    }
    
    while (!stack_obj.empty()) {
        stack_obj.pop();
    }
    
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
};

stack<int> default_stack;              // deque-based
stack<int, vector<int>> vector_stack;
stack<int, list<int>> list_stack;

// Compare performance...
```

## 💡 Stack with Custom Objects

```cpp
struct Task {
    string name;
    int priority;
    
    Task(string n, int p) : name(n), priority(p) {}
};

stack<Task> taskStack;

// Push tasks
taskStack.emplace("Task1", 1);          // More efficient
taskStack.push(Task("Task2", 2));       // Also works

// Process tasks
while (!taskStack.empty()) {
    Task current = taskStack.top();
    taskStack.pop();
    cout << "Processing: " << current.name 
         << " (Priority: " << current.priority << ")" << endl;
}
```

## 🎯 Common Patterns

### Undo Functionality
```cpp
class TextEditor {
private:
    string text;
    stack<string> history;
    
public:
    void addText(const string& newText) {
        history.push(text);                 // Save current state
        text += newText;
    }
    
    void undo() {
        if (!history.empty()) {
            text = history.top();
            history.pop();
        }
    }
    
    string getText() const { return text; }
};

// Usage
TextEditor editor;
editor.addText("Hello");
editor.addText(" World");
cout << editor.getText() << endl;       // "Hello World"
editor.undo();
cout << editor.getText() << endl;       // "Hello"
```

### Function Call Stack Simulation
```cpp
struct FunctionCall {
    string name;
    map<string, int> localVars;
    
    FunctionCall(string n) : name(n) {}
};

class CallStack {
private:
    stack<FunctionCall> calls;
    
public:
    void enterFunction(const string& name) {
        calls.emplace(name);
    }
    
    void exitFunction() {
        if (!calls.empty()) {
            cout << "Exiting: " << calls.top().name << endl;
            calls.pop();
        }
    }
    
    void setVariable(const string& var, int value) {
        if (!calls.empty()) {
            calls.top().localVars[var] = value;
        }
    }
    
    int getVariable(const string& var) {
        if (!calls.empty()) {
            auto& vars = calls.top().localVars;
            if (vars.find(var) != vars.end()) {
                return vars[var];
            }
        }
        return 0; // Default value
    }
};
```

### Stack-based DFS
```cpp
void dfsIterative(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    
    s.push(start);
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";
            
            // Add neighbors to stack
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}
```

## ⚡ Performance Tips

### Efficient Element Access
```cpp
// Bad: Multiple top() calls
stack<ExpensiveObject> s;
if (!s.empty()) {
    process(s.top());
    log(s.top());           // Second copy of expensive object
    s.pop();
}

// Good: Store reference
if (!s.empty()) {
    const auto& obj = s.top();
    process(obj);
    log(obj);
    s.pop();
}
```

### Bulk Operations
```cpp
// Push multiple elements efficiently
stack<int> s;
vector<int> data = {1, 2, 3, 4, 5};

for (int x : data) {
    s.push(x);              // Individual pushes
}

// For large datasets, consider using the underlying container directly
deque<int> d(data.begin(), data.end());
stack<int> s2(d);
```

### Memory Considerations
```cpp
// If you need to clear a stack and free memory
stack<int> s;
// ... use stack ...

// This might not free memory:
while (!s.empty()) s.pop();

// This guarantees memory is freed:
stack<int>().swap(s);       // Swap with empty stack
// or
s = stack<int>();           // Assignment from empty stack
```

## 🚫 Common Pitfalls

### Don't Access Empty Stack
```cpp
stack<int> s;
// s.top();                 // ❌ Undefined behavior!
// s.pop();                 // ❌ Undefined behavior!

// ✅ Always check first
if (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
}
```

### pop() Doesn't Return Value
```cpp
stack<int> s;
s.push(42);

// ❌ This doesn't work!
// int value = s.pop();     // pop() returns void!

// ✅ Correct way
int value = s.top();
s.pop();
```

### No Iterators
```cpp
stack<int> s = /* ... */;

// ❌ Stacks don't have iterators
// for (auto it = s.begin(); it != s.end(); ++it) { ... }

// ✅ Must pop to iterate
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

## 🎯 When to Use Stack

### Perfect Use Cases
- **Expression evaluation** (postfix, infix conversion)
- **Balanced parentheses checking**
- **Undo/Redo functionality**
- **Function call management**
- **Backtracking algorithms**
- **Browser history**
- **Depth-First Search (DFS)**

### Consider Alternatives When
- Need **random access** → use `vector` or `deque`
- Need **FIFO behavior** → use `queue`
- Need **priority-based access** → use `priority_queue`
- Need **both ends access** → use `deque`

## 💡 Pro Tips

- **Exception Safety**: Stack operations are strongly exception-safe
- **No Invalidation**: References to stack elements are stable until popped
- **Thread Safety**: Not thread-safe by default, use synchronization
- **Memory**: Default deque is usually the best choice for underlying container
- **Debugging**: Print stack contents by copying to another stack first
- **Performance**: All operations are O(1), making stack very efficient

---
*Master the stack! 📚*
