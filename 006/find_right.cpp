#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using std::cout;
using std::vector;

const int n = 100;   // Լ�������С��Χ
const int v = 1000;  // Լ������Ԫ�ط�Χ

std::random_device seed;  // Ӳ���������������
std::default_random_engine engine(seed());
std::uniform_int_distribution<int> distribution(0, v);

// �������һ������n��Ԫ�ص�vector
vector<int> randomVector(int n);

// ������������ <= num �����ұߵ�λ��
int find_right(vector<int>& sortedVecotr, int num);

int right(vector<int>& v, int num);

int main() {
  int test_time = 50000;
  cout << "test begin, a total of " << test_time << " times: \n";
  for (int i = 0; i < test_time; ++i) {
    std::uniform_int_distribution<int> distribution2(0, n);
    int size = distribution2(engine);
    vector<int> vec = randomVector(size);
    std::sort(vec.begin(), vec.end());
    int num = distribution(engine);
    if (right(vec, num) != find_right(vec, num)) cout << "error\n";
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

// ������������ <= num �����ұߵ�λ��
int find_right(vector<int>& sortedVecotr, int num) {
  int l = 0, r = sortedVecotr.size() - 1, m = 0, ans = -1;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (sortedVecotr[m] <= num) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ans;
}

int right(vector<int>& v, int num) {
  for (int i = v.size() - 1; i >= 0; --i) {
    if (v[i] <= num) {
      return i;
    }
  }
  return -1;
}