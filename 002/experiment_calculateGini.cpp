// 一开始有100个人，每个人都有100元
// 在每一轮都做如下的事情 :
// 每个人都必须拿出1元钱给除自己以外的其他人，给谁完全随机
// 如果某个人在这一轮的钱数为0，那么他可以不给，但是可以接收
// 发生很多很多轮之后，这100人的社会财富分布很均匀吗？

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

const int num = 100;  // 人数
const int money = 100;
vector<int> people(num, money);

int getRand(int min, int max) { return (rand() % (max - min + 1)) + min; }

// 进行实验
void experiment(vector<int>& people, int t);

// 计算基尼系数
double calculateGini(vector<int> people);

int main() {
  srand(time(0));
  cout << "一个社会的基尼系数是一个在0~1之间的小数\n";
  cout << "基尼系数为0代表所有人的财富完全一样\n";
  cout << "基尼系数为1代表有1个人掌握了全社会的财富\n";
  cout << "基尼系数越小，代表社会财富分布越均衡；越大则代表财富分布越不均衡\n";
  cout << "在2022年，世界各国的平均基尼系数为0.44\n";
  cout << "目前普遍认为，当基尼系数到达 0.5 时\n";
  cout << "就意味着社会贫富差距非常大，分布非常不均匀\n";
  cout << "社会可能会因此陷入危机，比如大量的犯罪或者经历社会动荡\n\n";
  cout << "测试开始\n";
  int t = 10000;
  cout << "人数 : " << num << '\n';
  cout << "轮数 : " << t << '\n';
  experiment(people, t);
  cout << "测试结束\n";
}

void experiment(vector<int>& people, int t) {
  for (int i = 0; i < t; ++i) {
    vector<bool> vb(num, false);
    for (int j = 0; j < num; ++j) {
      if (people[j] > 0) vb[j] = true;
    }
    for (int j = 0; j < num; ++j) {
      if (vb[j] == true) {
        int other = j;
        while (other == j) {
          other = getRand(0, 99);
        }
        people[j]--;
        people[other]++;
      }
    }
  }
  std::sort(people.begin(), people.end());
  cout << "列出每个人的财富(贫穷到富有) : \n";
  for (int i = 0; i < num; ++i) {
    cout << people[i] << " ";
    if (i % 10 == 9) {
      cout << '\n';
    }
  }
  cout << '\n';
  cout << "这个社会的基尼系数为 : " << calculateGini(people) << '\n';
}

double calculateGini(vector<int> people) {
  double dif = 0;
  double sum = 0;
  for (int i = 0; i < num; ++i) {
    sum += people[i];
    for (int j = 0; j < num; ++j) {
      dif += abs(people[i] - people[j]);
    }
  }
  return dif / (2 * num * sum);
}