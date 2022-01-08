#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i, n) for(int i=0;i<n;i++)
#define endl "\n"
using G = vector<vector<int>>;
using P = pair<int,int>;
using ll = long long;
const int INF = 1e9;

int n,m;
vector<vector<P>> g(100010);

void dfs() {
  queue<P> q;
  vector<int> dist(n, INF);

  // 全ての点について矛盾がないか調べる
  // グラフが連結していないケースがあるためするためnまでループして調べる
  REP(i,n) {
    if (dist[i] != INF) continue; // チェック済み

    q.push({ i, 0 });
    dist[i] = 0;
    while(!q.empty()) {
      auto v = q.front(); q.pop();
      int p = v.first;

      for(auto x: g[p]) {
        int np = x.first;
        int nd = dist[p] + x.second;

        if (dist[np] == INF) {
          dist[np] = nd;
          q.push(x);
        } else {
          // 矛盾しているため終了
          if (dist[np] != nd) { COUT("No"); return; }
        }
      }
    }
  }
  COUT("Yes");
}

int main() {
  cin >> n >> m;

  // m == 0 の場合はそもそも矛盾しない
  if (m == 0) { COUT("Yes"); return 0; }

  vector<int> l(m),r(m),d(m);
  REP(i,m) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--; r[i]--;
  }

  REP(i,m) {
    g[l[i]].push_back({r[i], d[i]});
    g[r[i]].push_back({l[i], -d[i]});
  }

  dfs();
  return 0;
}