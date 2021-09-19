#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  vector<pair<int,int>> ts(n);
  REP(i,n) {
    int s,t; cin >> s >> t;
    ts[i] = {t,s};
  }
  sort(ts.begin(),ts.end());

  int prev = -1, ans = 0;
  REP(i,n) {
    auto [t,s] = ts[i];
    if (prev <= s) {
      ans++;
      prev = t;
    }
  }

  cout << ans << endl;
  return 0;
}