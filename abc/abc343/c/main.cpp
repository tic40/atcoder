#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

bool is_palindrome(string s) {
  string t = s;
  reverse(t.begin(),t.end());
  return t == s;
}

int main() {
  ll n, ans = 0; cin >> n;
  REP(i,1e6+1) {
    ll x = (ll)i*i*i;
    if (x > n) break;
    if (is_palindrome(to_string(x))) { ans = x; }
  }
  cout << ans << endl;
  return 0;
}