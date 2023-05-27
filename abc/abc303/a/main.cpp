#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s,t; cin >> n >> s >> t;

  auto f = [&](int i) {
    REP(_,2) {
      if (s[i] == t[i]) return true;
      if (s[i] == '1' && t[i] == 'l') return true;
      if (s[i] == '0' && t[i] == 'o') return true;
      swap(s,t);
    }
    return false;
  };

  int ok = 1;
  REP(i,n) ok &= f(i);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}