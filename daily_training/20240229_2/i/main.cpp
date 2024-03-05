#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const ll LINF = numeric_limits<ll>::max();

// ベクトル型 構造体
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
  vector<P> p;
  REP(i,n) {
    int x,y; cin >> x >> y;
    p.emplace_back(x,y);
  }

  auto f = [&](int i, int j, int k) {
    i %= n; j %= n; k %= n;
    auto [x1,y1] = p[i];
    auto [x2,y2] = p[j];
    auto [x3,y3] = p[k];
    V v1 = V(x1,y1);
    V v2 = V(x2,y2);
    V v3 = V(x3,y3);
    // 三角形の面積の2倍を返す
    return (v2-v1).cross(v3-v1);
  };

  // 全体の面積
  ll tot = 0;
  for(int j = 2; j < n; j++) tot += f(0,j-1,j);

  ll s = 0, ans = LINF;
  int j = 1;
  REP(i,n) {
    while(s < tot) {
      s += f(i,j,j+1) * 4;
      ans = min(ans,abs(tot-s));
      j++;
    }
    s -= f(i,i+1,j) * 4;
    ans = min(ans,abs(tot-s));
  }
  cout << ans << endl;
  return 0;
}