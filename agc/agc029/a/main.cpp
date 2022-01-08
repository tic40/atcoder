#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  string s; cin >> s;

  ll ans = 0;
  int pos_w = 0;
  REP(i,s.size()) {
    if (s[i] == 'W') {
      ans += i-pos_w;
      pos_w++;
    }
  }

  cout << ans << endl;
  return 0;
}