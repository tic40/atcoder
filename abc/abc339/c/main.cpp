#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  ll ans = accumulate(a.begin(),a.end(),0LL);
  ll mn = *min_element(s.begin()+1,s.end());
  if (mn < 0) ans -= mn;
  cout << ans << endl;
  return 0;
}