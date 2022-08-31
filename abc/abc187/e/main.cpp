#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<vector<int>> g(2e5);
vector<int> depth(2e5);
vector<ll> dp(2e5);

void dfs(int now, int d, int p) {
  depth[now] = d;
  for(int v: g[now]) if (v != p) dfs(v,d+1,now);
  return;
}

void acc_dfs(int now, ll pv, int p) {
  dp[now] += pv;
  for(int v: g[now]) if (v != p) acc_dfs(v,dp[now],now);
  return;
}

int main() {
  int n; cin >> n;
  vector<int> a(n-1),b(n-1),c(n);
  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  dfs(0,0,-1);
  int q; cin >> q;
  REP(i,q) {
    int t,e,x; cin >> t >> e >> x;
    e--;
    int ae = a[e], be = b[e];
    if (t == 2) swap(ae,be);

    if (depth[ae] < depth[be]) {
      dp[0] += x;
      dp[be] -= x;
    } else {
      dp[ae] += x;
    }
  }

  // 累積和の集計
  acc_dfs(0,0,-1);

  REP(i,n) cout << dp[i] << endl;
  return 0;
}