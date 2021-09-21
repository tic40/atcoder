#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h,vector<int>(w));
  REP(i,h) REP(j,w) {
    cin >> a[i][j];
  }

  auto f = [&](int x, int y) {
    int ret = 0;
    REP(i,h) REP(j,w) {
      ret += a[i][j] * min(abs(x-i), abs(y-j));
    }
    return ret;
  };

  int ans = INF;
  REP(i,h) REP(j,w) {
    ans = min(ans, f(i,j));
  }

  cout << ans << endl;
  return 0;
}