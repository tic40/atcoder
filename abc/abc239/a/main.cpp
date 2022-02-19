#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  double x;
  cin >> x;
  double ans = sqrt( x * (12800000.0 + x) );
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}