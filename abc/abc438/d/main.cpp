#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n),c(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];

  vector<ll> sa(n+1),sb(n+1),sc(n+1);
  REP(i,n) sa[i+1] = sa[i] + a[i];
  REP(i,n) sb[i+1] = sb[i] + b[i];
  REP(i,n) sc[i+1] = sc[i] + c[i];

  vector<ll> suffixmax(n+1,-1e19);
  for(int i = n-1; i > 0; i--) {
    suffixmax[i] = max(sb[i] - sc[i], suffixmax[i+1]);
  }

  ll ans = 0;
  // x を固定
  for(int x = 1; x <= n-2; x++) {
    // sa[x] + (sb[y] - sb[x]) + (sc[n] - sc[y])
    // sa[x] - sb[x] + sb[y] - sc[y] + sc[n]
    // sb[y] - sc[y] を最大化したい
    ll now = 0;
    now = sa[x] - sb[x] + sc[n];
    now += suffixmax[x+1];
    ans = max(ans,now);
  }

  cout << ans << endl;
  return 0;
}
