#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

struct Edge { int from; int to; ll cost; };
int n,m;
vector<Edge> edges;
ll dp[305][305];

void warshall_floyd(int n) {
  REP(k,n) { // 経由する頂点
    REP(i,n) { // 開始頂点
      REP(j,n) { // 終端
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  return;
}

void solve() {
  warshall_floyd(n);

  int ans = 0;
  for(auto [a,b,c]: edges) {
    int can_delete = 0;
    REP(j,n) {
      if (dp[a][j] + dp[j][b] <= c) can_delete = 1;
    }
    ans += can_delete;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) REP(j,n) dp[i][j] = LINF;
  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    dp[a][b] = c;
    dp[b][a] = c;
    edges.emplace_back(Edge{a,b,c});
  }

  solve();
  return 0;
}