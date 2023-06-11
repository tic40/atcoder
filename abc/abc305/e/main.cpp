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
  vector<P> pa(k);
  REP(i,k) {
    int p,h; cin >> p >> h;
    p--;
    pa[i] = {h,p};
  }
  sort(pa.rbegin(),pa.rend()); // h の多い順にソート
  vector<int> mx(n,-1); // mx[i] := 頂点 i に訪問したときの 「警備員の体力 h - 頂点 i までの距離」 の最大値

  auto bfs = [&](int h, int i) -> void {
    queue<P> q;
    q.emplace(i,h);
    while(q.size()) {
      auto [ni,nh] = q.front(); q.pop();
      if (mx[ni] >= nh) continue;
      mx[ni] = nh;
      for(auto nv: g[ni]) q.emplace(nv,nh-1);
    }
  };

  for(auto [h,p]: pa) bfs(h,p);
  vector<int> ans;
  REP(i,n) if (mx[i] != -1) ans.push_back(i+1);
  cout << ans.size() << endl;
  for(int v: ans) cout << v << " ";
  return 0;
}