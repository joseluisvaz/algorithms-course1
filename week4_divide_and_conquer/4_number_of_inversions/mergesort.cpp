#include <iostream>
#include <vector>


using namespace std;

void merge(vector<int> &unsorted, int init_index, int end_index, int split_point);
void merge_sort(vector<int> &unsorted, int init_index, int end_index);

int main() {
  uint  n;
  cin >> n;
  vector<int> unsorted(n);

  for(int &x : unsorted) {
    cin >> x;
  }

  // Merge sort this bad boy
  merge_sort(unsorted, 0, (int) unsorted.size() - 1);

  cout << "Sorted" << endl;
  for(auto x: unsorted){
    cout <<  x << " ";
  }
  cout << endl;
}



void merge_sort(vector<int> &unsorted, int init_index, int end_index){
  if (init_index < end_index){

    int split_point = init_index + (end_index-init_index)/2;

    merge_sort(unsorted, init_index, split_point);
    merge_sort(unsorted, split_point + 1, end_index);
    merge(unsorted, init_index, end_index, split_point);
  }
}

void merge(vector<int> &unsorted,
           int init_index,
           int end_index,
           int split_point){

  auto n1 = (uint) (split_point - init_index + 1);
  auto n2 = (uint) (end_index - split_point);

  vector<int> left_array(n1);
  vector<int> right_array(n2);

  // Fill left and right array
  for (int i = 0; i < n1; i++)
    left_array[i] = unsorted[init_index + i];
  for (int j = 0; j < n2; j++)
    right_array[j] = unsorted[split_point + 1 + j];


  // Assign infinity to last elements of array
  int i = 0;
  int j = 0;
  int k = init_index;

  // Sort the array

  while(i < n1 && j < n2){
    if(left_array[i] <= right_array[j]) {
      unsorted[k] = left_array[i];
      i++;
    }
    else {
      unsorted[k] = right_array[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    unsorted[k] = left_array[i];
    i++;
    k++;
  }

  while(j < n2){
    unsorted[k] = right_array[j];
    j++;
    k++;
  }
}
