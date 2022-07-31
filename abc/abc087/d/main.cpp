#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<vector<P>> g(n+1);
  REP(i,m) {
    int l,r,d; cin >> l >> r >> d;
    l--; r--;
    g[l].emplace_back(r, d);
    g[r].emplace_back(l, -d);
  }

  queue<P> q;
  vector<int> dist(n,INF);
  bool ok = true;

  REP(i,n) {
    if (dist[i] != INF) continue;
    q.push({i,0});
    dist[i] = 0;

    while(q.size()) {
      auto now = q.front(); q.pop();
      for(auto v: g[now.first]) {
        int np = v.first;
        int nd = dist[now.first] + v.second;
        if (dist[np] == INF) {
          dist[np] = nd;
          q.push(v);
        } else {
          if (dist[np] != nd) ok = false;
        }
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}