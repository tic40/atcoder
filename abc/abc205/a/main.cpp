#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  double a,b;
  cin >> a >> b;
  double ans = a / 100.0 * b;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}