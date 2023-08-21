#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<ll> f(n),s(n);
  REP(i,n) { cin >> f[i] >> s[i]; f[i]--; }
  vector g(n,vector<ll>());
  REP(i,n) g[f[i]].push_back(s[i]);
  for(auto& v: g) sort(v.rbegin(),v.rend());

  ll ans = 0;
  for(auto v: g) if (v.size() > 1) chmax(ans,v[0]+v[1]/2);
  vector<ll> x;
  for(auto v: g) if (v.size()) x.push_back(v[0]);
  if (x.size() > 1) {
    sort(x.rbegin(),x.rend());
    chmax(ans,x[0]+x[1]);
  }

  cout << ans << endl;
  return 0;
}