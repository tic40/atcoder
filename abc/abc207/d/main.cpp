#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,int>;
struct C {
  int x,y;
  C(int x=0, int y=0) : x(x), y(y) {}
  C operator*(const C& a) const {
    return C(x*a.x - y*a.y, x*a.y + y*a.x);
    // (x+yi) * (a.x + a.yi)
  }
  C operator-(const C& a) const {
    return C(x-a.x, y-a.y);
  }
  bool operator<(const C& a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  };
  bool operator==(const C& a) const {
    return x == a.x && y == a.y;
  };
  int norm() const { return x*x + y*y; }
};

int main() {
  int n;
  cin >> n;
  vector<C> a(n), b(n);
  REP(i,n) {
    int x,y;
    cin >> x >> y;
    a[i] = C(x,y);
  }
  REP(i,n) {
    int x,y;
    cin >> x >> y;
    b[i] = C(x,y);
  }

  if (n == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  REP(i,n) REP(j,n) {
    if (i == j) continue;
    // 長さが異なっていたらスキップ
    if ( (a[1]-a[0]).norm() != (b[j]-b[i]).norm() ) continue;

    // 原点に移動する
    auto f = [&](vector<C> p, C o, C r) {
      REP(i,n) p[i] = p[i]-o; // 原点に移動
      REP(i,n) p[i] = p[i]*r; // 回転
      // ソートする
      sort(p.begin(), p.end());
      return p;
    };

    vector<C> na = f(a, a[0], b[j]-b[i]);
    vector<C> nb = f(b, b[i], a[1]-a[0]);
    if (na == nb) { // 一致したらok
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}