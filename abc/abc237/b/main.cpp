#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  REP(j,w) {
    REP(i,h) cout << a[i][j] << " ";
    cout << endl;
  }

  return 0;
}