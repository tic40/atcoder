#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> d = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int h,w,si,sj;
vector<string> c(16);
vector dist(16,vector<int>(16));

int dfs(int i, int j) {
  if (i == si && j == sj && dist[i][j]) {
    return dist[i][j] >= 3 ? dist[i][j] : -1;
  }

  int res = -1;
  for(auto [di,dj]: d) {
    int ni = di+i;
    int nj = dj+j;
    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    if (c[ni][nj] == '#') continue;
    if (dist[ni][nj]) continue;
    dist[ni][nj] = dist[i][j]+1;
    res = max(res, dfs(ni,nj));
    dist[ni][nj] = 0;
  }
  return res;
}

int main() {
  cin >> h >> w;
  REP(i,h) cin >> c[i];

  int ans = -1;
  REP(i,h) REP(j,w) {
    if (c[i][j] == '#') continue;
    si = i; sj = j;
    dist = vector (h,vector<int>(w));
    ans = max(ans, dfs(i,j));
  }
  cout << ans << endl;
  return 0;
}