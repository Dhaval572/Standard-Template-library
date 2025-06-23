# 🚀 C++ STL Queue Cheatsheet

*Complete guide to std::queue & priority_queue - First In, First Out (FIFO) & Priority-based containers*

## 📦 Includes & Types

```cpp
#include <queue>
using namespace std;

// Regular Queue - FIFO (First In, First Out)
queue<int> q1;                              // Default: uses deque<int>
queue<int, list<int>> q2;                   // Uses list as underlying container
queue<int, deque<int>> q3;                  // Explicitly uses deque

// Priority Queue - Elements ordered by priority
priority_queue<int> pq1;                    // Max heap (default)
priority_queue<int, vector<int>, greater<int>> pq2; // Min heap
```

## 🔍 Queue Types Comparison

| Feature | `queue` | `priority_queue` |
|---------|---------|------------------|
| **Access Pattern** | FIFO | Priority-based |
| **Access Points** | Front & Back | Top only |
| **Underlying Containers** | `deque`, `list` | `vector`, `deque` |
| **Ordering** | Insertion order | Priority order |
| **Time Complexity** | O(1) all ops | O(log n) insert/remove |

## 🚀 Creating Queues

### Regular Queue
```cpp
queue<int> q1;                              // Empty queue (uses deque)
queue<string> q2;                           // Queue of strings
queue<vector<int>> q3;                      // Queue of vectors

// With specific underlying container
queue<int, list<int>> list_queue;           // Uses list
queue<int, deque<int>> deque_queue;         // Uses deque (same as default)

// Copy constructor
queue<int> original;
original.push(1);
original.push(2);
queue<int> copy(original);                  // Copy constructor
```

### Priority Queue
```cpp
priority_queue<int> pq1;                    // Max heap (largest first)
priority_queue<int, vector<int>, greater<int>> pq2; // Min heap (smallest first)

// With custom comparator
auto cmp = [](int a, int b) { return a > b; }; // Min heap
priority_queue<int, vector<int>, decltype(cmp)> pq3(cmp);

// From container
vector<int> v = {3, 1, 4, 1, 5};
priority_queue<int> pq4(v.begin(), v.end()); // Max heap: 5,4,3,1,1
```

### From Underlying Container
```cpp
deque<int> d = {10, 20, 30};
queue<int> q(d);                            // Queue: front->10,20,30<-back

list<int> l = {1, 2, 3};
queue<int, list<int>> ql(l);               // Queue: front->1,2,3<-back
```

## ➕ Adding Elements

### Regular Queue
```cpp
queue<int> q;

// Push elements to back
q.push(10);                                 // Queue: [10]
q.push(20);                                 // Queue: [10, 20]
q.push(30);                                 // Queue: [10, 20, 30]

// Emplace (construct in place) - C++11
q.emplace(40);                              // Queue: [10, 20, 30, 40]

// For complex objects
queue<pair<int, string>> pq;
pq.emplace(1, "first");                     // More efficient than push
pq.push({2, "second"});                     // Alternative syntax
```

### Priority Queue
```cpp
priority_queue<int> pq;

// Push elements (automatically ordered)
pq.push(30);                                // PQ: [30]
pq.push(10);                                // PQ: [30, 10]
pq.push(50);                                // PQ: [50, 30, 10]
pq.push(20);                                // PQ: [50, 30, 20, 10]

// Emplace
pq.emplace(40);                             // PQ: [50, 40, 30, 20, 10]

// Min heap example
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(30);
min_pq.push(10);
min_pq.push(50);                            // Min PQ: [10, 30, 50]
```

## 🔍 Accessing Elements

### Regular Queue
```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

// Access front element (oldest)
cout << q.front() << endl;                  // Output: 10

// Access back element (newest)
cout << q.back() << endl;                   // Output: 30

// Modify elements
q.front() = 100;                            // Queue: [100, 20, 30]
q.back() = 300;                             // Queue: [100, 20, 300]

// Safe access
if (!q.empty()) {
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
}
```

