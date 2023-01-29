#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int m = t.size();

  vector<bool> ans(m+1,true);
  REP(_,2) {
    bool ok = true;
    REP(i,m) {
      if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) ok = false;
      ans[i+1] = ans[i+1] && ok;
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    reverse(ans.begin(),ans.end());
  }

  for(auto v: ans) cout << (v ? "Yes" : "No") << endl;
  return 0;
}