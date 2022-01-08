#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
int a[105][105], b[105][105];

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> a[i][j];
  REP(i,h) REP(j,w) cin >> b[i][j];

  int tota = 0, totb = 0;
  REP(i,h) REP(j,w) {
    tota += a[i][j];
    totb += b[i][j];
  }

  ll ans = 0;
  REP(i,h-1) REP(j,w-1) {
    int d = b[i][j] - a[i][j];
    a[i][j] += d;
    a[i+1][j] += d;
    a[i][j+1] += d;
    a[i+1][j+1] += d;
    ans += abs(d);
  }

  bool ok = true;
  REP(i,h) REP(j,w) {
    if (a[i][j] != b[i][j]) ok = false;
  }

  if (ok) {
    cout << "Yes" << endl;
    cout << ans << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}