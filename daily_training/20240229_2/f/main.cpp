#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

struct V {
  int x,y;
  V(int x=0, int y=0): x(x),y(y) {};
  V operator-(const V& a) const { return V(x-a.x, y-a.y); }
  // V a との外積を計算する
  int cross(const V& a) const { return x*a.y - y*a.x; }
  // V a との位置関係
  // 1: 反時計周り, -1: 時計回り, 0: 一直線上
  int ccw (const V& a) const {
    int area = cross(a);
    if (area > 0) return 1; // 反時計周り
    if (area < 0) return -1; // 時計周り
    return 0; // 一直線上
  }
};

int main() {
  vector<V> p(4);
  REP(i,4) cin >> p[i].x >> p[i].y;

  bool ok = true;
  REP(i,4) {
    V A = p[i];
    V B = p[(i+1)%4];
    V C = p[(i+2)%4];
    V b = B-A, c = C-A;
    if (b.ccw(c) != 1) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}