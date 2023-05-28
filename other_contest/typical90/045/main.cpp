#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmax(T& a, T b) { a = max(a,b); }
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,k; cin >> n >> k;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector dist(n,vector<ll>(n));
  REP(i,n) REP(j,n) dist[i][j] = powl(x[i]-x[j],2) + powl(y[i] - y[j],2);

  // s[bit] := 集合がbitのときの2点間の最大値
  vector<ll> s(1<<n);
  REP(bit,1<<n) REP(i,n) REP(j,n) {
    if ((bit>>i&1) && (bit>>j&1)) chmax(s[bit], dist[i][j]);
  }

  // dp[i][j]: [何個のグループ数に分けたときか][すでに選んだ点の集合(bit)]
  vector<ll> dp(1<<n,LINF);
  dp[0] = 0;
  REP(i,k) {
    vector<ll> p(1<<n,LINF);
    swap(dp,p);
    REP(bit, 1<<n) {
      // bit の 部分集合
      for(int pbit = bit; pbit > 0; pbit = (pbit-1) & bit) {
        chmin(dp[bit], max(p[bit - pbit], s[pbit]));
      }
    }
  }
  cout << dp[(1<<n)-1] << endl;
  return 0;
}