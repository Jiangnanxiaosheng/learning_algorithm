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

// i位置的数，向上调整大根堆
// arr[i] = x，x是新来的！往上看，直到不比父亲大，或者来到0位置(顶)
void heapinsert(int* arr, int i) {
  while (arr[i] > arr[(i - 1) / 2]) {
    swap(arr[i], arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

// i位置的数，变小了，又想维持大根堆结构
// 向下调整大根堆
// 当前堆的大小为size
void heapify(int* arr, int i, int size) {
  int l = i * 2 + 1;
  // 有左孩子，l
  // 右孩子，l+1
  // 评选，最强的孩子，是哪个下标的孩子
  while (l < size) {
    int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
    // 上面已经评选了最强的孩子，接下来，当前的数和最强的孩子之前，最强下标是谁
    best = arr[best] > arr[i] ? best : i;
    if (best == i) break;
    swap(arr[best], arr[i]);
    i = best;
    l = i * 2 + 1;
  }
}

// 从顶到底建立大根堆，O(n * logn)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
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

// 从底到顶建立大根堆，O(n)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
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