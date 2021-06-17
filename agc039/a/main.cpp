#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

string s;
ll k;

void solve() {
  ll cnt = 0;
  REP(i,s.size()-1) {
    if (s[i] == s[i+1]) { i++; cnt++; }
  }

  ll ans = 0;
  if (s[0] == s.back()) {
    ll left = 1, right = 1;
    REP(i,s.size()-1) {
      if (s[i] != s[i+1]) break;
      left++;
    }
    reverse(s.begin(), s.end());
    REP(i,s.size()-1) {
      if (s[i] != s[i+1]) break;
      right++;
    }

    // すべて同じとき
    if (left == s.size()) {
      ans = left*k/2;
    } else {
      ans = cnt*k;
      ans -= (k-1) * (left/2);
      ans -= (k-1) * (right/2);
      ans += (k-1) * ((left+right) / 2);
    }
  } else {
    ans = cnt * k;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> s >> k;
  solve();
  return 0;
}