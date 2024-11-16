#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  vector<pair<char,int>> vs;
  for(auto c: s) {
    if (vs.size() && vs.back().first == c) vs.back().second++;
    else vs.emplace_back(c,1);
  }
  REP(i,(int)vs.size()) {
    if (vs[i].first == '1') k--;
    if (k == 0) swap(vs[i-1],vs[i]);
  }
  for(auto [c,num]: vs) REP(i,num) cout << c;
  return 0;
}