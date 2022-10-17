#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; string s,t;
  cin >> n >> s >> t;

  int d = 0;
  REP(i,n) if (s[i] != t[i]) d++;
  // diffが奇数個の場合は不可能
  if (d%2) { cout << -1 << endl; return 0; }

  string ans = "";
  int scnt = d/2, tcnt = d/2;
  REP(i,n) {
    if (s[i] == t[i]) {
      ans += '0';
    } else {
      if (scnt == 0) ans += t[i], tcnt--;
      else if (tcnt == 0) ans += s[i], scnt--;
      else {
        ans += '0';
        s[i] == '0' ? scnt-- : tcnt--;
      }
    }
  }

  cout << ans << endl;
  return 0;
}