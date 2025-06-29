#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  auto solve = []() {
    int n; cin >> n;
    vector<int> s(n);
    REP(i,n) cin >> s[i];
    set<int> t;
    REP(i,n) if (s[i] <= s.back()) t.insert(s[i]);
    int now = s[0];
    int ans = 1;
    while(1) {
      auto it = t.upper_bound(now*2);
      it--;
      ans++;
      if (*it == s.back()) break;
      if (*it == now) return -1;
      now = *it;
    }
    return ans;
  };
  int t; cin >> t;
  REP(_,t) cout << solve() << endl;
  return 0;
}