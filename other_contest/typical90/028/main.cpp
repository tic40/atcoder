#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int mx = 1000;
int main() {
  int n; cin >> n;
  vector s(mx+1, vector<int>(mx+1)); // 2次元累積和
  REP(i,n) {
    int lx,ly,rx,ry;
    cin >> lx >> ly >> rx >> ry;
    s[lx][ly]++; // 左下
    s[lx][ry]--; // 左上
    s[rx][ly]--; // 右下
    s[rx][ry]++; // 右上
  }

  REP(i,mx) REP(j,mx) s[i+1][j] += s[i][j];
  REP(i,mx) REP(j,mx) s[i][j+1] += s[i][j];

  vector<int> ans(n+1);
  REP(i,mx) REP(j,mx) ans[s[i][j]]++;
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
  return 0;
}