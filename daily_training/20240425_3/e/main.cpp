#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

struct V {
  ll x,y;
  V(ll x=0, ll y=0): x(x),y(y) {};
  V operator-(const V& a) const { return V(x-a.x, y-a.y); }
  // 外積
  ll cross(const V& a) const { return x*a.y - y*a.x; }
  // ccw: counter clockwise
  ll ccw (const V& a) const {
    ll area = cross(a);
    if (area > 0) return 1; // 反時計周り
    if (area < 0) return -1; // 時計周り
    return 0; // 一直線上
  }
};

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  int ans = 0;
  REP(i,n) {
    for(int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        V v1 = V(x[i],y[i]);
        V v2 = V(x[j],y[j]);
        V v3 = V(x[k],y[k]);
        v2 = v2 - v1;
        v3 = v3 - v1;
        ll vol = v2.cross(v3);
        if (vol != 0) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}