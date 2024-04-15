// https://leetcode.cn/problems/add-two-numbers/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tmp = dummy;

    int carry = 0;
    int val = 0;
    int sum = 0;
    while (l1 != nullptr || l2 != nullptr) {
      sum =
          (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
      val = sum % 10;
      carry = sum / 10;
      tmp->next = new ListNode(val);

      l1 = l1 == nullptr ? nullptr : l1->next;
      l2 = l2 == nullptr ? nullptr : l2->next;
      tmp = tmp->next;
    }
    if (carry == 1) {
      tmp->next = new ListNode(1);
    }
    return dummy->next;
  }
};