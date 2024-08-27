#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> v(k);
  REP(i,k) { cin >> v[i]; v[i]--; }
  vector<int> m(n);
  REP(i,k) m[v[i]] = 1;

  set<int> ans;
  auto dfs = [&](auto self, int i, int p) -> int {
    int res = m[i];
    for(auto v: g[i]) if (v != p) res |= self(self,v,i);
    if (res) ans.insert(i);
    return res;
  };

  dfs(dfs,v[0],-1);
  cout << ans.size() << endl;
  return 0;
}