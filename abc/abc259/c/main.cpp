#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<char,int>;

vector<P> run_length(string s) {
  vector<P> vs;
  REP(i,(int)s.size()) {
    if (i > 0 && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }
  return vs;
}

int main() {
  string s,t; cin >> s >> t;

  auto vs = run_length(s);
  auto vt = run_length(t);

  if (vs.size() != vt.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  REP(i,(int)vs.size()) {
    if (vs[i].first != vt[i].first) ok = false;
    if (vs[i].second == 1 && vt[i].second > 1) ok = false;
    if (vs[i].second > vt[i].second) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}