### Priority Queue
```cpp
priority_queue<int> pq;
pq.push(30);
pq.push(10);
pq.push(50);

// Access top element (highest priority)
cout << pq.top() << endl;                   // Output: 50

// Modify top element
pq.top() = 100;                             // PQ top is now 100

// Safe access
if (!pq.empty()) {
    cout << "Highest priority: " << pq.top() << endl;
}
```

## ❌ Removing Elements

### Regular Queue
```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

// Pop front element (no return value!)
q.pop();                                    // Removes 10, Queue: [20, 30]
cout << q.front() << endl;                  // Output: 20

// Get and remove pattern
if (!q.empty()) {
    int front_value = q.front();            // Get the value first
    q.pop();                                // Then remove it
    cout << "Processed: " << front_value << endl;
}

// Process all elements
while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
cout << endl;                               // Output: 30
```

### Priority Queue
```cpp
priority_queue<int> pq;
pq.push(30);
pq.push(10);
pq.push(50);

// Pop top element (highest priority)
pq.pop();                                   // Removes 50
cout << pq.top() << endl;                   // Output: 30

// Process by priority
while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
cout << endl;                               // Output: 30 10
```

## 📏 Size & Capacity

```cpp
queue<int> q;
priority_queue<int> pq;

// Check if empty
cout << q.empty() << endl;                  // Output: 1 (true)
cout << pq.empty() << endl;                 // Output: 1 (true)

// Size
cout << q.size() << endl;                   // Output: 0
cout << pq.size() << endl;                  // Output: 0

q.push(10);
pq.push(10);

cout << q.empty() << endl;                  // Output: 0 (false)
cout << q.size() << endl;                   // Output: 1
cout << pq.size() << endl;                  // Output: 1
```

## 🔄 Queue Operations

### Basic Queue Usage
```cpp
queue<string> taskQueue;

// Add tasks
taskQueue.push("Task1");
taskQueue.push("Task2");
taskQueue.push("Task3");

// Process tasks in FIFO order
while (!taskQueue.empty()) {
    cout << "Processing: " << taskQueue.front() << endl;
    taskQueue.pop();
}
// Output: Processing: Task1, Task2, Task3
```

### Swap Queues
```cpp
queue<int> q1, q2;
q1.push(1); q1.push(2);
q2.push(10); q2.push(20);

q1.swap(q2);                                // Swap contents
// q1: [10, 20], q2: [1, 2]

// Alternative syntax
swap(q1, q2);                               // Swap back
```

## 🎨 Advanced Examples

### BFS (Breadth-First Search)
```cpp
void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        cout << current << " ";
        
        // Add unvisited neighbors
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Usage
vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
bfs(graph, 0);                              // Output: 0 1 2 3
```

### Level Order Tree Traversal
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```

### Sliding Window Maximum (using deque)
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Store indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices outside current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove indices of smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add maximum to result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
```

## 🏆 Priority Queue Examples

### Task Scheduling
```cpp
struct Task {
    string name;
    int priority;
    
    Task(string n, int p) : name(n), priority(p) {}
    
    // For max heap (higher priority first)
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

priority_queue<Task> taskPQ;

// Add tasks
taskPQ.emplace("Low Priority", 1);
taskPQ.emplace("High Priority", 10);
taskPQ.emplace("Medium Priority", 5);

// Process by priority
while (!taskPQ.empty()) {
    Task t = taskPQ.top();
    taskPQ.pop();
    cout << "Processing: " << t.name << " (Priority: " << t.priority << ")" << endl;
}
// Output: High Priority (10), Medium Priority (5), Low Priority (1)
```

### Dijkstra's Algorithm
```cpp
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start}); // {distance, vertex}
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

### Top K Elements
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Min heap of size k
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (auto& p : freq) {
        pq.push({p.second, p.first}); // {frequency, number}
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    return result;
}
```

### Merge K Sorted Lists
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min heap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
    // Add first node of each list
    for (ListNode* list : lists) {
        if (list) pq.push(list);
    }
    
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        tail->next = node;
        tail = node;
        
        if (node->next) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}
