#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> b(n);
  REP(i,n) {
    string s; cin >> s;
    REP(j,m) if (s[j] == 'o') b[i] += 1<<j;
  }

  int ans = 0;
  ll t = (1<<m)-1;
  REP(i,n) for(int j = i+1; j < n; j++) {
    ll x = b[i] | b[j];
    if (x == t) ans++;
  }

  cout << ans << endl;
  return 0;
}