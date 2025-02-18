#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;

  auto f = [&](string s) {
    vector<ll> res(n+1);
    int one = 0;
    REP(i,n) {
      res[i+1] = res[i];
      if (s[i] == '1') one++;
      else res[i+1]+=one;
    }
    return res;
  };

  auto l  = f(s);
  reverse(s.begin(),s.end());
  auto r  = f(s);
  ll ans = 1e18;
  REP(i,n+1) ans = min(ans,l[i]+r[n-i]);
  cout << ans << endl;
  return 0;
}
