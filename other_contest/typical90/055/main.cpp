#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,p,q;
vector<ll> a;
ll ans = 0;

void dfs(ll tot, int idx, int cnt) {
  if (cnt == 5) {
    if (tot == q) ans++;
    return;
  }
  if (n <= idx) return;

  dfs(tot, idx+1, cnt);
  dfs(tot*a[idx]%p, idx+1, cnt+1);
  return;
}

void solve() {
  dfs(1, 0, 0);
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> p >> q;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}