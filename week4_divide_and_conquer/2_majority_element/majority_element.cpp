#include <algorithm>
#include <iostream>

using std::vector;

bool has_majority(vector<int> &array, int left, int right, int key) {
   int count = 0;

   for (int i = left; i < right; i++) {
     if (array[i] ==  key)
       count++;
   }

  return (count > (right - left) / 2);
}

int get_majority_element(vector<int> &array, int left, int right) {

  if (left==right) return -1;
  if (left + 1==right) return array[left];

  int middle = (right + left)/2;

  int lc = get_majority_element(array, left, middle);
  if (lc >= 0 && has_majority(array, left, right, lc))
    return lc;

  int rc = get_majority_element(array, middle, right);
  if (rc >= 0 && has_majority(array, left, right, rc))
    return rc;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
