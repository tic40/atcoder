#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m,d;
  cin >> n >> m >> d;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 0;
  // horizontal
  REP(i,n) REP(j,m-(d-1)) {
    int ok = true;
    REP(k,d) {
      if (s[i][j+k] == '#') ok = false;
    }
    ans += ok;
  }
  REP(i,n-(d-1)) REP(j,m) {
    int ok = true;
    REP(k,d) {
      if (s[i+k][j] == '#') ok = false;
    }
    ans += ok;
  }

  cout << ans << endl;
  return 0;
}