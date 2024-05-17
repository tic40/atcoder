#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;

  string ans = "";
  for(auto c: s) {
    if (c == 'C' && ans.size() >= 2 && ans[ans.size() - 1] == 'B' && ans[ans.size() - 2] == 'A') {
      ans.pop_back();
      ans.pop_back();
    } else {
      ans += c;
    }
  }
  cout << ans << endl;
  return 0;
}