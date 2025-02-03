#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> xs;
  vector<vector<int>> g;
  auto dfs = [&](auto& dfs, int i) -> void {
    if (i == n) {
      ll x = 0;
      REP(j,(int)g.size()) {
        ll sum = 0;
        for(int ni: g[j]) sum += a[ni];
        x ^= sum;
      }
      xs.push_back(x);
      return;
    }

    REP(j,(int)g.size()) {
      g[j].push_back(i);
      dfs(dfs,i+1);
      g[j].pop_back();
    }
    g.push_back(vector<int>(1,i));
    dfs(dfs,i+1);
    g.pop_back();
  };
  dfs(dfs,0);

  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  cout << xs.size() << endl;
  return 0;
}