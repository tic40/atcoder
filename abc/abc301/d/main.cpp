#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  ll n; cin >> n;

  int sz = s.size();
  ll ans = 0;
  REP(i,sz) if (s[i] == '1') ans += (1LL << (sz-i-1));
  REP(i,sz) {
    if (s[i] != '?') continue;
    ll now = 1LL << (sz-i-1);
    if (ans + now <= n) ans += now;
  }

  cout << (ans > n ? -1 : ans) << endl;
  return 0;
}