// һ��ʼ��100���ˣ�ÿ���˶���100Ԫ
// ��ÿһ�ֶ������µ����� :
// ÿ���˶������ó�1ԪǮ�����Լ�����������ˣ���˭��ȫ���
// ���ĳ��������һ�ֵ�Ǯ��Ϊ0����ô�����Բ��������ǿ��Խ���
// �����ܶ�ܶ���֮����100�˵����Ƹ��ֲ��ܾ�����

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

const int num = 100;  // ����
const int money = 100;
vector<int> people(num, money);

int getRand(int min, int max) { return (rand() % (max - min + 1)) + min; }

// ����ʵ��
void experiment(vector<int>& people, int t);

// �������ϵ��
double calculateGini(vector<int> people);

int main() {
  srand(time(0));
  cout << "һ�����Ļ���ϵ����һ����0~1֮���С��\n";
  cout << "����ϵ��Ϊ0���������˵ĲƸ���ȫһ��\n";
  cout << "����ϵ��Ϊ1������1����������ȫ���ĲƸ�\n";
  cout << "����ϵ��ԽС���������Ƹ��ֲ�Խ���⣻Խ�������Ƹ��ֲ�Խ������\n";
  cout << "��2022�꣬���������ƽ������ϵ��Ϊ0.44\n";
  cout << "Ŀǰ�ձ���Ϊ��������ϵ������ 0.5 ʱ\n";
  cout << "����ζ�����ƶ�����ǳ��󣬷ֲ��ǳ�������\n";
  cout << "�����ܻ��������Σ������������ķ�����߾�����ᶯ��\n\n";
  cout << "���Կ�ʼ\n";
  int t = 10000;
  cout << "���� : " << num << '\n';
  cout << "���� : " << t << '\n';
  experiment(people, t);
  cout << "���Խ���\n";
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
  cout << "�г�ÿ���˵ĲƸ�(ƶ�����) : \n";
  for (int i = 0; i < num; ++i) {
    cout << people[i] << " ";
    if (i % 10 == 9) {
      cout << '\n';
    }
  }
  cout << '\n';
  cout << "������Ļ���ϵ��Ϊ : " << calculateGini(people) << '\n';
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