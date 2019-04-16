// https://abs.contest.atcoder.jp/tasks/abc083_b
#include <bits/stdc++.h>
using namespace std;

int sumEachDigit(int n) {
  int sum = 0;
  while(n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n, a, b, sum, total = 0;
  cin >> n >> a >> b;

  for (int i = 1; i <= n; i++) {
    sum = sumEachDigit(i);
    if (a <= sum && sum <= b) total += i;
  }
  cout << total << endl;
}