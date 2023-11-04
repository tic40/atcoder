#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string r,c; cin >> r >> c;
  string abc(n,'.');

  auto dfs = [&](auto self, char x, vector<string> s) -> bool {
    if (x == 'D') {
      string tr,tc;
      REP(i,n) REP(j,n) {
        if (s[i][j] != '.') { tr += s[i][j]; break; }
      }
      REP(j,n) REP(i,n) {
        if (s[i][j] != '.') { tc += s[i][j]; break; }
      }
      if (tr == r && tc == c) {
        cout << "Yes" << endl;
        REP(i,n) cout << s[i] << endl;
        return true;
      }
      return false;
    }

    vector<int> p(n);
    REP(i,n) p[i] = i;
    do {
      auto t = s;
      bool ok = true;
      REP(i,n) {
        if (t[i][p[i]] != '.') ok = false;
        t[i][p[i]] = x;
      }
      if (!ok) continue;
      if (self(self,x+1,t)) return true;
    } while (next_permutation(p.begin(),p.end()));
    return false;
  };

  vector<string> s(n,string(n,'.'));
  if (!dfs(dfs,'A',s)) cout << "No" << endl;
  return 0;
}