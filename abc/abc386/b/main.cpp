#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<pair<char,int>> vs;
  REP(i,n) {
    if (vs.size() && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }

  int ans = 0;
  for(auto [k,v]: vs) {
    if (k == '0') ans += (v+1)/2;
    else ans += v;
  }
  cout << ans << endl;
  return 0;
}