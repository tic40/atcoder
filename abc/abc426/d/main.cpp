#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int t; cin >> t;

  auto solve = []() {
    int n; string s; cin >> n >> s;

    vector<P> vs;
    REP(i,n) {
      if (vs.size() && vs.back().first == s[i]-'0') vs.back().second++;
      else vs.emplace_back(s[i]-'0',1);
    }

    vector<int> cnt(2);
    for(auto c: s) cnt[c-'0']++;
    int ans = 1e9;
    for(auto [k,v]: vs) ans = min(ans, (cnt[k]-v)*2 + cnt[k^1]);
    cout << ans << endl;
  };

  REP(_,t) solve();
  return 0;
}