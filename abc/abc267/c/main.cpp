#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> ac(n+1); // 累積和
  REP(i,n) ac[i+1] = ac[i] + a[i];

  ll now = 0;
  REP(i,m) now += a[i] * (i+1);
  ll ans = now;
  for(int i = 1; i < n-m+1; i++) {
    now -= ac[i+m-1] - ac[i-1];
    now += a[i+m-1] * m;
    ans = max(ans,now);
  }

  cout << ans << endl;
  return 0;
}