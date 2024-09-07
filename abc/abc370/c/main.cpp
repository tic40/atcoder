#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = s.size();

  vector<string> ans;
  while(s != t) {
    int idx = -1;
    REP(i,n) if (s[i] != t[i]) {
      idx = i;
      if (s[i] > t[i]) break;
    }
    s[idx] = t[idx];
    ans.push_back(s);
  }

  cout << ans.size() << endl;
  for(auto v: ans) cout << v << endl;
  return 0;
}