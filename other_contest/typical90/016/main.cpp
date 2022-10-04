#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  ll a,b,c; cin >> a >> b >> c;

  int ans = 1e4;
  REP(i,1e4) REP(j,1e4-i) {
    ll now = n - a*i - b*j;
    if (now >= 0 && now % c == 0) ans = min(ans, (int)(i+j+now/c));
  }

  cout << ans << endl;
  return 0;
}