#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector s(1001, vector<int>(1001)); // 2次元累積和
  REP(i,n) {
    int lx,ly,rx,ry;
    cin >> lx >> ly >> rx >> ry;
    s[lx][ly]++; // 左下
    s[lx][ry]--; // 左上
    s[rx][ly]--; // 右下
    s[rx][ry]++; // 右上
  }

  REP(i,1000) REP(j,1000) s[i+1][j] += s[i][j];
  REP(i,1000) REP(j,1000) s[i][j+1] += s[i][j];

  vector<int> ans(n+1);
  REP(i,1000) REP(j,1000) ans[s[i][j]]++;
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
  return 0;
}