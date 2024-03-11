// 力扣链接 https://leetcode.cn/problems/find-peak-element/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int findPeakElement(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return 0;
  if (nums[0] > nums[1]) return 0;
  if (nums[n - 1] > nums[n - 2]) return (n - 1);

  int l = 1, r = n - 2, m = 0, ans = -1;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (nums[m] < nums[m - 1]) {
      r = m - 1;
    } else if (nums[m] < nums[m + 1]) {
      l = m + 1;
    } else {
      ans = m;
      break;
    }
  }
  return ans;
}

int main() { return 0; }