#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,t,m; cin >> n >> t >> m;
  vector c(n,vector<int>(n)); // c[i][j] := i,j の相性が悪いかどうか
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    c[a][b] = c[b][a] = 1;
  }

  vector g(t,vector<int>()); // チームに所属しているメンバー情報
  auto dfs = [&](auto self, int i) -> int {
    if (i == n) {
      REP(j,t) if (g[j].size() == 0) return 0;
      return 1;
    }

    int res = 0;
    REP(j,t) {
      bool ok = true; // j チームに i を追加可能かどうか
      for(auto v: g[j]) if (c[i][v]) ok = false;
      if (!ok) continue;

      g[j].push_back(i);
      res += self(self,i+1);
      g[j].pop_back();
      if (g[j].size() == 0) break;
    }
    return res;
  };

  cout << dfs(dfs, 0) << endl;
  return 0;
}