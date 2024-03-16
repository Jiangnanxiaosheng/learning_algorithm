#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using std::cout;
using std::vector;

const int n = 100;   // 约定数组大小范围
const int v = 1000;  // 约定数组元素范围

std::random_device seed;  // 硬件生成随机数种子
std::default_random_engine engine(seed());
std::uniform_int_distribution<int> distribution(0, v);

// 随机构建一个具有n个元素的vector
vector<int> randomVector(int n);

bool exist(vector<int>& sortedVecotr, int num);

bool right(vector<int>& sortedVecotr, int num);

int main() {
  int test_time = 50000;
  cout << "test begin, a total of " << test_time << " times: \n";
  for (int i = 0; i < test_time; ++i) {
    std::uniform_int_distribution<int> distribution2(0, n);
    int size = distribution2(engine);
    vector<int> v = randomVector(size);
    std::sort(v.begin(), v.end());
    int num = distribution(engine);
    if (right(v, num) != exist(v, num)) cout << "error\n";
  }
  cout << "test end\n";
  return 0;
}

vector<int> randomVector(int n) {
  vector<int> vec(n);
  for (auto& x : vec) {
    x = distribution(engine);
  }
  return vec;
}

bool exist(vector<int>& sortedVecotr, int num) {
  if (sortedVecotr.size() == 0) return false;

  int l = 0, r = sortedVecotr.size() - 1, m = 0;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (sortedVecotr[m] == num) {
      return true;
    } else if (sortedVecotr[m] > num) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return false;
}
bool right(vector<int>& sortedVecotr, int num) {
  for (int cur : sortedVecotr) {
    if (cur == num) {
      return true;
    }
  }
  return false;
}