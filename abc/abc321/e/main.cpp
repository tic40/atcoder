#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

void solve() {
  ll n,x,k; cin >> n >> x >> k;

  // 頂点 v から d 降りたところの頂点を求める
  auto f = [&](ll v, ll d) -> ll {
    if (v > n) return 0;
    ll l = v, r = v;
    REP(i,d) {
      l *= 2;
      r = r*2+1;
      if (l > n) return 0;
    }
    r = min(r,n);
    return r - l + 1;
  };

  // x から k 個降りたところの個数
  ll ans = f(x,k);

  // 登って降りる
  while(x > 1 && k >= 2) {
    // x ^ 1 することで
    ans += f(x^1, k-2);
    k--; x /= 2;
  }
  if (k == 1 && x != 1) ans++;
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}