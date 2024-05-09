#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  vector rg(n,vector<P>());
  vector<int> s(m),t(m);
  REP(i,m) {
    cin >> s[i] >> t[i];
    s[i]--; t[i]--;
    g[s[i]].emplace_back(t[i],i);
    rg[t[i]].emplace_back(s[i],i);
  }

  auto bfs = [&](int di = -1) {
    queue<P> q;
    q.emplace(0,0);
    vector<int> dist(n,INF);
    dist[0] = 0;

    while(q.size()) {
      auto [i,d] = q.front(); q.pop();
      if (dist[i] != d) continue;
      for(auto [v,idx]: g[i]) {
        if (idx == di) continue;
        if (dist[v] <= d+1) continue;
        q.emplace(v,d+1);
        dist[v] = d+1;
      }
    }
    return dist;
  };

  auto dist = bfs();
  set<int> st;
  auto dfs = [&](auto self, int i) -> void {
    if (i == 0) return;
    for(auto [v,idx]: rg[i]) {
      if (dist[v] == dist[i]-1) {
        st.insert(idx);
        self(self,v);
        break;
      }
    }
  };
  dfs(dfs,n-1);

  REP(i,m) {
    int ans = st.count(i) ? bfs(i)[n-1] : dist[n-1];
    cout << (ans == INF ? -1 : ans) << endl;
  }
  return 0;
}