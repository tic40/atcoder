#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

const vector<int> di = {0,1,0,-1};
const vector<int> dj = {1,0,-1,0};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  P st,ga;
  REP(i,h) REP(j,w) {
    if (s[i][j] == 'S') st = P{i,j};
    if (s[i][j] == 'G') ga = P{i,j};
  }

  // dist[i][j][k]
  //   i,j マスで k(0: 横向き, 1: 縦向き)のときの最小移動回数
  vector dist(h,vector(w,vector<int>(2,INF)));
  queue<tuple<int,int,int>> q;

  auto push = [&](int i, int j, int k, int d) {
    if (i < 0 || j < 0 || i >= h || j >= w) return;
    if (s[i][j] == '#') return;
    if (dist[i][j][k] <= d) return;
    q.emplace(i,j,k);
    dist[i][j][k] = d;
  };

  push(st.first, st.second, 0, 0);
  push(st.first, st.second, 1, 0);

  while(q.size()) {
    auto [i,j,k] = q.front(); q.pop();
    REP(l,4) {
      int ni = i + di[l];
      int nj = j + dj[l];
      int nk = di[l] == 0 ? 0 : 1;
      if (nk == k) continue; // 向きが同じ場合
      push(ni,nj,nk,dist[i][j][k]+1);
    }
  }

  int ans = min(dist[ga.first][ga.second][0], dist[ga.first][ga.second][1]);
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}