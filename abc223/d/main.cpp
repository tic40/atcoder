#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

int n,m;
vector<vector<int>> to;
vector<int> deg;

void solve() {
  priority_queue<int,vector<int>,greater<int>> q;
  REP(i,n) if (deg[i] == 0) q.push(i);
  vector<int> ans;
  while(q.size()) {
    int v = q.top(); q.pop();
    ans.push_back(v);
    for (int u: to[v]) {
      deg[u]--;
      if (deg[u] == 0) q.push(u);
    }
  }

  if ((int)ans.size() != n) cout << -1 << endl;
  else {
    for(int v: ans) cout << v+1 << " ";
  }
  return;
}

int main() {
  cin >> n >> m;
  to.resize(n);
  deg.resize(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    deg[b]++;
  }

  solve();
  return 0;
}