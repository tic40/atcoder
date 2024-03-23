#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,a,b; cin >> n >> a >> b;
  string s; cin >> s;

  ll ans = LINF;
  REP(i,n) {
    ll now = (ll)a*i;
    REP(j,n/2) if (s[j] != s[n-1-j]) now += b;
    ans = min(ans,now);
    rotate(s.begin(), s.begin()+1, s.end());
  }
  cout << ans << endl;
  return 0;
}