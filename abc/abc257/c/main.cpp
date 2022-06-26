#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  map<int,vector<int>> mp;
  REP(i,n) mp[w[i]].push_back(i);

  int now = 0;
  for(char c: s) if (c == '1') now++;
  int ans = now;

  for(auto [_,v]: mp) {
    for(auto i: v) s[i] == '1' ? now-- : now++;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}
