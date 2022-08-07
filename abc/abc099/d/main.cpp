#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,C;
  cin >> n >> C;
  vector d(C,vector<int>(C));
  REP(i,C) REP(j,C) cin >> d[i][j];
  vector c(n,vector<int>(n));
  REP(i,n) REP(j,n) {
    cin >> c[i][j];
    c[i][j]--;
  }

  // cost[i][j] := i(0-2)のときの,色をjにするときの総コスト
  vector cost(3,vector<int>(C));
  REP(x,C) REP(i,n) REP(j,n) {
    cost[ (i+j)%3 ][x] += d[ c[i][j] ][x];
  }

  int ans = 1e9;
  REP(i,C) REP(j,C) REP(k,C) {
    if (i==j || j==k || k==i) continue;
    ans = min(ans, cost[0][i]+cost[1][j]+cost[2][k]);
  }

  cout << ans << endl;
  return 0;
}