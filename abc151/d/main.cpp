#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
vector<string> s(20);
int dist[20][20];
const vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int y, int x, int d) {
  dist[y][x]=d;
  auto ok = [&](int ny, int nx){
    if (ny < 0 || h <= ny || nx < 0 || w <= nx) return false;
    if (s[ny][nx] == '#') return false;
    if (dist[ny][nx] <= d+1) return false;
    return true;
  };

  for (auto v: moves) {
    int ny = y + v.first, nx = x + v.second;
    if (ok(ny,nx)) dfs(ny,nx,d+1);
  }
  return;
}

void solve() {
  int ans = 0;

  REP(i,h) REP(j,w) {
    REP(k,h) REP(l,w) dist[k][l] = INF;
    if (s[i][j] == '#') continue;
    dfs(i,j,0);
    REP(k,h) REP(l,w) {
      if (dist[k][l] != INF) ans = max(ans, dist[k][l]);
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w;
  REP(i,h) cin >> s[i];

  solve();
  return 0;
}