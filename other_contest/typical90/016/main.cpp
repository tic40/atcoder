#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,a,b,c; cin >> n >> a >> b >> c;
  int ans = 10000;
  REP(i,10000) REP(j,10000) {
    if (i+j >= ans) break;
    ll now = a*i + b*j;
    ll d = n - now;
    if (d >= 0 && d % c == 0) ans = min(ans, (int)(i+j+d/c));
  }
  cout << ans << endl;
  return 0;
}