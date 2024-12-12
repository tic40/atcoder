#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,ll>;
const int INF = 1e9;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector dp(n,vector<P>(n,{INF,0}));
  REP(i,n) REP(j,n) if (s[i][j] == 'Y') dp[i][j] = P(1,a[j]);

  REP(k,n) REP(i,n) REP(j,n) {
    int nd = dp[i][k].first + dp[k][j].first;
    ll ns = dp[i][k].second + dp[k][j].second;
    if (dp[i][j].first > nd) {
      dp[i][j] = P(nd,ns);
    } else if (dp[i][j].first == nd) {
      dp[i][j].second = max(dp[i][j].second, ns);
    }
  }

  int q; cin >> q;
  REP(i,q) {
    int u,v; cin >> u >> v; u--; v--;
    auto [dist,val] = dp[u][v];
    if (dist == INF) cout << "Impossible" << endl;
    else cout << dist << " " << val + a[u] << endl;
  }
  return 0;
}