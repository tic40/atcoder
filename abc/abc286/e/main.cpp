#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,ll>;
const int INF = 1e9;

vector dp(305, vector<P>(305));
void warshall_floyd(int n) {
  REP(k,n) REP(i,n) REP(j,n) {
    int nd = dp[i][k].first + dp[k][j].first;
    ll nc = dp[i][k].second + dp[k][j].second;

    if (dp[i][j].first > nd) {
      dp[i][j] = { nd, nc };
    } else if (dp[i][j].first == nd) {
      dp[i][j] = { dp[i][j].first, max(dp[i][j].second, nc) };
    }
  }
  return;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<string> s(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> s[i];
  int q; cin >> q;

  REP(i,n) REP(j,n) {
    int c = s[i][j] == 'Y' ? 1 : INF;
    dp[i][j] = {c,a[j]};
  }
  warshall_floyd(n);

  REP(_,q) {
    int u,v; cin >> u >> v;
    u--, v--;
    if (dp[u][v].first == INF) {
      cout << "Impossible" << endl;
    } else {
      cout << dp[u][v].first << " " << a[u] + dp[u][v].second << endl;
    }
  }

  return 0;
}