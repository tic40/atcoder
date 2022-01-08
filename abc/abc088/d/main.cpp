#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
vector<string> s;
const vector<pair<int, int>> moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve() {
  int dist[51][51];
  REP(i,51) REP(j,51) dist[i][j] = INF;
  queue<pair<int, int>> q;

  auto push = [&](int ny, int nx, int d) {
    if (ny < 0 || h <= ny || nx < 0 || w <= nx) return;
    if (s[ny][nx] == '#') return;
    if (dist[ny][nx] <= d+1) return;
    q.push({ ny, nx });
    dist[ny][nx] = d+1;
  };

  push(0,0,-1);
  while(q.size()) {
    auto cur = q.front(); q.pop();
    int y = cur.first, x = cur.second;
    if (h == y && w == x) break;

    for(auto m: moves) push(y + m.first, x + m.second, dist[y][x]);
  }

  int best = dist[h-1][w-1];
  if (best == INF) { cout << -1 << endl; }
  else {
    int cnt = 0;
    REP(i,h) REP(j,w) if (s[i][j] == '#') cnt++;
    int ans = h*w - cnt - best - 1;
    cout << ans << endl;
  }

  return;
}

int main() {
  cin >> h >> w;
  s.resize(h);
  REP(i,h) cin >> s[i];

  solve();
  return 0;
}