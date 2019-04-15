// https://abs.contest.atcoder.jp/tasks/abc085_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr.at(i);
  sort(arr.begin(), arr.end(), greater<int>());

  int last = 101, count = 0;
  for(int n: arr) {
    if (last == n) continue;
    if (last < n) break;
    count++;
    last = n;
  }
  cout << count << endl;
}