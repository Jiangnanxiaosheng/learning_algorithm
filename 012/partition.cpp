// https://leetcode.cn/problems/partition-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *l1 = new ListNode(-1), *cur1 = l1;
    ListNode *l2 = new ListNode(-1), *cur2 = l2;
    while (head != nullptr) {
      if (head->val >= x) {
        cur1->next = head;
        cur1 = cur1->next;
      } else {
        cur2->next = head;
        cur2 = cur2->next;
      }
      head = head->next;
    }
    cur2->next = l1->next;
    cur1->next = nullptr;

    return l2->next;
  }
};