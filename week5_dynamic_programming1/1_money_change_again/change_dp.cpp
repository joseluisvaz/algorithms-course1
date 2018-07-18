#include <iostream>
#include <vector>

/* Write a program which gives change to an amount of money with coins 
of the following denominations:
1, 3, 4
*/

using namespace std;

// Global Variables
vector<int> denominations = {4, 3, 1};

vector<int> get_change(int money) {
  vector<int> used_coins;
  for(auto coin: denominations) {
    while (coin <= money) {
      used_coins.push_back(coin);
      money -= coin;
    }
  }
  return used_coins;
}

int main() {
  int money;
  std::cin >> money;

  vector<int> used_coins = get_change(money);
  for (auto coin: used_coins) {
    cout << "used coin: "  << coin << endl;
  }
}
