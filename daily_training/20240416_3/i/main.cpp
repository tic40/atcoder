#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
template <class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n,m; cin >> n >> m;
  vector<P> p(m);
  REP(i,m) {
    int u,v; cin >> u >> v; u--; v--;
    p[i] = {u,v};
  }
  vector<int> w(n),a(n);
  REP(i,n) cin >> w[i];
  REP(i,n) cin >> a[i];

  // u > v のDAG(有向非巡回グラフ)
  vector g(n,vector<int>());
  for(auto [u,v]: p) {
    if (w[u] == w[v]) continue;
    if (w[u] < w[v]) swap(u,v);
    g[u].push_back(v);
  }

  // vs = w の重み順に昇順ソートしたもの
  vector<int> vs(n);
  REP(i,n) vs[i] = i;
  sort(vs.begin(),vs.end(),[&](int i, int j) { return w[i] < w[j]; });

  vector<int> dp(n); // dp[i] := i に1個コマがある状態からの手数のmax値
  for(int v: vs) {
    vector<int> dp2(w[v]); // dp2[i] := 重みの合計が i のときの dp[u] の合計のmax
    // v -> u の遷移で dp[v] を確定させる
    for(int u: g[v]) {
      // ナップザック問題のようなもの
      // 後ろから見ていくことで dp 配列を一つで済ませる
      // dp[u] の値はすでに確定している
      for(int j = w[v]-1; j >= w[u]; j--) chmax(dp2[j], dp2[j-w[u]] + dp[u]);
    }
    // v からの遷移分 + 1 する
    dp[v] = dp2[w[v]-1] + 1;
  }

  ll ans = 0;
  REP(i,n) ans += ll(a[i]) * dp[i];
  cout << ans << endl;
  return 0;
}