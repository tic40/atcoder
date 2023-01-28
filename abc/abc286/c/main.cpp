#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n, a,b;
  cin >> n >> a >> b;
  string s; cin >> s;

  ll ans = 1e15;
  REP(i,n) {
    if (i > 0) rotate(s.begin(), s.begin()+1, s.end());
    ll now = a * i;
    REP(i,n/2) if (s[i] != s[n-1-i]) now += b;
    ans = min(ans,now);
  }

  cout << ans << endl;
  return 0;
}