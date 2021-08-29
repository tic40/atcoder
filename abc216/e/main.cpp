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
  ll ok = 2 * INF, ng = 0;

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

  ll m = binary_search();
  ll ans = 0, cnt = 0;
  REP(i,n) {
    if (m <= a[i]) {
      ll d = a[i]-m+1;
      ans += (a[i] + m) * d / 2;
      cnt += d;
    }
  }
  if (cnt < k) ans += (m-1) * (k-cnt);

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