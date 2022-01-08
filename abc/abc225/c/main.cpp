#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll b[10005][10];
int main() {
  int n,m; cin >> n >> m;
  REP(i,n) REP(j,m) {
    cin >> b[i][j];
    b[i][j]--;
  }

  bool ok = true;
  REP(i,n) {
    int cur = b[i][0] / 7;
    REP(j,m) {
      if (0 < j) {
        if (b[i][j] / 7 != cur) ok = false;
        if (b[i][j] != b[i][j-1] + 1) ok = false;
      }
      if (0 < i) {
        if (b[i][j] != b[i-1][j] + 7) ok = false;
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}