#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // 二分探索で楽しさの値を探す
  ll ok = 2e9, ng = 0;
  while(ok - ng > 1) {
    ll mid = (ok+ng) / 2;
    ll cnt = 0;
    REP(i,n) cnt += max(0LL, a[i] - mid + 1);

    if (cnt <= k) ok = mid;
    else ng = mid;
  }

  ll p = ok;
  ll ans = 0, total = 0;
  REP(i,n) {
    if (p > a[i]) continue;
    int num = a[i] - p + 1;
    ans += (a[i] + p) * num / 2;
    total += num;
  }

  // 半端な分を計算する
  ans += (p - 1) * max(0LL, k - total);
  cout << ans << endl;
  return 0;
}