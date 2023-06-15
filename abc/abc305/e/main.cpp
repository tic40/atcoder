#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> d(n,-1);
  priority_queue<P> q;
  REP(i,k) {
    int p,h; cin >> p >> h;
    p--;
    d[p] = h;
    q.emplace(h,p);
  }

  while(q.size()) {
    auto [h,v] = q.top(); q.pop();
    if (d[v] != h) continue;
    for(int u: g[v]) {
      if (d[u] >= h-1) continue;
      d[u] = h-1;
      q.emplace(h-1,u);
    }
  }

  vector<int> ans;
  REP(i,n) if (d[i] >= 0) ans.push_back(i+1);
  cout << ans.size() << endl;
  for(int v: ans) cout << v << " ";
  return 0;
}