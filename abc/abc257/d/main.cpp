#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n),p(n);
  REP(i,n) cin >> x[i] >> y[i] >> p[i];

  ll ok = 4e9, ng = 0;
  while(ok - ng  > 1) {
    ll mid = (ok+ng) / 2;

    // dp[i][j] := iからjへの移動が可能なら1、不可能なら0
    vector dp(n, vector<int>(n));

    REP(i,n) REP(j,n) {
      ll d = (ll)abs(x[i]-x[j]) + abs(y[i]-y[j]);
      if (mid*p[i] >= d) dp[i][j] = 1;
    }
    REP(k,n) REP(i,n) REP(j,n) {
      dp[i][j] |= dp[i][k] & dp[k][j];
    }

    auto possible = [&]() {
      REP(i,n) {
        bool res = true;
        REP(j,n) if (dp[i][j] == 0) res = false;
        if (res) return true;
      }
      return false;
    };

    if (possible()) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}