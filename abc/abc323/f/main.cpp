#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll ax,bx,cx,ay,by,cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  // cx,cy を 原点(0,0) にする
  ax -= cx; bx -= cx;
  ay -= cy; by -= cy;

  // 荷物を第一象限へ移動しておく
  if (bx < 0) ax *= -1, bx *= -1;
  if (by < 0) ay *= -1, by *= -1;
  if (by == 0) swap(ax,ay), swap(bx,by);

  // (ax,ay) -> (x,y) の移動距離
  auto dist = [&](ll x, ll y) -> ll {
    if (ax == x && ay == y) return 0;
    ll res = abs(ax-x) + abs(ay-y);
    if (ax == x && ax == bx) {
      if ((ay < by) != (y < by)) res += 2;
    }
    if (ay == y && ay == by) {
      if ((ax < bx) != (x < bx)) res += 2;
    }
    return res;
  };

  if (bx == 0) {
    ll ans = dist(bx,by+1) + by;
    cout << ans << endl;
    return 0;
  }

  ll ans = min(dist(bx,by+1), dist(bx+1,by));
  ans += bx+by+2;
  cout << ans << endl;
  return 0;
}