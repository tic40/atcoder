#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,k;
vector<ll> a;

ll binary_search() {
  ll ok = 2 * INF;
  ll ng = 0;

  while (abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll cnt = 0;
    // 数列に含まれるmid以上の値はk個以下か
    REP(i,n) cnt += max(0LL, a[i]-mid+1);
    if (cnt <= k) ok = mid;
    else ng = mid;
  }
  return ok;
}


void solve() {
  sort(a.begin(), a.end());
  ll ans = 0;

  ll len = 0;
  REP(i,n) len += a[i];
  if (len < k) {
    REP(i,n) ans += a[i] * (a[i]+1) / 2;
  } else {
    ll m = binary_search();
    int cnt = 0;
    REP(i,n) {
      if (m <= a[i]) {
        ans += (a[i] + m) * (a[i]-m+1) / 2;
        cnt += a[i]-m+1;
      }
    }
    if (cnt < k) ans += (m-1) * (k-cnt);
  }

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