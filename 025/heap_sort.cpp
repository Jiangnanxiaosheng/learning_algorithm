#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/sort-an-array/
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    head_sort(nums);
    return nums;
  }

  void head_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(nums, i, n);
    }
    int size = n;
    while (size > 1) {
      swap(nums[0], nums[--size]);
      heapify(nums, 0, size);
    }
  }

  void heapify(vector<int>& nums, int i, int size) {
    int l = 2 * i + 1;
    while (l < size) {
      int best = l + 1 < size && nums[l + 1] > nums[l] ? l + 1 : l;
      if (nums[i] >= nums[best]) break;
      swap(nums[i], nums[best]);
      i = best;
      l = best * 2 + 1;
    }
  }
};

// iλ�õ��������ϵ��������
// arr[i] = x��x�������ģ����Ͽ���ֱ�����ȸ��״󣬻�������0λ��(��)
void heapinsert(int* arr, int i) {
  while (arr[i] > arr[(i - 1) / 2]) {
    swap(arr[i], arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

// iλ�õ�������С�ˣ�����ά�ִ���ѽṹ
// ���µ��������
// ��ǰ�ѵĴ�СΪsize
void heapify(int* arr, int i, int size) {
  int l = i * 2 + 1;
  // �����ӣ�l
  // �Һ��ӣ�l+1
  // ��ѡ����ǿ�ĺ��ӣ����ĸ��±�ĺ���
  while (l < size) {
    int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
    // �����Ѿ���ѡ����ǿ�ĺ��ӣ�����������ǰ��������ǿ�ĺ���֮ǰ����ǿ�±���˭
    best = arr[best] > arr[i] ? best : i;
    if (best == i) break;
    swap(arr[best], arr[i]);
    i = best;
    l = i * 2 + 1;
  }
}

// �Ӷ����׽�������ѣ�O(n * logn)
// ���ε����������ֵ���ź���O(n * logn)
// ����ʱ�临�Ӷ�O(n * logn)
void heap_sort1(int* arr, const int size) {
  int n = size;
  for (int i = 0; i < size; i++) {
    heapinsert(arr, i);
  }

  while (n > 1) {
    swap(arr[0], arr[--n]);
    heapify(arr, 0, n);
  }
}

// �ӵ׵�����������ѣ�O(n)
// ���ε����������ֵ���ź���O(n * logn)
// ����ʱ�临�Ӷ�O(n * logn)
void heap_sort2(int* arr, const int size) {
  int n = size;
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, i, n);
  }

  while (--n >= 0) {
    swap(arr[0], arr[n]);
    heapify(arr, 0, n);
  }
}

int main() {
  int arr[] = {-74, 48,  -20, 2,   10,  -84, -5,  -9,  11,  -24, -91, 2,   -71,
               64,  63,  80,  28,  -30, -58, -11, -44, -87, -22, 54,  -74, -10,
               -55, -28, -46, 29,  10,  50,  -72, 34,  26,  25,  8,   51,  13,
               30,  35,  -8,  50,  65,  -6,  16,  -2,  21,  -78, 35,  -13, 14,
               23,  -3,  26,  -90, 86,  25,  -56, 91,  -13, 92,  -25, 37,  57,
               -20, -69, 98,  95,  45,  47,  29,  86,  -28, 73,  -44, -46, 65,
               -84, -96, -24, -12, 72,  -68, 93,  57,  92,  52,  -45, -2,  85,
               -63, 56,  55,  12,  -85, 77,  -39};

  heap_sort2(arr, 98);

  for (auto x : arr) {
    cout << x << " ";
  }

  return 0;
}