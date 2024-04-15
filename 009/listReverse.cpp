#include <iostream>

// ��ֵ���ݡ������ô���
// �Ӷ�ջ�ǶȽ�������ڵ�
// �Զ�ջ�ӽ���������ת

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

  // ��������g1ʵ�ְ�main�е�bָ��nullptr
  // g1���β���Ҫ��Ϊ Number* &
  Number* b = new Number(5);
  g1(b);
  println(b->val);
  g2(b);
  println(b->val);

  // ���������һά����
  int c[] = {1, 2, 3, 4};
  g3(c);
  println(c[0]);
  g4(c);
  println(c[0]);
}

// ������ڵ�
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

// ��ת������������� : https://leetcode.cn/problems/reverse-linked-list/
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

// ˫����ڵ�
class DoubleListNode {
 public:
  DoubleListNode(int v) { value = v; }
  DoubleListNode* last;
  DoubleListNode* next;

 public:
  int value;
};

// ��ת˫����
// û���ҵ���������
// ���·����ǶԵ�
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