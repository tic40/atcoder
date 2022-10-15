#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,k; cin >> n >> k;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector dist(n,vector<ll>(n));
  REP(i,n) REP(j,n) dist[i][j] = powl(x[i]-x[j],2) + powl(y[i]-y[j],2);

  // s[bit] := 集合がbitのときの2点間の最大値
  vector<ll> s(1<<n);
  REP(bit,1<<n) REP(i,n) REP(j,n) {
    if (bit >> i & 1 && bit >> j & 1) {
      s[bit] = max(s[bit], dist[i][j]);
    }
  }

  // dp[i][j]: [何個のグループ数に分けたときか][すでに選んだ点の集合(bit)]
  vector<ll> dp(1<<n, LINF);
  dp[0] = 0;
  REP(i,k) {
    vector<ll> p(1<<n, LINF);
    swap(dp,p);
    REP(bit,1<<n) {
      for(int j = bit; j > 0; j = (j-1) & bit) {
        dp[bit] = min(dp[bit], max(p[bit-j], s[j]));
      }
    }
  }

  cout << dp[(1<<n)-1] << endl;
  return 0;
}