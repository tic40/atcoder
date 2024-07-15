#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct Vector {
  int x,y;
  Vector(int x = 0, int y = 0): x(x),y(y) {}
  Vector operator-(const Vector& v) const {
    return Vector(x-v.x, y-v.y);
  }
  int dot(const Vector& v) const {
    return x*v.x + y*v.y;
  }
};

int main() {
  // 三平方の定理から求める
  auto solve1 = [&]() {
    vector<int> x(3),y(3);
    REP(i,3) cin >> x[i] >> y[i];

    int a = pow(x[0]-x[1],2) + pow(y[0]-y[1],2);
    int b = pow(x[1]-x[2],2) + pow(y[1]-y[2],2);
    int c = pow(x[2]-x[0],2) + pow(y[2]-y[0],2);

    bool yes = a + b == c || b + c == a || c + a == b;
    cout << (yes ? "Yes" : "No") << endl;
  };

  // ベクトルの内積から求める
  auto solve2 = [&]() {
    Vector a,b,c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    bool ok = false;
    REP(i,3) {
      if ((b-a).dot(c-a) == 0) ok = true;
      swap(a,b); swap(b,c);
    }
    cout << (ok ? "Yes" : "No") << endl;
  };

  solve2();
  return 0;
}