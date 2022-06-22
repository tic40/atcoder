#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int m[5005][5005];
int main() {
  int n,k; cin >> n >> k;
  REP(i,n) {
    int a,b; cin >> a >> b;
    m[a][b]++;
  }

  // 二次元累積和
  REP(i,5000) REP(j,5000) m[i][j+1] += m[i][j];
  REP(i,5000) REP(j,5000) m[i+1][j] += m[i][j];

  int ans = 0;
  REP(i,5001) REP(j,5001) {
    int lx = max(0,j-k-1);
    int ty = max(0,i-k-1);

    int cnt = m[i][j];
    cnt -= m[ty][j];
    cnt -= m[i][lx];
    cnt += m[ty][lx];
    ans = max(ans,cnt);
  }

  cout << ans << endl;
  return 0;
}
