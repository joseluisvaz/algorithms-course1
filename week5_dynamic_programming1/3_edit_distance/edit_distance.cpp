#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

enum ReconsSteps {
  insertion,
  deletion, 
  match, 
  nomatch, 
  END
};

int edit_distance(const string &str1, const string &str2) {
  // Dynamic programming solution for edit distance
  int n = str1.size();
  int m = str2.size();

  int minDists[n][m];
  int directions[n][m];

  // Fill up corner cases
  for (int i = 0; i < n; i++)
    minDists[i][0] = i;
  for (int i = 0; i < m; i++)
    minDists[0][i] = i;

  for (string::size_type i = 1; i < n + 1; i++) {
    for (string::size_type j = 1; j < m + 1; j++) {
      int dist = INT_MAX; 
      int minSteps = INT_MAX;

      // Initialize minimization
      minDists[i][j] = INT_MAX;
      for (int step = insertion; step != END; step ++) {
        switch (step) {
          case insertion:
            dist = minDists[i][j-1] + 1;
          break;
          case deletion:
            dist = minDists[i-1][j] + 1;
          break;
          case match:
            if(str1[i-1] == str2[j-1])
              dist = minDists[i-1][j-1];
          break;
          case nomatch:
            if(str1[i-1] != str2[j-1])
              dist = minDists[i-1][j-1] + 1;
          break;
        }
        if (dist < minDists[i][j]) {
          minDists[i][j] = dist;
          directions[i][j] = step;
        }
      }
    }
  }

  return minDists[n][m]; 
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
