//
// Created by jose on 28/03/18.
//
#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &array, int p, int r) {

  int pivot = array[r];
  int i = p - 1;

  for (int j = p; j < r; j++) {
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[r], array[i+1]);
  return i + 1;
}

int quick_sort(vector<int> &array, int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}


