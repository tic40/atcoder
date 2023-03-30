#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector<char> c(n);
  REP(i,n) cin >> c[i];
  vector g(n, vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // dp[i][j] := i頂点のとき
  // jが 0: aのみ, 1: bのみ, 2: a,b両方 が何通りあるか
  vector dp(n,vector<mint>(3));

  auto dfs = [&](int i, int p, auto self) -> void {
    // val1: a,b どちらか一方の数
    // val2: 全体の数
    // a,b 両方含む数: val2 - val1
    mint val1 = 1, val2 = 1;
    for(int v: g[i]) {
      if (v == p) continue;
      self(v,i,self);

      // 例えば今の頂点が a のとき
      // a だけの数は、v 頂点が aだけの場合と a,b 両方含むものを切ったとき
      val1 *= dp[v][c[i] == 'a' ? 0 : 1] + dp[v][2];
      // 全体の数は a だけ + b だけ + a,b 両方含む + a,b 両方含むを切ったとき
      val2 *= dp[v][0] + dp[v][1] + dp[v][2] * 2;
    }
    dp[i][c[i] == 'a' ? 0 : 1] = val1;
    dp[i][2] = val2 - val1;

    return;
  };

  dfs(0,-1,dfs);
  cout << dp[0][2].val() << endl;
  return 0;
}