```

## 🔧 Container Adapters Comparison

### Queue Underlying Containers
```cpp
// Deque-based queue (default - recommended)
queue<int> deque_queue;
// Pros: Efficient front/back operations, good memory usage
// Cons: Slightly more complex than vector

// List-based queue
queue<int, list<int>> list_queue;
// Pros: Guaranteed O(1) operations, no reallocation
// Cons: Higher memory per element, poor cache locality
```

### Priority Queue Underlying Containers
```cpp
// Vector-based priority queue (default - recommended)
priority_queue<int> vector_pq;
// Pros: Good cache locality, efficient heap operations
// Cons: Reallocation costs for growth

// Deque-based priority queue
priority_queue<int, deque<int>> deque_pq;
// Pros: No reallocation, still good performance
// Cons: Slightly worse cache locality than vector
```

## 💡 Custom Comparators

### Function Objects
```cpp
struct MinHeapComparator {
    bool operator()(int a, int b) {
        return a > b; // Min heap (smaller elements have higher priority)
    }
};

priority_queue<int, vector<int>, MinHeapComparator> min_pq;
```

### Lambda Functions
```cpp
auto max_cmp = [](int a, int b) { return a < b; }; // Max heap
priority_queue<int, vector<int>, decltype(max_cmp)> max_pq(max_cmp);

auto min_cmp = [](int a, int b) { return a > b; }; // Min heap
priority_queue<int, vector<int>, decltype(min_cmp)> min_pq(min_cmp);
```

### Complex Objects
```cpp
struct Person {
    string name;
    int age;
    
    Person(string n, int a) : name(n), age(a) {}
};

// Priority by age (older first)
auto age_cmp = [](const Person& a, const Person& b) {
    return a.age < b.age;
};

priority_queue<Person, vector<Person>, decltype(age_cmp)> age_pq(age_cmp);
age_pq.emplace("Alice", 25);
age_pq.emplace("Bob", 30);
age_pq.emplace("Charlie", 20);

while (!age_pq.empty()) {
    Person p = age_pq.top();
    cout << p.name << " (" << p.age << ")" << endl;
    age_pq.pop();
}
// Output: Bob (30), Alice (25), Charlie (20)
```

## 🎯 Common Patterns

### Buffer/Producer-Consumer
```cpp
class Buffer {
private:
    queue<int> buffer;
    size_t maxSize;
    
public:
    Buffer(size_t size) : maxSize(size) {}
    
    bool produce(int item) {
        if (buffer.size() < maxSize) {
            buffer.push(item);
            return true;
        }
        return false; // Buffer full
    }
    
    bool consume(int& item) {
        if (!buffer.empty()) {
            item = buffer.front();
            buffer.pop();
            return true;
        }
        return false; // Buffer empty
    }
    
    size_t size() const { return buffer.size(); }
    bool empty() const { return buffer.empty(); }
    bool full() const { return buffer.size() == maxSize; }
};
```

### Event System
```cpp
struct Event {
    string type;
    int timestamp;
    string data;
    
    Event(string t, int ts, string d) : type(t), timestamp(ts), data(d) {}
    
    // Earlier events have higher priority
    bool operator<(const Event& other) const {
        return timestamp > other.timestamp;
    }
};

class EventSystem {
private:
    priority_queue<Event> events;
    
public:
    void scheduleEvent(const string& type, int timestamp, const string& data) {
        events.emplace(type, timestamp, data);
    }
    
    void processEvents(int currentTime) {
        while (!events.empty() && events.top().timestamp <= currentTime) {
            Event e = events.top();
            events.pop();
            
            cout << "Processing event: " << e.type 
                 << " at time " << e.timestamp << endl;
        }
    }
};
```

### Job Queue with Priorities
```cpp
enum class Priority { LOW = 1, MEDIUM = 2, HIGH = 3, URGENT = 4 };

struct Job {
    string description;
    Priority priority;
    int id;
    
    Job(string desc, Priority p, int i) : description(desc), priority(p), id(i) {}
    
