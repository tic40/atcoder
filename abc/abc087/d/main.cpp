#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<int> l(m),r(m),d(m);
  REP(i,m) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--; r[i]--;
  }

  vector<vector<P>> g(n+1);
  REP(i,m) {
    g[l[i]].emplace_back(r[i], d[i]);
    g[r[i]].emplace_back(l[i], -d[i]);
  }
  queue<P> q;
  vector<int> dist(n,INF);

  REP(i,n) {
    if (dist[i] != INF) continue;
    q.push({i,0});
    dist[i] = 0;

    while(q.size()) {
      auto v = q.front(); q.pop();
      for(auto w: g[v.first]) {
        int np = w.first;
        int nd = dist[v.first] + w.second;
        if (dist[np] == INF) {
          dist[np] = nd;
          q.push(w);
        } else {
          if (dist[np] != nd) {
            cout << "No" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}