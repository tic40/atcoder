#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,c; char _;
    cin >> a >> _ >> c >> _;
    a--; c--;
    g[a].push_back(c);
    g[c].push_back(a);
  }

  vector<bool> used(n);
  auto dfs = [&](int i, int p, auto dfs) {
    if (used[i]) return true;
    used[i] = true;

    bool res = false;
    for(int v: g[i]) {
      if (v == p) continue;
      res = res || dfs(v,i,dfs);
    }
    return res;
  };

  int x = 0, y = 0;
  REP(i,n) {
    if (!used[i]) dfs(i,-1,dfs) ? x++ : y++;
  }
  cout << x << " " << y << endl;
  return 0;
}