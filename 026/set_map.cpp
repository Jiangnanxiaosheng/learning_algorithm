#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main() {
  // �ײ�����
  map<int, string> treeMap;
  treeMap[5] = "����5";
  treeMap[7] = "����7";
  treeMap[1] = "����1";
  treeMap[2] = "����2";
  treeMap[3] = "����3";
  treeMap[4] = "����4";
  treeMap[8] = "����8";

  cout << treeMap.count(1) << endl;
  cout << treeMap.count(10) << endl;
  cout << treeMap[4] << endl;
  treeMap[4] = "������4";
  cout << treeMap[4] << endl;

  treeMap.erase(4);
  cout << (treeMap.count(4) == 0) << endl;

  cout << treeMap.begin()->first << endl;
  cout << treeMap.rbegin()->first << endl;
  // TreeMap�У����е�key��<= 4�������key��ʲô
  auto it = treeMap.lower_bound(4);
  if (it != treeMap.begin()) {
    cout << prev(it)->first << endl;
  } else {
    cout << "No such key" << endl;
  }
  // TreeMap�У����е�key��>= 4�������key��ʲô
  it = treeMap.upper_bound(4);
  if (it != treeMap.end()) {
    cout << it->first << endl;
  } else {
    cout << "No such key" << endl;
  }

  cout << "========" << endl;

  set<int> set;
  set.insert(3);
  set.insert(3);
  set.insert(4);
  set.insert(4);
  cout << "������С : " << set.size() << endl;
  while (!set.empty()) {
    cout << *set.begin() << endl;
    set.erase(set.begin());
    // cout << *set.rbegin() << endl;
    // set.erase(*set.rbegin());
  }

  // �ѣ�Ĭ��С���ѡ����Ҫ����ѣ����ƱȽ�����
  priority_queue<int, vector<int>, greater<int>> heap1;
  heap1.push(3);
  heap1.push(3);
  heap1.push(4);
  heap1.push(4);
  cout << "heap1�Ѵ�С : " << heap1.size() << endl;
  while (!heap1.empty()) {
    cout << heap1.top() << endl;
    heap1.pop();
  }

  // ���ƵĴ���ѣ��ñȽ�����
  priority_queue<int, vector<int>, less<int>> heap2;
  heap2.push(3);
  heap2.push(3);
  heap2.push(4);
  heap2.push(4);
  cout << "heap2�Ѵ�С : " << heap2.size() << endl;
  while (!heap2.empty()) {
    cout << heap2.top() << endl;
    heap2.pop();
  }

  return 0;
}