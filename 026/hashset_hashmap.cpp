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
    // ������Ҫ�������������д��ϣ���������Ի���ѧ���������������ϣֵ
    // ��ֻ��һ��ʾ��������Ĺ�ϣ����Ӧ�ø���ʵ�������ʵ��
    return std::hash<int>()(s.age) ^ (std::hash<std::string>()(s.name) << 1);
  }
};

struct StudentEqual {
  bool operator()(const Student& s1, const Student& s2) const {
    // ������Ҫ������������ʵ����ȱȽϺ���
    // һ����˵����ȱȽϺ���Ӧ�ñȽ�ѧ���������������
    return s1.age == s2.age && s1.name == s2.name;
  }
};

int main() {
  std::string str1 = std::string("Hello");
  std::string str2 = std::string("Hello");
  // false����Ϊ��ͬ���ڴ��ַ
  std::cout << (&str1 == &str2 ? "true" : "false") << std::endl;
  // true��==������Ѿ������أ����ڱȽ������ַ�������������Ƿ���ͬ
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
  std::cout << (map1.count("���")) << std::endl;
  map1.erase("Hello");
  std::cout << map1.size() << std::endl;
  map1.clear();
  std::cout << map1.empty() << std::endl;

  std::cout << "===========" << std::endl;

  // һ���ڱ����У�δ����Ҫ�����ϣ��
  std::unordered_map<int, int> map2;
  map2[56] = 7285;
  map2[34] = 3671263;
  map2[17] = 716311;
  map2[24] = 1263161;
  // �����map2��Ϊ�����Ա������������Ϊ���
  int arr[100];
  arr[56] = 7285;
  arr[34] = 3671263;
  arr[17] = 716311;
  arr[24] = 1263161;
  // ��ϣ�������ɾ���ġ��飬�����Ա����������ǰ����key�ķ�Χ�ǹ̶��ġ��ɿص�
  std::cout << "�ڱ��Գ����й�ϣ�������ᱻ�������" << std::endl;

  std::cout << "===========" << std::endl;

  Student s1(17, "����");
  Student s2(18, "����");
  std::unordered_map<Student, std::string, StudentHash, StudentEqual> map3;
  map3[s1] = "��������";
  std::cout << map3.count(s1) << std::endl;
  std::cout << map3.count(s2) << std::endl;
  map3[s2] = "������һ������";
  std::cout << map3.size() << std::endl;
  std::cout << map3[s1] << std::endl;
  std::cout << map3[s2] << std::endl;
}
