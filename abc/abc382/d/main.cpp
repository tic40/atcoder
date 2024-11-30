#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a;
  vector<vector<int>> ans;

  auto dfs = [&](auto dfs) -> void {
    int sz = a.size();
    if (sz == n) { ans.push_back(a); return; }

    for(int i = sz ? a.back()+10 : 1; i <= m-(10*(n-1-sz)); i++) {
      a.push_back(i);
      dfs(dfs);
      a.pop_back();
    }
  };

  dfs(dfs);
  cout << ans.size() << endl;
  for(auto v: ans) {
    for(auto w: v) cout << w << " ";
    cout << endl;
  }
  return 0;
}