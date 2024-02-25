#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector<pair<char,int>> run_length(string &s) {
  vector<pair<char,int>> vs;
  REP(i,(int)s.size()) {
    if (0 < i && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }
  return vs;
}

int main() {
  string s,t; cin >> s >> t;
  auto sp = run_length(s), tp = run_length(t);
  auto solve = [&]() {
    if (sp.size() != tp.size()) { return false; }
    REP(i,(int)tp.size()) {
      if (sp[i].first != tp[i].first) return false;
      if (sp[i].second > tp[i].second) return false;
      if (sp[i].second == 1 && tp[i].second > 1) return false;
    }
    return true;
  };
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}