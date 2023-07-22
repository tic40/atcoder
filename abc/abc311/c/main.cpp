#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  REP(i,n) {
    int a; cin >> a; a--;
    g[i].push_back(a);
  }

  vector<int> dir;
  vector<bool> used(n);
  auto dfs = [&](auto self, int i) -> void {
    if (used[i]) return;
    used[i] = true;
    for(auto v: g[i]) self(self,v);
    dir.push_back(i);
  };

  REP(i,n) {
    dir = vector<int>();
    dfs(dfs,i);
    if (dir.size() == 1) continue;
    cout << dir.size() << endl;
    reverse(dir.begin(),dir.end());
    for(auto v: dir) cout << v+1 << " ";
    break;
  }
  return 0;
}