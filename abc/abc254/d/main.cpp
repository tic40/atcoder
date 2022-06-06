#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

void solve1(int n) {
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
  return;
}

void solve2(int n) {
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int k = i;
    for(int p = 2; p*p <= k; p++) {
      while(k % (p*p) == 0) k /= (p*p);
    }
    // 平方数で割れるだけ割って残った数がkになっている
    // k*j が平方数になるには、k*k、k*k*(平方数)が条件となるので、それをカウントする
    for (int p = 1; k*(p*p) <= n; p++) ans++;
  }
  cout << ans << endl;
  return;
}

int main() {
  int n; cin >> n;
  // solve1(n);
  solve2(n);

  return 0;
}
