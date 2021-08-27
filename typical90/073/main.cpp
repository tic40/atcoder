#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int n;
vector<char> c;
vector<int> a,b;
vector<vector<int>> g;

// dp[pos][今の連結成分にどれがあるか] = 頂点posの部分木を考えたとき何通りか
// 2つ目については、0: 'a' しかない, 1: 'b' しかない, 2: 'a','b' 両方ある
int dp[100005][3];

void dfs(int pos, int pre) {
  ll val1 = 1, val2 = 1;
  for(int i: g[pos]) {
    if (i == pre) continue;

    dfs(i, pos);

    if (c[pos] == 'a') {
      val1 *= (dp[i][0] + dp[i][2]);
      val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
    } else {
			val1 *= (dp[i][1] + dp[i][2]);
			val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
    }
    val1 %= MOD;
    val2 %= MOD;
  }

  if (c[pos] == 'a') {
		dp[pos][0] = val1;
		dp[pos][2] = (val2 - val1 + MOD) % MOD;
  } else {
		dp[pos][1] = val1;
		dp[pos][2] = (val2 - val1 + MOD) % MOD;
  }

  return;
}


int main() {
  cin >> n;
  c.resize(n);
  g.resize(n);

  REP(i,n) cin >> c[i];
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1, -1);
  cout << dp[1][2] << endl;
  return 0;
}