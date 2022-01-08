#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s,t; cin >> s >> t;

  bool ok = s==t;
  REP(i,s.size()-1) {
    swap(s[i],s[i+1]);
    if (s == t) ok = true;
    swap(s[i],s[i+1]);
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}