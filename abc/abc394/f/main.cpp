#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = -1;
  // 木DP
  auto dfs = [&](auto& dfs, int v, int p) -> int {
    int res = 1;
    vector<int> d;
    for (int u: g[v]) if (u != p) d.push_back(dfs(dfs,u,v));

    sort(d.rbegin(),d.rend());
    if (d.size() >= 3) {
      // 頂点数の多い上位3つを選ぶ
      res = d[0]+d[1]+d[2]+1;
      // 4つ以上あるときは4つ目も選んで終わるケース
      if (d.size() >= 4) ans = max(ans,res+d[3]);
    }
    //
    if (d.size() >= 1) if (d[0]+1 >= 5) ans = max(ans,d[0]+1);
    return res;
  };

  dfs(dfs,0,-1);
  cout << ans << endl;
  return 0;
}
