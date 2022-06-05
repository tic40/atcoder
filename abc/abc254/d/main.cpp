#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<bool> sq(n+1);
  for(int i = 1; i*i <= n; i++) sq[i*i] = true;

  // d[i] = iの約数の配列
  vector<vector<int>> d(n+1);
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j+=i) d[j].push_back(i);
  }

  // 各 i/f(i) の数
  vector<int> cnt(n+1);
  for(int i = 1; i <= n; i++) {
    int t = 0;
    for(int v: d[i]) if (sq[v]) t = v;
    cnt[i/t]++;
  }

  int ans = 0;
  // cnt個の重複順列 cnt[i]^2
  for(int v: cnt) ans += v*v;
  cout << ans << endl;
  return 0;
}