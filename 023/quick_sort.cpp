#include <iostream>
#include <vector>
using namespace std;

int arr[] = {-74, 48,  -20, 2,   10,  -84, -5,  -9,  11,  -24, -91, 2,   -71,
             64,  63,  80,  28,  -30, -58, -11, -44, -87, -22, 54,  -74, -10,
             -55, -28, -46, 29,  10,  50,  -72, 34,  26,  25,  8,   51,  13,
             30,  35,  -8,  50,  65,  -6,  16,  -2,  21,  -78, 35,  -13, 14,
             23,  -3,  26,  -90, 86,  25,  -56, 91,  -13, 92,  -25, 37,  57,
             -20, -69, 98,  95,  45,  47,  29,  86,  -28, 73,  -44, -46, 65,
             -84, -96, -24, -12, 72,  -68, 93,  57,  92,  52,  -45, -2,  85,
             -63, 56,  55,  12,  -85, 77,  -39};

// 荷兰国旗问题(三路快排的划分过程)
// https://leetcode.cn/problems/sort-colors/
class Solution_sort_colors {
 public:
  void sortColors(vector<int>& nums) { partition(nums, 0, nums.size() - 1); }

  void partition(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int first = left, last = right, i = left;
    while (i <= last) {
      if (nums[i] == 1) {
        i++;
      } else if (nums[i] < 1) {
        swap(nums[i++], nums[first++]);
      } else {
        swap(nums[i], nums[last--]);
      }
    }
  }
};

// 排序数组，使用快排需使用改进版三路快排，否则会超时
// https://leetcode.cn/problems/sort-an-array/
class Solution_sort_an_array_ {
 public:
  void quickSort3Way(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    // 随机选取基准值
    // int pivot = nums[randIndex];
    // swap(nums[left], nums[randIndex]);
    int pivot = nums[left + rand() % (right - left + 1)];

    // 三路划分
    int lt = left, i = left, gt = right;

    while (i <= gt) {
      if (nums[i] == pivot) {
        i++;
      } else if (nums[i] < pivot) {
        swap(nums[i++], nums[lt++]);
      } else {
        swap(nums[i], nums[gt--]);
      }
    }

    // 递归处理左右两部分
    quickSort3Way(nums, left, lt - 1);
    quickSort3Way(nums, gt + 1, right);
  }

  vector<int> sortArray(vector<int>& nums) {
    quickSort3Way(nums, 0, nums.size() - 1);
    return nums;
  }
};

// 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/
class Solution_k {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quick(nums, 0, n - 1, n - k);
  }
#if 0  // 超时，需要改进
    int quick(vector<int>& nums, int l, int r, int k) {
        if (l >= r) return nums[k];

        int x = nums[l + rand() % (r - l + 1)];
        int mid = partition(nums, l , r, x);

        if (mid < k) {
            return quick(nums, mid+1, r, k);
        } else  if (mid > k ){
            return quick(nums, l, mid-1, k);
        } else {
            return nums[mid];
        }
    }

    int partition(vector<int>& nums, int l, int r, int x) {
        int a = l, xi = 0;
        for (int i = l; i <= r; i++) {
            if (nums[i] <= x) {
                swap(nums[i], nums[a]);
                if (nums[a] == x) {
                    xi = a;
                }
                a++;
            }
            
        }
        swap(nums[a-1], nums[xi]);
        return a-1;
    }

#endif

  int quick(vector<int>& nums, int l, int r, int k) {
    if (l >= r) return nums[k];

    int x = nums[l + rand() % (r - l + 1)];
    int first = l, last = r, i = l;
    while (i <= last) {
      if (nums[i] == x) {
        i++;
      } else if (nums[i] < x) {
        swap(nums[i++], nums[first++]);
      } else {
        swap(nums[i], nums[last--]);
      }
    }

    if (last == k)
      return nums[k];
    else if (last > k)
      return quick(nums, l, first - 1, k);
    else
      return quick(nums, last + 1, r, k);
  }
};

// 随机快速排序划分
int partition1(int* arr, int l, int r, int x) {
  int a = l, xi = 0;
  for (int i = l; i <= r; ++i) {
    if (arr[i] <= x) {
      swap(arr[i], arr[a]);
      if (arr[a] == x) {
        xi = a;
      }
      a++;
    }
  }
  swap(arr[xi], arr[a - 1]);
  return a - 1;
}

// 随机快速排序(不推荐)
void quick_sort1(int* arr, int l, int r) {
  if (l >= r) return;

  int x = arr[l + rand() % (r - l + 1)];
  int mid = partition1(arr, l, r, x);
  quick_sort1(arr, l, mid - 1);
  quick_sort1(arr, mid + 1, r);
}

// 改进版三路随机快速排序(推荐)
void quick_sort2(int* arr, int l, int r) {
  if (l >= r) return;

  int x = arr[l + rand() % (r - l + 1)];

  int first = l, last = r, i = l;
  while (i <= last) {
    if (arr[i] == x) {
      i++;
    } else if (arr[i] < x) {
      swap(arr[i++], arr[first++]);
    } else {
      swap(arr[i], arr[last--]);
    }
  }

  quick_sort2(arr, l, first - 1);
  quick_sort2(arr, last + 1, r);
}

int main() {
  quick_sort2(arr, 0, 97);
  for (auto x : arr) {
    cout << x << " ";
  }
}
