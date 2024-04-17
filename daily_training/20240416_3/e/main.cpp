#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n; cin >> n;

  auto f = [&](string s) {
    auto t = s;
    reverse(t.begin(),t.end());
    return t == s;
  };

  ll ans = 0;
  for(ll i = 1; i*i*i <= n; i++) {
    ll x = i*i*i;
    auto s = to_string(x);
    if (f(s)) ans = x;
  }
  cout << ans << endl;
  return 0;
}