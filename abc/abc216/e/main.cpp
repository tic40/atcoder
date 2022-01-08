#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,k;
vector<ll> a;

ll binary_search() {
  ll ok = 2*1e9; // k回以下乗れるときの数
  ll ng = 0; // k回以下乗れないときの数

  while (abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll cnt = 0; // 選んだ数
    REP(i,n) cnt += max(0LL, a[i]-mid+1);

    if (cnt <= k) ok = mid;
    else ng = mid;
  }
  return ok;
}

void solve() {
  sort(a.begin(), a.end());
  ll p = binary_search();

  ll ans = 0;
  int cnt = 0;
  REP(i,n) {
    if (p <= a[i]) {
      ans += (a[i] + p) * (0, a[i]-p+1) / 2;
      cnt += a[i] - p + 1;
    }
  }
  if (0 < k-cnt) ans += (p-1) * (k-cnt);

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}