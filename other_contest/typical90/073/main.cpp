#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

vector<char> c(1e5);
vector<vector<int>> g(1e5);
// dp[i][j(今の連結成分にどれがあるか)] := 頂点iの部分木を考えたとき何通りか
// j := 0: 'a' しかない, 1: 'b' しかない, 2: 'a','b' 両方ある
vector dp(1e5, vector<mint>(3));

void dfs(int i, int p) {
  // val1: a or b 片方だけ含む数
  // val2: 全体の数
  // val2 - val1 = a,b 両方含む数
  mint val1 = 1, val2 = 1;

  for(int v: g[i]) {
    if (v == p) continue;
    dfs(v,i);

    if (c[i] == 'a') {
      // 今いる場所が a のとき
      // dp[v][0]: 切らない
      // dp[v][2]: 切る
      val1 *= (dp[v][0] + dp[v][2]);
    } else {
      val1 *= (dp[v][1] + dp[v][2]);
    }
    // 全体の数
    // dp[v][0]: 切らない
    // dp[v][1]: 切らない
    // dp[v][2]*2: 切らない分と切る分
    val2 *= (dp[v][0] + dp[v][1] + dp[v][2]*2);
  }

  if (c[i] == 'a') dp[i][0] = val1;
  else dp[i][1] = val1;

  dp[i][2] = val2 - val1;
  return;
}

int main() {
  int n; cin >> n;
  REP(i,n) cin >> c[i];
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0,-1);
  cout << dp[0][2].val() << endl;

  return 0;
}