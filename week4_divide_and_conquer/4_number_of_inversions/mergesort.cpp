#include <iostream>
#include <vector>

using namespace std;

long long dummy_function(){
  cout << "hola" << endl;
}

int main() {
  uint  n;
  cin >> n;
  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  for (auto b : a) {
    cout << b << " " << endl;
  }

}
