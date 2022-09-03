#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const vector<vector<int>> g = { { 6 }, { 3 }, { 1,7 }, { 0,4 }, { 2,8 }, { 5 }, { 9 } };
const int l = g.size();

int main() {
  string s; cin >> s;
  if (s[0] == '1') { cout << "No" << endl; return 0; }

  vector<int> on;
  REP(i,l) for(int v: g[i]) {
    if (s[v] == '1') { on.push_back(i); break; }
  }

  bool ok = false;
  int last = -1;
  for(int v: on) {
    if (last == -1) last = v;
    if (v - last > 1) ok = true;
    last = v;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}