#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;

  /*
    x = y+d を置くと
    x^3 - y^3 = (y+d)^3 - y^3
    これを展開すると
    y^3+3d^2y + 3dy^2 + d^3 - y^3
    = d^3 + 3dy(d+y)
    上記から、d^3 < n がわかるので、d^3 < n の範囲を全探索する

    d^3 + 3dy(d+y) = n
    3dy(y+d) = n-d^3
    y(y+d)   = (n-d^3)/3d
    y^2 + yd - (n-d^3)/3d = -0
    (n-d^3)/3d は定数なので、解の公式を使い
    ```
      ax^2 + bx + c = 0
      x = (-b +-√b^2-4ac) / 2a
    ```
   */

  // d*d*d < n を全探索
  for(ll d = 1; d*d*d < n; d++) {
    ll c = n-d*d*d;
    // c = (n-d^3)/3d なので、3d で割り切れないときは不可
    if (c%(3*d)) continue;
    c /= 3*d;
    // 解の公式で y を求める
    ll y = (-d + sqrt(d*d+4*c))/2;
    ll x = y+d;
    if (x*x*x-y*y*y == n) { cout << x << " " << y << endl; return 0; }
  }
  cout << -1 << endl;
  return 0;
}
