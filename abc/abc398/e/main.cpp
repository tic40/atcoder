#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<P> es;
  REP(i,n-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    es.emplace_back(min(u,v),max(u,v));
  }

  vector<int> col(n,-1);
  queue<int> q;
  q.push(0);
  col[0] = 0;
  while(q.size()) {
    auto v = q.front(); q.pop();
    for(auto nv: g[v]) if (col[nv] == -1) {
      col[nv] = col[v]^1;
      q.push(nv);
    }
  }

  vector<int> x,y;
  REP(i,n) col[i] == 0 ? x.push_back(i) : y.push_back(i);
  int tot = x.size() * y.size() - (n-1);
  // 奇数なら先手が必勝
  cout << (tot%2 ? "First" : "Second") << endl;

  set<P> st;
  for(auto a: x) for(auto b: y) st.emplace(min(a,b),max(a,b));
  for(auto e: es) st.erase(e);
  int turn = tot%2;
  while(1) {
    if (turn == 1) {
      auto [u,v] = *st.begin();
      st.erase(st.begin());
      cout << u+1 << " " << v+1 << endl;
    }
    if (turn == 0) {
      int u,v; cin >> u >> v; u--; v--;
      if (u < 0) break;
      st.erase(P{min(u,v),max(u,v)});
    }
    turn ^= 1;
  }
  return 0;
}
