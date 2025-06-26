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
  reverse(e.begin(),e.end());

  string ans = "";
  int i = 0;
  for(auto [t,p,s]: e) {
    if (t == 1) {
      if (i == p) i = 0;
    }
    if (t == 2) {
      if (i == p) ans += s;
    }
    if (t == 3) {
      if (i == 0) i = p;
    }
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}