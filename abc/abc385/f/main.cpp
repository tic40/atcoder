#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct V {
  ll x,y;
  V(ll x=0, ll y=0): x(x),y(y) {};
  V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
  V operator+(const V& v) const { return V(*this) += v;}
  V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
  V operator-(const V& v) const { return V(*this) -= v;}
  V& operator*=(ll s) { x *= s; y *= s; return *this;}
  V operator*(ll s) const { return V(*this) *= s;}
  // 内積
  ll inner(const V& a) const { return x*a.x - y*a.y; }
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
  long double ans = -100;
  bool all = true;

  vector<V> conv;
  REP(i,n) {
    ll x,h; cin >> x >> h;
    V p(x,h);
    while(conv.size() >= 2) {
      V a = conv.back();
      V b = conv.end()[-2];
      // (py-ay)/(px-ax) < (py-by)/(px-bx)
      if ((p.y-a.y)*(p.x-b.x) < (p.y-b.y)*(p.x-a.x)) break;
      conv.pop_back();
    }
    if (conv.size() >= 1) {
      V a = conv.back();
      long double y = p.y + (long double)(a.y-p.y)*p.x/(p.x-a.x);
      if ((a.y-p.y)*p.x >= -p.y*(p.x-a.x)) all = false;
      ans = max(ans,y);
    }
    conv.push_back(p);
  }

  if (all) cout << -1 << endl;
  else printf("%.10Lf\n",ans);
  return 0;
}