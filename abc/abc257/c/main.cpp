#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  map<int, vector<int>> mp;
  REP(i,n) mp[w[i]].push_back(i);

  int x = 0;
  for(char c: s) if (c == '1') x++;
  int ans = x;

  for(auto [_,v]: mp) {
    for(int i: v) s[i] == '1' ? x-- : x++;
    ans = max(ans,x);
  }

  cout << ans << endl;
  return 0;
}