#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a,b,dp;
vector<vector<int>> g;

void dfs(int cur, int pre) {
  dp[cur] = 1;
  for(int nv: g[cur]) {
    if (nv == pre) continue;
    dfs(nv, cur);
    dp[cur] += dp[nv];
  }
  return;
}

ll solve() {
  dfs(0, -1);
  ll ans = 0;
  REP(i,n-1) {
    ll r = min(dp[a[i]], dp[b[i]]);
    ans += r * (n-r);
  }
  return ans;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  g.resize(n);
  dp.resize(n);

  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  cout << solve() << endl;
  return 0;
}