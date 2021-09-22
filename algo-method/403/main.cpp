#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;

  int ans = 0;
  if (a < 0) {
    ans += -a*c+d;
    a = 0;
  }
  ans += (b - a)*e;

  cout << ans << endl;
  return 0;
}