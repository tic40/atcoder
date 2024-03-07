#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int n2 = n*2;
  vector g(n2+2,vector<int>());
  for(int i = 1; i <= n; i++) {
    int a; cin >> a;
    g[a].push_back(2*i);
    g[a].push_back(2*i+1);
  }

  vector<int> ans(n2+2);
  auto dfs = [&](auto self, int i, int depth = 0) -> void {
    ans[i] = depth;
    for(auto v: g[i]) self(self,v,depth+1);
  };
  dfs(dfs,1);
  for(int i = 1; i <= n2+1; i++) cout << ans[i] << endl;
  return 0;
}