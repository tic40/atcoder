#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  const vector<string> vs = { "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD", };
  bool ok = false;
  for(auto c: vs) { if (s == c) ok = true; }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}