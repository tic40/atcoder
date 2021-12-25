#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> s(n+1); // 累積和
  REP(i,n) s[i+1] = s[i]+a[i];

  map<ll,int> mp;
  mp[0]++;
  REP(i,n) mp[s[i+1]]++;

  ll ans = 0;
  REP(i,n) {
    /*
      s[i+x] - s[i] = k になるものを探す
      s[i+x] = k + s[i]
    */
    mp[s[i]]--;
    ll d = k + s[i];
    ans += mp[d];
  }

  cout << ans << endl;
  return 0;
}