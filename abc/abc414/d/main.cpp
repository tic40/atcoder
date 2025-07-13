#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> x(n);
  REP(i,n) cin >> x[i];
  sort(x.begin(),x.end());

  vector<ll> s(n-1);
  REP(i,n-1) s[i] = x[i+1] - x[i];
  sort(s.begin(),s.end());
  ll ans = 0;
  REP(i,n-m) ans += s[i];
  cout << ans << endl;
  return 0;
}