#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);

  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    deg[b]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  // 入次数が0のものをキューに入れる
  REP(i,n) if (deg[i] == 0) q.push(i);
  vector<int> ans;

  while(q.size()) {
    int v = q.top(); q.pop();
    ans.push_back(v);
    for(int nv: g[v]) {
      deg[nv]--;
      if (deg[nv] == 0) q.push(nv);
    }
  }

  if ((int)ans.size() == n) {
    for(int v: ans) cout << v+1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}