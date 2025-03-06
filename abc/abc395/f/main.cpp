#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x; cin >> n >> x;
  vector<ll> u(n),d(n);
  REP(i,n) cin >> u[i] >> d[i];

  auto f = [&](ll h) -> bool {
    ll l = 0, r = h; // 1個前の範囲をl,rで持つ
    REP(i,n) {
      if (u[i]+d[i] < h) return false;

      // nl: uが取れる最小の値
      // h-d[i] より小さくすると u[i]+d[i] = h が不可能になるためこれが最小
      ll nl = max(h-d[i],0LL);
      // nr: u が取れる最大の値
      // u[i] より長くすることはできないので u[i] が最大
      ll nr = min(u[i],h);

      nl = max(nl,l-x);
      nr = min(nr,r+x);
      // l > r のときは条件を満たせない
      if (nl > nr) return false;
      l = nl; r = nr;
    }
    return true;
  };

  ll ok = 0, ng = 2e9+1;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }

  ll ans = 0;
  REP(i,n) ans += (u[i]+d[i])-ok;
  cout << ans << endl;
  return 0;
}
