#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<vector<int>> d(5005,vector<int>(5005));
  REP(i,n) {
    int a,b; cin >> a >> b;
    d[a][b]++;
  }

  // 二次元累積和
  for(int i = 1; i <= 5000; i++) {
    for(int j = 1; j <= 5000; j++) {
      d[i][j] += d[i-1][j];
    }
  }
  for(int i = 1; i <= 5000; i++) {
    for(int j = 1; j <= 5000; j++) {
      d[i][j] += d[i][j-1];
    }
  }

  int ans = 0;
  REP(i,5001) REP(j,5001) {
    int lx = max(0,j-k-1);
    int ty = max(0,i-k-1);
    int cnt = d[i][j];
    cnt -= d[ty][j];
    cnt -= d[i][lx];
    cnt += d[ty][lx];
    ans = max(ans,cnt);
  }

  cout << ans << endl;
  return 0;
}