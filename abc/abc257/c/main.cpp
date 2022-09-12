#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  map<int,vector<int>> mp;
  REP(i,n) mp[w[i]].push_back(s[i]-'0');

  int now = 0;
  for(char c: s) if (c == '1') now++;
  int ans = now;

  for(auto [a,b]: mp) {
    for(char c: b) c == 1 ? now-- : now++;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}