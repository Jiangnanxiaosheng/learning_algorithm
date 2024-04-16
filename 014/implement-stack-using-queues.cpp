// https://leetcode.cn/problems/implement-stack-using-queues/

#include <queue>

class MyStack {
  std::queue<int> q;

 public:
  MyStack() {}

  void push(int x) {
    int n = q.size();
    q.push(x);
    while (--n >= 0) {
      q.push(pop());
    }
  }

  int pop() {
    int x = top();
    q.pop();
    return x;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};