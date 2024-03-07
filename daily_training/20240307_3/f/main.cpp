#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll d; cin >> d;
 ll ans = LINF;
  REP(x,1e6) {
    ll diff = d - ll(x)*x;
    ll sq = sqrt(diff);
    ll now = abs(diff - (sq*sq));
    ans = min(ans,now);
    sq++;
    now = abs(diff - (sq*sq));
    ans = min(ans,now);
  }
  cout << ans << endl;
  return 0;
}