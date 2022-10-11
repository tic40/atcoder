#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
  int n,q; cin >> n >> q;
  vector<ll> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  ll minX = LINF, maxX = -LINF;
  ll minY = LINF, maxY = -LINF;
  REP(i,n) {
    ll nx = x[i]-y[i];
    ll ny = x[i]+y[i];
    x[i] = nx;
    y[i] = ny;
    chmin(minX, nx);
    chmax(maxX, nx);
    chmin(minY, ny);
    chmax(maxY, ny);
  }

  REP(_,q) {
    int t; cin >> t;
    t--;
    ll ans = max({
      abs(minX - x[t]),
      abs(maxX - x[t]),
      abs(minY - y[t]),
      abs(maxY - y[t])
    });
    cout << ans << endl;
  }
  return 0;
}