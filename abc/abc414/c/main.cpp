#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int a; ll n; cin >> a >> n;
  ll ans = 0;

  auto isPallindrome = [&](ll x) -> bool {
    string s;
    while(x) {
      s += '0' + x % a;
      x /= a;
    }
    int n = s.size();
    REP(i,n/2) if (s[i] != s[n-1-i]) return false;
    return true;
  };

  auto check = [&](string s) -> void {
    ll y = stoll(s);
    if (y <= n && isPallindrome(y)) ans += y;
  };

  for(ll x = 1; x < 1e6; x++) {
    string s = to_string(x);
    string rs = s;
    reverse(rs.begin(),rs.end());
    s += rs;

    check(s);
    s.erase(s.size()/2,1); // 真ん中を削除
    check(s);
  }
  cout << ans << endl;
  return 0;
}