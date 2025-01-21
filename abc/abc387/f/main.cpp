#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  // 強連結成分分解
  scc_graph g(n);
  REP(i,n) g.add_edge(i,a[i]);
  // グループに分割
  auto groups = g.scc();

  // gid[i] := 頂点 i のグループ id
  vector<int> gid(n);
  int s = groups.size();
  REP(i,s) for(int v: groups[i]) gid[v] = i;

  // pa[i] := 頂点 i の親のグループ番号
  vector<int> pa(s,s);
  REP(i,n) {
    int u = gid[i];
    int v = gid[a[i]];
    if (u == v) continue; // 同じグループ
    pa[u] = v;
  }

  // 木DP
  // dp[v][i] := グループ v 以下の部分木を決めて、x[v] が i 以下である場合の数
  vector dp(s+1,vector<mint>(m,1));
  // グループ毎に見ていく
  // scc_graph のグループはトポロジカル順になっているので、昇順にみていけば下から走査できる
  REP(i,s) {
    // 累積和を取る
    REP(j,m-1) dp[i][j+1] += dp[i][j];
    // 親の j に掛ける
    REP(j,m) dp[pa[i]][j] *= dp[i][j];
  }
  cout << dp[s][m-1].val() << endl;
  return 0;
}