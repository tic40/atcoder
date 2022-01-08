#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,m;
vector<int> a,x,y;
vector<int> dp; // dp[i]: 街iに到達できる街(街i自身を含まない)における金の最安値

void solve() {
  dp.resize(n,INF*2);
  vector<vector<int>> g(n);

  REP(i,m) g[x[i]].push_back(y[i]);

  REP(i,n) {
    for(auto v: g[i]) {
      dp[v] = min(min(dp[i],dp[v]), a[i]);
    }
  }

  int ans = -INF;
  REP(i,n) ans = max(ans, a[i]-dp[i]);

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  a.resize(n);
  REP(i,n) cin >> a[i];
  x.resize(m); y.resize(m);
  REP(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  solve();
  return 0;
}