#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const string atc = "atcoder";
  string s,t; cin >> s >> t;
  set<char> st;
  map<char,int> ms,mt;
  for(auto c: s) { st.insert(c); ms[c]++; }
  for(auto c: t) { st.insert(c); mt[c]++; }

  bool ok = true;
  for(char c: st) {
    if (c == '@') continue;
    int d = ms[c] - mt[c];
    if (d == 0) continue;
    if (atc.find(c) == string::npos) ok = false;
    d > 0 ? mt['@'] -= d : ms['@'] -= d;
  }

  if (ms['@'] < 0 || mt['@'] < 0) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}