#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = s.size();

  vector<string> ans;
  while(s != t) {
    vector<int> cand;
    REP(i,n) {
      if (s[i] == t[i]) continue;
      cand.push_back(i);
      if (s[i] > t[i]) break;
    }
    if (cand.size()) {
      s[cand.back()] = t[cand.back()];
      ans.push_back(s);
    }
  }

  cout << ans.size() << endl;
  for(auto v: ans) cout << v << endl;
  return 0;
}