#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector<pair<char,int>> run_length(string s) {
  vector<pair<char,int>> vs;
  REP(i,(int)s.size()) {
    if (0 < i && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }
  return vs;
}

int main() {
  string s; cin >> s;
  auto res = run_length(s);
  int ans = 0;
  for(auto [k,v]: res) {
    if (k == '0') ans += (v+1)/2;
    else ans += v;
  }
  cout << ans << endl;
  return 0;
}