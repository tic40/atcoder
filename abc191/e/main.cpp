#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,int>;
using edge = struct { int to; int cost; };
const int INF = 1e9;

int n,m;
vector<int> a,b,c;
vector<vector<edge>> g;

void solve(int s) {
  vector<int> d(n+5, INF);
  priority_queue<P, vector<P>, greater<P>> que;
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    REP(i,g[v].size()) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }

  int ans = INF;
  REP(i,n) {
    if (d[i] == INF) continue;
    for(auto x: g[i]) {
      if (x.to == s) ans = min(ans, d[i] + x.cost);
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return;
}

int main() {
  cin >> n >> m;
  a.resize(m); b.resize(m); c.resize(m);
  g.resize(n);

  REP(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    edge e = { b[i], c[i] };
    g[a[i]].emplace_back(e);
  }

  REP(i,n) solve(i);
  return 0;
}