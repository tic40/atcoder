#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  set<P> st;
  REP(i,m) {
    int x,y; cin >> x >> y;
    st.insert({x,y});
  }

  map<P,mint> dp;
  dp[{0,0}] = 1;

  REP(i,n) {
    map<P,mint> p;
    swap(dp,p);
    for(auto [t,v]: p) {
      auto [x,y] = t;
      if (st.count({x+a, y+b}) == 0) dp[{x+a, y+b}] += v;
      if (st.count({x+c, y+d}) == 0) dp[{x+c, y+d}] += v;
      if (st.count({x+e, y+f}) == 0) dp[{x+e, y+f}] += v;
    }
  }

  mint ans = 0;
  for(auto [_,v]: dp) ans += v;
  cout << ans.val() << endl;
  return 0;
}