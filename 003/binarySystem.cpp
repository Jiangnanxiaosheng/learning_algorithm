// ���ļ���ʵ������int��������
// ����long������ȫͬ��
// ����Ҫע�⣬�����long���͵�����num����64λ
// num & (1 << 48)������д������
// ��Ϊ1��һ��int���ͣ�ֻ��32λ������(1 << 48)�������ˣ�����������
// Ӧ��д�� : num & (1L << 48)

#include <iostream>
using std::cout;

// ��ӡһ��int���͵����֣�32λ���Ƶ�״̬
// ����Ǹ�λ���Ҳ��ǵ�λ
void printBinary(int num) {
  for (int i = 31; i >= 0; i--) {
    // �������д�������Ըĳ� :
    // cout << ((a & (1 << i)) != 0 ? "1" : "0");
    // �������Ըĳ� :
    // cout << ((a & (1 << i)) == 1 ? "1" : "0");
    // ��Ϊa�����iλ��1����ô(a & (1 << i))��2��i�η�������һ����1
    // ���磬a = 0010011
    // a�ĵ�0λ��1����1λ��1����4λ��1
    // (a & (1<<4)) == 16������1����˵��a�ĵ�4λ��1״̬
    cout << ((num & (1 << i)) == 0 ? "0" : "1");
  }
  cout << '\n';
}

bool returnTrue();
bool returnFalse();

int main() {
  // �Ǹ���
  int a = 78;
  cout << a << '\n';
  printBinary(a);
  cout << "===a===\n";
  // ����
  int b = -6;
  cout << b << '\n';
  printBinary(b);
  cout << "===b===\n";
  // ֱ��д�����Ƶ���ʽ�������
  int c = 0b1001110;
  cout << c << '\n';
  printBinary(c);
  cout << "===c===\n";
  // ֱ��дʮ�����Ƶ���ʽ�������
  //  0100 -> 4
  //  1110 -> e
  //  0x4e -> 01001110
  int d = 0x4e;
  cout << d << '\n';
  printBinary(d);
  cout << "===d===\n";
  //~���෴��
  cout << a << '\n';
  printBinary(a);
  printBinary(~a);
  int e = ~a + 1;
  cout << e << '\n';
  printBinary(e);
  cout << "===e===\n";
  // int��long����Сֵ��ȡ�෴��������ֵ�������Լ�
  int f = INT_MIN;
  cout << f << '\n';
  printBinary(f);
  cout << -f << '\n';
  printBinary(-f);
  cout << ~f + 1 << '\n';
  printBinary(~f + 1);
  cout << "===f===\n";
  // | & ^
  int g = 0b0001010;
  int h = 0b0001100;
  printBinary(g | h);
  printBinary(g & h);
  printBinary(g ^ h);
  cout << "===g��h===\n";
  // ������ôд : int num = 3231 | 6434;
  // ������ôд : int num = 3231 & 6434;
  // ������ôд : int num = 3231 || 6434;
  // ������ôд : int num = 3231 && 6434;
  // ��Ϊ ||��&& �� �߼����߼��룬ֻ������boolean����
  // ������ˣ�|��& ���ӵ�����һ���������
  // �� ||��&& �д�͸�Ե��ص�
  cout << "test1���Կ�ʼ\n";
  bool test1 = returnTrue() | returnFalse();
  cout << "test1�����" << test1 << '\n';
  cout << "test2���Կ�ʼ\n";
  bool test2 = returnTrue() || returnFalse();
  cout << "test2�����" << test2 << '\n';
  cout << "test3���Կ�ʼ\n";
  bool test3 = returnFalse() & returnTrue();
  cout << "test3�����" << test3 << '\n';
  cout << "test4���Կ�ʼ\n";
  bool test4 = returnFalse() && returnTrue();
  cout << "test4�����" << test4 << '\n';
  cout << "===|��&��||��&&===\n";
  // <<
  int i = 0b0011010;
  printBinary(i);
  printBinary(i << 1);
  printBinary(i << 2);
  printBinary(i << 3);
  cout << "===i << ===\n";
  // �Ǹ��� >> >>>��Ч��һ��
  printBinary(i);
  printBinary(i >> 2);
  printBinary(static_cast<unsigned int>(i) >> 2);
  cout << "===i >> >>>===\n";
  // ���� >> >>>��Ч����һ��
  int j = 0b11110000000000000000000000000000;
  printBinary(j);
  printBinary(j >> 2);
  printBinary(static_cast<unsigned int>(j) >> 2);
  cout << "===j >> >>>===\n";
  // �Ǹ��� << 1����ͬ�ڳ���2
  // �Ǹ��� << 2����ͬ�ڳ���4
  // �Ǹ��� << 3����ͬ�ڳ���8
  // �Ǹ��� << i����ͬ�ڳ���2��i�η�
  // ...
  // �Ǹ��� >> 1����ͬ�ڳ���2
  // �Ǹ��� >> 2����ͬ�ڳ���4
  // �Ǹ��� >> 3����ͬ�ڳ���8
  // �Ǹ��� >> i����ͬ�ڳ���2��i�η�
  // ֻ�зǸ����������������������Ҫ��
  int k = 10;
  cout << k;
  cout << (k << 1);
  cout << (k << 2);
  cout << (k << 3);
  cout << (k >> 1);
  cout << (k >> 2);
  cout << (k >> 3);
  cout << "===k===";
}

bool returnTrue() {
  cout << "������returnTrue����\n";
  return true;
}

bool returnFalse() {
  cout << "������returnFlase����\n";
  return false;
}
