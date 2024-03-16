#include <iostream>

void g1(int* b) {
  b = nullptr;
  std::cout << "b: " << b << " " << '\n';
}

int main() {
  int* a = new int(5);
  std::cout << "a: " << a << " " << *a << '\n';
  g1(a);
  std::cout << "a: " << a << " " << '\n';
}