#include <iostream>
#include <vector>

using namespace std;


// Dynamic programming algorithm for the longest subsequence

int lcs2(vector<int> &a, vector<int> &b) {
  int n = a.size() + 1;
  int m = b.size() + 1;
  int S[n][m];   // Solution matrix

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {

      if (i == 0 || j == 0) {
         S[i][j] = 0;
      } else if (a[i-1] == b[j-1]) {
        S[i][j] = S[i-1][j-1] + 1;
      } else {
        S[i][j] = max(S[i-1][j], S[i][j-1]);
      }
    }
  }

  return S[n - 1][m - 1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
