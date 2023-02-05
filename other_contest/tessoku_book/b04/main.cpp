#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  reverse(s.begin(),s.end());
  int ans = 0;
  REP(i,(int)s.size()) ans += (s[i]-'0') * (1<<i);
  cout << ans << endl;
  return 0;
}