// https://atcoder.jp/contests/arc029/tasks/arc029_1
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a = 0, b = 0;
  cin >> n;
  vector<int> meat(n);
  for (int i = 0; i < n; i++) cin >> meat.at(i);
  sort(meat.begin(), meat.end(), greater<int>());
  for (int t : meat) a <= b ? a += t : b += t;
  cout << max(a, b) << endl;
}
