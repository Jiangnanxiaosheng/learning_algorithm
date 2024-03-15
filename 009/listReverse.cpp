#include <iostream>

// 按值传递、按引用传递
// 从堆栈角度解释链表节点
// 以堆栈视角来看链表反转

#define println(x) std::cout << x << '\n'

struct Number {
  int val;
  Number(int v) : val(v) {}
};

void f(int a) { a = 0; }

void g1(Number* b) { b = nullptr; }

void g2(Number* b) { b->val = 6; }

void g3(int c[]) { c = nullptr; }

void g4(int c[]) { c[0] = 100; }

int main() {
  int a = 10;
  f(a);
  println(a);

  // 若是想在g1实现把main中的b指向nullptr
  // g1的形参需要改为 Number* &
  Number* b = new Number(5);
  g1(b);
  println(b->val);
  g2(b);
  println(b->val);

  // 比如下面的一维数组
  int c[] = {1, 2, 3, 4};
  g3(c);
  println(c[0]);
  g4(c);
  println(c[0]);
}

// 单链表节点
class ListNode {
 public:
  ListNode(int val) { this->val = val; }

  ListNode(int val, ListNode* next) {
    this->val = val;
    this->next = next;
  }

 public:
  int val;
  ListNode* next;
};

// 反转单链表测试链接 : https://leetcode.cn/problems/reverse-linked-list/
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* pre = nullptr;
    ListNode* next = head;
    while (head != nullptr) {
      head = head->next;
      next->next = pre;
      pre = next;
      next = head;
    }
    return pre;
  }
};

// 双链表节点
class DoubleListNode {
 public:
  DoubleListNode(int v) { value = v; }
  DoubleListNode* last;
  DoubleListNode* next;

 public:
  int value;
};

// 反转双链表
// 没有找到测试链接
// 如下方法是对的
DoubleListNode* reverseDoubleList(DoubleListNode* head) {
  DoubleListNode* pre = nullptr;
  DoubleListNode* next = nullptr;
  while (head != nullptr) {
    next = head->next;
    head->next = pre;
    head->last = next;
    pre = head;
    head = next;
  }
  return pre;
}
