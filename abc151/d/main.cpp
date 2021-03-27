#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int h,w;
vector<string> s;
int dist[20][20];

const vector<pair<int, int>> moves =  {
  {1,0}, {-1, 0}, {0, 1}, {0, -1}
};

void dfs(int i, int j, int d) {
  if (i < 0 || j < 0 || h <= i || w <= j) return;
  if (s[i][j] == '#') return;
  if (dist[i][j] <= d) return;

  dist[i][j] = d;

  for(auto v: moves) {
    int ni = i + v.first;
    int nj = j + v.second;
    dfs(ni, nj, d+1);
  }
}

int main() {
  cin >> h >> w;
  s.resize(h);
  REP(i,h) cin >> s[i];

  int ans = 0;
  REP(i,h) REP(j,w) {
    REP(k,h) REP(l,w) dist[k][l] = INF;

    dfs(i,j,0);

    REP(k,h) REP(l,w) if (dist[k][l] != INF) {
      ans = max(ans, dist[k][l]);
    }
  }

  cout << ans << endl;
  return 0;
}