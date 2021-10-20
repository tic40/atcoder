#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;

const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};

struct Edge { int x, y, cost; };
using T = tuple<int,int,int>;

int h,w,a[50][50];

vector<vector<int>> dijkstra(int i, int j) {
  vector<vector<int>> d(h,vector<int>(w,INF));
  priority_queue<T, vector<T>, greater<T>> q;

  d[i][j] = 0;
  q.push({ 0, i, j });

  while (q.size()) {
    auto [ cost, x, y ] = q.top(); q.pop();
    REP(v,4) {
      int ni = x + di[v], nj = y + dj[v];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;

      int nd = cost + a[ni][nj];
      if (d[ni][nj] <= nd) continue;

      d[ni][nj] = nd;
      q.push({ nd, ni, nj });
    }
  }

  return d;
}

void solve() {
  int ans = INF;
  auto d1 = dijkstra(h-1, 0);
  auto d2 = dijkstra(h-1, w-1);
  auto d3 = dijkstra(0, w-1);

  REP(i,h) REP(j,w) {
    int cur = d1[i][j] + d2[i][j] + d3[i][j];
    cur -= a[i][j] * 2; // 同じ点を3回通るので2回分を引く
    ans = min(ans,cur);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> a[i][j];

  solve();
  return 0;
}