#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  mt19937_64 rng(58);
  REP(_,100) {
    int i = 0, j = 0;
    while(i == j) {
      i = rng() % n;
      j = rng() % n;
    }

    // 2点 i,j を通る直線は
    //  傾き = (y2-y1)/(x2-x1)
    // 任意の点(x,y) について傾きは同じとなるので
    //  (y-y1)/(x-x1) = (y2-y1)/(x2-x1) が成り立つ
    // 変形して
    //  (y-y1)*(x2-x1) = (y2-y1)*(x-x1)
    // 展開して
    //  x2*y - x1*y - x2*y1 + x1y1 = x*y2 - x1*y2 - x*y1 + x1+y1
    //  x2*y - x1*y - x2*y1 = x*y2 - x1*y2 - x*y1
    //  y(x2-x1) - x2*y1 = x(y2-y1) - x1*y2
    //  -x(y2-y1) + y(x2-x1) - x2*y1 + x1*y2 = 0
    //  (y1-y2)x + (x2-x1)y + (x1*y2 - y2*y1) = 0

    ll a = y[i] - y[j];
    ll b = x[j] - x[i];
    ll c = x[i] * y[j] - x[j] * y[i];

    int cnt = 0;
    REP(k,n) if (a * x[k] + b * y[k] + c == 0) cnt++;

    if (cnt * 2 > n) {
      cout << "Yes" << endl;
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}