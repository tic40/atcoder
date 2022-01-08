#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

const int SIZE = 505;
int g[SIZE][SIZE];
int s[SIZE][SIZE];

int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  REP(i,M) {
    int l,r; cin >> l >> r;
    g[l-1][r-1]++;
  }

  // 前計算: 二次元累積和
  REP(i,N) REP(j,N) {
    s[i+1][j+1] = g[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];
  }

  REP(i,Q) {
    int l,r; cin >> l >> r;
    // 二次元累積和から答えを算出する
    int ans = s[r][r] - s[l-1][r] - s[r][l-1] + s[l-1][l-1];
    cout << ans << endl;
  }

  return 0;
}