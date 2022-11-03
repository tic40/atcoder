#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  vector b(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  REP(i,h) REP(j,w) cin >> b[i][j];

  ll ans = 0;
  REP(i,h-1) REP(j,w-1) {
    int d = b[i][j] - a[i][j];
    REP(k,2) REP(l,2) a[i+k][j+l] += d;
    ans += abs(d);
  }

  if (a == b) cout << "Yes" << endl << ans << endl;
  else cout << "No" << endl;

  return 0;
}