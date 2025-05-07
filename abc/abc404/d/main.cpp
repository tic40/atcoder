#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<int> c(n);
  REP(i,n) cin >> c[i];
  vector zoo(n,vector<int>());
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int a; cin >> a; a--;
      zoo[a].push_back(i);
    }
  }

  ll ans = LINF;
  vector<int> cnt(m);
  auto dfs = [&](auto dfs, int i, ll tot) {
    if (i == n) {
      REP(i,m) if (cnt[i] < 2) return;
      ans = min(ans,tot);
      return;
    }
    dfs(dfs,i+1,tot);
    for(auto v: zoo[i]) cnt[v]++;
    dfs(dfs,i+1,tot+c[i]);
    for(auto v: zoo[i]) cnt[v]++;
    dfs(dfs,i+1,tot+c[i]*2);
    for(auto v: zoo[i]) cnt[v]-=2;
  };
  dfs(dfs,0,0);
  cout << ans << endl;
  return 0;
}