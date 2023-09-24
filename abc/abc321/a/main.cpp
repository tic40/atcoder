#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  bool ok = true;
  REP(i,(int)s.size()-1) if (s[i]-'0' <= s[i+1]-'0') ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}