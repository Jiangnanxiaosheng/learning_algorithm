#include <iostream>

// �ݹ���Ľ���
// �õݹ�ʵ�ֶ��������������
struct TreeNode {
  int val;

  TreeNode* left;

  TreeNode* right;

  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// �ݹ�������ӣ��������ݹ���
void f(TreeNode* head);

// �����ӡ���нڵ㣬�ݹ��
void preOrder(TreeNode* head);

// �����ӡ���нڵ㣬�ݹ��
void inOrder(TreeNode* head);

// �����ӡ���нڵ㣬�ݹ��
void posOrder(TreeNode* head);

int main() {
  TreeNode* head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(4);
  head->left->right = new TreeNode(5);
  head->right->left = new TreeNode(6);
  head->right->right = new TreeNode(7);

  preOrder(head);
  std::cout << '\n';
  std::cout << "��������ݹ��\n";

  inOrder(head);
  std::cout << '\n';
  std::cout << "��������ݹ��\n";

  posOrder(head);
  std::cout << '\n';
  std::cout << "��������ݹ��\n";
}

// �ݹ�������ӣ��������ݹ���
void f(TreeNode* head) {
  if (head == nullptr) {
    return;
  }
  // 1
  f(head->left);
  // 2
  f(head->right);
  // 3
}

// �����ӡ���нڵ㣬�ݹ��
void preOrder(TreeNode* head) {
  if (head == nullptr) {
    return;
  }
  std::cout << head->val << " ";
  preOrder(head->left);
  preOrder(head->right);
}

// �����ӡ���нڵ㣬�ݹ��
void inOrder(TreeNode* head) {
  if (head == nullptr) {
    return;
  }
  inOrder(head->left);
  std::cout << head->val << " ";
  inOrder(head->right);
}

// �����ӡ���нڵ㣬�ݹ��
void posOrder(TreeNode* head) {
  if (head == nullptr) {
    return;
  }
  posOrder(head->left);
  posOrder(head->right);
  std::cout << head->val << " ";
}