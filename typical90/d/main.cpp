#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w,a[2000][2000];

void solve() {
  // sv[i]: 行iの横一列の和
  // sh[i]: 列iの縦一列の和
  vector<int> sv(h),sh(w);

  REP(i,h) REP(j,w) sv[i] += a[i][j];
  REP(j,w) REP(i,h) sh[j] += a[i][j];
  REP(i,h) REP(j,w) {
    cout << (sv[i] + sh[j] - a[i][j]);
    j == w-1 ? cout << endl : cout << " ";
  }

  return;
}

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> a[i][j];

  solve();
  return 0;
}