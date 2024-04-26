#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main() {
  // 底层红黑树
  map<int, string> treeMap;
  treeMap[5] = "这是5";
  treeMap[7] = "这是7";
  treeMap[1] = "这是1";
  treeMap[2] = "这是2";
  treeMap[3] = "这是3";
  treeMap[4] = "这是4";
  treeMap[8] = "这是8";

  cout << treeMap.count(1) << endl;
  cout << treeMap.count(10) << endl;
  cout << treeMap[4] << endl;
  treeMap[4] = "张三是4";
  cout << treeMap[4] << endl;

  treeMap.erase(4);
  cout << (treeMap.count(4) == 0) << endl;

  cout << treeMap.begin()->first << endl;
  cout << treeMap.rbegin()->first << endl;
  // TreeMap中，所有的key，<= 4且最近的key是什么
  auto it = treeMap.lower_bound(4);
  if (it != treeMap.begin()) {
    cout << prev(it)->first << endl;
  } else {
    cout << "No such key" << endl;
  }
  // TreeMap中，所有的key，>= 4且最近的key是什么
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
  cout << "有序表大小 : " << set.size() << endl;
  while (!set.empty()) {
    cout << *set.begin() << endl;
    set.erase(set.begin());
    // cout << *set.rbegin() << endl;
    // set.erase(*set.rbegin());
  }

  // 堆，默认小根堆、如果要大根堆，定制比较器！
  priority_queue<int, vector<int>, greater<int>> heap1;
  heap1.push(3);
  heap1.push(3);
  heap1.push(4);
  heap1.push(4);
  cout << "heap1堆大小 : " << heap1.size() << endl;
  while (!heap1.empty()) {
    cout << heap1.top() << endl;
    heap1.pop();
  }

  // 定制的大根堆，用比较器！
  priority_queue<int, vector<int>, less<int>> heap2;
  heap2.push(3);
  heap2.push(3);
  heap2.push(4);
  heap2.push(4);
  cout << "heap2堆大小 : " << heap2.size() << endl;
  while (!heap2.empty()) {
    cout << heap2.top() << endl;
    heap2.pop();
  }

  return 0;
}