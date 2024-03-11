#include <iostream>

template <typename T>
void bubble_sort(T arr, int n) {
  if (n < 2) return;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
    }
  }
}

template <typename T>
void select_sort(T arr, int n) {
  if (n < 2) return;

  for (int i = 0; i < n - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[min] > arr[j]) min = j;
    }
    std::swap(arr[i], arr[min]);
  }
}

template <typename T>
void insert_sort(T arr, int n) {
  if (n < 2) return;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j > 0; --j) {
      if (arr[j] < arr[j - 1]) std::swap(arr[j], arr[j - 1]);
    }
  }
}

int main() {
  // int a[10]{4, 6, 7, 5, 1, 9, 3, 2, 8, 0};
  // bubble_sort(a, 10);
  double a[10]{4, 6.5, 7.4, 5, 1, 9, 3, 2, 15.9, 0};
  // selsect_sort(a, 10);
  // insert_sort(a, 10);

  for (int i = 0; i < 10; ++i) {
    std::cout << a[i] << " ";
  }

  return 0;
}