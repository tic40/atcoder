#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = max(s.size(),t.size());
  REP(i, n - (int)s.size()) s.push_back('_');
  REP(i, n - (int)t.size()) t.push_back('_');

  int ans = 0;
  REP(i,n) if (s[i] != t[i]) { ans = i+1; break; }
  cout << ans << endl;
  return 0;
}