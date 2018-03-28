#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &array, int p, int r) {

  int pivot = array[p];
  int i = p;

  for (int j = p + 1; j <= r; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[j], array[i]);
    }
  }
  swap(array[p], array[i]);
  return i;
}

int partition3(vector<int> &array, int p, int r) {

  int pivot = array[p];
  int i = p;

  for (int j = p + 1; j <= r; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[j], array[i]);
    }
  }
  swap(array[p], array[i]);
  return i;
}

void randomized_quick_sort(vector<int> &array, int p, int r) {
  if (p >= r) {
    return;
  }

  int rand_index = p + rand() % (r - p + 1);
  swap(array[p], array[rand_index]);
  int q = partition2(array, p, r);

  randomized_quick_sort(array, p, q - 1);
  randomized_quick_sort(array, q + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
