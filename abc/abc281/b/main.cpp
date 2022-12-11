#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  regex r("^[A-Z][1-9][0-9]{5}[A-Z]$");
  bool ok = regex_match(s,r);
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}