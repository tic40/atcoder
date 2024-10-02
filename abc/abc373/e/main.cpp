#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; ll k; cin >> n >> m >> k;
  vector<ll> A(n);
  REP(i,n) cin >> A[i];

  if (n == m) { REP(i,n) cout << 0 << " "; return 0; }

  auto a = A;
  sort(a.begin(),a.end());
  // 累積和
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  ll remain = k - accumulate(a.begin(),a.end(),0LL);
  map<int,ll> ans;
  REP(i,n) {
    auto judge = [&](ll x) {
      ll y = a[i]+x;
      int r = upper_bound(a.begin(),a.end(),y+1) - a.begin();
      int l = n-m;
      if (r < l) return false;
      ll need = (y+1)*(r-l) - (s[r]-s[l]);
      if (l <= i && i < r) {
        need += a[i];
        need -= a[l-1];
      }
      return need > remain-x;
    };

    ll ok = remain+1, ng = -1;
    while(ok-ng > 1) {
      ll mid = (ok+ng)/2;
      if (judge(mid)) ok = mid;
      else ng = mid;
    }
    if (ok == remain+1) ok = -1;
    ans[a[i]] = ok;
  }

  REP(i,n) cout << ans[A[i]] << " ";
  return 0;
}