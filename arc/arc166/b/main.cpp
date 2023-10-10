#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  ll n,a,b,c; cin >> n >> a >> b >> c;
  vector<ll> x(n);
  REP(i,n) cin >> x[i];
  ll ab = lcm(a,b);
  ll ac = lcm(a,c);
  ll bc = lcm(b,c);
  ll abc = lcm(ab,c);
  vector<ll> r = { 1, a, b, ab, c, ac, bc, abc };

  auto f = [](ll x, ll y) -> ll { return (y - (x%y)) % y; };

  vector dp(n+1,vector<ll>(1<<3,2e18));
  dp[0][0] = 0;
  REP(i,n) REP(bit,1<<3) REP(j,(int)r.size()) {
    chmin(dp[i+1][bit | j], dp[i][bit] + f(x[i],r[j]));
  }

  cout << dp[n][(1<<3) - 1] << endl;
  return 0;
}