#include <iostream>
#include <vector>

using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left_i, size_t right_i);
int merge(vector<int> &a, vector<int> &b, size_t left_i, size_t middle_i, size_t right_i);


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left_i, size_t right_i) {
  long long number_of_inversions = 0;
  if (right_i > left_i) {
    // Avoids overflow
    size_t middle_i = left_i + (right_i - left_i)/2;
    number_of_inversions += get_number_of_inversions(a, b, left_i, middle_i);
    number_of_inversions += get_number_of_inversions(a, b, middle_i + 1, right_i);
    number_of_inversions += merge(a, b, left_i, middle_i + 1, right_i);
  }
  return number_of_inversions;
}


int merge(vector<int> &a, vector<int> &b, size_t left_i, size_t middle_i, size_t right_i) {

  int number_of_inversions = 0;

  // Assign infinity to last elements of array
  auto i = (int) left_i;
  auto j = (int) middle_i;
  auto k = (int) left_i;

  // Sort the array

  while((i <= middle_i-1) && (j <= right_i)){
    if (a[i] <= a[j]){
      b[k++] = a[i++];
    }
    else {
      b[k++] = a[j++];
      number_of_inversions += middle_i - i;
    }
  }

  // Copy remaining elements
  while(i <= middle_i - 1)
    b[k++] = a[i++];
  while(j <= right_i)
    b[k++] = a[j++];

  // Copy elements back to array
  for(int t = left_i; t < (right_i + 1); t++){
    a[t] = b[t];
  }

  return number_of_inversions;
}
