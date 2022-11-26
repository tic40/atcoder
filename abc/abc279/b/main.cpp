#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s,t;
  cin >> s >> t;

  REP(i,(int)s.size()) {
    int ok = true;
    REP(j,(int)t.size()) {
      if (i+j >= (int)s.size()) { ok = false; break; }
      if (s[i+j] != t[j]) ok = false;
    }
    if (ok) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}