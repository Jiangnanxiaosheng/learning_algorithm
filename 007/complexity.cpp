/*
 * 不要用代码结构来判断时间复杂度，比如只有一个while循环的冒泡排序，其实时间复杂度O(N^2)

 * 不要用代码结构来判断时间复杂度，比如 : N / 1 + N / 2 + N / 3 + ... +
    N / N，这个流程的时间复杂度是O(N*logN)，著名的调和级数

 * 时间复杂度只能是对算法流程充分理解才能分析出来，而不是简单的看代码结构!
    这是一个常见的错误!甚至有些算法的实现用了多层循环嵌套，但时间复杂度是O(N)的。

 * 常见复杂度一览 :
    0(1) 0(logN) 0(N) O(N*logN) 0(N^2) ... O(N^k) 0(2^N) ... O(k^N) O(N!)

 * 时间复杂度非常重要，可以直接判断某个方法能不能通过一个题目，根据数据量猜解法。
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 只用一个循环完成冒泡排序
// 但这是时间复杂度O(N^2)的！

template <typename T>
void bubbleSort(vector<T>& arr) {
  if (arr.size() < 2) {
    return;
  }
  int n = arr.size();
  int end = n - 1, i = 0;
  while (end > 0) {
    if (arr[i] > arr[i + 1]) {
      std::swap(arr[i], arr[i + 1]);
    }
    if (i < end - 1) {
      i++;
    } else {
      end--;
      i = 0;
    }
  }
}

int main() {
  // 随机生成长度为n
  // 值在0~v-1之间
  // 且任意相邻两数不相等的数组
  int n = 10;
  int v = 4;
  vector<int> arr1(n);
  arr1[0] = rand() % v;
  for (int i = 1; i < n; i++) {
    do {
      arr1[i] = rand() % v;
    } while (arr1[i] == arr1[i - 1]);
  }
  for (int num : arr1) {
    cout << num << " ";
  }
  cout << endl << "=========" << endl;

  vector<int> arr2 = {5, 4, 9};
  arr2[1] = 6;

  cout << arr2[1] << endl;
  cout << "=========" << endl;

  vector<int> arr = {64, 31, 78, 0, 5, 7, 103};
  bubbleSort(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl << "=========" << endl;

  int N = 200000;

  std::cout << "test begin:\n";
  auto start{std::chrono::steady_clock::now()};
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      // 这两个嵌套for循环的流程，时间复杂度为O(N * logN)
      // 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/n，也叫"调和级数"，收敛于O(logN)
      // 所以如果一个流程的表达式 : n/1 + n/2 + n/3 + ... + n/n
      // 那么这个流程时间复杂度O(N * logN)
    }
  }
  auto end{std::chrono::steady_clock::now()};
  std::chrono::duration<double> elapsed_seconds = end - start;
  cout << "test end. cost : " << elapsed_seconds.count() << "s\n";

  std::cout << "test begin:\n";
  start = std::chrono::steady_clock::now();
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      // 这两个嵌套for循环的流程，时间复杂度为O(N^2)
      // 很明显等差数列
    }
  }
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end - start;
  cout << "test end. cost : " << elapsed_seconds.count() << "s\n";
  return 0;
}