#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  vector<int> sh(h),sw(w);
  REP(i,h) REP(j,w) {
    sh[i] += a[i][j];
    sw[j] += a[i][j];
  }

  REP(i,h) {
    REP(j,w) cout << sh[i]+sw[j]-a[i][j] << " ";
    cout << endl;
  }
  return 0;
}