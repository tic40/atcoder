#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  string ans = "";
  REP(i,(int)s.size()) {
    if (s[i] == 'C') {
      if ((int)ans.size() >= 2 && ans.back() == 'B' && ans[(int)ans.size()-2] == 'A') {
        ans.pop_back();
        ans.pop_back();
      } else {
        ans += s[i];
      }
    } else {
      ans += s[i];
    }
  }

  cout << ans << endl;
  return 0;
}