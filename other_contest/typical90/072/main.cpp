#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

const vector<P> moves = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int h,w;
vector<string> c(16);
vector dist(16,vector<int>(16));
int gx, gy;
int ans = -1;

void dfs(int i, int j) {
  int k = dist[i][j];
  if (k > 0 && i == gx && j == gy) {
    if (k >= 3) ans = max(ans,k);
    return;
  }

  for(auto [di,dj]: moves) {
    int ni = i+di, nj = j+dj;
    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    if (c[ni][nj] == '#') continue;
    if (dist[ni][nj] > 0) continue;
    dist[ni][nj] = k+1;
    dfs(ni,nj);
    dist[ni][nj] = 0;
  }
  return;
}

int main() {
  cin >> h >> w;
  REP(i,h) cin >> c[i];
  REP(i,h) REP(j,w) {
    if (c[i][j] == '#') continue;
    dist = vector(h,vector<int>(w,0));
    gx = i, gy = j;
    dfs(i,j);
  }
  cout << ans << endl;
  return 0;
}