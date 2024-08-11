#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n, q; cin >> n;
  vector<vector<vector<int>>> a(n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
  vector<vector<vector<int>>> s(n+2, vector<vector<int>>(n+2, vector<int>(n+2)));
  REP(i,n) REP(j,n) REP(k,n) cin >> a[i][j][k];

  // 累積和
  REP(i,n) REP(j,n) REP(k,n) s[i+1][j+1][k+1] += a[i][j][k];
  // xyz 軸ごとに取る
  REP(i,n+1) REP(j,n+1) REP(k,n+1) s[i+1][j][k] += s[i][j][k];
  REP(i,n+1) REP(j,n+1) REP(k,n+1) s[i][j+1][k] += s[i][j][k];
  REP(i,n+1) REP(j,n+1) REP(k,n+1) s[i][j][k+1] += s[i][j][k];

  cin >> q;
  REP(_,q) {
    int lx,rx,ly,ry,lz,rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    int ans = 0;
    ans += s[rx][ry][rz];
    ans -= s[lx-1][ry][rz];
    ans -= s[rx][ly-1][rz];
    ans -= s[rx][ry][lz-1];
    ans += s[lx-1][ly-1][rz];
    ans += s[lx-1][ry][lz-1];
    ans += s[rx][ly-1][lz-1];
    ans -= s[lx-1][ly-1][lz-1];
    cout << ans << endl;
  }
  return 0;
}