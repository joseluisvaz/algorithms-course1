#include <iostream>
#include <vector>

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

vector<int> partition3(vector<int> &array, int p, int r) {

  int pivot = array[r];
  int i = p - 1;

  for (int k = p; k < r; k++) {
    if (array[k] < pivot) {
      i++;
      swap(array[i], array[k]);
    }
  }

  int j = i;
  for (int k = i; k < r; k++) {
    if (array[k] == pivot) {
      j++;
      swap(array[j], array[k]);
    }
  }

  swap(array[j + 1], array[r]);

  return vector<int> {i + 1, j + 1};
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

void randomized_quick_sort3(vector<int> &array, int p, int r) {

  if (p >= r) {
    return;
  }

  int rand_index = p + rand() % (r - p + 1);
  swap(array[rand_index], array[r]);

  vector<int> q = partition3(array, p, r);

  randomized_quick_sort3(array, p, q[0] - 1);
  randomized_quick_sort3(array, q[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (int i = 0; i < ((int) a.size()); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, (int) a.size() - 1);
  for (int i = 0; i < ((int) a.size()); ++i) {
    std::cout << a[i] << ' ';
  }
}
