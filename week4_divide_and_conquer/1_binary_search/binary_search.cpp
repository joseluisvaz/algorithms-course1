#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int binary_search(const vector<int> &array, int x) {

  int left = 0;
  int right = (int) array.size() - 1;
  int middle = (right - left) / 2;

  for (;;)  {

    if (array[middle] == x)
      return middle;

    if (array[middle] < x)
      left = middle;

    if (array[middle] > x)
      right = middle;

    middle = (right + left) / 2;

    // If right and left cursor are next to each other
    if ((right - left) == 1) {
      if (array[right]==x)
        return right;
      if (array[left]==x)
        return left;
      else
        return -1;
    }
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
