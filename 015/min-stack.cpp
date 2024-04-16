// https://leetcode.cn/problems/min-stack/

#include <stack>

namespace by_stack {
class MinStack {
  std::stack<int> s, min;

 public:
  MinStack() {}

  void push(int val) {
    s.push(val);
    if (min.empty() || val <= min.top())
      min.push(val);
    else
      min.push(min.top());
  }

  void pop() {
    s.pop();
    min.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min.top(); }
};
}  // namespace by_stack

namespace by_vec {
class MinStack {
  int data[8000];
  int min[8000];
  int size = 0;

 public:
  MinStack() {}

  void push(int val) {
    data[size] = val;
    if (size == 0 || val <= min[size - 1])
      min[size] = val;
    else
      min[size] = min[size - 1];
    size++;
  }

  void pop() { size--; }

  int top() { return data[size - 1]; }

  int getMin() { return min[size - 1]; }
};
}  // namespace by_vec
