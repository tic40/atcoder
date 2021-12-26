#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;


int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  map<ll,int> mp;
  REP(i,n+1) mp[s[i]]++;

  ll ans = 0;
  /*
  s[i+x] - s[i] = k;
  s[i+x] = k+s[i]
  */
  REP(i,n) {
    mp[s[i]]--;
    ans += mp[k+s[i]];
  }
  cout << ans << endl;
  return 0;
}