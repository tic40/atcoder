#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll r; cin >> r;
  auto in = [&](ll x, ll y) {
    // (i+0.5)^2 + (j+0.5)^2 <= r^2
    // 両辺を 4 倍する
    x = x*2+1;
    y = y*2+1;
    return x*x + y*y <= r*r*4;
  };

  ll ans = 0;
  ll x = 0;
  for(ll y = r; y >= 0; y--) {
    // x を一個ずらして計算するため +1 している
    while(in(x+1,y)) x++;
    ans += x;
  }
  ans *= 4;
  ans++; // 原点の正方形分を+1
  cout << ans << endl;
  return 0;
}