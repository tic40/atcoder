// https://abs.contest.atcoder.jp/tasks/abc088_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cards(n);
  for(int i = 0; i < n; i++) cin >> cards.at(i);
  sort(cards.begin(), cards.end(), std::greater<int>());

  bool aliceTurn = true;
  int alice = 0, bob = 0;
  for (int n: cards) {
    aliceTurn ? alice += n : bob += n;
    aliceTurn = !aliceTurn;
  }
  cout << alice - bob << endl;
}