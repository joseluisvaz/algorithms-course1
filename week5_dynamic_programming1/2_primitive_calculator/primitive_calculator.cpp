#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

enum Steps
{
  First_step,
  Second_step,
  Third_step,
  END
};

vector<long> optimal_sequence(long number)
{

  // Initialize vector of solutions with INT_MAX and size n
  vector<int> minStepsPointers(number + 1, INT_MAX);
  vector<long> sequence;
  vector<int> minSteps(number + 1, INT_MAX);

  // Recursion base cases
  minSteps[0] = 1;
  minSteps[1] = 1;
  minStepsPointers[0] = 0;
  minStepsPointers[1] = 0;

  // Iterate until the desired number
  for (size_t n = 2; n < number + 1; n++)
  {
    for (int step = First_step; step != END; step++) {
      int numSteps = INT_MAX;
      switch (step) {
        case First_step:
          if (n%3 == 0) {
            numSteps = minSteps[n / 3] + 1;
            if (numSteps < minSteps[n]) {
              minSteps[n] = numSteps;
              minStepsPointers[n] = n / 3;
            }
          }
          break;
        case Second_step:
          if (n%2 == 0) {
            numSteps = minSteps[n/2] + 1;
            if (numSteps < minSteps[n]) {
              minSteps[n] = numSteps;
              minStepsPointers[n] = n / 2;
            }
          }
          break;
        case Third_step:
            numSteps = minSteps[n-1] + 1;
            if (numSteps < minSteps[n]) {
              minSteps[n] = numSteps;
              minStepsPointers[n] = n - 1;
            }
          break;
      }
    }
  }
  // Reconstruct the solution vector
  for (long i = number; i >= 1; i = minStepsPointers[i]) {
    sequence.push_back(i);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  long n;
  std::cin >> n;
  vector<long> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
