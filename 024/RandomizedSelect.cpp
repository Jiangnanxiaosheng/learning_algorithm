/*
 * 利用改写快排的方法，时间复杂度为O(n), 额外空间复杂度O(1)
 */

#include <algorithm>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/kth-largest-element-in-an-array/
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quick(nums, 0, n - 1, n - k);
  }

  int quick(vector<int>& nums, int l, int r, int k) {
    int ans = 0;

    while (l <= r) {
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

      if (k < first) {
        r = first - 1;
      } else if (k > last) {
        l = last + 1;
      } else {
        ans = nums[k];
        break;
      }
    }
    return ans;
  }
};