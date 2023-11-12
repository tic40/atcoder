#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  string ans = "";
  REP(i,(int)s.size()) {
    if (s[i] == 'C' && (int)ans.size() >= 2 && ans.substr(ans.size() - 2) == "AB") {
      ans.pop_back();
      ans.pop_back();
    } else {
      ans += s[i];
    }
  }

  cout << ans << endl;
  return 0;
}