    bool operator<(const Job& other) const {
        if (priority != other.priority) {
            return priority < other.priority; // Higher priority first
        }
        return id > other.id; // Earlier jobs first if same priority
    }
};

class JobQueue {
private:
    priority_queue<Job> jobs;
    int nextId = 0;
    
public:
    void addJob(const string& desc, Priority p) {
        jobs.emplace(desc, p, nextId++);
    }
    
    bool processNextJob() {
        if (jobs.empty()) return false;
        
        Job job = jobs.top();
        jobs.pop();
        
        cout << "Processing job " << job.id << ": " << job.description 
             << " (Priority: " << static_cast<int>(job.priority) << ")" << endl;
        
        return true;
    }
};
```

## ⚡ Performance Tips

### Efficient Queue Operations
```cpp
// Bad: Multiple front() calls
queue<ExpensiveObject> q;
if (!q.empty()) {
    process(q.front());
    log(q.front());         // Second copy
    q.pop();
}

// Good: Store reference
if (!q.empty()) {
    const auto& obj = q.front();
    process(obj);
    log(obj);
    q.pop();
}
```

### Priority Queue Performance
```cpp
// Reserve space for better performance
vector<int> data = {5, 2, 8, 1, 9};
priority_queue<int> pq;

// Bad: Individual pushes might cause reallocations
for (int x : data) {
    pq.push(x);
}

// Better: Construct from range (uses make_heap)
priority_queue<int> pq2(data.begin(), data.end());
```

### Memory Management
```cpp
// Clear queue and free memory
queue<int> q;
// ... use queue ...

// This empties but might not free memory:
while (!q.empty()) q.pop();

// This guarantees memory is freed:
queue<int>().swap(q);       // Swap with empty queue
// or
q = queue<int>();           // Assignment from empty queue
```

## 🚫 Common Pitfalls

### Don't Access Empty Queue
```cpp
queue<int> q;
// q.front();               // ❌ Undefined behavior!
// q.back();                // ❌ Undefined behavior!
// q.pop();                 // ❌ Undefined behavior!

// ✅ Always check first
if (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
}
```

### pop() Doesn't Return Value
```cpp
queue<int> q;
q.push(42);

// ❌ This doesn't work!
// int value = q.pop();     // pop() returns void!

// ✅ Correct way
int value = q.front();
q.pop();
```

### Priority Queue Comparator Confusion
```cpp
// ❌ Common mistake: assuming < means "higher priority"
struct BadComparator {
    bool operator()(int a, int b) {
        return a < b; // This creates MAX heap, not min heap!
    }
};

// ✅ Remember: operator< defines "less priority"
struct GoodComparator {
    bool operator()(int a, int b) {
        return a > b; // For MIN heap (smaller = higher priority)
    }
};
```

## 🎯 When to Use Queue vs Priority Queue

### Use Regular Queue When
- **FIFO processing** is required
- **Order of arrival** matters
- **Simple task scheduling**
- **BFS algorithms**
- **Buffer implementations**

### Use Priority Queue When
- **Elements have different priorities**
- **Need to process highest/lowest priority first**
- **Implementing Dijkstra's algorithm**
- **Finding top K elements**
- **Event simulation systems**
- **Huffman coding**

### Consider Alternatives When
- Need **LIFO behavior** → use `stack`
- Need **random access** → use `vector` or `deque`
- Need **both ends access** → use `deque`
- Need **sorted container** → use `set` or `multiset`

## 💡 Pro Tips

- **Exception Safety**: Queue operations are strongly exception-safe
- **Thread Safety**: Not thread-safe by default, use synchronization
- **Memory**: Deque is usually best for queue, vector for priority_queue
- **Performance**: All queue ops are O(1), priority_queue ops are O(log n)
- **Debugging**: Copy queue to iterate through elements without destroying
- **Custom Types**: Remember to define comparison operators for priority_queue
- **Min/Max Heap**: Use `greater<T>` for min heap, default for max heap

---
*Master the queues! 🚀*
