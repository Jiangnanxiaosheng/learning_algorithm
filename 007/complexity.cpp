/*
 * ��Ҫ�ô���ṹ���ж�ʱ�临�Ӷȣ�����ֻ��һ��whileѭ����ð��������ʵʱ�临�Ӷ�O(N^2)

 * ��Ҫ�ô���ṹ���ж�ʱ�临�Ӷȣ����� : N / 1 + N / 2 + N / 3 + ... +
    N / N��������̵�ʱ�临�Ӷ���O(N*logN)�������ĵ��ͼ���

 * ʱ�临�Ӷ�ֻ���Ƕ��㷨���̳�������ܷ��������������Ǽ򵥵Ŀ�����ṹ!
    ����һ�������Ĵ���!������Щ�㷨��ʵ�����˶��ѭ��Ƕ�ף���ʱ�临�Ӷ���O(N)�ġ�

 * �������Ӷ�һ�� :
    0(1) 0(logN) 0(N) O(N*logN) 0(N^2) ... O(N^k) 0(2^N) ... O(k^N) O(N!)

 * ʱ�临�Ӷȷǳ���Ҫ������ֱ���ж�ĳ�������ܲ���ͨ��һ����Ŀ�������������½ⷨ��
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// ֻ��һ��ѭ�����ð������
// ������ʱ�临�Ӷ�O(N^2)�ģ�

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
  // ������ɳ���Ϊn
  // ֵ��0~v-1֮��
  // ������������������ȵ�����
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
      // ������Ƕ��forѭ�������̣�ʱ�临�Ӷ�ΪO(N * logN)
      // 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/n��Ҳ��"���ͼ���"��������O(logN)
      // �������һ�����̵ı��ʽ : n/1 + n/2 + n/3 + ... + n/n
      // ��ô�������ʱ�临�Ӷ�O(N * logN)
    }
  }
  auto end{std::chrono::steady_clock::now()};
  std::chrono::duration<double> elapsed_seconds = end - start;
  cout << "test end. cost : " << elapsed_seconds.count() << "s\n";

  std::cout << "test begin:\n";
  start = std::chrono::steady_clock::now();
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      // ������Ƕ��forѭ�������̣�ʱ�临�Ӷ�ΪO(N^2)
      // �����ԵȲ�����
    }
  }
  end = std::chrono::steady_clock::now();
  elapsed_seconds = end - start;
  cout << "test end. cost : " << elapsed_seconds.count() << "s\n";
  return 0;
}