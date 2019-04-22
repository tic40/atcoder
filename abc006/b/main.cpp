#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n, vector<int> &memo) {
  if (n <= 2) return 0;
  if (n == 3) return 1;
  if (memo.at(n)) return memo.at(n);

  memo.at(n) = 0;
  for (int i = 1; i <= 3; i++) memo.at(n) += tribonacci(n - i, memo);
  memo.at(n) %= 10007;
  return memo.at(n);
}

int main() {
  int n;
  cin >> n;
  vector<int> memo(n + 1);
  cout << tribonacci(n, memo) << "\n";
}