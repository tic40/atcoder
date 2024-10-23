#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n,k; cin >> n >> k;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto dfs = [&](auto self, int i, int p, int rest) -> mint {
    mint res = rest;
    int used = 1;
    if (i != 0) used++;
    for(auto v: g[i]) if (v != p) {
      res *= self(self,v,i,k-used);
      used++;
    }
    return res;
  };

  cout << dfs(dfs,0,-1,k).val() << endl;
  return 0;
}