#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<vector<int>> g;
vector<int> a,b,dp(100000);

void dfs(int cur, int pre) {
  dp[cur] = 1;
  for(int nv: g[cur]) {
    if (nv == pre) continue;
    dfs(nv, cur);
    dp[cur]+=dp[nv];
  }
  return;
}

void solve() {
  dfs(0, -1);

  ll ans = 0;
  REP(i,n) {
    ll r = min(dp[a[i]], dp[b[i]]);
    ans += r * (n-r);
  }
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  g.resize(n);
  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  solve();
  return 0;
}