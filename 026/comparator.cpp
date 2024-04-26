#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Employee {
  int company;
  int age;

  Employee(int c, int a) : company(c), age(a) {}
};

struct EmployeeComparator {
  bool operator()(const Employee& o1, const Employee& o2) const {
    // 比较器默认
    // 返回true表示o1的优先级更高
    // 返回false表示o2的优先级更高
    // 利用这一设定，定制优先级和比较
    // 不再涉及大小，只涉及优先级
    return o1.age < o2.age;
  }
};

int main() {
  Employee s1(2, 27);
  Employee s2(1, 60);
  Employee s3(4, 19);
  Employee s4(3, 23);
  Employee s5(1, 35);
  Employee s6(3, 55);
  vector<Employee> arr = {s1, s2, s3, s4, s5, s6};

  sort(arr.begin(), arr.end(), EmployeeComparator());

  for (const auto& e : arr) {
    cout << e.company << " , " << e.age << endl;
  }

  cout << "=====" << endl;

  sort(arr.begin(), arr.end(),
       [](const Employee& a, const Employee& b) { return b.age < a.age; });

  for (const auto& e : arr) {
    cout << e.company << " , " << e.age << endl;
  }

  cout << "=====" << endl;

  // 先按公司编号，若相同按年龄
  sort(arr.begin(), arr.end(), [](const Employee& a, const Employee& b) {
    return (a.company != b.company) ? (a.company < b.company) : (a.age < b.age);
  });

  for (const auto& e : arr) {
    cout << e.company << " , " << e.age << endl;
  }

  return 0;
}