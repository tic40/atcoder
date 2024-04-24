#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<int> t(n);
  REP(i,n) {
    cin >> t[i];
    int k; cin >> k;
    REP(j,k) {
      int a; cin >> a;
      a--;
      g[i].push_back(a);
    }
  }

  vector<int> used(n);
  auto dfs = [&](auto self, int i, int p) -> ll {
    if (used[i]) return 0;
    used[i] = 1;
    ll res = t[i];
    for(auto v: g[i]) {
      if (v == p) continue;
      res += self(self,v,i);
    }
    return res;
  };

  cout << dfs(dfs,n-1,-1) << endl;
  return 0;
}