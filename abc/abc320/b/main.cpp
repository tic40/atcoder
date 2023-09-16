#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  auto check = [&](string s) {
    auto t = s;
    reverse(t.begin(),t.end());
    return t == s;
  };

  int ans = 0;
  REP(i,n) for(int j = 1; j+i <= n; j++) {
    if (check(s.substr(i,j))) ans = max(ans,j);
  }
  cout << ans << endl;
  return 0;
}