#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // 累積和
  vector<ll> m(n+1);
  REP(i,n) m[i+1] = m[i] + a[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, LINF));

  // O(n^3)
  // dp[l][r]=(区間[l,r]に相当するスライムが1匹にまとまっているとき、それを分解するために必要な最小コスト)
  auto f = [&](auto self, int l, int r) {
    if (l == r) return 0LL;
    if (dp[l][r] != LINF) return dp[l][r];

    ll res = LINF;
    for(int i = l; i < r; i++) res = min(res, self(self,l,i) + self(self,i+1,r));
    return dp[l][r] = res + (m[r+1] - m[l]);
  };

  cout << f(f,0,n-1) << endl;
  return 0;
}
