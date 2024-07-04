#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[l][r] := 区間 [l,r] からスタートしたときのの最適な値
  vector dp(n,vector<ll>(n, LINF));
  auto dfs = [&](auto self, int l, int r) {
    if (l > r) return 0LL;
    if (dp[l][r] != LINF) return dp[l][r];

    ll res = -LINF;
    res = max(res, -self(self, l+1, r) + a[l]);
    res = max(res, -self(self, l, r-1) + a[r]);

    return dp[l][r] = res;
  };

  cout << dfs(dfs,0,n-1) << endl;
  return 0;
}