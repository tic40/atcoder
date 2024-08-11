#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m=0; cin >> n;
  vector<string> s(n,string(100,'*'));
  REP(i,n) {
    string t; cin >> t;
    m = max(m,(int)t.size());
    REP(j,(int)t.size()) s[i][j] = t[j];
  }

  REP(j,m) {
    string ans = "";
    REP(i,n) ans = s[i][j] + ans;
    while(ans.back() == '*') ans.pop_back();
    cout << ans << endl;
  }
  return 0;
}