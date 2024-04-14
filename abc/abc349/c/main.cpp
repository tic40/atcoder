#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  REP(i,3) t[i] = tolower(t[i]);

  int now = 0;
  string ns = "";
  for(auto c: s) if (c == t[now]) { now++; ns += c; }

  if (ns.size() == 2) ns += 'x';
  cout << (ns == t ? "Yes" : "No") << endl;
  return 0;
}