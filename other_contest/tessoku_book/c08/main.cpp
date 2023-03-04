#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  REP(i,n) cin >> s[i] >> t[i];

  auto check = [&](string a1, string a2) {
    int diff = 0;
    REP(i,4) if (a1[i] != a2[i]) diff++;
    if (diff == 0) return 1;
    if (diff == 1) return 2;
    return 3;
  };

  vector<string> ans;
  REP(i,10000) {
    string now = to_string(i);
    while(now.size() < 4) now = "0" + now;
    bool ok = true;
    REP(j,n) if (check(s[j],now) != t[j]) ok = false;
    if (ok) ans.push_back(now);
  }

  cout << ((int)ans.size() == 1 ? ans[0] : "Can't Solve") << endl;
  return 0;
}