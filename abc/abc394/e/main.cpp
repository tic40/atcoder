#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<string> c(n);
  REP(i,n) cin >> c[i];

  vector dist(n,vector<int>(n,INF));
  queue<P> q;
  auto push = [&](int s, int t, int d) -> void {
    if (dist[s][t] <= d) return;
    dist[s][t] = d;
    q.emplace(s,t);
  };

  REP(i,n) push(i,i,0);
  REP(i,n) REP(j,n) if (c[i][j] != '-') push(i,j,1);

  while(q.size()) {
    auto [s,t] = q.front(); q.pop();
    // s -> t のパス(回文)から
    // ns -> s -> t -> nt のパス(回文)にできるものを調べる
    REP(ns,n) REP(nt,n) {
      if (c[ns][s] == '-') continue; // ns -> s のパスあるか
      if (c[t][nt] == '-') continue; // t -> nt のパスがあるか
      if (c[ns][s] != c[t][nt]) continue; // ns と nt の文字が一致するか
      push(ns,nt,dist[s][t]+2);
    }
  }

  REP(i,n) {
    REP(j,n) cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
    cout << endl;
  }
  return 0;
}
