#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  auto dfs = [&](auto& dfs, int i, int cnt, ll now) -> void {
    if (cnt == k) { ans = max(ans,now); return; }
    if (i == n) return;

    dfs(dfs,i+1,cnt,now);
    dfs(dfs,i+1,cnt+1,now^a[i]);
  };

  if (n-k >= k) {
    dfs(dfs,0,0,0);
  } else {
    ll allxor = 0;
    REP(i,n) allxor ^= a[i];
    dfs(dfs,0,k-(n-k),allxor);
  }
  cout << ans << endl;
  return 0;
}