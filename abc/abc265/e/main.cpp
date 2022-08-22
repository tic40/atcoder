#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m; cin >> n >> m;
  int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

  set<P> st;
  REP(i,m) {
    int x,y; cin >> x >> y;
    st.emplace(x,y);
  }

  map<P,mint> mp;
  mp[{0,0}] = 1;
  REP(i,n) {
    map<P,mint> p;
    swap(mp,p);
    for(auto [k,v]: p) {
      auto [nx,ny] = k;
      if (st.count({nx+a, ny+b}) == 0) {
        mp[{nx+a,ny+b}] += v;
      }
      if (st.count({nx+c, ny+d}) == 0) {
        mp[{nx+c,ny+d}] += v;
      }
      if (st.count({nx+e, ny+f}) == 0) {
        mp[{nx+e,ny+f}] += v;
      }
    }
  }

  mint ans = 0;
  for(auto [k,v]: mp) ans += v;
  cout << ans.val() << endl;
  return 0;
}