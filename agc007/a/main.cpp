#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w;
vector<string> a;
int visited[10][10];

void dfs(int y, int x) {
  if (h <= y || w <= x) return;
  visited[y][x] = 1;
  if (y == h-1 && x == w-1) return;

  if (a[y][x+1] == '#') dfs(y, x+1);
  else if (a[y+1][x] == '#') dfs(y+1, x);

  return;
}

void solve() {
  dfs(0,0);
  bool ok = true;

  REP(i,h) REP(j,w) {
    if (a[i][j] == '#' && visited[i][j] == 0) {
      cout << "Impossible" << endl;
      return;
    }
  }
  cout << "Possible" << endl;
}

int main() {
  cin >> h >> w;
  a.resize(h);
  REP(i,h) REP(j,w) cin >> a[i][j];

  solve();
  return 0;
}