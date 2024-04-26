#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Student {
 public:
  int age;
  std::string name;

  Student(int a, const std::string& b) : age(a), name(b) {}
};

struct StudentHash {
  size_t operator()(const Student& s) const {
    // 这里需要根据您的需求编写哈希函数，可以基于学生的属性来计算哈希值
    // 这只是一个示例，具体的哈希函数应该根据实际情况来实现
    return std::hash<int>()(s.age) ^ (std::hash<std::string>()(s.name) << 1);
  }
};

struct StudentEqual {
  bool operator()(const Student& s1, const Student& s2) const {
    // 这里需要根据您的需求实现相等比较函数
    // 一般来说，相等比较函数应该比较学生对象的所有属性
    return s1.age == s2.age && s1.name == s2.name;
  }
};

int main() {
  std::string str1 = std::string("Hello");
  std::string str2 = std::string("Hello");
  // false，因为不同的内存地址
  std::cout << (&str1 == &str2 ? "true" : "false") << std::endl;
  // true，==运算符已经被重载，用于比较两个字符串对象的内容是否相同
  std::cout << (str1 == str2 ? "true" : "false") << std::endl;

  std::unordered_set<std::string> set;
  set.insert(str1);
  std::cout << set.count("Hello") << std::endl;
  std::cout << set.count(str2) << std::endl;
  set.insert(str2);
  std::cout << set.size() << std::endl;
  set.erase(str1);
  set.clear();
  std::cout << set.empty() << std::endl;

  std::cout << "===========" << std::endl;

  std::unordered_map<std::string, std::string> map1;
  map1[str1] = "World";
  std::cout << (map1.count("Hello") ? 1 : 0) << std::endl;
  std::cout << (map1.count(str2) ? 1 : 0) << std::endl;
  std::cout << map1[str2] << std::endl;
  std::cout << (map1.count("你好")) << std::endl;
  map1.erase("Hello");
  std::cout << map1.size() << std::endl;
  map1.clear();
  std::cout << map1.empty() << std::endl;

  std::cout << "===========" << std::endl;

  // 一般在笔试中，未必需要申请哈希表
  std::unordered_map<int, int> map2;
  map2[56] = 7285;
  map2[34] = 3671263;
  map2[17] = 716311;
  map2[24] = 1263161;
  // 上面的map2行为，可以被如下数组的行为替代
  int arr[100];
  arr[56] = 7285;
  arr[34] = 3671263;
  arr[17] = 716311;
  arr[24] = 1263161;
  // 哈希表的增、删、改、查，都可以被数组替代，前提是key的范围是固定的、可控的
  std::cout << "在笔试场合中哈希表往往会被数组替代" << std::endl;

  std::cout << "===========" << std::endl;

  Student s1(17, "张三");
  Student s2(18, "张三");
  std::unordered_map<Student, std::string, StudentHash, StudentEqual> map3;
  map3[s1] = "这是张三";
  std::cout << map3.count(s1) << std::endl;
  std::cout << map3.count(s2) << std::endl;
  map3[s2] = "这是另一个张三";
  std::cout << map3.size() << std::endl;
  std::cout << map3[s1] << std::endl;
  std::cout << map3[s2] << std::endl;
}
