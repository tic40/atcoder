#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  auto dfs = [&](auto dfs, int i, int cnt, ll now) {
    if (cnt == k) { ans = max(ans,now); return; }
    if (i >= n) return;

    dfs(dfs,i+1,cnt,now);
    dfs(dfs,i+1,cnt+1,now^a[i]);
  };

  if (k <= n-k) {
    dfs(dfs,0,0,0);
  } else {
    ll allxor = 0;
    REP(i,n) allxor ^= a[i];
    dfs(dfs,0,k-(n-k),allxor);
  }
  cout << ans << endl;
  return 0;
}