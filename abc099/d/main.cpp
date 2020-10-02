#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int N,C;
int d[30][30],c[500][500];
int cost[3][30];
int ans=1e9;

int main() {
  cin >> N >> C;
  REP(i,C) REP(j,C) cin >> d[i][j];
  REP(i,N) REP(j,N) cin >> c[i][j], c[i][j]--;

  // 前処理
  REP(x,C) REP(i,N) REP(j,N) {
    cost[(i+j)%3][x] += d[c[i][j]][x];
  }

  REP(i,C) REP(j,C) REP(k,C) {
    if (i==j || j==k || k==i) continue;
    ans = min(ans, cost[0][i]+cost[1][j]+cost[2][k]);
  }

  cout << ans << endl;
  return 0;
}