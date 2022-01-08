#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

// 2次元累積和
int s[1005][1005];

int main() {
  int n; cin >> n;
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

  vector<int> ans(1000005);
  REP(i,1000) REP(j,1000) {
    if (1 <= s[i][j]) ans[s[i][j]]++;
  }

	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
  return 0;
}