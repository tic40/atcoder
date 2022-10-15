#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<vector<int>> g(1e5);
vector<int> dp(1e5);

int dfs(int i, int p) {
  int now = 1;
  for(int v: g[i]) {
    if (v == p) continue;
    now += dfs(v,i);
  }
  return dp[i] = now;
}

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  dfs(0,-1);
  ll ans = 0;
  // 辺ごとに通る数を合算する
  REP(i,n-1) {
    // 貢献度が小さい方が部下にあたる頂点
    ll r = min(dp[a[i]], dp[b[i]]);
    ans += r * (n-r);
  }
  cout << ans << endl;
  return 0;
}