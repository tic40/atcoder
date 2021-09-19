#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string x; int n;
  cin >> x >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  map<char, int> mp;
  REP(i,(int)x.size()) mp[x[i]] = i;

  REP(i,n) REP(j,(int)s[i].size()) {
    s[i][j] = 'a' + mp[s[i][j]];
  }

  sort(s.begin(),s.end());
  REP(i,n) {
    REP(j,(int)s[i].size()) {
      cout << x[s[i][j]-'a'];
    }
    cout << endl;
  }
  return 0;
}