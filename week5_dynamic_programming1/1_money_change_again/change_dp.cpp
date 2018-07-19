#include <iostream>
#include <vector>
#include <climits>

/* Write a program which gives change to an amount of money with coins 
of the following denominations:
1, 3, 4
*/

using namespace std;

// Global Variables
vector<int> denominations = {4, 3, 1};

int get_change_greedy(int money) {
  vector<int> used_coins;
  for(auto coin: denominations) {
    while (coin <= money) {
      used_coins.push_back(coin);
      money -= coin;
    }
  }
  return used_coins.size();
}

int get_change_recursive(int money) {
  // recursive solution for the get change recursive problem
  if (money <= 0)
    return 0;
  int minNumCoins = INT_MAX;
  for (auto coin: denominations) {
    int numCoins = get_change_recursive(money - coin);
    if (numCoins + 1 < minNumCoins)
      minNumCoins = numCoins + 1;
  }
  return minNumCoins;
}

int main() {
  int money;
  std::cin >> money;

  int used_coins = get_change_recursive(money);
  cout << used_coins << endl;

}
