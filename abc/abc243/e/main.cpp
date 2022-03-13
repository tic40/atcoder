#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18+5;
struct Edge { int a; int b; int c; };

int main() {
  int n,m; cin >> n >> m;
  vector<Edge> edges(m);
  vector<vector<ll>> dp(n, vector<ll> (n, LINF));
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    dp[a][b] = dp[b][a] = c;
    edges[i] = {a,b,c};
  }

  REP(k,n) REP(i,n) REP(j,n) { // warshall_floyd
    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
  }

  int ans = 0;
  for(auto [a,b,c]: edges) {
    REP(i,n) if (dp[a][i] + dp[i][b] <= c) { ans++; break; }
  }
  cout << ans << endl;
  return 0;
}