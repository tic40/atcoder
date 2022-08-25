#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

// 拡張ユークリッドの互除法
// {g,x,y}: ax + by = g
tuple<ll,ll,ll> extgcd(ll a, ll b) {
  if (b == 0) return {a,1,0};
  ll g,x,y;
  tie(g,x,y) = extgcd(b, a%b);
  return { g, y, x-a/b*y };
}

int main() {
  int t; cin >> t;
  REP(i,t) {
    ll n,s,k; cin >> n >> s >> k;
    ll g,x,y;
    // s + k*x ≡ 0 mod n
    // k*x ≡ -s mod n
    // k*x + n*y = g に変形できる
    // g, x, y を求める
    tie(g,x,y) = extgcd(k,n);
    if (s%g != 0) {
      cout << -1 << endl;
      continue;
    }
    n /= g; s /= g; k /= g;
    ll ans = ((x * -s) % n + n) % n;
    cout << ans << endl;
  }
  return 0;
}