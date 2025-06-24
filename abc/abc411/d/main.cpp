#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<tuple<int,int,string>> e;
  REP(i,q) {
    int t,p; string s;
    cin >> t >> p; // p--;
    if (t == 2) { cin >> s; reverse(s.begin(),s.end()); }
    e.emplace_back(t,p,s);
  }

  string ans = "";
  int i = 0;
  for(int t = q-1; t >= 0; t--) {
    auto [type,p,s] = e[t];
    if (type == 1) {
      if (i == p) i = 0;
    }
    if (type == 2) {
      if (i == p) ans += s;
    }
    if (type == 3) {
      if (i == 0) i = p;
    }
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}