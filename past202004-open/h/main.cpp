#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
int n,m;
int si,sj,gi,gj;
int s[50][50];
int d[10][50][50];

void dfs(int i, int j, int cur) {
  if (cur == 10) return;
  REP(dir,4) {
    int ni = i+di[dir];
    int nj = j+dj[dir];
    if (ni < 0 || nj < 0 || n <= ni || m <= nj) continue;

    int nd = d[cur][i][j]+1;
    int ncur = cur;
    if (cur+1 == s[ni][nj]) ncur = min(9, cur+1);

    if (d[ncur][ni][nj] <= nd) continue;
    d[ncur][ni][nj] = nd;
    dfs(ni,nj,ncur);
  }
  return;
}

int main() {
  cin >> n >> m;

  REP(i,n) {
    string t; cin >> t;
    REP(j,m) {
      if (t[j] == 'S') s[i][j] = 0;
      else if (t[j] == 'G') s[i][j] = 10;
      else s[i][j] = t[j]-'0';
    }
  }

  REP(i,n) REP(j,m) {
    if (s[i][j] == 0) { si = i; sj = j; }
    if (s[i][j] == 10) { gi = i; gj = j; }
  }

  REP(i,10) REP(j,50) REP(k,50) d[i][j][k] = INF;
  d[0][si][sj] = 0;

  dfs(si, sj, 0);

  int ans = d[9][gi][gj];
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}