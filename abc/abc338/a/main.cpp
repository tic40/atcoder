#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  bool ok = regex_match(s,regex("[A-Z][a-z]*"));
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}